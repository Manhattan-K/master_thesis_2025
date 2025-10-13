//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_mtimes_helper.cpp
//
// Code generation for function 'eml_mtimes_helper'
//

// Include files
#include "eml_mtimes_helper.h"
#include "mexFunctions_data.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op_1(coder::array<real_T, 2U> &in1, const real_T in2[6],
                        const coder::array<real_T, 1U> &in3,
                        const real_T in4[3], int32_T in5, const real_T in6[2])
{
  coder::array<real_T, 2U> c_in4;
  coder::array<real_T, 1U> b_in3;
  coder::array<real_T, 1U> b_in4;
  int32_T loop_ub;
  int32_T stride_0_0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  b_in4.set_size(in5 + 4);
  b_in4[0] = in4[0];
  b_in4[1] = in4[1];
  b_in4[2] = in4[2];
  for (int32_T i{0}; i <= in5; i++) {
    b_in4[i + 3] = in3[i];
  }
  loop_ub = b_in4.size(0);
  b_in3.set_size(b_in4.size(0));
  stride_0_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in3[i] = in3[i * stride_0_0] - b_in4[i];
  }
  b_in4.set_size(loop_ub);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in4[i] = b_in3[i];
  }
  loop_ub = static_cast<int32_T>(in6[0]);
  stride_0_0 = static_cast<int32_T>(in6[1]);
  c_in4 = b_in4.reshape(loop_ub, stride_0_0);
  coder::internal::blas::mtimes(in2, c_in4, in1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void binary_expand_op_3(coder::array<real_T, 2U> &in1, const real_T in2[6],
                        const real_T in3[60],
                        const coder::array<real_T, 1U> &in4,
                        const real_T in5[2])
{
  coder::array<real_T, 2U> c_in3;
  real_T b_in3[60];
  int32_T in5_idx_1;
  int32_T stride_0_0;
  stride_0_0 = (in4.size(0) != 1);
  for (in5_idx_1 = 0; in5_idx_1 < 60; in5_idx_1++) {
    b_in3[in5_idx_1] = in3[in5_idx_1] - in4[in5_idx_1 * stride_0_0];
  }
  stride_0_0 = static_cast<int32_T>(in5[0]);
  in5_idx_1 = static_cast<int32_T>(in5[1]);
  c_in3.set(&b_in3[0], stride_0_0, in5_idx_1);
  coder::internal::blas::mtimes(in2, c_in3, in1);
}

// End of code generation (eml_mtimes_helper.cpp)
