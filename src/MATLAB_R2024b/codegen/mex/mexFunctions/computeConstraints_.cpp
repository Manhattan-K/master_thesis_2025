//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeConstraints_.cpp
//
// Code generation for function 'computeConstraints_'
//

// Include files
#include "computeConstraints_.h"
#include "anonymous_function.h"
#include "checkVectorNonFinite.h"
#include "constraints.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "stickyStruct.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
int32_T computeConstraints_(const ::coder::internal::r_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0)
{
  array<real_T, 1U> c_obst_av;
  real_T tmp_data[4200];
  int32_T ineqRange_data[4200];
  int32_T status;
  int32_T yk;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (obj.next.next.next.next.next.value - 1 < 0) {
    status = 0;
  } else {
    status = static_cast<uint16_T>(obj.next.next.next.next.next.value - 1) + 1;
  }
  if (status > 0) {
    ineqRange_data[0] = 0;
    yk = 0;
    for (int32_T k{2}; k <= status; k++) {
      yk++;
      ineqRange_data[k - 1] = yk;
    }
  }
  yk = status - 1;
  for (int32_T k{0}; k <= yk; k++) {
    ineqRange_data[k] += ineq0;
  }
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  Obstacle avoidance
  //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
  if (obj.next.next.next.next.next.next.next.value.workspace.obstacles.M_l >=
      1.0) {
    stateEvolution(
        x, obj.next.next.next.next.next.next.next.value.workspace.x0,
        obj.next.next.next.next.next.next.next.value.workspace.sys.n,
        obj.next.next.next.next.next.next.next.value.workspace.sys.Ts,
        obj.next.next.next.next.next.next.next.value.workspace.N, c_obst_av);
    yk = ::coder::internal::blas::mtimes(obj.next.next.next.next.next.next.next
                                             .value.workspace.obstacles.A_bar_l,
                                         c_obst_av, tmp_data);
    if (yk == obj.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.size[0]) {
      c_obst_av.set_size(yk);
      for (int32_T k{0}; k < yk; k++) {
        c_obst_av[k] =
            tmp_data[k] - obj.next.next.next.next.next.next.next.value.workspace
                              .obstacles.B_bar_l.data[k];
      }
    } else {
      binary_expand_op_11(c_obst_av, tmp_data, yk, obj);
    }
  } else {
    //  If there are no constraints
    c_obst_av.set_size(0);
  }
  //  Input constraints
  //  Defined in the fmincon function
  //  Final output
  for (int32_T k{0}; k < status; k++) {
    Cineq_workspace_data[ineqRange_data[k] - 1] = c_obst_av[k];
  }
  status = internal::checkVectorNonFinite(obj.next.next.next.next.next.value,
                                          Cineq_workspace_data, ineq0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return status;
}

int32_T computeConstraints_(const ::coder::internal::i_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0)
{
  array<real_T, 1U> c_obst_av;
  real_T tmp_data[4200];
  int32_T ineqRange_data[4200];
  int32_T status;
  int32_T yk;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (obj.next.next.next.next.next.value - 1 < 0) {
    status = 0;
  } else {
    status = static_cast<uint16_T>(obj.next.next.next.next.next.value - 1) + 1;
  }
  if (status > 0) {
    ineqRange_data[0] = 0;
    yk = 0;
    for (int32_T k{2}; k <= status; k++) {
      yk++;
      ineqRange_data[k - 1] = yk;
    }
  }
  yk = status - 1;
  for (int32_T k{0}; k <= yk; k++) {
    ineqRange_data[k] += ineq0;
  }
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  Obstacle avoidance
  //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
  if (obj.next.next.next.next.next.next.next.value.workspace.obstacles.M_l >=
      1.0) {
    stateEvolution(
        x, obj.next.next.next.next.next.next.next.value.workspace.x0,
        obj.next.next.next.next.next.next.next.value.workspace.sys.n,
        obj.next.next.next.next.next.next.next.value.workspace.sys.Ts,
        obj.next.next.next.next.next.next.next.value.workspace.N, c_obst_av);
    yk = ::coder::internal::blas::mtimes(obj.next.next.next.next.next.next.next
                                             .value.workspace.obstacles.A_bar_l,
                                         c_obst_av, tmp_data);
    if (yk == obj.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.size[0]) {
      c_obst_av.set_size(yk);
      for (int32_T k{0}; k < yk; k++) {
        c_obst_av[k] =
            tmp_data[k] - obj.next.next.next.next.next.next.next.value.workspace
                              .obstacles.B_bar_l.data[k];
      }
    } else {
      binary_expand_op_10(c_obst_av, tmp_data, yk, obj);
    }
  } else {
    //  If there are no constraints
    c_obst_av.set_size(0);
  }
  //  Input constraints
  //  Defined in the fmincon function
  //  Final output
  for (int32_T k{0}; k < status; k++) {
    Cineq_workspace_data[ineqRange_data[k] - 1] = c_obst_av[k];
  }
  status = internal::checkVectorNonFinite(obj.next.next.next.next.next.value,
                                          Cineq_workspace_data, ineq0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return status;
}

int32_T computeConstraints_(const ::coder::internal::bb_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0)
{
  array<real_T, 1U> c_obst_av;
  real_T b_y_data[4200];
  int32_T ineqRange_data[800];
  int32_T status;
  int32_T yk;
  uint16_T y_data[4200];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (obj.next.next.next.next.next.value - 1 < 0) {
    status = 0;
  } else {
    status = static_cast<uint16_T>(obj.next.next.next.next.next.value - 1) + 1;
  }
  if (status > 0) {
    y_data[0] = 0U;
    yk = 0;
    for (int32_T k{2}; k <= status; k++) {
      yk++;
      y_data[k - 1] = static_cast<uint16_T>(yk);
    }
  }
  for (int32_T k{0}; k < status; k++) {
    ineqRange_data[k] = y_data[k] + ineq0;
  }
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  Obstacle avoidance
  //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
  if (obj.next.next.next.next.next.next.next.value.workspace.obstacles.M_f >=
      1.0) {
    stateEvolution(
        x, obj.next.next.next.next.next.next.next.value.workspace.x0,
        obj.next.next.next.next.next.next.next.value.workspace.sys.n,
        obj.next.next.next.next.next.next.next.value.workspace.sys.Ts,
        obj.next.next.next.next.next.next.next.value.workspace.N, c_obst_av);
    yk = ::coder::internal::blas::mtimes(obj.next.next.next.next.next.next.next
                                             .value.workspace.obstacles.A_bar_f,
                                         c_obst_av, b_y_data);
    if (yk == obj.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_f.size[0]) {
      c_obst_av.set_size(yk);
      for (int32_T k{0}; k < yk; k++) {
        c_obst_av[k] =
            b_y_data[k] - obj.next.next.next.next.next.next.next.value.workspace
                              .obstacles.B_bar_f.data[k];
      }
    } else {
      binary_expand_op_9(c_obst_av, b_y_data, yk, obj);
    }
  } else {
    //  If there are no constraints
    c_obst_av.set_size(0);
  }
  //  Input constraints
  //  Defined in the fmincon function
  //  Final output
  for (int32_T k{0}; k < status; k++) {
    Cineq_workspace_data[ineqRange_data[k] - 1] = c_obst_av[k];
  }
  status = internal::checkVectorNonFinite(obj.next.next.next.next.next.value,
                                          Cineq_workspace_data, ineq0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return status;
}

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeConstraints_.cpp)
