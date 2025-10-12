/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evaluateObstacles_mex_emxutil.c
 *
 * Code generation for function 'evaluateObstacles_mex_emxutil'
 *
 */

/* Include files */
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void ab_emxFreeStruct_coder_internal(bb_coder_internal_stickyStruct *pStruct)
{
  y_emxFreeStruct_coder_internal_(&pStruct->next);
}

void ab_emxInitStruct_coder_internal(v_coder_internal_stickyStruct *pStruct)
{
  bb_emxInitStruct_coder_internal(&pStruct->next);
}

void bb_emxInitStruct_coder_internal(u_coder_internal_stickyStruct *pStruct)
{
  cb_emxInitStruct_coder_internal(&pStruct->next);
}

void c_emxFreeStruct_anonymous_funct(anonymous_function *pStruct)
{
  emxFreeStruct_struct_T2(&pStruct->workspace);
}

void c_emxFreeStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_anonymous_funct(&pStruct->value);
}

void c_emxInitStruct_anonymous_funct(anonymous_function *pStruct)
{
  emxInitStruct_struct_T2(&pStruct->workspace);
}

void c_emxInitStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct)
{
  d_emxInitStruct_coder_internal_(&pStruct->next);
}

void cb_emxInitStruct_coder_internal(t_coder_internal_stickyStruct *pStruct)
{
  f_emxInitStruct_anonymous_funct(&pStruct->value);
  db_emxInitStruct_coder_internal(&pStruct->next);
}

void d_emxFreeStruct_anonymous_funct(c_anonymous_function *pStruct)
{
  emxFreeStruct_struct_T7(&pStruct->workspace);
}

void d_emxFreeStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_coder_internal_(&pStruct->next);
}

void d_emxInitStruct_anonymous_funct(b_anonymous_function *pStruct)
{
  emxInitStruct_struct_T3(&pStruct->workspace);
}

void d_emxInitStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct)
{
  e_emxInitStruct_coder_internal_(&pStruct->next);
}

void db_emxInitStruct_coder_internal(s_coder_internal_stickyStruct *pStruct)
{
  g_emxInitStruct_anonymous_funct(&pStruct->value);
}

void e_emxFreeStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct)
{
  d_emxFreeStruct_coder_internal_(&pStruct->next);
}

void e_emxInitStruct_anonymous_funct(d_anonymous_function *pStruct)
{
  emxInitStruct_struct_T9(&pStruct->workspace);
}

void e_emxInitStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct)
{
  f_emxInitStruct_coder_internal_(&pStruct->next);
}

void emxCopyMatrix_int32_T1(int32_T dst[5], const int32_T src[5])
{
  int32_T i;
  for (i = 0; i < 5; i++) {
    dst[i] = src[i];
  }
}

void emxCopyMatrix_int32_T2(int32_T dst[6], const int32_T src[6])
{
  int32_T i;
  for (i = 0; i < 6; i++) {
    dst[i] = src[i];
  }
}

void emxCopyStruct_struct5_T(struct5_T *dst, const struct5_T *src)
{
  dst->M_l = src->M_l;
  dst->M_f = src->M_f;
  emxCopy_real_T(&dst->A_bar_l, &src->A_bar_l);
  emxCopy_real_T_4200(&dst->B_bar_l, &src->B_bar_l);
  emxCopy_real_T(&dst->A_bar_f, &src->A_bar_f);
  emxCopy_real_T_800(&dst->B_bar_f, &src->B_bar_f);
}

void emxCopyStruct_struct_T(k_struct_T *dst, const k_struct_T *src)
{
  dst->mConstr = src->mConstr;
  dst->mConstrOrig = src->mConstrOrig;
  dst->mConstrMax = src->mConstrMax;
  dst->nVar = src->nVar;
  dst->nVarOrig = src->nVarOrig;
  dst->nVarMax = src->nVarMax;
  dst->ldA = src->ldA;
  emxCopy_real_T(&dst->Aineq, &src->Aineq);
  emxCopy_real_T_4200(&dst->bineq, &src->bineq);
  emxCopy_real_T_0(&dst->Aeq, &src->Aeq);
  emxCopy_real_T_4241(&dst->lb, &src->lb);
  emxCopy_real_T_4241(&dst->ub, &src->ub);
  emxCopy_int32_T_4241(&dst->indexLB, &src->indexLB);
  emxCopy_int32_T_4241(&dst->indexUB, &src->indexUB);
  emxCopy_int32_T_4241(&dst->indexFixed, &src->indexFixed);
  dst->mEqRemoved = src->mEqRemoved;
  emxCopy_real_T(&dst->ATwset, &src->ATwset);
  emxCopy_real_T(&dst->bwset, &src->bwset);
  dst->nActiveConstr = src->nActiveConstr;
  emxCopy_real_T(&dst->maxConstrWorkspace, &src->maxConstrWorkspace);
  emxCopyMatrix_int32_T1(dst->sizes, src->sizes);
  emxCopyMatrix_int32_T1(dst->sizesNormal, src->sizesNormal);
  emxCopyMatrix_int32_T1(dst->sizesPhaseOne, src->sizesPhaseOne);
  emxCopyMatrix_int32_T1(dst->sizesRegularized, src->sizesRegularized);
  emxCopyMatrix_int32_T1(dst->sizesRegPhaseOne, src->sizesRegPhaseOne);
  emxCopyMatrix_int32_T2(dst->isActiveIdx, src->isActiveIdx);
  emxCopyMatrix_int32_T2(dst->isActiveIdxNormal, src->isActiveIdxNormal);
  emxCopyMatrix_int32_T2(dst->isActiveIdxPhaseOne, src->isActiveIdxPhaseOne);
  emxCopyMatrix_int32_T2(dst->isActiveIdxRegularized,
                         src->isActiveIdxRegularized);
  emxCopyMatrix_int32_T2(dst->isActiveIdxRegPhaseOne,
                         src->isActiveIdxRegPhaseOne);
  emxCopy_boolean_T_14801(&dst->isActiveConstr, &src->isActiveConstr);
  emxCopy_int32_T_14801(&dst->Wid, &src->Wid);
  emxCopy_int32_T_14801(&dst->Wlocalidx, &src->Wlocalidx);
  emxCopyMatrix_int32_T1(dst->nWConstr, src->nWConstr);
  dst->probType = src->probType;
  dst->SLACK0 = src->SLACK0;
}

void emxCopy_boolean_T_14801(emxArray_boolean_T_14801 *dst,
                             const emxArray_boolean_T_14801 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0],
           (uint32_T)numElSrc * sizeof(boolean_T));
  }
}

void emxCopy_int32_T_14801(emxArray_int32_T_14801 *dst,
                           const emxArray_int32_T_14801 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0], (uint32_T)numElSrc * sizeof(int32_T));
  }
}

void emxCopy_int32_T_4241(emxArray_int32_T_4241 *dst,
                          const emxArray_int32_T_4241 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0], (uint32_T)numElSrc * sizeof(int32_T));
  }
}

void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int32_T i;
  int32_T numElDst;
  int32_T numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxCopy_real_T_0(emxArray_real_T_0 *dst, const emxArray_real_T_0 *src)
{
  dst->size[0] = src->size[0];
}

void emxCopy_real_T_4200(emxArray_real_T_4200 *dst,
                         const emxArray_real_T_4200 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0], (uint32_T)numElSrc * sizeof(real_T));
  }
}

void emxCopy_real_T_4241(emxArray_real_T_4241 *dst,
                         const emxArray_real_T_4241 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0], (uint32_T)numElSrc * sizeof(real_T));
  }
}

void emxCopy_real_T_800(emxArray_real_T_800 *dst,
                        const emxArray_real_T_800 *src)
{
  int32_T numElSrc;
  numElSrc = src->size[0];
  dst->size[0] = src->size[0];
  if (numElSrc - 1 >= 0) {
    memcpy(&dst->data[0], &src->data[0], (uint32_T)numElSrc * sizeof(real_T));
  }
}

void emxEnsureCapacity_ptrdiff_t(emxArray_ptrdiff_t *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(ptrdiff_t));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(ptrdiff_t) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (ptrdiff_t *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_struct4_T(struct4_T *pStruct)
{
  emxFree_real_T(&pStruct->A_bar_l);
  emxFree_real_T(&pStruct->B_bar_l);
  emxFree_real_T(&pStruct->A_bar_f);
  emxFree_real_T(&pStruct->B_bar_f);
}

void emxFreeStruct_struct5_T(struct5_T *pStruct)
{
  emxFree_real_T(&pStruct->A_bar_l);
  emxFree_real_T(&pStruct->A_bar_f);
}

void emxFreeStruct_struct_T(k_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->Aineq);
  emxFree_real_T(&pStruct->ATwset);
  emxFree_real_T(&pStruct->bwset);
  emxFree_real_T(&pStruct->maxConstrWorkspace);
}

void emxFreeStruct_struct_T1(j_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->lambdasqp);
  emxFree_real_T(&pStruct->lambdaStopTest);
  emxFree_real_T(&pStruct->lambdaStopTestPrev);
  emxFree_real_T(&pStruct->JacCineqTrans_old);
  emxFree_real_T(&pStruct->lambda);
}

void emxFreeStruct_struct_T2(b_struct_T *pStruct)
{
  emxFreeStruct_struct5_T(&pStruct->obstacles);
}

void emxFreeStruct_struct_T3(m_struct_T *pStruct)
{
  c_emxFreeStruct_anonymous_funct(&pStruct->nonlin);
}

void emxFreeStruct_struct_T4(e_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->workspace_float);
}

void emxFreeStruct_struct_T5(f_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->QR);
  emxFree_real_T(&pStruct->Q);
  emxFree_real_T(&pStruct->tau);
}

void emxFreeStruct_struct_T6(n_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->FMat);
}

void emxFreeStruct_struct_T7(g_struct_T *pStruct)
{
  emxFreeStruct_struct5_T(&pStruct->obstacles);
}

void emxFreeStruct_struct_T8(p_struct_T *pStruct)
{
  d_emxFreeStruct_anonymous_funct(&pStruct->nonlin);
}

void emxFreeStruct_struct_T9(q_struct_T *pStruct)
{
  d_emxFreeStruct_anonymous_funct(&pStruct->nonlin);
}

void emxFree_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray)
{
  if (*pEmxArray != (emxArray_ptrdiff_t *)NULL) {
    if (((*pEmxArray)->data != (ptrdiff_t *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_ptrdiff_t *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  pStruct->lb.size[0] = 0;
  pStruct->lb.size[1] = 0;
  pStruct->ub.size[0] = 0;
  pStruct->ub.size[1] = 0;
}

void emxInitStruct_struct2_T(struct2_T *pStruct)
{
  pStruct->lb.size[0] = 0;
  pStruct->lb.size[1] = 0;
  pStruct->ub.size[0] = 0;
  pStruct->ub.size[1] = 0;
}

void emxInitStruct_struct4_T(struct4_T *pStruct)
{
  emxInit_real_T(&pStruct->A_bar_l, 2);
  emxInit_real_T(&pStruct->B_bar_l, 1);
  emxInit_real_T(&pStruct->A_bar_f, 2);
  emxInit_real_T(&pStruct->B_bar_f, 1);
}

void emxInitStruct_struct5_T(struct5_T *pStruct)
{
  emxInit_real_T(&pStruct->A_bar_l, 2);
  pStruct->B_bar_l.size[0] = 0;
  emxInit_real_T(&pStruct->A_bar_f, 2);
  pStruct->B_bar_f.size[0] = 0;
}

void emxInitStruct_struct_T(k_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->Aineq, 1);
  pStruct->bineq.size[0] = 0;
  pStruct->Aeq.size[0] = 0;
  pStruct->lb.size[0] = 0;
  pStruct->ub.size[0] = 0;
  pStruct->indexLB.size[0] = 0;
  pStruct->indexUB.size[0] = 0;
  pStruct->indexFixed.size[0] = 0;
  emxInit_real_T(&pStruct->ATwset, 1);
  emxInit_real_T(&pStruct->bwset, 1);
  emxInit_real_T(&pStruct->maxConstrWorkspace, 1);
  pStruct->isActiveConstr.size[0] = 0;
  pStruct->Wid.size[0] = 0;
  pStruct->Wlocalidx.size[0] = 0;
}

void emxInitStruct_struct_T1(j_struct_T *pStruct)
{
  pStruct->cIneq.size[0] = 0;
  pStruct->cIneq_old.size[0] = 0;
  pStruct->grad.size[0] = 0;
  pStruct->grad_old.size[0] = 0;
  emxInit_real_T(&pStruct->lambdasqp, 1);
  emxInit_real_T(&pStruct->lambdaStopTest, 1);
  emxInit_real_T(&pStruct->lambdaStopTestPrev, 1);
  pStruct->delta_x.size[0] = 0;
  pStruct->socDirection.size[0] = 0;
  pStruct->workingset_old.size[0] = 0;
  emxInit_real_T(&pStruct->JacCineqTrans_old, 2);
  pStruct->gradLag.size[0] = 0;
  pStruct->delta_gradLag.size[0] = 0;
  pStruct->xstar.size[0] = 0;
  emxInit_real_T(&pStruct->lambda, 1);
  pStruct->searchDir.size[0] = 0;
}

void emxInitStruct_struct_T10(p_struct_T *pStruct)
{
  e_emxInitStruct_anonymous_funct(&pStruct->objfun);
  f_emxInitStruct_anonymous_funct(&pStruct->nonlin);
  pStruct->cIneq_1.size[0] = 0;
}

void emxInitStruct_struct_T11(i_struct_T *pStruct)
{
  emxInitStruct_struct1_T(&pStruct->robotParams);
}

void emxInitStruct_struct_T12(q_struct_T *pStruct)
{
  g_emxInitStruct_anonymous_funct(&pStruct->objfun);
  f_emxInitStruct_anonymous_funct(&pStruct->nonlin);
  pStruct->cIneq_1.size[0] = 0;
}

void emxInitStruct_struct_T2(b_struct_T *pStruct)
{
  emxInitStruct_struct5_T(&pStruct->obstacles);
  emxInitStruct_struct2_T(&pStruct->robotParams);
}

void emxInitStruct_struct_T3(c_struct_T *pStruct)
{
  emxInitStruct_struct2_T(&pStruct->robotParams);
}

void emxInitStruct_struct_T4(m_struct_T *pStruct)
{
  d_emxInitStruct_anonymous_funct(&pStruct->objfun);
  c_emxInitStruct_anonymous_funct(&pStruct->nonlin);
  pStruct->cIneq_1.size[0] = 0;
}

void emxInitStruct_struct_T5(e_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->workspace_float, 2);
  pStruct->workspace_int.size[0] = 0;
  pStruct->workspace_sort.size[0] = 0;
}

void emxInitStruct_struct_T6(f_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->QR, 2);
  emxInit_real_T(&pStruct->Q, 2);
  pStruct->jpvt.size[0] = 0;
  emxInit_real_T(&pStruct->tau, 1);
}

void emxInitStruct_struct_T7(n_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->FMat, 2);
}

void emxInitStruct_struct_T8(g_struct_T *pStruct)
{
  emxInitStruct_struct5_T(&pStruct->obstacles);
  emxInitStruct_struct1_T(&pStruct->robotParams);
}

void emxInitStruct_struct_T9(h_struct_T *pStruct)
{
  emxInitStruct_struct1_T(&pStruct->robotParams);
}

void emxInit_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray)
{
  emxArray_ptrdiff_t *emxArray;
  *pEmxArray =
      (emxArray_ptrdiff_t *)emlrtMallocEmxArray(sizeof(emxArray_ptrdiff_t));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_ptrdiff_t,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (ptrdiff_t *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_real_T,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void f_emxFreeStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct)
{
  e_emxFreeStruct_coder_internal_(&pStruct->next);
}

void f_emxInitStruct_anonymous_funct(c_anonymous_function *pStruct)
{
  emxInitStruct_struct_T8(&pStruct->workspace);
}

void f_emxInitStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct)
{
  g_emxInitStruct_coder_internal_(&pStruct->next);
}

void g_emxFreeStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct)
{
  f_emxFreeStruct_coder_internal_(&pStruct->next);
}

void g_emxInitStruct_anonymous_funct(e_anonymous_function *pStruct)
{
  emxInitStruct_struct_T11(&pStruct->workspace);
}

void g_emxInitStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct)
{
  h_emxInitStruct_coder_internal_(&pStruct->next);
}

void h_emxFreeStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct)
{
  g_emxFreeStruct_coder_internal_(&pStruct->next);
}

void h_emxInitStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct)
{
  i_emxInitStruct_coder_internal_(&pStruct->next);
}

void i_emxFreeStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct)
{
  h_emxFreeStruct_coder_internal_(&pStruct->next);
}

void i_emxInitStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct)
{
  j_emxInitStruct_coder_internal_(&pStruct->next);
}

void j_emxFreeStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct)
{
  i_emxFreeStruct_coder_internal_(&pStruct->next);
}

void j_emxInitStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct)
{
  c_emxInitStruct_anonymous_funct(&pStruct->value);
  k_emxInitStruct_coder_internal_(&pStruct->next);
}

void k_emxFreeStruct_coder_internal_(k_coder_internal_stickyStruct *pStruct)
{
  d_emxFreeStruct_anonymous_funct(&pStruct->value);
}

void k_emxInitStruct_coder_internal_(coder_internal_stickyStruct *pStruct)
{
  d_emxInitStruct_anonymous_funct(&pStruct->value);
}

void l_emxFreeStruct_coder_internal_(l_coder_internal_stickyStruct *pStruct)
{
  k_emxFreeStruct_coder_internal_(&pStruct->next);
}

void l_emxInitStruct_coder_internal_(r_coder_internal_stickyStruct *pStruct)
{
  m_emxInitStruct_coder_internal_(&pStruct->next);
}

void m_emxFreeStruct_coder_internal_(m_coder_internal_stickyStruct *pStruct)
{
  l_emxFreeStruct_coder_internal_(&pStruct->next);
}

void m_emxInitStruct_coder_internal_(q_coder_internal_stickyStruct *pStruct)
{
  n_emxInitStruct_coder_internal_(&pStruct->next);
}

void n_emxFreeStruct_coder_internal_(n_coder_internal_stickyStruct *pStruct)
{
  m_emxFreeStruct_coder_internal_(&pStruct->next);
}

void n_emxInitStruct_coder_internal_(p_coder_internal_stickyStruct *pStruct)
{
  o_emxInitStruct_coder_internal_(&pStruct->next);
}

void o_emxFreeStruct_coder_internal_(o_coder_internal_stickyStruct *pStruct)
{
  n_emxFreeStruct_coder_internal_(&pStruct->next);
}

void o_emxInitStruct_coder_internal_(o_coder_internal_stickyStruct *pStruct)
{
  p_emxInitStruct_coder_internal_(&pStruct->next);
}

void p_emxFreeStruct_coder_internal_(p_coder_internal_stickyStruct *pStruct)
{
  o_emxFreeStruct_coder_internal_(&pStruct->next);
}

void p_emxInitStruct_coder_internal_(n_coder_internal_stickyStruct *pStruct)
{
  q_emxInitStruct_coder_internal_(&pStruct->next);
}

void q_emxFreeStruct_coder_internal_(q_coder_internal_stickyStruct *pStruct)
{
  p_emxFreeStruct_coder_internal_(&pStruct->next);
}

void q_emxInitStruct_coder_internal_(m_coder_internal_stickyStruct *pStruct)
{
  r_emxInitStruct_coder_internal_(&pStruct->next);
}

void r_emxFreeStruct_coder_internal_(r_coder_internal_stickyStruct *pStruct)
{
  q_emxFreeStruct_coder_internal_(&pStruct->next);
}

void r_emxInitStruct_coder_internal_(l_coder_internal_stickyStruct *pStruct)
{
  s_emxInitStruct_coder_internal_(&pStruct->next);
}

void s_emxFreeStruct_coder_internal_(t_coder_internal_stickyStruct *pStruct)
{
  d_emxFreeStruct_anonymous_funct(&pStruct->value);
}

void s_emxInitStruct_coder_internal_(k_coder_internal_stickyStruct *pStruct)
{
  f_emxInitStruct_anonymous_funct(&pStruct->value);
  t_emxInitStruct_coder_internal_(&pStruct->next);
}

void t_emxFreeStruct_coder_internal_(u_coder_internal_stickyStruct *pStruct)
{
  s_emxFreeStruct_coder_internal_(&pStruct->next);
}

void t_emxInitStruct_coder_internal_(j_coder_internal_stickyStruct *pStruct)
{
  e_emxInitStruct_anonymous_funct(&pStruct->value);
}

void u_emxFreeStruct_coder_internal_(v_coder_internal_stickyStruct *pStruct)
{
  t_emxFreeStruct_coder_internal_(&pStruct->next);
}

void u_emxInitStruct_coder_internal_(bb_coder_internal_stickyStruct *pStruct)
{
  v_emxInitStruct_coder_internal_(&pStruct->next);
}

void v_emxFreeStruct_coder_internal_(w_coder_internal_stickyStruct *pStruct)
{
  u_emxFreeStruct_coder_internal_(&pStruct->next);
}

void v_emxInitStruct_coder_internal_(ab_coder_internal_stickyStruct *pStruct)
{
  w_emxInitStruct_coder_internal_(&pStruct->next);
}

void w_emxFreeStruct_coder_internal_(x_coder_internal_stickyStruct *pStruct)
{
  v_emxFreeStruct_coder_internal_(&pStruct->next);
}

void w_emxInitStruct_coder_internal_(y_coder_internal_stickyStruct *pStruct)
{
  x_emxInitStruct_coder_internal_(&pStruct->next);
}

void x_emxFreeStruct_coder_internal_(y_coder_internal_stickyStruct *pStruct)
{
  w_emxFreeStruct_coder_internal_(&pStruct->next);
}

void x_emxInitStruct_coder_internal_(x_coder_internal_stickyStruct *pStruct)
{
  y_emxInitStruct_coder_internal_(&pStruct->next);
}

void y_emxFreeStruct_coder_internal_(ab_coder_internal_stickyStruct *pStruct)
{
  x_emxFreeStruct_coder_internal_(&pStruct->next);
}

void y_emxInitStruct_coder_internal_(w_coder_internal_stickyStruct *pStruct)
{
  ab_emxInitStruct_coder_internal(&pStruct->next);
}

/* End of code generation (evaluateObstacles_mex_emxutil.c) */
