/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RemoveDependentIneq_.c
 *
 * Code generation for function 'RemoveDependentIneq_'
 *
 */

/* Include files */
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void RemoveDependentIneq_(emlrtCTX aTLS, i_struct_T *workingset,
                          g_struct_T *qrmanager, f_struct_T *memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T maxDiag;
  real_T maxDiagPrime;
  real_T tol;
  real_T x;
  int32_T RemoveDependentIneq__numThreads;
  int32_T b_idx;
  int32_T idx;
  int32_T idxDiag;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 *
                              (real_T)muIntScalarMax_sint32(
                                  workingset->nVar, workingset->nActiveConstr));
    if (nFixedConstr < 1200) {
      for (idx = 0; idx < nFixedConstr; idx++) {
        qrmanager->jpvt.data[idx] = 1;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      RemoveDependentIneq__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(RemoveDependentIneq__numThreads)

      for (idx = 0; idx < nFixedConstr; idx++) {
        qrmanager->jpvt.data[idx] = 1;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nActiveConstr) {
      memset(&qrmanager->jpvt.data[idxDiag + -1], 0,
             (uint32_T)((nActiveConstr - idxDiag) + 1) * sizeof(int32_T));
    }
    for (idxDiag = 0; idxDiag < nActiveConstr; idxDiag++) {
      n_t = (ptrdiff_t)nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idxDiag], &incx_t,
            &qrmanager->QR->data[qrmanager->ldq * idxDiag], &incy_t);
    }
    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(workingset->nVar, workingset->nActiveConstr);
      xgeqp3(aTLS, qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    nActiveConstr = 0;
    for (b_idx = workingset->nActiveConstr - 1; b_idx + 1 > nVar; b_idx--) {
      nActiveConstr++;
      memspace->workspace_int.data[nActiveConstr - 1] =
          qrmanager->jpvt.data[b_idx];
    }
    maxDiag = muDoubleScalarAbs(qrmanager->QR->data[0]);
    if (b_idx < 1200) {
      for (idx = 0; idx < b_idx; idx++) {
        maxDiag = muDoubleScalarMax(
            maxDiag,
            muDoubleScalarAbs(
                qrmanager->QR->data[(qrmanager->ldq * (idx + 1) + idx) + 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      RemoveDependentIneq__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(RemoveDependentIneq__numThreads) private(     \
        maxDiagPrime, x)
      {
        maxDiagPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < b_idx; idx++) {
          x = qrmanager->QR->data[(qrmanager->ldq * (idx + 1) + idx) + 1];
          maxDiagPrime = muDoubleScalarMax(maxDiagPrime, muDoubleScalarAbs(x));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          maxDiag = muDoubleScalarMax(maxDiag, maxDiagPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (b_idx + 1 <= workingset->nVar) {
      idxDiag = b_idx + qrmanager->ldq * b_idx;
      while (
          (b_idx + 1 > nFixedConstr) &&
          (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol * maxDiag)) {
        nActiveConstr++;
        memspace->workspace_int.data[nActiveConstr - 1] =
            qrmanager->jpvt.data[b_idx];
        b_idx--;
        idxDiag = (idxDiag - qrmanager->ldq) - 1;
      }
    }
    countsort(aTLS, memspace->workspace_int.data, nActiveConstr,
              memspace->workspace_sort.data, nFixedConstr + 1,
              workingset->nActiveConstr);
    for (b_idx = nActiveConstr; b_idx >= 1; b_idx--) {
      removeConstr(workingset, memspace->workspace_int.data[b_idx - 1]);
    }
  }
}

void b_RemoveDependentIneq_(emlrtCTX aTLS, i_struct_T *workingset,
                            g_struct_T *qrmanager, f_struct_T *memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T maxDiag;
  real_T maxDiagPrime;
  real_T tol;
  real_T x;
  int32_T b_RemoveDependentIneq__numThreads;
  int32_T b_idx;
  int32_T idx;
  int32_T idxDiag;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    tol = 10.0 * muDoubleScalarMin(
                     1.4901161193847656E-8,
                     2.2204460492503131E-15 *
                         (real_T)muIntScalarMax_sint32(
                             workingset->nVar, workingset->nActiveConstr));
    if (nFixedConstr < 1200) {
      for (idx = 0; idx < nFixedConstr; idx++) {
        qrmanager->jpvt.data[idx] = 1;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_RemoveDependentIneq__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_RemoveDependentIneq__numThreads)

      for (idx = 0; idx < nFixedConstr; idx++) {
        qrmanager->jpvt.data[idx] = 1;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nActiveConstr) {
      memset(&qrmanager->jpvt.data[idxDiag + -1], 0,
             (uint32_T)((nActiveConstr - idxDiag) + 1) * sizeof(int32_T));
    }
    for (idxDiag = 0; idxDiag < nActiveConstr; idxDiag++) {
      n_t = (ptrdiff_t)nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idxDiag], &incx_t,
            &qrmanager->QR->data[qrmanager->ldq * idxDiag], &incy_t);
    }
    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(workingset->nVar, workingset->nActiveConstr);
      xgeqp3(aTLS, qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    nActiveConstr = 0;
    for (b_idx = workingset->nActiveConstr - 1; b_idx + 1 > nVar; b_idx--) {
      nActiveConstr++;
      memspace->workspace_int.data[nActiveConstr - 1] =
          qrmanager->jpvt.data[b_idx];
    }
    maxDiag = muDoubleScalarAbs(qrmanager->QR->data[0]);
    if (b_idx < 1200) {
      for (idx = 0; idx < b_idx; idx++) {
        maxDiag = muDoubleScalarMax(
            maxDiag,
            muDoubleScalarAbs(
                qrmanager->QR->data[(qrmanager->ldq * (idx + 1) + idx) + 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_RemoveDependentIneq__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_RemoveDependentIneq__numThreads) private(   \
        maxDiagPrime, x)
      {
        maxDiagPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < b_idx; idx++) {
          x = qrmanager->QR->data[(qrmanager->ldq * (idx + 1) + idx) + 1];
          maxDiagPrime = muDoubleScalarMax(maxDiagPrime, muDoubleScalarAbs(x));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          maxDiag = muDoubleScalarMax(maxDiag, maxDiagPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (b_idx + 1 <= workingset->nVar) {
      idxDiag = b_idx + qrmanager->ldq * b_idx;
      while (
          (b_idx + 1 > nFixedConstr) &&
          (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol * maxDiag)) {
        nActiveConstr++;
        memspace->workspace_int.data[nActiveConstr - 1] =
            qrmanager->jpvt.data[b_idx];
        b_idx--;
        idxDiag = (idxDiag - qrmanager->ldq) - 1;
      }
    }
    countsort(aTLS, memspace->workspace_int.data, nActiveConstr,
              memspace->workspace_sort.data, nFixedConstr + 1,
              workingset->nActiveConstr);
    for (b_idx = nActiveConstr; b_idx >= 1; b_idx--) {
      removeConstr(workingset, memspace->workspace_int.data[b_idx - 1]);
    }
  }
}

/* End of code generation (RemoveDependentIneq_.c) */
