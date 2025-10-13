//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtMCInfo emlrtMCI{
    53,       // lineNo
    5,        // colNo
    "repmat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pName
};

// Function Declarations
static void b_error(const mxArray *m, emlrtMCInfo &location);

// Function Definitions
static void b_error(const mxArray *m, emlrtMCInfo &location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, nullptr, 1, &pArray, "error",
                        true, &location);
}

namespace coder {
void repmat(const array<real_T, 1U> &a, real_T varargin_1, array<real_T, 1U> &b)
{
  static const int32_T b_iv[2]{1, 15};
  static const char_T u[15]{'M', 'A', 'T', 'L', 'A', 'B', ':', 'p',
                            'm', 'a', 'x', 's', 'i', 'z', 'e'};
  const mxArray *m;
  const mxArray *y;
  int32_T ntilerows;
  int32_T outsize_idx_0;
  outsize_idx_0 = a.size(0) * static_cast<int32_T>(varargin_1);
  if (!(outsize_idx_0 ==
        static_cast<real_T>(a.size(0)) *
            static_cast<real_T>(static_cast<int32_T>(varargin_1)))) {
    y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 15, m, &u[0]);
    emlrtAssign(&y, m);
    b_error(y, emlrtMCI);
  }
  b.set_size(outsize_idx_0);
  outsize_idx_0 = a.size(0);
  ntilerows = static_cast<int32_T>(varargin_1);
  for (int32_T itilerow{0}; itilerow < ntilerows; itilerow++) {
    int32_T ibcol;
    ibcol = itilerow * outsize_idx_0;
    for (int32_T k{0}; k < outsize_idx_0; k++) {
      b[ibcol + k] = a[k];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
