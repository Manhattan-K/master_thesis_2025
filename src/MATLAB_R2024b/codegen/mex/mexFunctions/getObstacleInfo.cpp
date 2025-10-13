//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// getObstacleInfo.cpp
//
// Code generation for function 'getObstacleInfo'
//

// Include files
#include "getObstacleInfo.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
void getObstacleInfo(const struct0_T obstacles_data[],
                     const int32_T obstacles_size[2],
                     const real_T selector_data[], real_T obsNum,
                     const real_T x0[2], coder::array<real_T, 2U> &q,
                     coder::array<real_T, 2U> &d)
{
  static const char_T a[6]{'c', 'i', 'r', 'c', 'l', 'e'};
  int32_T i;
  int32_T loop_ub_tmp;
  uint32_T j;
  // GETOBSTACLEINFO get qis from obstacles
  q.set_size(2, static_cast<int32_T>(obsNum));
  loop_ub_tmp = static_cast<int32_T>(obsNum) << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    q[i] = 0.0;
  }
  d.set_size(static_cast<int32_T>(obsNum), static_cast<int32_T>(obsNum));
  loop_ub_tmp = static_cast<int32_T>(obsNum) * static_cast<int32_T>(obsNum);
  for (i = 0; i < loop_ub_tmp; i++) {
    d[i] = 0.0;
  }
  //  Index for the selected obstacles only
  j = 1U;
  if ((obstacles_size[1] == 0) || (obsNum == 0.0)) {
    q.set_size(2, 0);
    d.set_size(0, 0);
  } else {
    i = obstacles_size[1];
    for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
      if (selector_data[loop_ub_tmp] != 0.0) {
        int32_T i1;
        //  GETQIFROMSHAPE is a function that tries to construct the distance
        //  and position of the line tangent to the shape and perpendicular to
        //  x0 (robot pos) shape is a structure holding information on the
        //  particular shape if shape.type = "circle", shape.center,
        //  shape.radius must be present if " = "ellipse", shape.a, shape.b,
        //  shape.center, shape.theta if " = "general_poly", shape.vertices as
        //  2-by-l matrix (l number of vertices) if " = "wall" (thing which is
        //  perpendicular to axes), shape.is_x_wall, shape.wall_pos
        q[2 * (static_cast<int32_T>(j) - 1)] = 0.0;
        q[2 * (static_cast<int32_T>(j) - 1) + 1] = 0.0;
        d[static_cast<int32_T>(j) - 1] = 0.0;
        if (std::memcmp((char_T *)&a[0],
                        (char_T *)&obstacles_data[loop_ub_tmp].type.Value[0],
                        6) == 0) {
          i1 = 0;
        } else {
          i1 = -1;
        }
        if (i1 == 0) {
          real_T absxk;
          real_T b_d;
          real_T d1;
          real_T dist_from_center;
          real_T scale;
          real_T t;
          scale = 3.3121686421112381E-170;
          b_d = obstacles_data[loop_ub_tmp].center[0];
          absxk = muDoubleScalarAbs(x0[0] - b_d);
          if (absxk > 3.3121686421112381E-170) {
            dist_from_center = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            dist_from_center = t * t;
          }
          d1 = obstacles_data[loop_ub_tmp].center[1];
          absxk = muDoubleScalarAbs(x0[1] - d1);
          if (absxk > scale) {
            t = scale / absxk;
            dist_from_center = dist_from_center * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            dist_from_center += t * t;
          }
          dist_from_center = scale * muDoubleScalarSqrt(dist_from_center);
          scale = 1.0 - obstacles_data[loop_ub_tmp].radius / dist_from_center;
          d[static_cast<int32_T>(j) - 1] = scale * dist_from_center;
          q[2 * (static_cast<int32_T>(j) - 1)] = x0[0] + (b_d - x0[0]) * scale;
          q[2 * (static_cast<int32_T>(j) - 1) + 1] =
              x0[1] + (d1 - x0[1]) * scale;
        }
        j++;
      }
    }
  }
}

// End of code generation (getObstacleInfo.cpp)
