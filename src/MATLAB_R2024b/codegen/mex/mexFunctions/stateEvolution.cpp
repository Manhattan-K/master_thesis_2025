//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stateEvolution.cpp
//
// Code generation for function 'stateEvolution'
//

// Include files
#include "stateEvolution.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
void stateEvolution(const real_T U[40], const real_T x0[3], real_T sys_n,
                    real_T sys_Ts, real_T N, coder::array<real_T, 1U> &x_pred)
{
  coder::array<real_T, 1U> r;
  real_T prev_i;
  real_T q;
  real_T tmp_data;
  int32_T i;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T trueCount;
  boolean_T b;
  boolean_T rEQ0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Given the initial state, the prediction horizon N and the input
  //  values, the function evaluate and create a stacked matrix of the next
  //  N states of the system
  loop_ub_tmp = static_cast<int32_T>(sys_n * N);
  x_pred.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    x_pred[i] = 0.0;
  }
  loop_ub_tmp = static_cast<int32_T>(sys_n);
  r.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    r[i] = 0.0;
  }
  q = sys_Ts * U[0];
  r[0] = x0[0] + q * muDoubleScalarCos(x0[2]);
  r[1] = x0[1] + q * muDoubleScalarSin(x0[2]);
  trueCount = 0;
  prev_i = x0[2] + sys_Ts * U[1];
  b = ((prev_i < -3.1415926535897931) || (prev_i > 3.1415926535897931));
  if (b) {
    trueCount = 1;
    if (muDoubleScalarIsNaN(prev_i + 3.1415926535897931) ||
        muDoubleScalarIsInf(prev_i + 3.1415926535897931)) {
      tmp_data = rtNaN;
    } else if (prev_i + 3.1415926535897931 == 0.0) {
      tmp_data = 0.0;
    } else {
      tmp_data =
          muDoubleScalarRem(prev_i + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (tmp_data == 0.0);
      if (!rEQ0) {
        q = muDoubleScalarAbs((prev_i + 3.1415926535897931) /
                              6.2831853071795862);
        rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                 2.2204460492503131E-16 * q);
      }
      if (rEQ0) {
        tmp_data = 0.0;
      } else if (tmp_data < 0.0) {
        tmp_data += 6.2831853071795862;
      }
    }
  }
  for (int32_T b_i{0}; b_i < trueCount; b_i++) {
    if ((tmp_data == 0.0) && (prev_i + 3.1415926535897931 > 0.0)) {
      tmp_data = 6.2831853071795862;
    }
  }
  if (b) {
    prev_i = tmp_data - 3.1415926535897931;
  }
  r[2] = prev_i;
  x_pred[0] = r[0];
  x_pred[1] = r[1];
  x_pred[2] = r[2];
  i = static_cast<int32_T>(N - 1.0);
  if (static_cast<int32_T>(N - 1.0) - 1 >= 0) {
    loop_ub = static_cast<int32_T>(sys_n);
  }
  for (int32_T b_i{0}; b_i < i; b_i++) {
    real_T curr_i;
    real_T input_i;
    prev_i = ((static_cast<real_T>(b_i) + 1.0) - 1.0) * 3.0;
    curr_i = (static_cast<real_T>(b_i) + 1.0) * 3.0;
    input_i = (static_cast<real_T>(b_i) + 1.0) * 2.0;
    r.set_size(loop_ub_tmp);
    for (trueCount = 0; trueCount < loop_ub; trueCount++) {
      r[trueCount] = 0.0;
    }
    real_T d;
    q = sys_Ts * U[static_cast<int32_T>(input_i + 1.0) - 1];
    d = x_pred[static_cast<int32_T>((prev_i + 1.0) + 2.0) - 1];
    r[0] = x_pred[static_cast<int32_T>(prev_i + 1.0) - 1] +
           q * muDoubleScalarCos(d);
    r[1] = x_pred[static_cast<int32_T>((prev_i + 1.0) + 1.0) - 1] +
           q * muDoubleScalarSin(d);
    prev_i = d + sys_Ts * U[static_cast<int32_T>((input_i + 1.0) + 1.0) - 1];
    trueCount = 0;
    if ((prev_i < -3.1415926535897931) || (prev_i > 3.1415926535897931)) {
      trueCount = 1;
      if (muDoubleScalarIsNaN(prev_i + 3.1415926535897931) ||
          muDoubleScalarIsInf(prev_i + 3.1415926535897931)) {
        tmp_data = rtNaN;
      } else if (prev_i + 3.1415926535897931 == 0.0) {
        tmp_data = 0.0;
      } else {
        tmp_data =
            muDoubleScalarRem(prev_i + 3.1415926535897931, 6.2831853071795862);
        rEQ0 = (tmp_data == 0.0);
        if (!rEQ0) {
          q = muDoubleScalarAbs((prev_i + 3.1415926535897931) /
                                6.2831853071795862);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          tmp_data = 0.0;
        } else if (tmp_data < 0.0) {
          tmp_data += 6.2831853071795862;
        }
      }
    }
    for (int32_T c_i{0}; c_i < trueCount; c_i++) {
      if ((tmp_data == 0.0) && (prev_i + 3.1415926535897931 > 0.0)) {
        tmp_data = 6.2831853071795862;
      }
    }
    if ((prev_i < -3.1415926535897931) || (prev_i > 3.1415926535897931)) {
      prev_i = tmp_data - 3.1415926535897931;
    }
    r[2] = prev_i;
    x_pred[static_cast<int32_T>(curr_i + 1.0) - 1] = r[0];
    x_pred[static_cast<int32_T>((curr_i + 1.0) + 1.0) - 1] = r[1];
    x_pred[static_cast<int32_T>((curr_i + 1.0) + 2.0) - 1] = r[2];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (stateEvolution.cpp)
