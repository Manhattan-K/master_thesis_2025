//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// followerCost.cpp
//
// Code generation for function 'followerCost'
//

// Include files
#include "followerCost.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op_2(real_T in1[20], const coder::array<real_T, 2U> &in2,
                        const real_T in3[20])
{
  int32_T stride_0_1;
  stride_0_1 = (in2.size(1) != 1);
  for (int32_T i{0}; i < 20; i++) {
    in1[i] = in2[i * stride_0_1] - in3[i];
  }
}

// End of code generation (followerCost.cpp)
