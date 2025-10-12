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
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
              const int32_T lb_size[2], const real_T ub_data[],
              const int32_T ub_size[2], j_struct_T *TrialState,
              l_struct_T *MeritFunction,
              const r_coder_internal_stickyStruct *FcnEvaluator,
              p_struct_T *FiniteDifferences, e_struct_T *memspace,
              k_struct_T *WorkingSet, f_struct_T *QRManager,
              n_struct_T *CholManager, d_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void d_driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
              const int32_T lb_size[2], const real_T ub_data[],
              const int32_T ub_size[2], j_struct_T *TrialState,
              l_struct_T *MeritFunction,
              const bb_coder_internal_stickyStruct *FcnEvaluator,
              q_struct_T *FiniteDifferences, e_struct_T *memspace,
              k_struct_T *WorkingSet, f_struct_T *QRManager,
              n_struct_T *CholManager, d_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
            const int32_T lb_size[2], const real_T ub_data[],
            const int32_T ub_size[2], j_struct_T *TrialState,
            l_struct_T *MeritFunction,
            const i_coder_internal_stickyStruct *FcnEvaluator,
            m_struct_T *FiniteDifferences, e_struct_T *memspace,
            k_struct_T *WorkingSet, f_struct_T *QRManager,
            n_struct_T *CholManager, d_struct_T *QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

/* End of code generation (driver.h) */
