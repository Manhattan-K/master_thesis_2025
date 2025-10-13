/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * followerMPCandUpdate.h
 *
 * Code generation for function 'followerMPCandUpdate'
 *
 */

#pragma once

/* Include files */
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void followerMPCandUpdate(emlrtCTX aTLS, mexFunctionsStackData *SD,
                          const struct3_T *sys, const real_T x0[3],
                          const real_T X_L_stacked[60], real_T N,
                          const struct2_T *robotParams,
                          const struct5_T *obstacles, const real_T U_f_old[40],
                          emxArray_real_T *p_tp1, emxArray_real_T *X_F,
                          struct6_T *b_error, real_T u_t[2], real_T u_opt[40]);

real_T followerMPCandUpdate_anonFcn1(
    emlrtCTX aTLS, const real_T x0[3], real_T sys_n, real_T sys_Ts, real_T N,
    const real_T X_L_stacked[60], const real_T robotParams_Px[6],
    const real_T robotParams_d_FL_sq[20], real_T robotParams_C,
    const real_T robotParams_beta_N[20], const real_T U[40]);

int32_T followerMPCandUpdate_anonFcn2(emlrtCTX aTLS, const real_T x0[3],
                                      real_T obstacles_M_f,
                                      const emxArray_real_T *obstacles_A_bar_f,
                                      const real_T obstacles_B_bar_f_data[],
                                      int32_T obstacles_B_bar_f_size, real_T N,
                                      real_T sys_n, real_T sys_Ts,
                                      const real_T U[40],
                                      real_T varargout_1_data[]);

/* End of code generation (followerMPCandUpdate.h) */
