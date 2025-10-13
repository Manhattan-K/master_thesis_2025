//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFiniteDifferences.cpp
//
// Code generation for function 'computeFiniteDifferences'
//

// Include files
#include "computeFiniteDifferences.h"
#include "anonymous_function.h"
#include "finDiffEvalAndChkErr.h"
#include "fwdFinDiffInsideBnds.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
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
boolean_T computeFiniteDifferences(o_struct_T &obj, real_T fCurrent,
                                   const real_T cIneqCurrent_data[],
                                   int32_T ineq0, real_T xk[40],
                                   real_T gradf_data[],
                                   array<real_T, 1U> &JacCineqTrans,
                                   int32_T CineqColStart, int32_T ldJI,
                                   const real_T lb[40], const real_T ub[40])
{
  int32_T idx;
  boolean_T evalOK;
  boolean_T exitg1;
  evalOK = true;
  obj.numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 40)) {
    real_T deltaX;
    int32_T t2_mIneq;
    boolean_T guard1;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 *
             (1.0 - 2.0 * static_cast<real_T>(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj.hasLB[idx] || obj.hasUB[idx]) {
      if (obj.hasLB[idx] && obj.hasUB[idx]) {
        modifiedStep =
            internal::fwdFinDiffInsideBnds(xk[idx], lb[idx], ub[idx], deltaX);
      } else if (obj.hasUB[idx]) {
        if ((xk[idx] <= ub[idx]) && (xk[idx] + deltaX > ub[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else if ((xk[idx] >= lb[idx]) && (xk[idx] + deltaX < lb[idx])) {
        deltaX = -deltaX;
        modifiedStep = true;
      }
    }
    t2_mIneq = obj.mIneq;
    evalOK = internal::finDiffEvalAndChkErr(
        obj.objfun, obj.nonlin, t2_mIneq, obj.cIneq_1.data, obj.cIneq_1.size[0],
        idx + 1, deltaX, xk, obj.f_1);
    obj.numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj.hasLB[idx]) {
          real_T d;
          d = xk[idx] + deltaX;
          if ((d >= lb[idx]) && obj.hasUB[idx] && (d <= ub[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj.hasBounds) || modifiedStep) {
          evalOK = internal::finDiffEvalAndChkErr(
              obj.objfun, obj.nonlin, t2_mIneq, obj.cIneq_1.data,
              obj.cIneq_1.size[0], idx + 1, deltaX, xk, obj.f_1);
          obj.numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf_data[idx] = (obj.f_1 - fCurrent) / deltaX;
      t2_mIneq = static_cast<uint16_T>(obj.mIneq);
      for (int32_T idx_row{0}; idx_row < t2_mIneq; idx_row++) {
        JacCineqTrans[idx + ldJI * ((CineqColStart + idx_row) - 1)] =
            (obj.cIneq_1.data[idx_row] -
             cIneqCurrent_data[(ineq0 + idx_row) - 1]) /
            deltaX;
      }
      idx++;
    }
  }
  return evalOK;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFiniteDifferences.cpp)
