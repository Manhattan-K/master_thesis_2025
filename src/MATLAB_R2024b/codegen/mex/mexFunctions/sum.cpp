//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
real_T sum(const array<real_T, 2U> &x)
{
  array<real_T, 1U> c_x;
  real_T y;
  if (x.size(1) == 0) {
    y = 0.0;
  } else if (x.size(1) < 4096) {
    int32_T b_x;
    b_x = x.size(1);
    c_x = x.reshape(b_x);
    y = sumColumnB(c_x, x.size(1));
  } else {
    int32_T b_x;
    int32_T inb;
    int32_T nfb;
    int32_T nleft;
    nfb = static_cast<int32_T>(static_cast<uint32_T>(x.size(1)) >> 12);
    inb = nfb << 12;
    nleft = x.size(1) - inb;
    b_x = x.size(1);
    c_x = x.reshape(b_x);
    y = sumColumnB4(c_x, 1);
    if (nfb >= 2) {
      b_x = x.size(1);
    }
    for (int32_T ib{2}; ib <= nfb; ib++) {
      c_x = x.reshape(b_x);
      y += sumColumnB4(c_x, ((ib - 1) << 12) + 1);
    }
    if (nleft > 0) {
      b_x = x.size(1);
      c_x = x.reshape(b_x);
      y += sumColumnB(c_x, nleft, inb + 1);
    }
  }
  return y;
}

} // namespace coder

// End of code generation (sum.cpp)
