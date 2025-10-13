/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RemoveDependentEq_.c
 *
 * Code generation for function 'RemoveDependentEq_'
 *
 */

/* Include files */
#include "RemoveDependentEq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
int32_T RemoveDependentEq_(emlrtCTX aTLS, f_struct_T *memspace,
                           i_struct_T *workingset, g_struct_T *qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  int32_T RemoveDependentEq__numThreads;
  int32_T idx;
  int32_T idxDiag;
  int32_T idx_col;
  int32_T mTotalWorkingEq;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  nVar = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq > 0) {
    real_T tol;
    int32_T i;
    i = (uint16_T)nVar;
    for (idxDiag = 0; idxDiag < mTotalWorkingEq; idxDiag++) {
      for (idx_col = 0; idx_col < i; idx_col++) {
        qrmanager->QR->data[idxDiag + qrmanager->ldq * idx_col] =
            workingset->ATwset->data[idx_col + workingset->ldA * idxDiag];
      }
    }
    idxDiag = mTotalWorkingEq - workingset->nVar;
    nDepInd = muIntScalarMax_sint32(0, idxDiag);
    i = (uint16_T)workingset->nVar;
    if (i - 1 >= 0) {
      memset(&qrmanager->jpvt.data[0], 0, (uint32_T)i * sizeof(int32_T));
    }
    if (mTotalWorkingEq * workingset->nVar == 0) {
      qrmanager->mrows = mTotalWorkingEq;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq, workingset->nVar);
      xgeqp3(aTLS, qrmanager->QR, mTotalWorkingEq, workingset->nVar,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    tol = muDoubleScalarMin(
        1.4901161193847656E-8,
        2.2204460492503131E-15 *
            (real_T)muIntScalarMax_sint32(mTotalWorkingEq, workingset->nVar));
    idxDiag = muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq);
    idxDiag += qrmanager->ldq * (idxDiag - 1);
    while ((idxDiag > 0) &&
           (muDoubleScalarAbs(qrmanager->QR->data[idxDiag - 1]) <
            tol * muDoubleScalarAbs(qrmanager->QR->data[0]))) {
      idxDiag = (idxDiag - qrmanager->ldq) - 1;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      computeQ_(aTLS, qrmanager, qrmanager->mrows);
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        real_T x;
        n_t = (ptrdiff_t)mTotalWorkingEq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        x = ddot(&n_t,
                 &qrmanager->Q->data[qrmanager->ldq *
                                     ((mTotalWorkingEq - idx_col) - 1)],
                 &incx_t, &workingset->bwset->data[0], &incy_t);
        if (muDoubleScalarAbs(x) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx_col++;
        }
      }
    }
    if (nDepInd > 0) {
      n_t = (ptrdiff_t)nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      for (idx_col = 0; idx_col < mTotalWorkingEq; idx_col++) {
        dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idx_col],
              &incx_t, &qrmanager->QR->data[qrmanager->ldq * idx_col], &incy_t);
      }
      if (mWorkingFixed < 1200) {
        for (idx = 0; idx < mWorkingFixed; idx++) {
          qrmanager->jpvt.data[idx] = 1;
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        RemoveDependentEq__numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(RemoveDependentEq__numThreads)

        for (idx = 0; idx < mWorkingFixed; idx++) {
          qrmanager->jpvt.data[idx] = 1;
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      i = workingset->nWConstr[0] + 1;
      if (i <= mTotalWorkingEq) {
        memset(&qrmanager->jpvt.data[i + -1], 0,
               (uint32_T)((mTotalWorkingEq - i) + 1) * sizeof(int32_T));
      }
      if (workingset->nVar * mTotalWorkingEq == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq;
        qrmanager->minRowCol =
            muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq);
        xgeqp3(aTLS, qrmanager->QR, workingset->nVar, mTotalWorkingEq,
               qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
      }
      if (nDepInd < 1200) {
        for (idx = 0; idx < nDepInd; idx++) {
          memspace->workspace_int.data[idx] =
              qrmanager->jpvt.data[(mTotalWorkingEq - nDepInd) + idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        RemoveDependentEq__numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(RemoveDependentEq__numThreads)

        for (idx = 0; idx < nDepInd; idx++) {
          memspace->workspace_int.data[idx] =
              qrmanager->jpvt.data[(mTotalWorkingEq - nDepInd) + idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      countsort(aTLS, memspace->workspace_int.data, nDepInd,
                memspace->workspace_sort.data, 1, mTotalWorkingEq);
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        i = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (i != 0) {
          idxDiag = memspace->workspace_int.data[idx_col - 1];
          if (idxDiag <= i) {
            if ((workingset->nActiveConstr == i) || (idxDiag == i)) {
              workingset->mEqRemoved++;
              /* A check that is always false is detected at compile-time.
               * Eliminating code that follows. */
            } else {
              workingset->mEqRemoved++;
              /* A check that is always false is detected at compile-time.
               * Eliminating code that follows. */
            }
          }
        }
      }
    }
  }
  return nDepInd;
}

/* End of code generation (RemoveDependentEq_.c) */
