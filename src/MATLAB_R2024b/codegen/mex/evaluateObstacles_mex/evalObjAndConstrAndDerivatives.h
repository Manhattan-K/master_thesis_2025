/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstrAndDerivatives.h
 *
 * Code generation for function 'evalObjAndConstrAndDerivatives'
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
real_T b_evalObjAndConstrAndDerivative(
    int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const i_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status);

real_T evalObjAndConstrAndDerivatives(
    int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const h_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status);

/* End of code generation (evalObjAndConstrAndDerivatives.h) */
