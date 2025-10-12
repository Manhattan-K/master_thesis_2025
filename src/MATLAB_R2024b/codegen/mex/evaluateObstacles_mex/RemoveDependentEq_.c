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
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
int32_T RemoveDependentEq_(e_struct_T *memspace, k_struct_T *workingset,
                           f_struct_T *qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idxDiag;
  int32_T idx_col;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  nVar = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    real_T tol;
    int32_T i;
    int32_T totalRank_tmp;
    i = (uint16_T)nVar;
    for (idxDiag = 0; idxDiag < mTotalWorkingEq_tmp; idxDiag++) {
      for (idx_col = 0; idx_col < i; idx_col++) {
        qrmanager->QR->data[idxDiag + qrmanager->ldq * idx_col] =
            workingset->ATwset->data[idx_col + workingset->ldA * idxDiag];
      }
    }
    idxDiag = mTotalWorkingEq_tmp - workingset->nVar;
    nDepInd = muIntScalarMax_sint32(0, idxDiag);
    i = (uint16_T)workingset->nVar;
    memset(&qrmanager->jpvt.data[0], 0, (uint32_T)i * sizeof(int32_T));
    i = mTotalWorkingEq_tmp * workingset->nVar;
    if (i == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq_tmp, workingset->nVar);
      xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 *
                                (real_T)muIntScalarMax_sint32(
                                    mTotalWorkingEq_tmp, workingset->nVar));
    totalRank_tmp =
        muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq_tmp);
    idxDiag = totalRank_tmp + qrmanager->ldq * (totalRank_tmp - 1);
    while ((idxDiag > 0) &&
           (muDoubleScalarAbs(qrmanager->QR->data[idxDiag - 1]) <
            tol * muDoubleScalarAbs(qrmanager->QR->data[0]))) {
      idxDiag = (idxDiag - qrmanager->ldq) - 1;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      computeQ_(qrmanager, qrmanager->mrows);
      idxDiag = 0;
      exitg1 = false;
      while ((!exitg1) && (idxDiag <= nDepInd - 1)) {
        real_T x;
        n_t = (ptrdiff_t)mTotalWorkingEq_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        x = ddot(&n_t,
                 &qrmanager->Q->data[qrmanager->ldq *
                                     ((mTotalWorkingEq_tmp - idxDiag) - 1)],
                 &incx_t, &workingset->bwset->data[0], &incy_t);
        if (muDoubleScalarAbs(x) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idxDiag++;
        }
      }
    }
    if (nDepInd > 0) {
      n_t = (ptrdiff_t)nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
        dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idx_col],
              &incx_t, &qrmanager->QR->data[qrmanager->ldq * idx_col], &incy_t);
      }
      for (idxDiag = 0; idxDiag < mWorkingFixed; idxDiag++) {
        qrmanager->jpvt.data[idxDiag] = 1;
      }
      idxDiag = workingset->nWConstr[0] + 1;
      if (idxDiag <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt.data[idxDiag + -1], 0,
               (uint32_T)((mTotalWorkingEq_tmp - idxDiag) + 1) *
                   sizeof(int32_T));
      }
      if (i == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = totalRank_tmp;
        xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
               qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
      }
      for (idxDiag = 0; idxDiag < nDepInd; idxDiag++) {
        memspace->workspace_int.data[idxDiag] =
            qrmanager->jpvt.data[(mTotalWorkingEq_tmp - nDepInd) + idxDiag];
      }
      countsort(memspace->workspace_int.data, nDepInd,
                memspace->workspace_sort.data, 1, mTotalWorkingEq_tmp);
      for (idxDiag = nDepInd; idxDiag >= 1; idxDiag--) {
        if (mTotalWorkingEq_tmp != 0) {
          i = memspace->workspace_int.data[idxDiag - 1];
          if (i <= mTotalWorkingEq_tmp) {
            if ((workingset->nActiveConstr == mTotalWorkingEq_tmp) ||
                (i == mTotalWorkingEq_tmp)) {
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
