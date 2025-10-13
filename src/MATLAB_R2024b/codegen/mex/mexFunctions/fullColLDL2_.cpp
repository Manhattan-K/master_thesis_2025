//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fullColLDL2_.cpp
//
// Code generation for function 'fullColLDL2_'
//

// Include files
#include "fullColLDL2_.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(e_struct_T &obj, int32_T LD_offset, int32_T NColsRemain)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T alpha1;
  int32_T LDimSizeP1;
  LDimSizeP1 = obj.ldm;
  for (int32_T k{0}; k < NColsRemain; k++) {
    real_T y;
    int32_T LD_diagOffset;
    int32_T jA;
    int32_T subMatrixDim;
    LD_diagOffset = LD_offset + (LDimSizeP1 + 1) * k;
    alpha1 = -1.0 / obj.FMat[LD_diagOffset - 1];
    subMatrixDim = (NColsRemain - k) - 2;
    y = obj.workspace_;
    for (jA = 0; jA <= subMatrixDim; jA++) {
      y = obj.FMat[LD_diagOffset + jA];
    }
    obj.workspace_ = y;
    if (!(alpha1 == 0.0)) {
      jA = (LD_diagOffset + LDimSizeP1) - 1;
      for (int32_T j{0}; j <= subMatrixDim; j++) {
        if (y != 0.0) {
          real_T temp;
          int32_T i;
          int32_T i1;
          temp = y * alpha1;
          i = jA + 2;
          i1 = subMatrixDim + jA;
          for (int32_T ijA{i}; ijA <= i1 + 2; ijA++) {
            obj.FMat[ijA - 1] = obj.FMat[ijA - 1] + y * temp;
          }
        }
        jA += obj.ldm;
      }
    }
    alpha1 = 1.0 / obj.FMat[LD_diagOffset - 1];
    if (subMatrixDim + 1 >= 1) {
      n_t = (ptrdiff_t)(subMatrixDim + 1);
      incx_t = (ptrdiff_t)1;
      dscal(&n_t, &alpha1, &obj.FMat[LD_diagOffset], &incx_t);
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (fullColLDL2_.cpp)
