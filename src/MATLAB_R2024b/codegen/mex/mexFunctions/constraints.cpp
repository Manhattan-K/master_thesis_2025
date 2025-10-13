//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constraints.cpp
//
// Code generation for function 'constraints'
//

// Include files
#include "constraints.h"
#include "anonymous_function.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                      const int32_T &in2_size, const real_T in3_data[],
                      const int32_T &in3_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3_size == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3_size;
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2_size != 1);
  stride_1_0 = (in3_size != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
  }
}

void binary_expand_op_10(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                         const int32_T &in2_size,
                         const coder::internal::i_stickyStruct &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
          .size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
            .size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.next.next.next.next.next.next.next.value.workspace.obstacles
                    .B_bar_l.size[0] != 1);
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
          .size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.data[i1 * stride_1_0];
  }
}

void binary_expand_op_11(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                         const int32_T &in2_size,
                         const coder::internal::r_stickyStruct &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
          .size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
            .size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.next.next.next.next.next.next.next.value.workspace.obstacles
                    .B_bar_l.size[0] != 1);
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_l
          .size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_l.data[i1 * stride_1_0];
  }
}

void binary_expand_op_6(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::b_anonymous_function &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.workspace.obstacles.B_bar_f.size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.workspace.obstacles.B_bar_f.size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.workspace.obstacles.B_bar_f.size[0] != 1);
  if (in3.workspace.obstacles.B_bar_f.size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.workspace.obstacles.B_bar_f.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.workspace.obstacles.B_bar_f.data[i1 * stride_1_0];
  }
}

void binary_expand_op_7(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::d_anonymous_function &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.workspace.obstacles.B_bar_l.size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.workspace.obstacles.B_bar_l.size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.workspace.obstacles.B_bar_l.size[0] != 1);
  if (in3.workspace.obstacles.B_bar_l.size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.workspace.obstacles.B_bar_l.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.workspace.obstacles.B_bar_l.data[i1 * stride_1_0];
  }
}

void binary_expand_op_8(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::d_anonymous_function &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.workspace.obstacles.B_bar_l.size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.workspace.obstacles.B_bar_l.size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.workspace.obstacles.B_bar_l.size[0] != 1);
  if (in3.workspace.obstacles.B_bar_l.size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.workspace.obstacles.B_bar_l.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.workspace.obstacles.B_bar_l.data[i1 * stride_1_0];
  }
}

void binary_expand_op_9(coder::array<real_T, 1U> &in1, const real_T in2_data[],
                        const int32_T &in2_size,
                        const coder::internal::bb_stickyStruct &in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_f
          .size[0] == 1) {
    i = in2_size;
  } else {
    i = in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_f
            .size[0];
  }
  in1.set_size(i);
  i = (in2_size != 1);
  stride_1_0 = (in3.next.next.next.next.next.next.next.value.workspace.obstacles
                    .B_bar_f.size[0] != 1);
  if (in3.next.next.next.next.next.next.next.value.workspace.obstacles.B_bar_f
          .size[0] == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_f.size[0];
  }
  for (int32_T i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = in2_data[i1 * i] -
              in3.next.next.next.next.next.next.next.value.workspace.obstacles
                  .B_bar_f.data[i1 * stride_1_0];
  }
}

// End of code generation (constraints.cpp)
