/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct.c
 *
 * Code generation for function 'factoryConstruct'
 *
 */

/* Include files */
#include "factoryConstruct.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void factoryConstruct(int32_T nVarMax, int32_T mConstrMax, int32_T mIneq,
                      int32_T mNonlinIneq, h_struct_T *obj)
{
  int32_T i;
  obj->nVarMax = nVarMax;
  obj->mNonlinIneq = mNonlinIneq;
  obj->mNonlinEq = 0;
  obj->mIneq = mIneq;
  obj->mEq = 0;
  obj->iNonIneq0 = (mIneq - mNonlinIneq) + 1;
  obj->iNonEq0 = 1;
  obj->sqpFval = 0.0;
  obj->sqpFval_old = 0.0;
  obj->cIneq.size[0] = mIneq;
  obj->cIneq_old.size[0] = mIneq;
  obj->grad.size[0] = nVarMax;
  obj->grad_old.size[0] = nVarMax;
  obj->FunctionEvaluations = 0;
  obj->sqpIterations = 0;
  obj->sqpExitFlag = 0;
  i = obj->lambdasqp->size[0];
  obj->lambdasqp->size[0] = mConstrMax;
  emxEnsureCapacity_real_T(obj->lambdasqp, i);
  for (i = 0; i < mConstrMax; i++) {
    obj->lambdasqp->data[i] = 0.0;
  }
  i = obj->lambdaStopTest->size[0];
  obj->lambdaStopTest->size[0] = mConstrMax;
  emxEnsureCapacity_real_T(obj->lambdaStopTest, i);
  i = obj->lambdaStopTestPrev->size[0];
  obj->lambdaStopTestPrev->size[0] = mConstrMax;
  emxEnsureCapacity_real_T(obj->lambdaStopTestPrev, i);
  obj->steplength = 1.0;
  obj->delta_x.size[0] = nVarMax;
  if (nVarMax - 1 >= 0) {
    memset(&obj->delta_x.data[0], 0, (uint32_T)nVarMax * sizeof(real_T));
  }
  obj->socDirection.size[0] = nVarMax;
  obj->workingset_old.size[0] = mConstrMax;
  if (mNonlinIneq > 0) {
    i = obj->JacCineqTrans_old->size[0] * obj->JacCineqTrans_old->size[1];
    obj->JacCineqTrans_old->size[0] = nVarMax;
    obj->JacCineqTrans_old->size[1] = mNonlinIneq;
    emxEnsureCapacity_real_T(obj->JacCineqTrans_old, i);
  } else {
    obj->JacCineqTrans_old->size[0] = 0;
    obj->JacCineqTrans_old->size[1] = 0;
  }
  obj->gradLag.size[0] = nVarMax;
  obj->delta_gradLag.size[0] = nVarMax;
  obj->xstar.size[0] = nVarMax;
  obj->fstar = 0.0;
  obj->firstorderopt = 0.0;
  i = obj->lambda->size[0];
  obj->lambda->size[0] = mConstrMax;
  emxEnsureCapacity_real_T(obj->lambda, i);
  for (i = 0; i < mConstrMax; i++) {
    obj->lambda->data[i] = 0.0;
  }
  obj->state = 0;
  obj->maxConstr = 0.0;
  obj->iterations = 0;
  obj->searchDir.size[0] = nVarMax;
}

/* End of code generation (factoryConstruct.c) */
