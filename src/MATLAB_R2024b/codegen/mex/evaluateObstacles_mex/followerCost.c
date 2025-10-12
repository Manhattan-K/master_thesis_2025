/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * followerCost.c
 *
 * Code generation for function 'followerCost'
 *
 */

/* Include files */
#include "followerCost.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void binary_expand_op_2(real_T in1[20], const emxArray_real_T *in2,
                        const real_T in3[20])
{
  const real_T *in2_data;
  int32_T i;
  int32_T stride_0_1;
  in2_data = in2->data;
  stride_0_1 = (in2->size[1] != 1);
  for (i = 0; i < 20; i++) {
    in1[i] = in2_data[i * stride_0_1] - in3[i];
  }
}

/* End of code generation (followerCost.c) */
