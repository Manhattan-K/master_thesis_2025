//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// finDiffEvalAndChkErr.cpp
//
// Code generation for function 'finDiffEvalAndChkErr'
//

// Include files
#include "finDiffEvalAndChkErr.h"
#include "anonymous_function.h"
#include "constraints.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T finDiffEvalAndChkErr(const e_anonymous_function &obj_objfun,
                               const d_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus)
{
  array<real_T, 1U> c_obst_av;
  real_T tmp_data[4200];
  real_T temp_tmp;
  int32_T idx;
  boolean_T evalOK;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  fplus = leaderMPCandUpdateHalt_anonFcn1(
      obj_objfun.workspace.x0, obj_objfun.workspace.sys.n,
      obj_objfun.workspace.sys.Ts, obj_objfun.workspace.N,
      obj_objfun.workspace.robotParams.Px, xk);
  evalOK = ((!muDoubleScalarIsInf(fplus)) && (!muDoubleScalarIsNaN(fplus)));
  if (evalOK) {
    //  Obtain the number of vertices
    //  Obtain the number of states n and number of inputs m
    //  Obstacle avoidance
    //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
    if (obj_nonlin.workspace.obstacles.M_l >= 1.0) {
      stateEvolution(xk, obj_nonlin.workspace.x0, obj_nonlin.workspace.sys.n,
                     obj_nonlin.workspace.sys.Ts, obj_nonlin.workspace.N,
                     c_obst_av);
      idx = ::coder::internal::blas::mtimes(
          obj_nonlin.workspace.obstacles.A_bar_l, c_obst_av, tmp_data);
      if (idx == obj_nonlin.workspace.obstacles.B_bar_l.size[0]) {
        c_obst_av.set_size(idx);
        for (int32_T i{0}; i < idx; i++) {
          c_obst_av[i] =
              tmp_data[i] - obj_nonlin.workspace.obstacles.B_bar_l.data[i];
        }
      } else {
        binary_expand_op_8(c_obst_av, tmp_data, idx, obj_nonlin);
      }
    } else {
      //  If there are no constraints
      c_obst_av.set_size(0);
    }
    //  Input constraints
    //  Defined in the fmincon function
    //  Final output
    idx = c_obst_av.size(0);
    cIneqPlus_size = c_obst_av.size(0);
    for (int32_T i{0}; i < idx; i++) {
      cIneqPlus_data[i] = c_obst_av[i];
    }
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(c_obst_av[idx])) &&
                (!muDoubleScalarIsNaN(c_obst_av[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return evalOK;
}

boolean_T finDiffEvalAndChkErr(const c_anonymous_function &obj_objfun,
                               const d_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus)
{
  array<real_T, 1U> c_obst_av;
  real_T tmp_data[4200];
  real_T temp_tmp;
  int32_T idx;
  boolean_T evalOK;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  fplus = leaderMPCandUpdate_anonFcn1(
      obj_objfun.workspace.x0, obj_objfun.workspace.sys.n,
      obj_objfun.workspace.sys.Ts, obj_objfun.workspace.robotParams.W,
      obj_objfun.workspace.robotParams.W_hat,
      obj_objfun.workspace.robotParams.R_hat, obj_objfun.workspace.N, xk);
  evalOK = ((!muDoubleScalarIsInf(fplus)) && (!muDoubleScalarIsNaN(fplus)));
  if (evalOK) {
    //  Obtain the number of vertices
    //  Obtain the number of states n and number of inputs m
    //  Obstacle avoidance
    //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
    if (obj_nonlin.workspace.obstacles.M_l >= 1.0) {
      stateEvolution(xk, obj_nonlin.workspace.x0, obj_nonlin.workspace.sys.n,
                     obj_nonlin.workspace.sys.Ts, obj_nonlin.workspace.N,
                     c_obst_av);
      idx = ::coder::internal::blas::mtimes(
          obj_nonlin.workspace.obstacles.A_bar_l, c_obst_av, tmp_data);
      if (idx == obj_nonlin.workspace.obstacles.B_bar_l.size[0]) {
        c_obst_av.set_size(idx);
        for (int32_T i{0}; i < idx; i++) {
          c_obst_av[i] =
              tmp_data[i] - obj_nonlin.workspace.obstacles.B_bar_l.data[i];
        }
      } else {
        binary_expand_op_7(c_obst_av, tmp_data, idx, obj_nonlin);
      }
    } else {
      //  If there are no constraints
      c_obst_av.set_size(0);
    }
    //  Input constraints
    //  Defined in the fmincon function
    //  Final output
    idx = c_obst_av.size(0);
    cIneqPlus_size = c_obst_av.size(0);
    for (int32_T i{0}; i < idx; i++) {
      cIneqPlus_data[i] = c_obst_av[i];
    }
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(c_obst_av[idx])) &&
                (!muDoubleScalarIsNaN(c_obst_av[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return evalOK;
}

boolean_T finDiffEvalAndChkErr(const anonymous_function &obj_objfun,
                               const b_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus)
{
  array<real_T, 1U> c_obst_av;
  real_T y_data[4200];
  real_T temp_tmp;
  int32_T idx;
  boolean_T evalOK;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  fplus = followerMPCandUpdate_anonFcn1(
      obj_objfun.workspace.x0, obj_objfun.workspace.sys.n,
      obj_objfun.workspace.sys.Ts, obj_objfun.workspace.N,
      obj_objfun.workspace.X_L_stacked, obj_objfun.workspace.robotParams.Px,
      obj_objfun.workspace.robotParams.d_FL_sq,
      obj_objfun.workspace.robotParams.C,
      obj_objfun.workspace.robotParams.beta_N, xk);
  evalOK = ((!muDoubleScalarIsInf(fplus)) && (!muDoubleScalarIsNaN(fplus)));
  if (evalOK) {
    //  Obtain the number of vertices
    //  Obtain the number of states n and number of inputs m
    //  Obstacle avoidance
    //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
    if (obj_nonlin.workspace.obstacles.M_f >= 1.0) {
      stateEvolution(xk, obj_nonlin.workspace.x0, obj_nonlin.workspace.sys.n,
                     obj_nonlin.workspace.sys.Ts, obj_nonlin.workspace.N,
                     c_obst_av);
      idx = ::coder::internal::blas::mtimes(
          obj_nonlin.workspace.obstacles.A_bar_f, c_obst_av, y_data);
      if (idx == obj_nonlin.workspace.obstacles.B_bar_f.size[0]) {
        c_obst_av.set_size(idx);
        for (int32_T i{0}; i < idx; i++) {
          c_obst_av[i] =
              y_data[i] - obj_nonlin.workspace.obstacles.B_bar_f.data[i];
        }
      } else {
        binary_expand_op_6(c_obst_av, y_data, idx, obj_nonlin);
      }
    } else {
      //  If there are no constraints
      c_obst_av.set_size(0);
    }
    //  Input constraints
    //  Defined in the fmincon function
    //  Final output
    idx = c_obst_av.size(0);
    cIneqPlus_size = c_obst_av.size(0);
    for (int32_T i{0}; i < idx; i++) {
      cIneqPlus_data[i] = c_obst_av[i];
    }
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(c_obst_av[idx])) &&
                (!muDoubleScalarIsNaN(c_obst_av[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return evalOK;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (finDiffEvalAndChkErr.cpp)
