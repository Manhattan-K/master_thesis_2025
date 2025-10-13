/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normal.h
 *
 * Code generation for function 'normal'
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
void normal(emlrtCTX aTLS, mexFunctionsStackData *SD,
            const real_T Hessian[1600], const real_T grad_data[],
            h_struct_T *TrialState, j_struct_T *MeritFunction,
            f_struct_T *memspace, i_struct_T *WorkingSet, g_struct_T *QRManager,
            m_struct_T *CholManager, e_struct_T *QPObjective,
            const n_struct_T *qpoptions, struct_T *stepFlags);

/* End of code generation (normal.h) */
