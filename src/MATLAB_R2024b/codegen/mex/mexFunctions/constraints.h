//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constraints.h
//
// Code generation for function 'constraints'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder {
class b_anonymous_function;

class d_anonymous_function;

namespace internal {
class bb_stickyStruct;

class i_stickyStruct;

class r_stickyStruct;

} // namespace internal
} // namespace coder

// Function Declarations
void binary_expand_op(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                      const int32_T &in2_size, const real_T in3_data[],
                      const int32_T &in3_size);

void binary_expand_op_10(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                         const int32_T &in2_size,
                         const coder::internal::i_stickyStruct &in3);

void binary_expand_op_11(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                         const int32_T &in2_size,
                         const coder::internal::r_stickyStruct &in3);

void binary_expand_op_6(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::b_anonymous_function &in3);

void binary_expand_op_7(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::d_anonymous_function &in3);

void binary_expand_op_8(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::d_anonymous_function &in3);

void binary_expand_op_9(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::internal::bb_stickyStruct &in3);

// End of code generation (constraints.h)
