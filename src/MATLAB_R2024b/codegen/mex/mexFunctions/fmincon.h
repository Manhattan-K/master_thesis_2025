/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fmincon.h
 *
 * Code generation for function 'fmincon'
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
real_T b_fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
                 real_T fun_workspace_sys_n, real_T fun_workspace_sys_m,
                 real_T fun_workspace_sys_Ts,
                 const struct1_T *fun_workspace_robotParams,
                 real_T fun_workspace_N, real_T x0[40], const real_T lb[40],
                 const real_T ub[40], const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt);

real_T c_fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
                 real_T fun_workspace_sys_n, real_T fun_workspace_sys_m,
                 real_T fun_workspace_sys_Ts, real_T fun_workspace_N,
                 const struct1_T *fun_workspace_robotParams, real_T x0[40],
                 const real_T lb[40], const real_T ub[40],
                 const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt);

real_T fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
               real_T fun_workspace_sys_n, real_T fun_workspace_sys_Ts,
               real_T fun_workspace_N,
               const real_T fun_workspace_X_L_stacked[60],
               const struct2_T *fun_workspace_robotParams, real_T x0[40],
               const real_T lb[40], const real_T ub[40],
               const real_T nonlcon_workspace_x0[3],
               const struct5_T *nonlcon_workspace_obstacles,
               real_T nonlcon_workspace_N,
               const struct3_T nonlcon_workspace_sys, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               char_T output_algorithm[3], real_T *output_constrviolation,
               real_T *output_stepsize, real_T *output_lssteplength,
               real_T *output_firstorderopt);

/* End of code generation (fmincon.h) */
