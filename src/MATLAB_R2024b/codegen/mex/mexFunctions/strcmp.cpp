//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// strcmp.cpp
//
// Code generation for function 'strcmp'
//

// Include files
#include "strcmp.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
boolean_T b_strcmp(const char_T a[7])
{
  static const char_T b[7]{'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  return std::memcmp((char_T *)&a[0], (char_T *)&b[0], 7) == 0;
}

} // namespace internal
} // namespace coder

// End of code generation (strcmp.cpp)
