/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.h
 *
 * Code generation for function 'driver'
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
void c_driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
              const real_T ub[40], h_struct_T *TrialState,
              j_struct_T *MeritFunction,
              const s_coder_internal_stickyStruct *FcnEvaluator,
              o_struct_T *FiniteDifferences, f_struct_T *memspace,
              i_struct_T *WorkingSet, g_struct_T *QRManager,
              m_struct_T *CholManager, e_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void d_driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
              const real_T ub[40], h_struct_T *TrialState,
              j_struct_T *MeritFunction,
              const bb_coder_internal_stickyStruct *FcnEvaluator,
              p_struct_T *FiniteDifferences, f_struct_T *memspace,
              i_struct_T *WorkingSet, g_struct_T *QRManager,
              m_struct_T *CholManager, e_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
            const real_T ub[40], h_struct_T *TrialState,
            j_struct_T *MeritFunction,
            const k_coder_internal_stickyStruct *FcnEvaluator,
            l_struct_T *FiniteDifferences, f_struct_T *memspace,
            i_struct_T *WorkingSet, g_struct_T *QRManager,
            m_struct_T *CholManager, e_struct_T *QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

/* End of code generation (driver.h) */
