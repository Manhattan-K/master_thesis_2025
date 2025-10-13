/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * phaseone.h
 *
 * Code generation for function 'phaseone'
 *
 */

#pragma once

/* Include files */
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void phaseone(const real_T H[1600], const real_T f_data[], h_struct_T *solution,
              f_struct_T *memspace, i_struct_T *workingset,
              g_struct_T *qrmanager, m_struct_T *cholmanager,
              e_struct_T *objective, const char_T options_SolverName[7],
              const n_struct_T *runTimeOptions);

/* End of code generation (phaseone.h) */
