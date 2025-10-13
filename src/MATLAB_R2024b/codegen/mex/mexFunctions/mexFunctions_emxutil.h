/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_emxutil.h
 *
 * Code generation for function 'mexFunctions_emxutil'
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
void ab_emxFreeStruct_coder_internal(bb_coder_internal_stickyStruct *pStruct);

void ab_emxInitStruct_coder_internal(t_coder_internal_stickyStruct *pStruct);

void c_emxFreeStruct_anonymous_funct(d_anonymous_function *pStruct);

void c_emxFreeStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct);

void c_emxInitStruct_anonymous_funct(d_anonymous_function *pStruct);

void c_emxInitStruct_coder_internal_(k_coder_internal_stickyStruct *pStruct);

void d_emxFreeStruct_anonymous_funct(d_anonymous_function *pStruct);

void d_emxFreeStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct);

void d_emxInitStruct_anonymous_funct(d_anonymous_function *pStruct);

void d_emxInitStruct_coder_internal_(j_coder_internal_stickyStruct *pStruct);

void e_emxFreeStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct);

void e_emxInitStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct);

void emxCopyMatrix_int32_T1(int32_T dst[5], const int32_T src[5]);

void emxCopyMatrix_int32_T2(int32_T dst[6], const int32_T src[6]);

void emxCopyStruct_struct5_T(struct5_T *dst, const struct5_T *src);

void emxCopyStruct_struct_T(i_struct_T *dst, const i_struct_T *src);

void emxCopy_boolean_T_8481(emxArray_boolean_T_8481 *dst,
                            const emxArray_boolean_T_8481 *src);

void emxCopy_int32_T_4241(emxArray_int32_T_4241 *dst,
                          const emxArray_int32_T_4241 *src);

void emxCopy_int32_T_8481(emxArray_int32_T_8481 *dst,
                          const emxArray_int32_T_8481 *src);

void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

void emxCopy_real_T_0(emxArray_real_T_0 *dst, const emxArray_real_T_0 *src);

void emxCopy_real_T_4200(emxArray_real_T_4200 *dst,
                         const emxArray_real_T_4200 *src);

void emxCopy_real_T_4241(emxArray_real_T_4241 *dst,
                         const emxArray_real_T_4241 *src);

void emxCopy_real_T_800(emxArray_real_T_800 *dst,
                        const emxArray_real_T_800 *src);

void emxEnsureCapacity_ptrdiff_t(emxArray_ptrdiff_t *emxArray,
                                 int32_T oldNumel);

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);

void emxFreeStruct_struct4_T(struct4_T *pStruct);

void emxFreeStruct_struct5_T(struct5_T *pStruct);

void emxFreeStruct_struct_T(i_struct_T *pStruct);

void emxFreeStruct_struct_T1(h_struct_T *pStruct);

void emxFreeStruct_struct_T2(k_struct_T *pStruct);

void emxFreeStruct_struct_T3(f_struct_T *pStruct);

void emxFreeStruct_struct_T4(l_struct_T *pStruct);

void emxFreeStruct_struct_T5(g_struct_T *pStruct);

void emxFreeStruct_struct_T6(m_struct_T *pStruct);

void emxFreeStruct_struct_T7(k_struct_T *pStruct);

void emxFreeStruct_struct_T8(o_struct_T *pStruct);

void emxFreeStruct_struct_T9(p_struct_T *pStruct);

void emxFree_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray);

void emxFree_real_T(emxArray_real_T **pEmxArray);

void emxInitStruct_struct4_T(struct4_T *pStruct);

void emxInitStruct_struct5_T(struct5_T *pStruct);

void emxInitStruct_struct_T(i_struct_T *pStruct);

void emxInitStruct_struct_T1(h_struct_T *pStruct);

void emxInitStruct_struct_T2(k_struct_T *pStruct);

void emxInitStruct_struct_T3(f_struct_T *pStruct);

void emxInitStruct_struct_T4(l_struct_T *pStruct);

void emxInitStruct_struct_T5(g_struct_T *pStruct);

void emxInitStruct_struct_T6(m_struct_T *pStruct);

void emxInitStruct_struct_T7(k_struct_T *pStruct);

void emxInitStruct_struct_T8(o_struct_T *pStruct);

void emxInitStruct_struct_T9(p_struct_T *pStruct);

void emxInit_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray);

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);

void f_emxFreeStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct);

void f_emxInitStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct);

void g_emxFreeStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct);

void g_emxInitStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct);

void h_emxFreeStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct);

void h_emxInitStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct);

void i_emxFreeStruct_coder_internal_(j_coder_internal_stickyStruct *pStruct);

void i_emxInitStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct);

void j_emxFreeStruct_coder_internal_(k_coder_internal_stickyStruct *pStruct);

void j_emxInitStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct);

void k_emxFreeStruct_coder_internal_(l_coder_internal_stickyStruct *pStruct);

void k_emxInitStruct_coder_internal_(s_coder_internal_stickyStruct *pStruct);

void l_emxFreeStruct_coder_internal_(m_coder_internal_stickyStruct *pStruct);

void l_emxInitStruct_coder_internal_(r_coder_internal_stickyStruct *pStruct);

void m_emxFreeStruct_coder_internal_(n_coder_internal_stickyStruct *pStruct);

void m_emxInitStruct_coder_internal_(q_coder_internal_stickyStruct *pStruct);

void n_emxFreeStruct_coder_internal_(o_coder_internal_stickyStruct *pStruct);

void n_emxInitStruct_coder_internal_(p_coder_internal_stickyStruct *pStruct);

void o_emxFreeStruct_coder_internal_(p_coder_internal_stickyStruct *pStruct);

void o_emxInitStruct_coder_internal_(o_coder_internal_stickyStruct *pStruct);

void p_emxFreeStruct_coder_internal_(q_coder_internal_stickyStruct *pStruct);

void p_emxInitStruct_coder_internal_(n_coder_internal_stickyStruct *pStruct);

void q_emxFreeStruct_coder_internal_(r_coder_internal_stickyStruct *pStruct);

void q_emxInitStruct_coder_internal_(m_coder_internal_stickyStruct *pStruct);

void r_emxFreeStruct_coder_internal_(s_coder_internal_stickyStruct *pStruct);

void r_emxInitStruct_coder_internal_(l_coder_internal_stickyStruct *pStruct);

void s_emxFreeStruct_coder_internal_(t_coder_internal_stickyStruct *pStruct);

void s_emxInitStruct_coder_internal_(bb_coder_internal_stickyStruct *pStruct);

void t_emxFreeStruct_coder_internal_(u_coder_internal_stickyStruct *pStruct);

void t_emxInitStruct_coder_internal_(ab_coder_internal_stickyStruct *pStruct);

void u_emxFreeStruct_coder_internal_(v_coder_internal_stickyStruct *pStruct);

void u_emxInitStruct_coder_internal_(y_coder_internal_stickyStruct *pStruct);

void v_emxFreeStruct_coder_internal_(w_coder_internal_stickyStruct *pStruct);

void v_emxInitStruct_coder_internal_(x_coder_internal_stickyStruct *pStruct);

void w_emxFreeStruct_coder_internal_(x_coder_internal_stickyStruct *pStruct);

void w_emxInitStruct_coder_internal_(w_coder_internal_stickyStruct *pStruct);

void x_emxFreeStruct_coder_internal_(y_coder_internal_stickyStruct *pStruct);

void x_emxInitStruct_coder_internal_(v_coder_internal_stickyStruct *pStruct);

void y_emxFreeStruct_coder_internal_(ab_coder_internal_stickyStruct *pStruct);

void y_emxInitStruct_coder_internal_(u_coder_internal_stickyStruct *pStruct);

/* End of code generation (mexFunctions_emxutil.h) */
