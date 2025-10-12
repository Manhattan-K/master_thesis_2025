/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "RemoveDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "evaluateObstacles_mex_types.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void PresolveWorkingSet(j_struct_T *solution, e_struct_T *memspace,
                        k_struct_T *workingset, f_struct_T *qrmanager)
{
  int32_T idxStartIneq_tmp;
  int32_T idx_global;
  solution->state = 82;
  idxStartIneq_tmp = RemoveDependentEq_(memspace, workingset, qrmanager);
  if ((idxStartIneq_tmp != -1) &&
      (workingset->nActiveConstr <= qrmanager->ldq)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace->workspace_float, solution->xstar.data, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      b_RemoveDependentIneq_(workingset, qrmanager, memspace);
      okWorkingSet =
          feasibleX0ForWorkingSet(memspace->workspace_float,
                                  solution->xstar.data, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      real_T constrViolation;
      constrViolation =
          d_maxConstraintViolation(workingset, solution->xstar.data);
      if (constrViolation > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    int32_T idxEndIneq;
    int32_T idxStartIneq;
    solution->state = -3;
    idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    idxStartIneq = idxStartIneq_tmp + 1;
    idxEndIneq = workingset->nActiveConstr;
    for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
      workingset->isActiveConstr.data
          [(workingset->isActiveIdx[workingset->Wid.data[idx_global - 1] - 1] +
            workingset->Wlocalidx.data[idx_global - 1]) -
           2] = false;
    }
    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = idxStartIneq_tmp;
  }
}

/* End of code generation (PresolveWorkingSet.c) */
