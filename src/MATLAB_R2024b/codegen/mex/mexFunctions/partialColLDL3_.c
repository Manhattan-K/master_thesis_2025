/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * partialColLDL3_.c
 *
 * Code generation for function 'partialColLDL3_'
 *
 */

/* Include files */
#include "partialColLDL3_.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void partialColLDL3_(m_struct_T *obj, int32_T LD_offset, int32_T NColsRemain)
{
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T i;
  int32_T i1;
  int32_T ia;
  int32_T iac;
  int32_T ic;
  int32_T idx;
  int32_T ix;
  int32_T j;
  int32_T k;
  int32_T subRows;
  LDimSizeP1 = obj->ldm + 1;
  for (k = 0; k < 48; k++) {
    real_T y;
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset = (LD_offset + LDimSizeP1 * k) - 1;
    for (idx = 0; idx <= subRows; idx++) {
      obj->workspace_ = obj->FMat->data[LD_diagOffset + idx];
    }
    for (idx = 0; idx < NColsRemain; idx++) {
      obj->workspace2_ = obj->workspace_;
    }
    idx = obj->ldm;
    y = obj->workspace2_;
    if ((NColsRemain != 0) && (k != 0)) {
      ix = LD_offset + k;
      i = obj->ldm * (k - 1) + 1;
      for (iac = 1; idx < 0 ? iac >= i : iac <= i; iac += idx) {
        i1 = iac + NColsRemain;
        for (ia = iac; ia < i1; ia++) {
          y += obj->workspace_ * -obj->FMat->data[ix - 1];
        }
        ix += obj->ldm;
      }
    }
    obj->workspace2_ = y;
    for (idx = 0; idx < NColsRemain; idx++) {
      obj->workspace_ = y;
    }
    for (idx = 0; idx <= subRows; idx++) {
      obj->FMat->data[LD_diagOffset + idx] = obj->workspace_;
    }
    for (idx = 0; idx < subRows; idx++) {
      i = (LD_diagOffset + idx) + 1;
      obj->FMat->data[i] /= obj->FMat->data[LD_diagOffset];
    }
  }
  i = NColsRemain - 1;
  for (j = 48; j <= i; j += 48) {
    int32_T i2;
    int32_T i3;
    int32_T m;
    subRows = NColsRemain - j;
    LD_diagOffset = muIntScalarMin_sint32(48, subRows);
    i1 = j + LD_diagOffset;
    for (k = j; k < i1; k++) {
      m = i1 - k;
      for (idx = 0; idx < 48; idx++) {
        obj->workspace2_ =
            obj->FMat->data[((LD_offset + k) + idx * obj->ldm) - 1];
      }
      ix = k + 1;
      idx = obj->ldm;
      if (m != 0) {
        i2 = (k + obj->ldm * 47) + 1;
        for (iac = ix; idx < 0 ? iac >= i2 : iac <= i2; iac += idx) {
          i3 = iac + m;
          for (ia = iac; ia < i3; ia++) {
            /* Check node always fails. would cause program termination and was
             * eliminated */
          }
        }
      }
    }
    if (i1 < NColsRemain) {
      int32_T ic0;
      m = subRows - LD_diagOffset;
      ic0 = ((LD_offset + LD_diagOffset) + LDimSizeP1 * j) - 1;
      for (idx = 0; idx < 48; idx++) {
        ix = (LD_offset + j) + idx * obj->ldm;
        for (subRows = 0; subRows < LD_diagOffset; subRows++) {
          obj->workspace2_ = obj->FMat->data[(ix + subRows) - 1];
        }
      }
      iac = obj->ldm;
      if ((m != 0) && (LD_diagOffset != 0)) {
        ix = ic0 + obj->ldm * (LD_diagOffset - 1);
        subRows = 0;
        for (ia = ic0; iac < 0 ? ia >= ix : ia <= ix; ia += iac) {
          subRows++;
          i1 = subRows + iac * 47;
          for (k = subRows; iac < 0 ? k >= i1 : k <= i1; k += iac) {
            i2 = ia + 1;
            i3 = ia + m;
            LD_diagOffset = ((((i3 - ia) / 4) << 2) + ia) + 1;
            idx = LD_diagOffset - 4;
            for (ic = i2; ic <= idx; ic += 4) {
              __m256d r;
              r = _mm256_loadu_pd(&obj->FMat->data[ic - 1]);
              _mm256_storeu_pd(
                  &obj->FMat->data[ic - 1],
                  _mm256_add_pd(
                      r, _mm256_set1_pd(-obj->workspace2_ * obj->workspace_)));
            }
            for (ic = LD_diagOffset; ic <= i3; ic++) {
              obj->FMat->data[ic - 1] += -obj->workspace2_ * obj->workspace_;
            }
          }
        }
      }
    }
  }
}

/* End of code generation (partialColLDL3_.c) */
