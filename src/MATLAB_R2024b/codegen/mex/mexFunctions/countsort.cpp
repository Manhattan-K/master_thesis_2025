//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// countsort.cpp
//
// Code generation for function 'countsort'
//

// Include files
#include "countsort.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
void countsort(int32_T x_data[], int32_T xLen, int32_T workspace_data[],
               int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T i;
    int32_T idxEnd;
    int32_T idxStart;
    i = xMax - xMin;
    if (i >= 0) {
      std::memset(&workspace_data[0], 0,
                  static_cast<uint32_T>(i + 1) * sizeof(int32_T));
    }
    for (int32_T idx{0}; idx < xLen; idx++) {
      idxStart = x_data[idx] - xMin;
      workspace_data[idxStart]++;
    }
    for (int32_T idx{2}; idx <= i + 1; idx++) {
      workspace_data[idx - 1] += workspace_data[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace_data[0];
    for (int32_T idx{0}; idx < i; idx++) {
      for (int32_T idxFill{idxStart}; idxFill <= idxEnd; idxFill++) {
        x_data[idxFill - 1] = idx + xMin;
      }
      idxStart = workspace_data[idx] + 1;
      idxEnd = workspace_data[idx + 1];
    }
    for (int32_T idx{idxStart}; idx <= idxEnd; idx++) {
      x_data[idx - 1] = xMax;
    }
  }
}

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (countsort.cpp)
