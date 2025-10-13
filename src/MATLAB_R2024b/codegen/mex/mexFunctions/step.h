/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.h
 *
 * Code generation for function 'step'
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
void step(emlrtCTX aTLS, mexFunctionsStackData *SD, struct_T *stepFlags,
          real_T Hessian[1600], const real_T lb[40], const real_T ub[40],
          h_struct_T *TrialState, j_struct_T *MeritFunction,
          f_struct_T *memspace, i_struct_T *WorkingSet, g_struct_T *QRManager,
          m_struct_T *CholManager, e_struct_T *QPObjective,
          n_struct_T *qpoptions);

/* End of code generation (step.h) */
