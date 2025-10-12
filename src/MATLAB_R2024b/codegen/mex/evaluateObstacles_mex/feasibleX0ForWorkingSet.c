/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * feasibleX0ForWorkingSet.c
 *
 * Code generation for function 'feasibleX0ForWorkingSet'
 *
 */

/* Include files */
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "factorQRE.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xcopy.h"
#include "xdot.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "xtrsm.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T feasibleX0ForWorkingSet(emxArray_real_T *workspace,
                                  real_T xCurrent_data[],
                                  k_struct_T *workingset, f_struct_T *qrmanager)
{
  emxArray_real_T *b_workspace;
  real_T *b_workspace_data;
  real_T *workspace_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T mWConstr;
  int32_T minmn;
  int32_T nVar;
  int32_T rankQR;
  boolean_T nonDegenerateWset;
  workspace_data = workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  emxInit_real_T(&b_workspace, 2);
  if (mWConstr != 0) {
    real_T tol;
    if (mWConstr >= nVar) {
      i = (uint16_T)nVar;
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        minmn = qrmanager->ldq * loop_ub;
        for (rankQR = 0; rankQR < mWConstr; rankQR++) {
          qrmanager->QR->data[rankQR + minmn] =
              workingset->ATwset->data[loop_ub + workingset->ldA * rankQR];
        }
        qrmanager->jpvt.data[loop_ub] = 0;
      }
      if (mWConstr * nVar == 0) {
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = mWConstr;
        qrmanager->ncols = nVar;
        qrmanager->minRowCol = muIntScalarMin_sint32(mWConstr, nVar);
        xgeqp3(qrmanager->QR, mWConstr, nVar, qrmanager->jpvt.data,
               &qrmanager->jpvt.size[0], qrmanager->tau);
      }
      computeQ_(qrmanager, qrmanager->mrows);
      rankQR = 0;
      minmn = muIntScalarMin_sint32(qrmanager->mrows, qrmanager->ncols);
      if (minmn > 0) {
        tol = muDoubleScalarMin(1.4901161193847656E-8,
                                2.2204460492503131E-15 *
                                    (real_T)muIntScalarMax_sint32(
                                        qrmanager->mrows, qrmanager->ncols)) *
              muDoubleScalarAbs(qrmanager->QR->data[0]);
        while ((rankQR < minmn) &&
               (!(muDoubleScalarAbs(
                      qrmanager->QR->data[rankQR + qrmanager->QR->size[0] *
                                                       rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        tol = workingset->bwset->data[minmn];
        workspace_data[minmn] = tol;
        workspace_data[minmn + workspace->size[0]] = tol;
      }
      xgemv(nVar, mWConstr, workingset->ATwset, workingset->ldA, xCurrent_data,
            workspace);
      workspace_data = workspace->data;
      i1 = b_workspace->size[0] * b_workspace->size[1];
      b_workspace->size[0] = workspace->size[0];
      b_workspace->size[1] = workspace->size[1];
      emxEnsureCapacity_real_T(b_workspace, i1);
      b_workspace_data = b_workspace->data;
      loop_ub = workspace->size[0] * workspace->size[1] - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        b_workspace_data[i1] = workspace_data[i1];
      }
      xgemm(nVar, mWConstr, qrmanager->Q, qrmanager->ldq, b_workspace,
            workspace->size[0], workspace, workspace->size[0]);
      xtrsm(rankQR, qrmanager->QR, qrmanager->ldq, workspace,
            workspace->size[0]);
      workspace_data = workspace->data;
      i1 = rankQR + 1;
      for (minmn = i1; minmn <= nVar; minmn++) {
        workspace_data[minmn - 1] = 0.0;
        workspace_data[(minmn + workspace->size[0]) - 1] = 0.0;
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace_data[(qrmanager->jpvt.data[minmn] + workspace->size[0] * 2) -
                       1] = workspace_data[minmn];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace_data[minmn] = workspace_data[minmn + workspace->size[0] * 2];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace_data[(qrmanager->jpvt.data[minmn] + workspace->size[0] * 2) -
                       1] = workspace_data[minmn + workspace->size[0]];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace_data[minmn + workspace->size[0]] =
            workspace_data[minmn + workspace->size[0] * 2];
      }
    } else {
      if (mWConstr - 1 >= 0) {
        memset(&qrmanager->jpvt.data[0], 0,
               (uint32_T)mWConstr * sizeof(int32_T));
      }
      factorQRE(qrmanager, workingset->ATwset, nVar, mWConstr, workingset->ldA);
      computeQ_(qrmanager, qrmanager->minRowCol);
      rankQR = 0;
      minmn = muIntScalarMin_sint32(qrmanager->mrows, qrmanager->ncols);
      if (minmn > 0) {
        tol = muDoubleScalarMin(1.4901161193847656E-8,
                                2.2204460492503131E-15 *
                                    (real_T)muIntScalarMax_sint32(
                                        qrmanager->mrows, qrmanager->ncols)) *
              muDoubleScalarAbs(qrmanager->QR->data[0]);
        while ((rankQR < minmn) &&
               (!(muDoubleScalarAbs(
                      qrmanager->QR->data[rankQR + qrmanager->QR->size[0] *
                                                       rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        workspace_data[minmn] =
            workingset->bwset->data[qrmanager->jpvt.data[minmn] - 1] -
            xdot(nVar, workingset->ATwset,
                 (qrmanager->jpvt.data[minmn] - 1) * workingset->ldA + 1,
                 xCurrent_data);
        workspace_data[minmn + workspace->size[0]] =
            workingset->bwset->data[qrmanager->jpvt.data[minmn] - 1];
      }
      minmn = workspace->size[0];
      b_xtrsm(rankQR, qrmanager->QR, qrmanager->ldq, workspace,
              workspace->size[0]);
      workspace_data = workspace->data;
      i = b_workspace->size[0] * b_workspace->size[1];
      b_workspace->size[0] = workspace->size[0];
      b_workspace->size[1] = workspace->size[1];
      emxEnsureCapacity_real_T(b_workspace, i);
      b_workspace_data = b_workspace->data;
      loop_ub = workspace->size[0] * workspace->size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_workspace_data[i] = workspace_data[i];
      }
      b_xgemm(nVar, rankQR, qrmanager->Q, qrmanager->ldq, b_workspace, minmn,
              workspace, minmn);
      workspace_data = workspace->data;
    }
    minmn = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (minmn <= (uint16_T)nVar - 1) {
        tol = workspace_data[minmn];
        if (muDoubleScalarIsInf(tol) || muDoubleScalarIsNaN(tol)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          tol = workspace_data[minmn + workspace->size[0]];
          if (muDoubleScalarIsInf(tol) || muDoubleScalarIsNaN(tol)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            minmn++;
          }
        }
      } else {
        real_T constrViolation_basicX;
        b_xaxpy(nVar, xCurrent_data, workspace);
        tol = b_maxConstraintViolation(workingset, workspace);
        constrViolation_basicX = c_maxConstraintViolation(
            workingset, workspace, workspace->size[0] + 1);
        if ((tol <= 2.2204460492503131E-16) || (tol < constrViolation_basicX)) {
          b_xcopy(nVar, workspace, xCurrent_data);
        } else {
          c_xcopy(nVar, workspace, workspace->size[0] + 1, xCurrent_data);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emxFree_real_T(&b_workspace);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return nonDegenerateWset;
}

/* End of code generation (feasibleX0ForWorkingSet.c) */
