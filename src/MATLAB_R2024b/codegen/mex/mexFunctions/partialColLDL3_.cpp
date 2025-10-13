//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// partialColLDL3_.cpp
//
// Code generation for function 'partialColLDL3_'
//

// Include files
#include "partialColLDL3_.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void partialColLDL3_(e_struct_T &obj, int32_T LD_offset, int32_T NColsRemain)
{
  real_T d;
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T i;
  int32_T i1;
  int32_T ix;
  int32_T k;
  int32_T lda;
  int32_T subRows;
  LDimSizeP1 = obj.ldm + 1;
  for (k = 0; k < 48; k++) {
    real_T y;
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset = (LD_offset + LDimSizeP1 * k) - 1;
    for (int32_T idx{0}; idx <= subRows; idx++) {
      obj.workspace_ = obj.FMat[LD_diagOffset + idx];
    }
    for (int32_T idx{0}; idx < NColsRemain; idx++) {
      obj.workspace2_ = obj.workspace_;
    }
    lda = obj.ldm;
    y = obj.workspace2_;
    if ((NColsRemain != 0) && (k != 0)) {
      ix = LD_offset + k;
      i = obj.ldm * (k - 1) + 1;
      for (int32_T iac{1}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        i1 = iac + NColsRemain;
        for (int32_T idx{iac}; idx < i1; idx++) {
          y += obj.workspace_ * -obj.FMat[ix - 1];
        }
        ix += obj.ldm;
      }
    }
    obj.workspace2_ = y;
    for (int32_T idx{0}; idx < NColsRemain; idx++) {
      obj.workspace_ = y;
    }
    for (int32_T idx{0}; idx <= subRows; idx++) {
      obj.FMat[LD_diagOffset + idx] = obj.workspace_;
    }
    for (int32_T idx{0}; idx < subRows; idx++) {
      i = (LD_diagOffset + idx) + 1;
      obj.FMat[i] = obj.FMat[i] / obj.FMat[LD_diagOffset];
    }
  }
  i = NColsRemain - 1;
  for (int32_T j{48}; j <= i; j += 48) {
    int32_T i2;
    int32_T i3;
    int32_T m;
    int32_T subBlockSize;
    subRows = NColsRemain - j;
    subBlockSize = muIntScalarMin_sint32(48, subRows);
    i1 = j + subBlockSize;
    for (k = j; k < i1; k++) {
      m = i1 - k;
      i2 = obj.ldm;
      for (int32_T idx{0}; idx < 48; idx++) {
        d = obj.FMat[((LD_offset + k) + idx * i2) - 1];
      }
      obj.workspace2_ = d;
      ix = k + 1;
      lda = obj.ldm;
      if (m != 0) {
        i2 = (k + obj.ldm * 47) + 1;
        for (int32_T iac{ix}; lda < 0 ? iac >= i2 : iac <= i2; iac += lda) {
          i3 = iac + m;
          for (int32_T idx{iac}; idx < i3; idx++) {
            // Check node always fails. would cause program termination and was
            // eliminated
          }
        }
      }
    }
    if (i1 < NColsRemain) {
      m = subRows - subBlockSize;
      k = ((LD_offset + subBlockSize) + LDimSizeP1 * j) - 1;
      for (int32_T idx{0}; idx < 48; idx++) {
        ix = (LD_offset + j) + idx * obj.ldm;
        for (subRows = 0; subRows < subBlockSize; subRows++) {
          obj.workspace2_ = obj.FMat[(ix + subRows) - 1];
        }
      }
      LD_diagOffset = obj.ldm;
      if ((m != 0) && (subBlockSize != 0)) {
        ix = k + obj.ldm * (subBlockSize - 1);
        subRows = 0;
        for (int32_T idx{k}; LD_diagOffset < 0 ? idx >= ix : idx <= ix;
             idx += LD_diagOffset) {
          subRows++;
          i1 = subRows + LD_diagOffset * 47;
          for (lda = subRows; LD_diagOffset < 0 ? lda >= i1 : lda <= i1;
               lda += LD_diagOffset) {
            i2 = idx + 1;
            i3 = idx + m;
            for (int32_T iac{i2}; iac <= i3; iac++) {
              obj.FMat[iac - 1] =
                  obj.FMat[iac - 1] + -obj.workspace2_ * obj.workspace_;
            }
          }
        }
      }
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (partialColLDL3_.cpp)
