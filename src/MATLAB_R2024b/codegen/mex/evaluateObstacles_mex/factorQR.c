/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQR.c
 *
 * Code generation for function 'factorQR'
 *
 */

/* Include files */
#include "factorQR.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void factorQR(f_struct_T *obj, const emxArray_real_T *A, int32_T mrows,
              int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T minmana;
  boolean_T guard1;
  A_data = A->data;
  i = mrows * ncols;
  guard1 = false;
  if (i > 0) {
    for (minmana = 0; minmana < ncols; minmana++) {
      n_t = (ptrdiff_t)mrows;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&A_data[ldA * minmana], &incx_t,
            &obj->QR->data[obj->ldq * minmana], &incy_t);
    }
    guard1 = true;
  } else if (i == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    int32_T ma;
    int32_T na;
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    na = (ncols / 8) << 3;
    ma = na - 8;
    for (minmana = 0; minmana <= ma; minmana += 8) {
      _mm256_storeu_si256(
          (__m256i *)&obj->jpvt.data[minmana],
          _mm256_add_epi32(
              _mm256_add_epi32(_mm256_set1_epi32(minmana),
                               _mm256_loadu_si256((const __m256i *)&iv1[0])),
              _mm256_set1_epi32(1)));
    }
    for (minmana = na; minmana < ncols; minmana++) {
      obj->jpvt.data[minmana] = minmana + 1;
    }
    i = muIntScalarMin_sint32(mrows, ncols);
    obj->minRowCol = i;
    ma = obj->QR->size[0];
    na = obj->QR->size[1];
    minmana = muIntScalarMin_sint32(ma, na);
    na = obj->tau->size[0];
    obj->tau->size[0] = minmana;
    emxEnsureCapacity_real_T(obj->tau, na);
    if (ncols == 0) {
      i = obj->tau->size[0];
      obj->tau->size[0] = minmana;
      emxEnsureCapacity_real_T(obj->tau, i);
      for (i = 0; i < minmana; i++) {
        obj->tau->data[i] = 0.0;
      }
    } else {
      n_t = LAPACKE_dgeqrf(102, (ptrdiff_t)mrows, (ptrdiff_t)ncols,
                           &obj->QR->data[0], (ptrdiff_t)obj->QR->size[0],
                           &obj->tau->data[0]);
      if ((int32_T)n_t != 0) {
        for (j = 0; j < ncols; j++) {
          na = (uint16_T)mrows;
          for (b_i = 0; b_i < na; b_i++) {
            obj->QR->data[j * ma + b_i] = rtNaN;
          }
        }
        ma = i - 1;
        for (b_i = 0; b_i <= ma; b_i++) {
          obj->tau->data[b_i] = rtNaN;
        }
        i++;
        for (b_i = i; b_i <= minmana; b_i++) {
          obj->tau->data[b_i - 1] = 0.0;
        }
      }
    }
  }
}

/* End of code generation (factorQR.c) */
