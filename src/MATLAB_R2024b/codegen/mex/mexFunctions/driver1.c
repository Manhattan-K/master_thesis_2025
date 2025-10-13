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
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void b_driver(emlrtCTX aTLS, const real_T H[1600], const real_T f_data[],
              h_struct_T *solution, f_struct_T *memspace,
              i_struct_T *workingset, g_struct_T *qrmanager,
              m_struct_T *cholmanager, e_struct_T *objective,
              const n_struct_T *options, const n_struct_T *runTimeOptions)
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T b_solution;
  emxArray_real_T c_solution;
  emxArray_real_T *r;
  real_T *r1;
  int32_T b_driver_numThreads;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T nVar;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  solution->iterations = 0;
  nVar = workingset->nVar;
  emxInit_real_T(&r, 1);
  guard1 = false;
  if (workingset->probType == 3) {
    loop_ub = (uint16_T)workingset->sizes[0];
    for (idx = 0; idx < loop_ub; idx++) {
      solution->xstar.data[workingset->indexFixed.data[idx] - 1] =
          workingset->ub.data[workingset->indexFixed.data[idx] - 1];
    }
    loop_ub = (uint16_T)workingset->sizes[3];
    for (idx = 0; idx < loop_ub; idx++) {
      if (workingset->isActiveConstr
              .data[(workingset->isActiveIdx[3] + idx) - 1]) {
        solution->xstar.data[workingset->indexLB.data[idx] - 1] =
            -workingset->lb.data[workingset->indexLB.data[idx] - 1];
      }
    }
    loop_ub = (uint16_T)workingset->sizes[4];
    for (idx = 0; idx < loop_ub; idx++) {
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
        d_maxConstraintViolation(aTLS, workingset, solution->xstar.data);
    if (solution->maxConstr > 1.0E-6) {
      phaseone(H, f_data, solution, memspace, workingset, qrmanager,
               cholmanager, objective, options->SolverName, runTimeOptions);
      if (solution->state != 0) {
        solution->maxConstr =
            d_maxConstraintViolation(aTLS, workingset, solution->xstar.data);
        if (solution->maxConstr > 1.0E-6) {
          loop_ub = workingset->mConstrMax;
          for (idx = 0; idx < loop_ub; idx++) {
            solution->lambda->data[idx] = 0.0;
          }
          solution->fstar =
              computeFval(aTLS, objective, memspace->workspace_float, H, f_data,
                          solution->xstar.data);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            real_T maxConstr_new;
            loop_ub = r->size[0];
            r->size[0] = solution->searchDir.size[0];
            emxEnsureCapacity_real_T(r, loop_ub);
            r1 = r->data;
            loop_ub = solution->searchDir.size[0];
            if (loop_ub < 1200) {
              for (i = 0; i < loop_ub; i++) {
                r1[i] = solution->searchDir.data[i];
              }
            } else {
              emlrtEnterParallelRegion(aTLS, omp_in_parallel());
              emlrtPushJmpBuf(aTLS, &emlrtJBStack);
              b_driver_numThreads = emlrtAllocRegionTLSs(
                  aTLS, omp_in_parallel(), omp_get_max_threads(),
                  omp_get_num_procs());
#pragma omp parallel for num_threads(b_driver_numThreads)

              for (i = 0; i < loop_ub; i++) {
                r1[i] = solution->searchDir.data[i];
              }
              emlrtPopJmpBuf(aTLS, &emlrtJBStack);
              emlrtExitParallelRegion(aTLS, omp_in_parallel());
            }
            b_solution.data = &solution->xstar.data[0];
            b_solution.size = &solution->xstar.size[0];
            b_solution.allocatedSize = 4241;
            b_solution.numDimensions = 1;
            b_solution.canFreeData = false;
            xcopy(nVar, &b_solution, r);
            r1 = r->data;
            loop_ub = r->size[0];
            solution->searchDir.size[0] = r->size[0];
            idx = r->size[0];
            if (r->size[0] < 1200) {
              for (i = 0; i < loop_ub; i++) {
                solution->searchDir.data[i] = r1[i];
              }
            } else {
              emlrtEnterParallelRegion(aTLS, omp_in_parallel());
              emlrtPushJmpBuf(aTLS, &emlrtJBStack);
              b_driver_numThreads = emlrtAllocRegionTLSs(
                  aTLS, omp_in_parallel(), omp_get_max_threads(),
                  omp_get_num_procs());
#pragma omp parallel for num_threads(b_driver_numThreads)

              for (i = 0; i < idx; i++) {
                solution->searchDir.data[i] = r1[i];
              }
              emlrtPopJmpBuf(aTLS, &emlrtJBStack);
              emlrtExitParallelRegion(aTLS, omp_in_parallel());
            }
            PresolveWorkingSet(solution, memspace, workingset, qrmanager);
            maxConstr_new = d_maxConstraintViolation(aTLS, workingset,
                                                     solution->xstar.data);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              loop_ub = r->size[0];
              r->size[0] = solution->xstar.size[0];
              emxEnsureCapacity_real_T(r, loop_ub);
              r1 = r->data;
              loop_ub = solution->xstar.size[0];
              if (loop_ub < 1200) {
                for (i = 0; i < loop_ub; i++) {
                  r1[i] = solution->xstar.data[i];
                }
              } else {
                emlrtEnterParallelRegion(aTLS, omp_in_parallel());
                emlrtPushJmpBuf(aTLS, &emlrtJBStack);
                b_driver_numThreads = emlrtAllocRegionTLSs(
                    aTLS, omp_in_parallel(), omp_get_max_threads(),
                    omp_get_num_procs());
#pragma omp parallel for num_threads(b_driver_numThreads)

                for (i = 0; i < loop_ub; i++) {
                  r1[i] = solution->xstar.data[i];
                }
                emlrtPopJmpBuf(aTLS, &emlrtJBStack);
                emlrtExitParallelRegion(aTLS, omp_in_parallel());
              }
              c_solution.data = &solution->searchDir.data[0];
              c_solution.size = &solution->searchDir.size[0];
              c_solution.allocatedSize = 4241;
              c_solution.numDimensions = 1;
              c_solution.canFreeData = false;
              xcopy(nVar, &c_solution, r);
              r1 = r->data;
              loop_ub = r->size[0];
              solution->xstar.size[0] = r->size[0];
              idx = r->size[0];
              if (r->size[0] < 1200) {
                for (i = 0; i < loop_ub; i++) {
                  solution->xstar.data[i] = r1[i];
                }
              } else {
                emlrtEnterParallelRegion(aTLS, omp_in_parallel());
                emlrtPushJmpBuf(aTLS, &emlrtJBStack);
                b_driver_numThreads = emlrtAllocRegionTLSs(
                    aTLS, omp_in_parallel(), omp_get_max_threads(),
                    omp_get_num_procs());
#pragma omp parallel for num_threads(b_driver_numThreads)

                for (i = 0; i < idx; i++) {
                  solution->xstar.data[i] = r1[i];
                }
                emlrtPopJmpBuf(aTLS, &emlrtJBStack);
                emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (driver1.c) */
