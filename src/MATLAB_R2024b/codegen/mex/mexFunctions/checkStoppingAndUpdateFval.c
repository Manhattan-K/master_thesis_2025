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
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void b_checkStoppingAndUpdateFval(emlrtCTX aTLS, int32_T *activeSetChangeID,
                                  h_struct_T *solution, f_struct_T *memspace,
                                  const e_struct_T *objective,
                                  i_struct_T *workingset, g_struct_T *qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T *updateFval)
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T b_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T b_checkStoppingAndUpdateFval_numThreads;
  int32_T idx;
  int32_T nVar;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  solution->iterations++;
  nVar = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }
  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    tempMaxConstr =
        d_maxConstraintViolation(aTLS, workingset, solution->xstar.data);
    solution->maxConstr = tempMaxConstr;
    if (objective->objtype == 5) {
      tempMaxConstr =
          solution->maxConstr - solution->xstar.data[objective->nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      int32_T b_loop_ub;
      int32_T loop_ub;
      boolean_T nonDegenerateWset;
      emxInit_real_T(&r, 1);
      loop_ub = solution->searchDir.size[0];
      b_loop_ub = r->size[0];
      r->size[0] = loop_ub;
      emxEnsureCapacity_real_T(r, b_loop_ub);
      r1 = r->data;
      if (loop_ub < 1200) {
        for (idx = 0; idx < loop_ub; idx++) {
          r1[idx] = solution->searchDir.data[idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        b_checkStoppingAndUpdateFval_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(b_checkStoppingAndUpdateFval_numThreads)

        for (idx = 0; idx < loop_ub; idx++) {
          r1[idx] = solution->searchDir.data[idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
      b_loop_ub = r->size[0];
      if (r->size[0] < 1200) {
        for (idx = 0; idx < loop_ub; idx++) {
          solution->searchDir.data[idx] = r1[idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        b_checkStoppingAndUpdateFval_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(b_checkStoppingAndUpdateFval_numThreads)

        for (idx = 0; idx < b_loop_ub; idx++) {
          solution->searchDir.data[idx] = r1[idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      emxFree_real_T(&r);
      nonDegenerateWset = feasibleX0ForWorkingSet(
          aTLS, memspace->workspace_float, solution->searchDir.data, workingset,
          qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      tempMaxConstr =
          d_maxConstraintViolation(aTLS, workingset, solution->searchDir.data);
      if (tempMaxConstr < solution->maxConstr) {
        if (nVar < 1200) {
          for (idx = 0; idx < nVar; idx++) {
            solution->xstar.data[idx] = solution->searchDir.data[idx];
          }
        } else {
          emlrtEnterParallelRegion(aTLS, omp_in_parallel());
          emlrtPushJmpBuf(aTLS, &emlrtJBStack);
          b_checkStoppingAndUpdateFval_numThreads =
              emlrtAllocRegionTLSs(aTLS, omp_in_parallel(),
                                   omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_checkStoppingAndUpdateFval_numThreads)

          for (idx = 0; idx < nVar; idx++) {
            solution->xstar.data[idx] = solution->searchDir.data[idx];
          }
          emlrtPopJmpBuf(aTLS, &emlrtJBStack);
          emlrtExitParallelRegion(aTLS, omp_in_parallel());
        }
        solution->maxConstr = tempMaxConstr;
      }
    }
  }
  if (*updateFval) {
    *updateFval = false;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

void checkStoppingAndUpdateFval(emlrtCTX aTLS, int32_T *activeSetChangeID,
                                const real_T f_data[], h_struct_T *solution,
                                f_struct_T *memspace,
                                const e_struct_T *objective,
                                i_struct_T *workingset, g_struct_T *qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T *updateFval)
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T b_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T checkStoppingAndUpdateFval_numThreads;
  int32_T idx;
  int32_T nVar;
  int32_T objType;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  solution->iterations++;
  nVar = objective->nvar;
  objType = objective->objtype;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }
  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    solution->maxConstr =
        d_maxConstraintViolation(aTLS, workingset, solution->xstar.data);
    tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      tempMaxConstr =
          solution->maxConstr - solution->xstar.data[objective->nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      int32_T b_loop_ub;
      int32_T loop_ub;
      boolean_T nonDegenerateWset;
      emxInit_real_T(&r, 1);
      loop_ub = r->size[0];
      r->size[0] = solution->searchDir.size[0];
      emxEnsureCapacity_real_T(r, loop_ub);
      r1 = r->data;
      loop_ub = solution->searchDir.size[0];
      if (loop_ub < 1200) {
        for (idx = 0; idx < loop_ub; idx++) {
          r1[idx] = solution->searchDir.data[idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        checkStoppingAndUpdateFval_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(checkStoppingAndUpdateFval_numThreads)

        for (idx = 0; idx < loop_ub; idx++) {
          r1[idx] = solution->searchDir.data[idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
      b_loop_ub = r->size[0];
      if (r->size[0] < 1200) {
        for (idx = 0; idx < loop_ub; idx++) {
          solution->searchDir.data[idx] = r1[idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        checkStoppingAndUpdateFval_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(checkStoppingAndUpdateFval_numThreads)

        for (idx = 0; idx < b_loop_ub; idx++) {
          solution->searchDir.data[idx] = r1[idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      emxFree_real_T(&r);
      nonDegenerateWset = feasibleX0ForWorkingSet(
          aTLS, memspace->workspace_float, solution->searchDir.data, workingset,
          qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      tempMaxConstr =
          d_maxConstraintViolation(aTLS, workingset, solution->searchDir.data);
      if (tempMaxConstr < solution->maxConstr) {
        if (nVar < 1200) {
          for (idx = 0; idx < nVar; idx++) {
            solution->xstar.data[idx] = solution->searchDir.data[idx];
          }
        } else {
          emlrtEnterParallelRegion(aTLS, omp_in_parallel());
          emlrtPushJmpBuf(aTLS, &emlrtJBStack);
          checkStoppingAndUpdateFval_numThreads =
              emlrtAllocRegionTLSs(aTLS, omp_in_parallel(),
                                   omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(checkStoppingAndUpdateFval_numThreads)

          for (idx = 0; idx < nVar; idx++) {
            solution->xstar.data[idx] = solution->searchDir.data[idx];
          }
          emlrtPopJmpBuf(aTLS, &emlrtJBStack);
          emlrtExitParallelRegion(aTLS, omp_in_parallel());
        }
        solution->maxConstr = tempMaxConstr;
      }
    }
  }
  if (*updateFval) {
    solution->fstar =
        computeFval_ReuseHx(aTLS, objective, memspace->workspace_float, f_data,
                            solution->xstar.data);
    if ((solution->fstar < 1.0E-6) &&
        ((solution->state != 0) || (objType != 5))) {
      solution->state = 2;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (checkStoppingAndUpdateFval.c) */
