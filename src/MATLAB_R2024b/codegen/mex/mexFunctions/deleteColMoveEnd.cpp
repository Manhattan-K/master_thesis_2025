//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// deleteColMoveEnd.cpp
//
// Code generation for function 'deleteColMoveEnd'
//

// Include files
#include "deleteColMoveEnd.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void deleteColMoveEnd(d_struct_T &obj, int32_T idx)
{
  real_T c;
  real_T d;
  real_T s;
  real_T temp;
  int32_T i;
  if (obj.usedPivoting) {
    i = 1;
    while ((i <= obj.ncols) && (obj.jpvt.data[i - 1] != idx)) {
      i++;
    }
    idx = i;
  }
  if (idx >= obj.ncols) {
    obj.ncols--;
  } else {
    int32_T b_i;
    int32_T k;
    obj.jpvt.data[idx - 1] = obj.jpvt.data[obj.ncols - 1];
    b_i = obj.minRowCol;
    for (k = 0; k < b_i; k++) {
      obj.QR[k + obj.ldq * (idx - 1)] = obj.QR[k + obj.ldq * (obj.ncols - 1)];
    }
    obj.ncols--;
    obj.minRowCol = muIntScalarMin_sint32(obj.mrows, obj.ncols);
    if (idx < obj.mrows) {
      int32_T b_temp_tmp;
      int32_T endIdx;
      int32_T idxRotGCol;
      int32_T ix;
      int32_T n;
      int32_T temp_tmp;
      i = obj.mrows - 1;
      endIdx = muIntScalarMin_sint32(i, obj.ncols);
      k = endIdx;
      idxRotGCol = obj.ldq * (idx - 1);
      while (k >= idx) {
        b_i = k + idxRotGCol;
        temp = obj.QR[b_i - 1];
        d = obj.QR[b_i];
        c = 0.0;
        s = 0.0;
        drotg(&temp, &d, &c, &s);
        obj.QR[b_i - 1] = temp;
        obj.QR[b_i] = d;
        obj.QR[k + obj.ldq * (k - 1)] = 0.0;
        i = k + obj.ldq * idx;
        n = obj.ncols - idx;
        if (n >= 1) {
          ix = i - 1;
          for (int32_T b_k{0}; b_k < n; b_k++) {
            temp = c * obj.QR[ix] + s * obj.QR[i];
            obj.QR[i] = c * obj.QR[i] - s * obj.QR[ix];
            obj.QR[ix] = temp;
            i += obj.ldq;
            ix += obj.ldq;
          }
        }
        i = obj.ldq * (k - 1);
        ix = obj.ldq + i;
        n = obj.mrows;
        for (int32_T b_k{0}; b_k < n; b_k++) {
          temp_tmp = ix + b_k;
          b_temp_tmp = i + b_k;
          temp = c * obj.Q[b_temp_tmp] + s * obj.Q[temp_tmp];
          obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[b_temp_tmp];
          obj.Q[b_temp_tmp] = temp;
        }
        k--;
      }
      b_i = idx + 1;
      for (k = b_i; k <= endIdx; k++) {
        i = k + obj.ldq * (k - 1);
        temp = obj.QR[i - 1];
        d = obj.QR[i];
        c = 0.0;
        s = 0.0;
        drotg(&temp, &d, &c, &s);
        obj.QR[i - 1] = temp;
        obj.QR[i] = d;
        i = k * (obj.ldq + 1);
        n = obj.ncols - k;
        if (n >= 1) {
          ix = i - 1;
          for (int32_T b_k{0}; b_k < n; b_k++) {
            temp = c * obj.QR[ix] + s * obj.QR[i];
            obj.QR[i] = c * obj.QR[i] - s * obj.QR[ix];
            obj.QR[ix] = temp;
            i += obj.ldq;
            ix += obj.ldq;
          }
        }
        i = obj.ldq * (k - 1);
        ix = obj.ldq + i;
        n = obj.mrows;
        for (int32_T b_k{0}; b_k < n; b_k++) {
          temp_tmp = ix + b_k;
          b_temp_tmp = i + b_k;
          temp = c * obj.Q[b_temp_tmp] + s * obj.Q[temp_tmp];
          obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[b_temp_tmp];
          obj.Q[b_temp_tmp] = temp;
        }
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (deleteColMoveEnd.cpp)
