/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getObstacleInfo.c
 *
 * Code generation for function 'getObstacleInfo'
 *
 */

/* Include files */
#include "getObstacleInfo.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void getObstacleInfo(const struct0_T obstacles_data[],
                     const int32_T obstacles_size[2],
                     const real_T selector_data[], real_T obsNum,
                     const real_T x0[2], emxArray_real_T *q, emxArray_real_T *d)
{
  static const char_T a[6] = {'c', 'i', 'r', 'c', 'l', 'e'};
  real_T *d_data;
  real_T *q_data;
  int32_T b_i;
  int32_T i;
  int32_T loop_ub_tmp;
  uint32_T j;
  emlrtMEXProfilingFunctionEntry((char_T *)getObstacleInfo_complete_name,
                                 isMexOutdated);
  /* GETOBSTACLEINFO get qis from obstacles */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emlrtMEXProfilingStatement(2, isMexOutdated);
  i = q->size[0] * q->size[1];
  q->size[0] = 2;
  q->size[1] = (int32_T)obsNum;
  emxEnsureCapacity_real_T(q, i);
  q_data = q->data;
  loop_ub_tmp = (int32_T)obsNum << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    q_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(3, isMexOutdated);
  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)obsNum;
  d->size[1] = (int32_T)obsNum;
  emxEnsureCapacity_real_T(d, i);
  d_data = d->data;
  loop_ub_tmp = (int32_T)obsNum * (int32_T)obsNum;
  for (i = 0; i < loop_ub_tmp; i++) {
    d_data[i] = 0.0;
  }
  /*  Index for the selected obstacles only */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  j = 1U;
  emlrtMEXProfilingStatement(5, isMexOutdated);
  if ((obstacles_size[1] == 0) || (obsNum == 0.0)) {
    emlrtMEXProfilingStatement(6, isMexOutdated);
    q->size[0] = 2;
    q->size[1] = 0;
    d->size[0] = 0;
    d->size[1] = 0;
    emlrtMEXProfilingStatement(14, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(7, isMexOutdated);
    emlrtMEXProfilingStatement(8, isMexOutdated);
    i = obstacles_size[1];
    for (b_i = 0; b_i < i; b_i++) {
      emlrtMEXProfilingStatement(9, isMexOutdated);
      if (selector_data[b_i] != 0.0) {
        int32_T i1;
        emlrtMEXProfilingStatement(10, isMexOutdated);
        emlrtMEXProfilingFunctionEntry((char_T *)getqiFromShape_complete_name,
                                       isMexOutdated);
        /*  GETQIFROMSHAPE is a function that tries to construct the distance
         * and */
        /*  position of the line tangent to the shape and perpendicular to x0
         * (robot pos) */
        /*  shape is a structure holding information on the particular shape */
        /*  if shape.type = "circle", shape.center, shape.radius must be present
         */
        /*  if " = "ellipse", shape.a, shape.b, shape.center, shape.theta */
        /*  if " = "general_poly", shape.vertices as 2-by-l matrix (l number of
         * vertices) */
        /*  if " = "wall" (thing which is perpendicular to axes),
         * shape.is_x_wall, */
        /*  shape.wall_pos */
        emlrtMEXProfilingStatement(1, isMexOutdated);
        loop_ub_tmp = 2 * ((int32_T)j - 1);
        q_data[loop_ub_tmp] = 0.0;
        q_data[loop_ub_tmp + 1] = 0.0;
        emlrtMEXProfilingStatement(2, isMexOutdated);
        d_data[(int32_T)j - 1] = 0.0;
        emlrtMEXProfilingStatement(3, isMexOutdated);
        if (memcmp((char_T *)&a[0],
                   (char_T *)&obstacles_data[b_i].type.Value[0], 6) == 0) {
          i1 = 0;
        } else {
          i1 = -1;
        }
        if (i1 == 0) {
          __m128d r;
          real_T absxk;
          real_T dist_from_center;
          real_T scale;
          real_T t;
          emlrtMEXProfilingStatement(4, isMexOutdated);
          emlrtMEXProfilingStatement(5, isMexOutdated);
          scale = 3.3121686421112381E-170;
          absxk = muDoubleScalarAbs(x0[0] - obstacles_data[b_i].center[0]);
          if (absxk > 3.3121686421112381E-170) {
            dist_from_center = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            dist_from_center = t * t;
          }
          absxk = muDoubleScalarAbs(x0[1] - obstacles_data[b_i].center[1]);
          if (absxk > scale) {
            t = scale / absxk;
            dist_from_center = dist_from_center * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            dist_from_center += t * t;
          }
          dist_from_center = scale * muDoubleScalarSqrt(dist_from_center);
          emlrtMEXProfilingStatement(6, isMexOutdated);
          scale = 1.0 - obstacles_data[b_i].radius / dist_from_center;
          emlrtMEXProfilingStatement(7, isMexOutdated);
          d_data[(int32_T)j - 1] = scale * dist_from_center;
          emlrtMEXProfilingStatement(8, isMexOutdated);
          r = _mm_loadu_pd(&x0[0]);
          _mm_storeu_pd(
              &q_data[loop_ub_tmp],
              _mm_add_pd(
                  r, _mm_mul_pd(
                         _mm_sub_pd(
                             _mm_loadu_pd(&obstacles_data[b_i].center[0]), r),
                         _mm_set1_pd(scale))));
          emlrtMEXProfilingStatement(9, isMexOutdated);
        }
        emlrtMEXProfilingStatement(34, isMexOutdated);
        emlrtMEXProfilingFunctionExit(isMexOutdated);
        emlrtMEXProfilingStatement(11, isMexOutdated);
        j++;
        emlrtMEXProfilingStatement(12, isMexOutdated);
      }
      emlrtMEXProfilingStatement(13, isMexOutdated);
    }
    emlrtMEXProfilingStatement(14, isMexOutdated);
  }
  emlrtMEXProfilingStatement(15, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (getObstacleInfo.c) */
