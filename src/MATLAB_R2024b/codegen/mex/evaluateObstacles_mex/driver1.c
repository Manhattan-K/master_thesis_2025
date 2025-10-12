/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include <string.h>

/* Function Definitions */
void b_driver(const real_T H[1600], const real_T f_data[], j_struct_T *solution,
              e_struct_T *memspace, k_struct_T *workingset,
              f_struct_T *qrmanager, n_struct_T *cholmanager,
              d_struct_T *objective, const o_struct_T *options,
              const o_struct_T *runTimeOptions)
{
  emxArray_real_T b_solution;
  emxArray_real_T c_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T i;
  int32_T idx;
  int32_T nVar;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution->iterations = 0;
  nVar = workingset->nVar;
  emxInit_real_T(&r, 1);
  guard1 = false;
  if (workingset->probType == 3) {
    i = (uint16_T)workingset->sizes[0];
    for (idx = 0; idx < i; idx++) {
      solution->xstar.data[workingset->indexFixed.data[idx] - 1] =
          workingset->ub.data[workingset->indexFixed.data[idx] - 1];
    }
    i = (uint16_T)workingset->sizes[3];
    for (idx = 0; idx < i; idx++) {
      if (workingset->isActiveConstr
              .data[(workingset->isActiveIdx[3] + idx) - 1]) {
        solution->xstar.data[workingset->indexLB.data[idx] - 1] =
            -workingset->lb.data[workingset->indexLB.data[idx] - 1];
      }
    }
    i = (uint16_T)workingset->sizes[4];
    for (idx = 0; idx < i; idx++) {
      if (workingset->isActiveConstr
              .data[(workingset->isActiveIdx[4] + idx) - 1]) {
        solution->xstar.data[workingset->indexUB.data[idx] - 1] =
            workingset->ub.data[workingset->indexUB.data[idx] - 1];
      }
    }
    PresolveWorkingSet(solution, memspace, workingset, qrmanager);
    if (solution->state >= 0) {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }
  if (guard1) {
    solution->iterations = 0;
    solution->maxConstr =
        d_maxConstraintViolation(workingset, solution->xstar.data);
    if (solution->maxConstr > 1.0E-6) {
      phaseone(H, f_data, solution, memspace, workingset, qrmanager,
               cholmanager, objective, options->SolverName, runTimeOptions);
      if (solution->state != 0) {
        solution->maxConstr =
            d_maxConstraintViolation(workingset, solution->xstar.data);
        if (solution->maxConstr > 1.0E-6) {
          idx = workingset->mConstrMax;
          for (nVar = 0; nVar < idx; nVar++) {
            solution->lambda->data[nVar] = 0.0;
          }
          solution->fstar = computeFval(objective, memspace->workspace_float, H,
                                        f_data, solution->xstar.data);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            real_T maxConstr_new;
            i = r->size[0];
            r->size[0] = solution->searchDir.size[0];
            emxEnsureCapacity_real_T(r, i);
            r1 = r->data;
            idx = solution->searchDir.size[0];
            for (i = 0; i < idx; i++) {
              r1[i] = solution->searchDir.data[i];
            }
            b_solution.data = &solution->xstar.data[0];
            b_solution.size = &solution->xstar.size[0];
            b_solution.allocatedSize = 4241;
            b_solution.numDimensions = 1;
            b_solution.canFreeData = false;
            xcopy(nVar, &b_solution, r);
            r1 = r->data;
            idx = r->size[0];
            solution->searchDir.size[0] = r->size[0];
            for (i = 0; i < idx; i++) {
              solution->searchDir.data[i] = r1[i];
            }
            PresolveWorkingSet(solution, memspace, workingset, qrmanager);
            maxConstr_new =
                d_maxConstraintViolation(workingset, solution->xstar.data);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              i = r->size[0];
              r->size[0] = solution->xstar.size[0];
              emxEnsureCapacity_real_T(r, i);
              r1 = r->data;
              idx = solution->xstar.size[0];
              for (i = 0; i < idx; i++) {
                r1[i] = solution->xstar.data[i];
              }
              c_solution.data = &solution->searchDir.data[0];
              c_solution.size = &solution->searchDir.size[0];
              c_solution.allocatedSize = 4241;
              c_solution.numDimensions = 1;
              c_solution.canFreeData = false;
              xcopy(nVar, &c_solution, r);
              r1 = r->data;
              idx = r->size[0];
              solution->xstar.size[0] = r->size[0];
              for (i = 0; i < idx; i++) {
                solution->xstar.data[i] = r1[i];
              }
            }
          }
          b_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                    cholmanager, objective, options->SolverName,
                    runTimeOptions->MaxIterations);
        }
      }
    } else {
      b_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                cholmanager, objective, options->SolverName,
                runTimeOptions->MaxIterations);
    }
  }
  emxFree_real_T(&r);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (driver1.c) */
