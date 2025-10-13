//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// relaxed.cpp
//
// Code generation for function 'relaxed'
//

// Include files
#include "relaxed.h"
#include "assignResidualsToXSlack.h"
#include "driver1.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "updatePenaltyParam.h"
#include "xasum.h"
#include "xdot.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void b_relaxed(const real_T Hessian[1600], const real_T grad_data[],
               int32_T grad_size, f_struct_T &b_TrialState,
               h_struct_T &b_MeritFunction, c_struct_T &memspace,
               g_struct_T &WorkingSet, d_struct_T &b_QRManager,
               e_struct_T &b_CholManager, b_struct_T &QPObjective,
               i_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_grad_data;
  real_T beta;
  real_T rho;
  int32_T idx;
  int32_T mIneq;
  int32_T nActiveLBArtificial;
  int32_T nVarOrig;
  int32_T temp;
  nVarOrig = WorkingSet.nVar + 1;
  mIneq = WorkingSet.sizes[2];
  beta = 0.0;
  temp = static_cast<uint16_T>(WorkingSet.nVar);
  for (idx = 0; idx < temp; idx++) {
    beta += Hessian[idx + 40 * idx];
  }
  beta /= static_cast<real_T>(WorkingSet.nVar);
  if (b_TrialState.sqpIterations <= 1) {
    b_grad_data.set((real_T *)&grad_data[0], grad_size);
    temp = QPObjective.nvar;
    if (temp < 1) {
      temp = 0;
    } else {
      n_t = (ptrdiff_t)temp;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, &(b_grad_data.data())[0], &incx_t);
      temp = (int32_T)n_t;
    }
    rho =
        100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad_data[temp - 1]));
  } else {
    temp = WorkingSet.mConstr;
    if (temp < 1) {
      temp = 0;
    } else {
      n_t = (ptrdiff_t)temp;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t);
      temp = (int32_T)n_t;
    }
    rho = muDoubleScalarAbs(b_TrialState.lambdasqp[temp - 1]);
  }
  QPObjective.nvar = WorkingSet.nVar;
  QPObjective.beta = beta;
  QPObjective.rho = rho;
  QPObjective.hasLinear = true;
  QPObjective.objtype = 4;
  qpactiveset::WorkingSet::setProblemType(WorkingSet, 2);
  relaxed::assignResidualsToXSlack(nVarOrig - 1, WorkingSet, b_TrialState,
                                   memspace);
  temp = qpoptions.MaxIterations;
  qpoptions.MaxIterations =
      ((qpoptions.MaxIterations + WorkingSet.nVar) - nVarOrig) + 1;
  ::coder::optim::coder::qpactiveset::driver(
      Hessian, grad_data, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, qpoptions, qpoptions);
  qpoptions.MaxIterations = temp;
  nActiveLBArtificial = 0;
  temp = static_cast<uint16_T>(WorkingSet.sizes[2]);
  for (idx = 0; idx < temp; idx++) {
    boolean_T tf;
    tf = WorkingSet.isActiveConstr
             .data[(((WorkingSet.isActiveIdx[3] + WorkingSet.sizes[3]) -
                     WorkingSet.sizes[2]) +
                    idx) -
                   1];
    memspace.workspace_int.data[idx] = tf;
    nActiveLBArtificial += tf;
  }
  if (b_TrialState.state != -6) {
    temp = WorkingSet.nVarMax - nVarOrig;
    MeritFunction::updatePenaltyParam(
        b_MeritFunction, b_TrialState.sqpFval, b_TrialState.cIneq.data, mIneq,
        b_TrialState.sqpIterations,
        (b_TrialState.fstar -
         rho * ::coder::internal::blas::xasum(temp, b_TrialState.xstar.data,
                                              nVarOrig)) -
            beta / 2.0 *
                ::coder::internal::blas::xdot(temp, b_TrialState.xstar.data,
                                              nVarOrig, b_TrialState.xstar.data,
                                              nVarOrig),
        b_TrialState.xstar.data, nVarOrig, WorkingSet.nVarMax - nVarOrig);
    temp = WorkingSet.isActiveIdx[2];
    mIneq = WorkingSet.nActiveConstr;
    for (idx = temp; idx <= mIneq; idx++) {
      if (WorkingSet.Wid.data[idx - 1] == 3) {
        b_TrialState.lambda[idx - 1] =
            static_cast<real_T>(
                memspace.workspace_int
                    .data[WorkingSet.Wlocalidx.data[idx - 1] - 1]) *
            b_TrialState.lambda[idx - 1];
      }
    }
  }
  temp = WorkingSet.sizes[0];
  mIneq = WorkingSet.sizes[3] - WorkingSet.sizes[2];
  idx = WorkingSet.nActiveConstr;
  while ((idx > temp) && (nActiveLBArtificial > 0)) {
    if ((WorkingSet.Wid.data[idx - 1] == 4) &&
        (WorkingSet.Wlocalidx.data[idx - 1] > mIneq)) {
      beta = b_TrialState.lambda[WorkingSet.nActiveConstr - 1];
      b_TrialState.lambda[WorkingSet.nActiveConstr - 1] = 0.0;
      b_TrialState.lambda[idx - 1] = beta;
      qpactiveset::WorkingSet::removeConstr(WorkingSet, idx);
      nActiveLBArtificial--;
    }
    idx--;
  }
  QPObjective.nvar = nVarOrig - 1;
  QPObjective.hasLinear = true;
  QPObjective.objtype = 3;
  qpactiveset::WorkingSet::setProblemType(WorkingSet, 3);
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

// End of code generation (relaxed.cpp)
