/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkStoppingAndUpdateFval.c
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
 *
 */

/* Include files */
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Function Definitions */
void b_checkStoppingAndUpdateFval(int32_T *activeSetChangeID,
                                  j_struct_T *solution, e_struct_T *memspace,
                                  const d_struct_T *objective,
                                  k_struct_T *workingset, f_struct_T *qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T *updateFval)
{
  emxArray_real_T b_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T i;
  int32_T loop_ub;
  int32_T nVar;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution->iterations++;
  nVar = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }
  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    tempMaxConstr = d_maxConstraintViolation(workingset, solution->xstar.data);
    solution->maxConstr = tempMaxConstr;
    if (objective->objtype == 5) {
      tempMaxConstr =
          solution->maxConstr - solution->xstar.data[objective->nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      boolean_T nonDegenerateWset;
      emxInit_real_T(&r, 1);
      loop_ub = solution->searchDir.size[0];
      i = r->size[0];
      r->size[0] = loop_ub;
      emxEnsureCapacity_real_T(r, i);
      r1 = r->data;
      for (i = 0; i < loop_ub; i++) {
        r1[i] = solution->searchDir.data[i];
      }
      b_solution.data = &solution->xstar.data[0];
      b_solution.size = &solution->xstar.size[0];
      b_solution.allocatedSize = 4241;
      b_solution.numDimensions = 1;
      b_solution.canFreeData = false;
      xcopy(objective->nvar, &b_solution, r);
      r1 = r->data;
      loop_ub = r->size[0];
      solution->searchDir.size[0] = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        solution->searchDir.data[i] = r1[i];
      }
      emxFree_real_T(&r);
      nonDegenerateWset = feasibleX0ForWorkingSet(memspace->workspace_float,
                                                  solution->searchDir.data,
                                                  workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      tempMaxConstr =
          d_maxConstraintViolation(workingset, solution->searchDir.data);
      if (tempMaxConstr < solution->maxConstr) {
        for (loop_ub = 0; loop_ub < nVar; loop_ub++) {
          solution->xstar.data[loop_ub] = solution->searchDir.data[loop_ub];
        }
        solution->maxConstr = tempMaxConstr;
      }
    }
  }
  if (*updateFval) {
    *updateFval = false;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void checkStoppingAndUpdateFval(int32_T *activeSetChangeID,
                                const real_T f_data[], j_struct_T *solution,
                                e_struct_T *memspace,
                                const d_struct_T *objective,
                                k_struct_T *workingset, f_struct_T *qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T *updateFval)
{
  emxArray_real_T b_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T i;
  int32_T loop_ub;
  int32_T nVar;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution->iterations++;
  nVar = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }
  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    solution->maxConstr =
        d_maxConstraintViolation(workingset, solution->xstar.data);
    tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      tempMaxConstr =
          solution->maxConstr - solution->xstar.data[objective->nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      boolean_T nonDegenerateWset;
      emxInit_real_T(&r, 1);
      i = r->size[0];
      r->size[0] = solution->searchDir.size[0];
      emxEnsureCapacity_real_T(r, i);
      r1 = r->data;
      loop_ub = solution->searchDir.size[0];
      for (i = 0; i < loop_ub; i++) {
        r1[i] = solution->searchDir.data[i];
      }
      b_solution.data = &solution->xstar.data[0];
      b_solution.size = &solution->xstar.size[0];
      b_solution.allocatedSize = 4241;
      b_solution.numDimensions = 1;
      b_solution.canFreeData = false;
      xcopy(objective->nvar, &b_solution, r);
      r1 = r->data;
      loop_ub = r->size[0];
      solution->searchDir.size[0] = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        solution->searchDir.data[i] = r1[i];
      }
      emxFree_real_T(&r);
      nonDegenerateWset = feasibleX0ForWorkingSet(memspace->workspace_float,
                                                  solution->searchDir.data,
                                                  workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      tempMaxConstr =
          d_maxConstraintViolation(workingset, solution->searchDir.data);
      if (tempMaxConstr < solution->maxConstr) {
        for (loop_ub = 0; loop_ub < nVar; loop_ub++) {
          solution->xstar.data[loop_ub] = solution->searchDir.data[loop_ub];
        }
        solution->maxConstr = tempMaxConstr;
      }
    }
  }
  if (*updateFval) {
    solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float,
                                          f_data, solution->xstar.data);
    if ((solution->fstar < 1.0E-6) &&
        ((solution->state != 0) || (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (checkStoppingAndUpdateFval.c) */
