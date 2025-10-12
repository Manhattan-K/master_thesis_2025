/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * leaderMPCandUpdate.h
 *
 * Code generation for function 'leaderMPCandUpdate'
 *
 */

#pragma once

/* Include files */
#include "evaluateObstacles_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void leaderMPCandUpdate(evaluateObstacles_mexStackData *SD,
                        const struct3_T *sys, const real_T x0[3], real_T N,
                        const struct1_T *robotParams,
                        const struct5_T *obstacles, const real_T U_l_old[40],
                        emxArray_real_T *p_tp1, emxArray_real_T *X_L,
                        emxArray_real_T *X_L_stacked, struct6_T *c_error,
                        real_T u_t[2], real_T u_opt[40]);

real_T leaderMPCandUpdate_anonFcn1(const real_T x0[3], real_T sys_n,
                                   real_T sys_Ts, const real_T robotParams_W[9],
                                   const real_T robotParams_W_hat[3600],
                                   const real_T robotParams_R_hat[1600],
                                   real_T N, const real_T U[40]);

/* End of code generation (leaderMPCandUpdate.h) */
