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
#include "evaluateObstacles_mex_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void RemoveDependentIneq_(k_struct_T *workingset, f_struct_T *qrmanager,
                          e_struct_T *memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idx;
  int32_T idxDiag;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nDepIneq = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    real_T maxDiag;
    real_T tol;
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 *
                              (real_T)muIntScalarMax_sint32(
                                  workingset->nVar, workingset->nActiveConstr));
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager->jpvt.data[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nDepIneq) {
      memset(&qrmanager->jpvt.data[idxDiag + -1], 0,
             (uint32_T)((nDepIneq - idxDiag) + 1) * sizeof(int32_T));
    }
    for (idxDiag = 0; idxDiag < nDepIneq; idxDiag++) {
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
      xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr - 1; idx + 1 > nVar; idx--) {
      nDepIneq++;
      memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx];
    }
    maxDiag = muDoubleScalarAbs(qrmanager->QR->data[0]);
    for (idxDiag = 0; idxDiag < idx; idxDiag++) {
      maxDiag = muDoubleScalarMax(
          maxDiag,
          muDoubleScalarAbs(
              qrmanager->QR
                  ->data[(qrmanager->ldq * (idxDiag + 1) + idxDiag) + 1]));
    }
    if (idx + 1 <= workingset->nVar) {
      idxDiag = idx + qrmanager->ldq * idx;
      while (
          (idx + 1 > nFixedConstr) &&
          (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol * maxDiag)) {
        nDepIneq++;
        memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx];
        idx--;
        idxDiag = (idxDiag - qrmanager->ldq) - 1;
      }
    }
    countsort(memspace->workspace_int.data, nDepIneq,
              memspace->workspace_sort.data, nFixedConstr + 1,
              workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      removeConstr(workingset, memspace->workspace_int.data[idx - 1]);
    }
  }
}

void b_RemoveDependentIneq_(k_struct_T *workingset, f_struct_T *qrmanager,
                            e_struct_T *memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idx;
  int32_T idxDiag;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nDepIneq = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
          workingset->nWConstr[4] >
      0) {
    real_T maxDiag;
    real_T tol;
    tol = 10.0 * muDoubleScalarMin(
                     1.4901161193847656E-8,
                     2.2204460492503131E-15 *
                         (real_T)muIntScalarMax_sint32(
                             workingset->nVar, workingset->nActiveConstr));
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager->jpvt.data[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nDepIneq) {
      memset(&qrmanager->jpvt.data[idxDiag + -1], 0,
             (uint32_T)((nDepIneq - idxDiag) + 1) * sizeof(int32_T));
    }
    for (idxDiag = 0; idxDiag < nDepIneq; idxDiag++) {
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
      xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
             qrmanager->jpvt.data, &qrmanager->jpvt.size[0], qrmanager->tau);
    }
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr - 1; idx + 1 > nVar; idx--) {
      nDepIneq++;
      memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx];
    }
    maxDiag = muDoubleScalarAbs(qrmanager->QR->data[0]);
    for (idxDiag = 0; idxDiag < idx; idxDiag++) {
      maxDiag = muDoubleScalarMax(
          maxDiag,
          muDoubleScalarAbs(
              qrmanager->QR
                  ->data[(qrmanager->ldq * (idxDiag + 1) + idxDiag) + 1]));
    }
    if (idx + 1 <= workingset->nVar) {
      idxDiag = idx + qrmanager->ldq * idx;
      while (
          (idx + 1 > nFixedConstr) &&
          (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol * maxDiag)) {
        nDepIneq++;
        memspace->workspace_int.data[nDepIneq - 1] = qrmanager->jpvt.data[idx];
        idx--;
        idxDiag = (idxDiag - qrmanager->ldq) - 1;
      }
    }
    countsort(memspace->workspace_int.data, nDepIneq,
              memspace->workspace_sort.data, nFixedConstr + 1,
              workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      removeConstr(workingset, memspace->workspace_int.data[idx - 1]);
    }
  }
}

/* End of code generation (RemoveDependentIneq_.c) */
