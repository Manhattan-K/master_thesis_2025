//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// normal.cpp
//
// Code generation for function 'normal'
//

// Include files
#include "normal.h"
#include "driver1.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void normal(mexFunctionsStackData *SD, const real_T Hessian[1600],
            const real_T grad_data[], f_struct_T &b_TrialState,
            h_struct_T &b_MeritFunction, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            const i_struct_T &qpoptions, struct_T &stepFlags)
{
  boolean_T isEqAndIneqFeasible;
  ::coder::optim::coder::qpactiveset::driver(
      Hessian, grad_data, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, qpoptions, qpoptions);
  isEqAndIneqFeasible =
      (qpactiveset::WorkingSet::b_maxConstraintViolation(
           SD, WorkingSet, b_TrialState.xstar.data) <= 1.0E-6);
  if ((b_TrialState.state > 0) ||
      ((b_TrialState.state == 0) && isEqAndIneqFeasible) ||
      ((b_TrialState.state != -6) && (WorkingSet.sizes[2] == 0))) {
    real_T constrViolationIneq;
    real_T linearizedConstrViolPrev;
    real_T penaltyParamTrial;
    int32_T i;
    penaltyParamTrial = b_MeritFunction.penaltyParam;
    constrViolationIneq = 0.0;
    i = static_cast<uint16_T>(WorkingSet.sizes[2]);
    for (int32_T idx{0}; idx < i; idx++) {
      linearizedConstrViolPrev = b_TrialState.cIneq.data[idx];
      if (linearizedConstrViolPrev > 0.0) {
        constrViolationIneq += linearizedConstrViolPrev;
      }
    }
    linearizedConstrViolPrev = b_MeritFunction.linearizedConstrViol;
    b_MeritFunction.linearizedConstrViol = 0.0;
    linearizedConstrViolPrev += constrViolationIneq;
    if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
        (b_TrialState.fstar > 0.0)) {
      if (b_TrialState.sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }
      penaltyParamTrial =
          penaltyParamTrial * b_TrialState.fstar / linearizedConstrViolPrev;
    }
    if (penaltyParamTrial < b_MeritFunction.penaltyParam) {
      b_MeritFunction.phi =
          b_TrialState.sqpFval + penaltyParamTrial * constrViolationIneq;
      if ((b_MeritFunction.initFval +
           penaltyParamTrial * b_MeritFunction.initConstrViolationIneq) -
              b_MeritFunction.phi >
          static_cast<real_T>(b_MeritFunction.nPenaltyDecreases) *
              b_MeritFunction.threshold) {
        b_MeritFunction.nPenaltyDecreases++;
        if ((b_MeritFunction.nPenaltyDecreases << 1) >
            b_TrialState.sqpIterations) {
          b_MeritFunction.threshold *= 10.0;
        }
        b_MeritFunction.penaltyParam =
            muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      } else {
        b_MeritFunction.phi =
            b_TrialState.sqpFval +
            b_MeritFunction.penaltyParam * constrViolationIneq;
      }
    } else {
      b_MeritFunction.penaltyParam =
          muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      b_MeritFunction.phi = b_TrialState.sqpFval +
                            b_MeritFunction.penaltyParam * constrViolationIneq;
    }
    b_MeritFunction.phiPrimePlus = muDoubleScalarMin(
        b_TrialState.fstar - b_MeritFunction.penaltyParam * constrViolationIneq,
        0.0);
  } else if (b_TrialState.state != -6) {
    stepFlags.stepType = 2;
  }
  qpactiveset::parseoutput::sortLambdaQP(
      b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
      WorkingSet.isActiveIdx, WorkingSet.Wid.data, WorkingSet.Wlocalidx.data,
      memspace.workspace_float);
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (normal.cpp)
