//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sumMatrixIncludeNaN.cpp
//
// Code generation for function 'sumMatrixIncludeNaN'
//

// Include files
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
real_T sumColumnB(const array<real_T, 2U> &x, int32_T col)
{
  int32_T i0;
  i0 = (col - 1) << 1;
  return x[i0] + x[i0 + 1];
}

real_T sumColumnB(const array<real_T, 1U> &x, int32_T vlen, int32_T vstart)
{
  real_T y;
  if (vlen <= 1024) {
    y = x[vstart - 1];
    for (int32_T k{0}; k <= vlen - 2; k++) {
      y += x[vstart + k];
    }
  } else {
    real_T b_y;
    int32_T b_vstart;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    y = x[vstart - 1];
    for (int32_T k{0}; k < 1023; k++) {
      y += x[vstart + k];
    }
    for (int32_T k{2}; k <= nfb; k++) {
      b_vstart = vstart + ((k - 1) << 10);
      b_y = x[b_vstart - 1];
      for (int32_T b_k{0}; b_k < 1023; b_k++) {
        b_y += x[b_vstart + b_k];
      }
      y += b_y;
    }
    if (vlen > inb) {
      b_vstart = vstart + inb;
      b_y = x[b_vstart - 1];
      nfb = vlen - inb;
      for (int32_T k{0}; k <= nfb - 2; k++) {
        b_y += x[b_vstart + k];
      }
      y += b_y;
    }
  }
  return y;
}

real_T sumColumnB(const array<real_T, 1U> &x, int32_T vlen)
{
  real_T y;
  if (vlen <= 1024) {
    y = x[0];
    for (int32_T k{0}; k <= vlen - 2; k++) {
      y += x[k + 1];
    }
  } else {
    real_T b_y;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    y = x[0];
    for (int32_T k{0}; k < 1023; k++) {
      y += x[k + 1];
    }
    for (int32_T k{2}; k <= nfb; k++) {
      int32_T vstart;
      vstart = (k - 1) << 10;
      b_y = x[vstart];
      for (int32_T b_k{0}; b_k < 1023; b_k++) {
        b_y += x[(vstart + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      b_y = x[inb];
      nfb = vlen - inb;
      for (int32_T k{0}; k <= nfb - 2; k++) {
        b_y += x[(inb + k) + 1];
      }
      y += b_y;
    }
  }
  return y;
}

real_T sumColumnB4(const array<real_T, 1U> &x, int32_T vstart)
{
  real_T psum2;
  real_T psum3;
  real_T psum4;
  real_T y;
  y = x[vstart - 1];
  psum2 = x[vstart + 1023];
  psum3 = x[vstart + 2047];
  psum4 = x[vstart + 3071];
  for (int32_T k{0}; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = vstart + k;
    y += x[psum1_tmp];
    psum2 += x[psum1_tmp + 1024];
    psum3 += x[psum1_tmp + 2048];
    psum4 += x[psum1_tmp + 3072];
  }
  return (y + psum2) + (psum3 + psum4);
}

} // namespace coder

// End of code generation (sumMatrixIncludeNaN.cpp)
