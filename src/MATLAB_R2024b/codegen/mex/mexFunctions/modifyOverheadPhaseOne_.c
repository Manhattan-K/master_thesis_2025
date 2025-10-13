/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modifyOverheadPhaseOne_.c
 *
 * Code generation for function 'modifyOverheadPhaseOne_'
 *
 */

/* Include files */
#include "modifyOverheadPhaseOne_.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void modifyOverheadPhaseOne_(i_struct_T *obj)
{
  int32_T i;
  int32_T idx;
  int32_T idxStartIneq;
  i = (uint16_T)obj->sizes[0];
  for (idx = 0; idx < i; idx++) {
    obj->ATwset->data[(obj->nVar + obj->ldA * idx) - 1] = 0.0;
  }
  i = (uint16_T)obj->sizes[2];
  for (idx = 0; idx < i; idx++) {
    obj->Aineq->data[(obj->nVar + obj->ldA * idx) - 1] = -1.0;
  }
  obj->indexLB.data[obj->sizes[3] - 1] = obj->nVar;
  obj->lb.data[obj->nVar - 1] = 1.0E-5;
  idxStartIneq = obj->isActiveIdx[2];
  i = obj->nActiveConstr;
  for (idx = idxStartIneq; idx <= i; idx++) {
    obj->ATwset->data[(obj->nVar + obj->ldA * (idx - 1)) - 1] = -1.0;
  }
  idxStartIneq = obj->isActiveIdx[4] - 1;
  if (obj->nWConstr[4] > 0) {
    i = obj->sizesNormal[4];
    for (idx = i; idx >= 1; idx--) {
      int32_T i1;
      i1 = idxStartIneq + idx;
      obj->isActiveConstr.data[i1] = obj->isActiveConstr.data[i1 - 1];
    }
  } else {
    obj->isActiveConstr.data[(obj->isActiveIdx[4] + obj->sizesNormal[4]) - 1] =
        false;
  }
  obj->isActiveConstr.data[obj->isActiveIdx[4] - 1] = false;
}

/* End of code generation (modifyOverheadPhaseOne_.c) */
