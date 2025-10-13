/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * countsort.c
 *
 * Code generation for function 'countsort'
 *
 */

/* Include files */
#include "countsort.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void countsort(emlrtCTX aTLS, int32_T x_data[], int32_T xLen,
               int32_T workspace_data[], int32_T xMin, int32_T xMax)
{
  jmp_buf *volatile emlrtJBStack;
  int32_T countsort_numThreads;
  int32_T idx;
  int32_T idxEnd;
  int32_T idxFill;
  int32_T idxW;
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T i;
    int32_T idxStart;
    i = xMax - xMin;
    if (i >= 0) {
      memset(&workspace_data[0], 0, (uint32_T)(i + 1) * sizeof(int32_T));
    }
    for (idxEnd = 0; idxEnd < xLen; idxEnd++) {
      idxStart = x_data[idxEnd] - xMin;
      workspace_data[idxStart]++;
    }
    for (idxEnd = 2; idxEnd <= i + 1; idxEnd++) {
      workspace_data[idxEnd - 1] += workspace_data[idxEnd - 2];
    }
    idxStart = 1;
    idxEnd = workspace_data[0];
    for (idxW = 0; idxW < i; idxW++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x_data[idxFill - 1] = idxW + xMin;
      }
      idxStart = workspace_data[idxW] + 1;
      idxEnd = workspace_data[idxW + 1];
    }
    if ((idxEnd - idxStart) + 1 < 1200) {
      for (idx = idxStart; idx <= idxEnd; idx++) {
        x_data[idx - 1] = xMax;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      countsort_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(countsort_numThreads)

      for (idx = idxStart; idx <= idxEnd; idx++) {
        x_data[idx - 1] = xMax;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
}

/* End of code generation (countsort.c) */
