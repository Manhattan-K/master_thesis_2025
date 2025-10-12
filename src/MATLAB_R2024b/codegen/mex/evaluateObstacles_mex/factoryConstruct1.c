/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct1.c
 *
 * Code generation for function 'factoryConstruct1'
 *
 */

/* Include files */
#include "factoryConstruct1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int32_T b_factoryConstruct(int32_T MaxVars, int32_T *obj_Hx_size,
                           boolean_T *obj_hasLinear, int32_T *obj_nvar,
                           int32_T *obj_maxVar, real_T *obj_beta,
                           real_T *obj_rho, int32_T *obj_objtype,
                           int32_T *obj_prev_objtype, int32_T *obj_prev_nvar,
                           boolean_T *obj_prev_hasLinear,
                           real_T *obj_gammaScalar)
{
  int32_T obj_grad_size;
  obj_grad_size = MaxVars;
  *obj_Hx_size = MaxVars - 1;
  *obj_hasLinear = false;
  *obj_nvar = 0;
  *obj_maxVar = MaxVars;
  *obj_beta = 0.0;
  *obj_rho = 0.0;
  *obj_objtype = 3;
  *obj_prev_objtype = 3;
  *obj_prev_nvar = 0;
  *obj_prev_hasLinear = false;
  *obj_gammaScalar = 0.0;
  return obj_grad_size;
}

/* End of code generation (factoryConstruct1.c) */
