/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.h
 *
 * Code generation for function 'driver1'
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
void b_driver(const real_T H[1600], const real_T f_data[], j_struct_T *solution,
              e_struct_T *memspace, k_struct_T *workingset,
              f_struct_T *qrmanager, n_struct_T *cholmanager,
              d_struct_T *objective, const o_struct_T *options,
              const o_struct_T *runTimeOptions);

/* End of code generation (driver1.h) */
