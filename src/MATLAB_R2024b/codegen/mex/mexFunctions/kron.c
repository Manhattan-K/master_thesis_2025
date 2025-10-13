/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kron.c
 *
 * Code generation for function 'kron'
 *
 */

/* Include files */
#include "kron.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void kron(const emxArray_real_T *A, const emxArray_real_T *B,
          emxArray_real_T *K)
{
  const real_T *A_data;
  const real_T *B_data;
  real_T *K_data;
  int32_T b_j1;
  int32_T i1;
  int32_T i2;
  int32_T j2;
  int32_T kidx;
  int32_T ma;
  int32_T mb;
  int32_T na;
  int32_T nb;
  B_data = B->data;
  A_data = A->data;
  ma = A->size[0];
  na = A->size[1];
  mb = B->size[0];
  nb = B->size[1];
  kidx = K->size[0] * K->size[1];
  K->size[0] = A->size[0] * B->size[0];
  K->size[1] = A->size[1] * B->size[1];
  emxEnsureCapacity_real_T(K, kidx);
  K_data = K->data;
  kidx = -1;
  for (b_j1 = 0; b_j1 < na; b_j1++) {
    for (j2 = 0; j2 < nb; j2++) {
      for (i1 = 0; i1 < ma; i1++) {
        int32_T scalarLB;
        int32_T vectorUB;
        scalarLB = (mb / 4) << 2;
        vectorUB = scalarLB - 4;
        for (i2 = 0; i2 <= vectorUB; i2 += 4) {
          _mm256_storeu_pd(
              &K_data[(kidx + i2) + 1],
              _mm256_mul_pd(_mm256_set1_pd(A_data[i1 + A->size[0] * b_j1]),
                            _mm256_loadu_pd(&B_data[i2 + B->size[0] * j2])));
        }
        for (i2 = scalarLB; i2 < mb; i2++) {
          K_data[(kidx + i2) + 1] =
              A_data[i1 + A->size[0] * b_j1] * B_data[i2 + B->size[0] * j2];
        }
        if (mb - 1 >= 0) {
          kidx += mb;
        }
      }
    }
  }
}

/* End of code generation (kron.c) */
