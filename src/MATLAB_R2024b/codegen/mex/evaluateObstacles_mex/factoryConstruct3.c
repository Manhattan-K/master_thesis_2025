/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct3.c
 *
 * Code generation for function 'factoryConstruct3'
 *
 */

/* Include files */
#include "factoryConstruct3.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void d_factoryConstruct(real_T fval, const real_T Cineq_workspace_data[],
                        int32_T mNonlinIneq, l_struct_T *obj)
{
  real_T normResid;
  int32_T i;
  int32_T idx;
  obj->penaltyParam = 1.0;
  obj->threshold = 0.0001;
  obj->nPenaltyDecreases = 0;
  obj->linearizedConstrViol = 0.0;
  obj->initFval = fval;
  normResid = 0.0;
  i = (uint16_T)mNonlinIneq;
  for (idx = 0; idx < i; idx++) {
    real_T d;
    d = Cineq_workspace_data[idx];
    if (d > 0.0) {
      normResid += d;
    }
  }
  obj->initConstrViolationIneq = normResid;
  obj->phi = 0.0;
  obj->phiPrimePlus = 0.0;
  obj->phiFullStep = 0.0;
  obj->feasRelativeFactor = 0.0;
  obj->nlpPrimalFeasError = 0.0;
  obj->nlpDualFeasError = 0.0;
  obj->nlpComplError = 0.0;
  obj->firstOrderOpt = 0.0;
}

/* End of code generation (factoryConstruct3.c) */
