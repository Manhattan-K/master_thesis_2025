//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evalObjAndConstrAndDerivatives.cpp
//
// Code generation for function 'evalObjAndConstrAndDerivatives'
//

// Include files
#include "evalObjAndConstrAndDerivatives.h"
#include "anonymous_function.h"
#include "computeConstraints_.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
real_T evalObjAndConstrAndDerivatives(
    const ::coder::internal::r_stickyStruct &obj, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T &Cineq_workspace_size,
    int32_T ineq0, int32_T &status)
{
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
  boolean_T b;
  fval = leaderMPCandUpdateHalt_anonFcn1(
      obj.next.next.next.next.next.next.next.next.value.workspace.x0,
      obj.next.next.next.next.next.next.next.next.value.workspace.sys.n,
      obj.next.next.next.next.next.next.next.next.value.workspace.sys.Ts,
      obj.next.next.next.next.next.next.next.next.value.workspace.N,
      obj.next.next.next.next.next.next.next.next.value.workspace.robotParams
          .Px,
      x);
  status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      status = -3;
    } else if (fval < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  if (status == 1) {
    int32_T loop_ub;
    loop_ub = Cineq_workspace_size;
    if (loop_ub - 1 >= 0) {
      std::copy(&Cineq_workspace_data[0], &Cineq_workspace_data[loop_ub],
                &b_Cineq_workspace_data[0]);
    }
    status = computeConstraints_(obj, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub - 1 >= 0) {
      std::copy(&b_Cineq_workspace_data[0], &b_Cineq_workspace_data[loop_ub],
                &Cineq_workspace_data[0]);
    }
  }
  return fval;
}

real_T evalObjAndConstrAndDerivatives(
    const ::coder::internal::i_stickyStruct &obj, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T &Cineq_workspace_size,
    int32_T ineq0, int32_T &status)
{
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
  boolean_T b;
  fval = leaderMPCandUpdate_anonFcn1(
      obj.next.next.next.next.next.next.next.next.value.workspace.x0,
      obj.next.next.next.next.next.next.next.next.value.workspace.sys.n,
      obj.next.next.next.next.next.next.next.next.value.workspace.sys.Ts,
      obj.next.next.next.next.next.next.next.next.value.workspace.robotParams.W,
      obj.next.next.next.next.next.next.next.next.value.workspace.robotParams
          .W_hat,
      obj.next.next.next.next.next.next.next.next.value.workspace.robotParams
          .R_hat,
      obj.next.next.next.next.next.next.next.next.value.workspace.N, x);
  status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      status = -3;
    } else if (fval < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  if (status == 1) {
    int32_T loop_ub;
    loop_ub = Cineq_workspace_size;
    if (loop_ub - 1 >= 0) {
      std::copy(&Cineq_workspace_data[0], &Cineq_workspace_data[loop_ub],
                &b_Cineq_workspace_data[0]);
    }
    status = computeConstraints_(obj, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub - 1 >= 0) {
      std::copy(&b_Cineq_workspace_data[0], &b_Cineq_workspace_data[loop_ub],
                &Cineq_workspace_data[0]);
    }
  }
  return fval;
}

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (evalObjAndConstrAndDerivatives.cpp)
