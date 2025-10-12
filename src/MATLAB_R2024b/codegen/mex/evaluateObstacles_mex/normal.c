/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normal.c
 *
 * Code generation for function 'normal'
 *
 */

/* Include files */
#include "normal.h"
#include "driver1.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void normal(evaluateObstacles_mexStackData *SD, const real_T Hessian[1600],
            const real_T grad_data[], j_struct_T *TrialState,
            l_struct_T *MeritFunction, e_struct_T *memspace,
            k_struct_T *WorkingSet, f_struct_T *QRManager,
            n_struct_T *CholManager, d_struct_T *QPObjective,
            const o_struct_T *qpoptions, struct_T *stepFlags)
{
  int32_T idx;
  boolean_T isEqAndIneqFeasible;
  b_driver(Hessian, grad_data, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, qpoptions, qpoptions);
  isEqAndIneqFeasible = (maxConstraintViolation(
                             SD, WorkingSet, TrialState->xstar.data) <= 1.0E-6);
  if ((TrialState->state > 0) ||
      ((TrialState->state == 0) && isEqAndIneqFeasible) ||
      ((TrialState->state != -6) && (WorkingSet->sizes[2] == 0))) {
    real_T constrViolationIneq;
    real_T linearizedConstrViolPrev;
    real_T penaltyParamTrial;
    int32_T i;
    penaltyParamTrial = MeritFunction->penaltyParam;
    constrViolationIneq = 0.0;
    i = (uint16_T)WorkingSet->sizes[2];
    for (idx = 0; idx < i; idx++) {
      linearizedConstrViolPrev = TrialState->cIneq.data[idx];
      if (linearizedConstrViolPrev > 0.0) {
        constrViolationIneq += linearizedConstrViolPrev;
      }
    }
    linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    linearizedConstrViolPrev += constrViolationIneq;
    if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
        (TrialState->fstar > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }
      penaltyParamTrial =
          penaltyParamTrial * TrialState->fstar / linearizedConstrViolPrev;
    }
    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi =
          TrialState->sqpFval + penaltyParamTrial * constrViolationIneq;
      if ((MeritFunction->initFval +
           penaltyParamTrial * MeritFunction->initConstrViolationIneq) -
              MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam =
            muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval +
                             MeritFunction->penaltyParam * constrViolationIneq;
      }
    } else {
      MeritFunction->penaltyParam =
          muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval +
                           MeritFunction->penaltyParam * constrViolationIneq;
    }
    MeritFunction->phiPrimePlus = muDoubleScalarMin(
        TrialState->fstar - MeritFunction->penaltyParam * constrViolationIneq,
        0.0);
  } else if (TrialState->state != -6) {
    stepFlags->stepType = 2;
  }
  sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid.data,
               WorkingSet->Wlocalidx.data, memspace->workspace_float);
}

/* End of code generation (normal.c) */
