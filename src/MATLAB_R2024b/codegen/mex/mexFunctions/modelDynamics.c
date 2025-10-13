/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modelDynamics.c
 *
 * Code generation for function 'modelDynamics'
 *
 */

/* Include files */
#include "modelDynamics.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void modelDynamics(const real_T x_k[3], const real_T u_k[2], real_T sys_n,
                   real_T sys_Ts, emxArray_real_T *x_k1)
{
  real_T unnamed_idx_0;
  real_T x_k1_tmp;
  real_T *x_k1_data;
  int32_T i;
  int32_T loop_ub_tmp;
  boolean_T b;
  emlrtMEXProfilingFunctionEntry((char_T *)modelDynamics_complete_name,
                                 isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  loop_ub_tmp = (int32_T)sys_n;
  i = x_k1->size[0];
  x_k1->size[0] = (int32_T)sys_n;
  emxEnsureCapacity_real_T(x_k1, i);
  x_k1_data = x_k1->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    x_k1_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(2, isMexOutdated);
  x_k1_tmp = sys_Ts * u_k[0];
  x_k1_data[0] = x_k[0] + x_k1_tmp * muDoubleScalarCos(x_k[2]);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  x_k1_data[1] = x_k[1] + x_k1_tmp * muDoubleScalarSin(x_k[2]);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  loop_ub_tmp = 0;
  unnamed_idx_0 = x_k[2] + sys_Ts * u_k[1];
  b = ((unnamed_idx_0 < -3.1415926535897931) ||
       (unnamed_idx_0 > 3.1415926535897931));
  if (b) {
    loop_ub_tmp = 1;
    if (muDoubleScalarIsNaN(unnamed_idx_0 + 3.1415926535897931) ||
        muDoubleScalarIsInf(unnamed_idx_0 + 3.1415926535897931)) {
      x_k1_tmp = rtNaN;
    } else if (unnamed_idx_0 + 3.1415926535897931 == 0.0) {
      x_k1_tmp = 0.0;
    } else {
      boolean_T rEQ0;
      x_k1_tmp = muDoubleScalarRem(unnamed_idx_0 + 3.1415926535897931,
                                   6.2831853071795862);
      rEQ0 = (x_k1_tmp == 0.0);
      if (!rEQ0) {
        real_T q;
        q = muDoubleScalarAbs((unnamed_idx_0 + 3.1415926535897931) /
                              6.2831853071795862);
        rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                 2.2204460492503131E-16 * q);
      }
      if (rEQ0) {
        x_k1_tmp = 0.0;
      } else if (x_k1_tmp < 0.0) {
        x_k1_tmp += 6.2831853071795862;
      }
    }
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    if ((x_k1_tmp == 0.0) && (unnamed_idx_0 + 3.1415926535897931 > 0.0)) {
      x_k1_tmp = 6.2831853071795862;
    }
  }
  if (b) {
    unnamed_idx_0 = x_k1_tmp - 3.1415926535897931;
  }
  x_k1_data[2] = unnamed_idx_0;
  emlrtMEXProfilingStatement(5, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (modelDynamics.c) */
