/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkLinearInputs.c
 *
 * Code generation for function 'checkLinearInputs'
 *
 */

/* Include files */
#include "checkLinearInputs.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
real_T checkLinearInputs(const real_T lb_data[], const int32_T lb_size[2],
                         const real_T ub_data[], const int32_T ub_size[2])
{
  real_T exitflag;
  boolean_T b;
  boolean_T b1;
  exitflag = rtInf;
  b = (lb_size[0] == 0);
  b1 = (lb_size[1] == 0);
  if ((!b) && (!b1) && ((ub_size[0] != 0) && (ub_size[1] != 0))) {
    int32_T k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 40)) {
      if (lb_data[k] > ub_data[k]) {
        exitflag = -2.0;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return exitflag;
}

/* End of code generation (checkLinearInputs.c) */
