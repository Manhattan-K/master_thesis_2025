/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initActiveSet.c
 *
 * Code generation for function 'initActiveSet'
 *
 */

/* Include files */
#include "initActiveSet.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <string.h>

/* Function Definitions */
void initActiveSet(i_struct_T *obj)
{
  int32_T b_i;
  int32_T i;
  int32_T idxFillStart;
  int32_T idx_local;
  setProblemType(obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  i = obj->mConstrMax;
  if (idxFillStart <= i) {
    memset(&obj->isActiveConstr.data[idxFillStart + -1], 0,
           (uint32_T)((i - idxFillStart) + 1) * sizeof(boolean_T));
  }
  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 0;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0];
  i = (uint16_T)obj->sizes[0];
  for (idx_local = 0; idx_local < i; idx_local++) {
    int32_T i1;
    int32_T i2;
    obj->Wid.data[idx_local] = 1;
    obj->Wlocalidx.data[idx_local] = idx_local + 1;
    obj->isActiveConstr.data[idx_local] = true;
    idxFillStart = obj->ldA * idx_local;
    i1 = (uint8_T)(obj->indexFixed.data[idx_local] - 1);
    for (b_i = 0; b_i < i1; b_i++) {
      obj->ATwset->data[b_i + idxFillStart] = 0.0;
    }
    obj->ATwset->data[(obj->indexFixed.data[idx_local] + idxFillStart) - 1] =
        1.0;
    i1 = obj->indexFixed.data[idx_local] + 1;
    i2 = obj->nVar;
    for (b_i = i1; b_i <= i2; b_i++) {
      obj->ATwset->data[(b_i + idxFillStart) - 1] = 0.0;
    }
    obj->bwset->data[idx_local] =
        obj->ub.data[obj->indexFixed.data[idx_local] - 1];
  }
}

/* End of code generation (initActiveSet.c) */
