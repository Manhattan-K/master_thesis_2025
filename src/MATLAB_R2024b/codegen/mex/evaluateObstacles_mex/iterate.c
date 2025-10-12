/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * iterate.c
 *
 * Code generation for function 'iterate'
 *
 */

/* Include files */
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "checkUnboundedOrIllPosed.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "strcmp.h"
#include "xaxpy.h"
#include "xnrm2.h"
#include <string.h>

/* Function Definitions */
void b_iterate(const real_T H[1600], const real_T f_data[],
               j_struct_T *solution, e_struct_T *memspace,
               k_struct_T *workingset, f_struct_T *qrmanager,
               n_struct_T *cholmanager, d_struct_T *objective,
               const char_T options_SolverName[7],
               int32_T runTimeOptions_MaxIterations)
{
  emxArray_real_T *y;
  real_T *y_data;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T iAineq0;
  int32_T idx;
  int32_T k;
  int32_T nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  nVar_tmp = workingset->nVar;
  globalActiveConstrIdx = 0;
  computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float,
                                        f_data, solution->xstar.data);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  iAineq0 = workingset->mConstrMax;
  for (k = 0; k < iAineq0; k++) {
    solution->lambda->data[k] = 0.0;
  }
  emxInit_real_T(&y, 1);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T minLambda;
      int32_T iAw0;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          squareQ_appendCol(qrmanager, workingset->ATwset,
                            workingset->ldA * (workingset->nActiveConstr - 1) +
                                1);
          break;
        case -1:
          deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          factorQR(qrmanager, workingset->ATwset, nVar_tmp,
                   workingset->nActiveConstr, workingset->ldA);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective,
                       b_strcmp(options_SolverName));
        if (solution->state != -5) {
          exitg1 = 1;
        } else if ((xnrm2(nVar_tmp, solution->searchDir.data) < 1.0E-6) ||
                   (workingset->nActiveConstr >= nVar_tmp)) {
          guard1 = true;
        } else {
          minLambda = feasibleratiotest(
              solution->xstar.data, solution->searchDir.data,
              memspace->workspace_float, workingset->nVar, workingset->ldA,
              workingset->Aineq, workingset->bineq.data, workingset->lb.data,
              workingset->ub.data, workingset->indexLB.data,
              workingset->indexUB.data, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr.data,
              workingset->nWConstr, TYPE == 5, &updateFval, &i, &k);
          if (updateFval) {
            switch (i) {
            case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr
                  .data[(workingset->isActiveIdx[2] + k) - 2] = true;
              workingset->nActiveConstr++;
              i = workingset->nActiveConstr - 1;
              workingset->Wid.data[i] = 3;
              workingset->Wlocalidx.data[i] = k;
              iAineq0 = workingset->ldA * (k - 1);
              iAw0 = workingset->ldA * i;
              i = workingset->nVar;
              for (idx = 0; idx < i; idx++) {
                workingset->ATwset->data[iAw0 + idx] =
                    workingset->Aineq->data[iAineq0 + idx];
              }
              workingset->bwset->data[workingset->nActiveConstr - 1] =
                  workingset->bineq.data[k - 1];
              break;
            case 4:
              addBoundToActiveSetMatrix_(workingset, 4, k);
              break;
            default:
              addBoundToActiveSetMatrix_(workingset, 5, k);
              break;
            }
            activeSetChangeID = 1;
          } else {
            checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }
          xaxpy(nVar_tmp, minLambda, solution->searchDir.data,
                solution->xstar.data);
          computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
          updateFval = true;
          b_checkStoppingAndUpdateFval(
              &activeSetChangeID, solution, memspace, objective, workingset,
              qrmanager, runTimeOptions_MaxIterations, &updateFval);
        }
      } else {
        iAw0 = solution->searchDir.size[0];
        i = y->size[0];
        y->size[0] = iAw0;
        emxEnsureCapacity_real_T(y, i);
        y_data = y->data;
        iAineq0 = solution->searchDir.size[0];
        for (i = 0; i < iAineq0; i++) {
          y_data[i] = solution->searchDir.data[i];
        }
        for (k = 0; k < nVar_tmp; k++) {
          y_data[k] = 0.0;
        }
        for (i = 0; i < iAw0; i++) {
          solution->searchDir.data[i] = y_data[i];
        }
        guard1 = true;
      }
      if (guard1) {
        compute_lambda(memspace->workspace_float, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar_tmp)) {
          iAineq0 = 0;
          minLambda = 0.0;
          i = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          iAw0 = workingset->nActiveConstr;
          for (idx = i; idx <= iAw0; idx++) {
            real_T d;
            d = solution->lambda->data[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              iAineq0 = idx;
            }
          }
          if (iAineq0 == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = iAineq0;
            subProblemChanged = true;
            removeConstr(workingset, iAineq0);
            if (iAineq0 < workingset->nActiveConstr + 1) {
              solution->lambda->data[iAineq0 - 1] =
                  solution->lambda->data[workingset->nActiveConstr];
            }
            solution->lambda->data[workingset->nActiveConstr] = 0.0;
          }
        } else {
          iAineq0 = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          removeConstr(workingset, workingset->nActiveConstr);
          solution->lambda->data[iAineq0 - 1] = 0.0;
        }
        updateFval = false;
        b_checkStoppingAndUpdateFval(&activeSetChangeID, solution, memspace,
                                     objective, workingset, qrmanager,
                                     runTimeOptions_MaxIterations, &updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(
            objective, memspace->workspace_float, f_data, solution->xstar.data);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void iterate(const real_T H[1600], const real_T f_data[], j_struct_T *solution,
             e_struct_T *memspace, k_struct_T *workingset,
             f_struct_T *qrmanager, n_struct_T *cholmanager,
             d_struct_T *objective, const char_T options_SolverName[7],
             int32_T runTimeOptions_MaxIterations)
{
  emxArray_real_T *y;
  real_T *y_data;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx;
  int32_T idx_local;
  int32_T nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  nVar_tmp = workingset->nVar;
  globalActiveConstrIdx = 0;
  computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float,
                                        f_data, solution->xstar.data);
  if (runTimeOptions_MaxIterations > 0) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  iAineq0 = workingset->mConstrMax;
  for (iAw0 = 0; iAw0 < iAineq0; iAw0++) {
    solution->lambda->data[iAw0] = 0.0;
  }
  emxInit_real_T(&y, 1);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T minLambda;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          squareQ_appendCol(qrmanager, workingset->ATwset,
                            workingset->ldA * (workingset->nActiveConstr - 1) +
                                1);
          break;
        case -1:
          deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          factorQR(qrmanager, workingset->ATwset, nVar_tmp,
                   workingset->nActiveConstr, workingset->ldA);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective,
                       b_strcmp(options_SolverName));
        if (solution->state != -5) {
          exitg1 = 1;
        } else if ((xnrm2(nVar_tmp, solution->searchDir.data) <
                    1.4901161193847657E-10) ||
                   (workingset->nActiveConstr >= nVar_tmp)) {
          guard1 = true;
        } else {
          minLambda = feasibleratiotest(
              solution->xstar.data, solution->searchDir.data,
              memspace->workspace_float, workingset->nVar, workingset->ldA,
              workingset->Aineq, workingset->bineq.data, workingset->lb.data,
              workingset->ub.data, workingset->indexLB.data,
              workingset->indexUB.data, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr.data,
              workingset->nWConstr, true, &updateFval, &i, &idx_local);
          if (updateFval) {
            switch (i) {
            case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr
                  .data[(workingset->isActiveIdx[2] + idx_local) - 2] = true;
              workingset->nActiveConstr++;
              i = workingset->nActiveConstr - 1;
              workingset->Wid.data[i] = 3;
              workingset->Wlocalidx.data[i] = idx_local;
              iAineq0 = workingset->ldA * (idx_local - 1);
              iAw0 = workingset->ldA * i;
              i = workingset->nVar;
              for (idx = 0; idx < i; idx++) {
                workingset->ATwset->data[iAw0 + idx] =
                    workingset->Aineq->data[iAineq0 + idx];
              }
              workingset->bwset->data[workingset->nActiveConstr - 1] =
                  workingset->bineq.data[idx_local - 1];
              break;
            case 4:
              addBoundToActiveSetMatrix_(workingset, 4, idx_local);
              break;
            default:
              addBoundToActiveSetMatrix_(workingset, 5, idx_local);
              break;
            }
            activeSetChangeID = 1;
          } else {
            checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }
          xaxpy(nVar_tmp, minLambda, solution->searchDir.data,
                solution->xstar.data);
          computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
          updateFval = true;
          checkStoppingAndUpdateFval(&activeSetChangeID, f_data, solution,
                                     memspace, objective, workingset, qrmanager,
                                     runTimeOptions_MaxIterations, &updateFval);
        }
      } else {
        iAineq0 = solution->searchDir.size[0];
        i = y->size[0];
        y->size[0] = iAineq0;
        emxEnsureCapacity_real_T(y, i);
        y_data = y->data;
        for (i = 0; i < iAineq0; i++) {
          y_data[i] = solution->searchDir.data[i];
        }
        for (iAw0 = 0; iAw0 < nVar_tmp; iAw0++) {
          y_data[iAw0] = 0.0;
        }
        for (i = 0; i < iAineq0; i++) {
          solution->searchDir.data[i] = y_data[i];
        }
        guard1 = true;
      }
      if (guard1) {
        compute_lambda(memspace->workspace_float, solution, objective,
                       qrmanager);
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar_tmp)) {
          iAineq0 = 0;
          minLambda = 0.0;
          i = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          iAw0 = workingset->nActiveConstr;
          for (idx = i; idx <= iAw0; idx++) {
            real_T d;
            d = solution->lambda->data[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              iAineq0 = idx;
            }
          }
          if (iAineq0 == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = iAineq0;
            subProblemChanged = true;
            removeConstr(workingset, iAineq0);
            if (iAineq0 < workingset->nActiveConstr + 1) {
              solution->lambda->data[iAineq0 - 1] =
                  solution->lambda->data[workingset->nActiveConstr];
            }
            solution->lambda->data[workingset->nActiveConstr] = 0.0;
          }
        } else {
          iAineq0 = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          removeConstr(workingset, workingset->nActiveConstr);
          solution->lambda->data[iAineq0 - 1] = 0.0;
        }
        updateFval = false;
        checkStoppingAndUpdateFval(&activeSetChangeID, f_data, solution,
                                   memspace, objective, workingset, qrmanager,
                                   runTimeOptions_MaxIterations, &updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(
            objective, memspace->workspace_float, f_data, solution->xstar.data);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (iterate.c) */
