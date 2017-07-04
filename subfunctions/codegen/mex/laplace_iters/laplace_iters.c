/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters.c
 *
 * Code generation for function 'laplace_iters'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "laplace_iters_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "imfilter.h"
#include "laplace_iters_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 30,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 34,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 35,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 40,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 46,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 9,   /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 58,  /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 77,  /* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 16,  /* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 67,  /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 7,  /* lineNo */
  "nansum",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/nansum.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 74, /* lineNo */
  "nan_sum_or_mean",                   /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  30,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 34,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = { 30,/* lineNo */
  27,                                  /* colNo */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "rdivide",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/rdivide.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  51,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  41,                                  /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  40,                                  /* lineNo */
  37,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 3,   /* nDims */
  36,                                  /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 3,   /* nDims */
  16,                                  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 23,    /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 23,  /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  17,                                  /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  20,                                  /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/myCode_subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void laplace_iters(const emlrtStack *sp, const emxArray_boolean_T *source, const
                   emxArray_boolean_T *sink, const emxArray_real_T *init, real_T
                   maxiters, emxArray_real_T *LP, emxArray_real_T *iter_change)
{
  emxArray_boolean_T *x;
  int32_T velup;
  int32_T ixstart;
  boolean_T overflow;
  real_T total_vol;
  emxArray_boolean_T *r0;
  emxArray_boolean_T *r1;
  int32_T varargin_2[3];
  int32_T varargin_1[3];
  int32_T n;
  int32_T i;
  uint32_T iters;
  emxArray_real_T *b_velup;
  emxArray_real_T *insulate_correction;
  emxArray_int32_T *r2;
  emxArray_real_T *b_x;
  emxArray_real_T *b_varargin_1;
  boolean_T exitg1;
  boolean_T p;
  boolean_T exitg2;
  uint32_T x_idx_0;
  real_T y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T1(sp, &x, 1, &emlrtRTEI, true);

  /*  iterative averaging filter to solve Laplace equation with greater */
  /*  accuracy than initial fast-marching */
  st.site = &emlrtRSI;
  velup = x->size[0];
  x->size[0] = init->size[0] * init->size[1] * init->size[2];
  emxEnsureCapacity(&st, (emxArray__common *)x, velup, sizeof(boolean_T),
                    &emlrtRTEI);
  ixstart = init->size[0] * init->size[1] * init->size[2];
  for (velup = 0; velup < ixstart; velup++) {
    x->data[velup] = (init->data[velup] >= 0.0);
  }

  b_st.site = &g_emlrtRSI;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&b_st, &n_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  c_st.site = &h_emlrtRSI;
  if (x->size[0] == 0) {
    total_vol = 0.0;
  } else {
    total_vol = x->data[0];
    d_st.site = &i_emlrtRSI;
    overflow = ((!(2 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (ixstart = 2; ixstart <= x->size[0]; ixstart++) {
      total_vol += (real_T)x->data[ixstart - 1];
    }
  }

  emxFree_boolean_T(&x);
  emxInit_boolean_T(&c_st, &r0, 3, &emlrtRTEI, true);
  total_vol /= 100000.0;

  /* change threshold should depend on total volume - greater volumes require more */
  /* filter set-up (26 nearest neighbours) */
  velup = r0->size[0] * r0->size[1] * r0->size[2];
  r0->size[0] = source->size[0];
  r0->size[1] = source->size[1];
  r0->size[2] = source->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)r0, velup, sizeof(boolean_T),
                    &emlrtRTEI);
  ixstart = source->size[0] * source->size[1] * source->size[2];
  for (velup = 0; velup < ixstart; velup++) {
    r0->data[velup] = !source->data[velup];
  }

  emxInit_boolean_T(sp, &r1, 3, &emlrtRTEI, true);
  velup = r1->size[0] * r1->size[1] * r1->size[2];
  r1->size[0] = sink->size[0];
  r1->size[1] = sink->size[1];
  r1->size[2] = sink->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)r1, velup, sizeof(boolean_T),
                    &emlrtRTEI);
  ixstart = sink->size[0] * sink->size[1] * sink->size[2];
  for (velup = 0; velup < ixstart; velup++) {
    r1->data[velup] = !sink->data[velup];
  }

  for (velup = 0; velup < 3; velup++) {
    varargin_2[velup] = r0->size[velup];
    varargin_1[velup] = r1->size[velup];
  }

  emlrtSizeEqCheckNDR2012b(varargin_2, varargin_1, &c_emlrtECI, sp);
  velup = r0->size[0] * r0->size[1] * r0->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)r0, velup, sizeof(boolean_T),
                    &emlrtRTEI);
  velup = r0->size[0];
  ixstart = r0->size[1];
  n = r0->size[2];
  ixstart = velup * ixstart * n;
  for (velup = 0; velup < ixstart; velup++) {
    r0->data[velup] = (r0->data[velup] && r1->data[velup]);
  }

  velup = r1->size[0] * r1->size[1] * r1->size[2];
  r1->size[0] = init->size[0];
  r1->size[1] = init->size[1];
  r1->size[2] = init->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)r1, velup, sizeof(boolean_T),
                    &emlrtRTEI);
  ixstart = init->size[0] * init->size[1] * init->size[2];
  for (velup = 0; velup < ixstart; velup++) {
    r1->data[velup] = muDoubleScalarIsNaN(init->data[velup]);
  }

  for (velup = 0; velup < 3; velup++) {
    varargin_2[velup] = r0->size[velup];
    varargin_1[velup] = r1->size[velup];
  }

  emlrtSizeEqCheckNDR2012b(varargin_2, varargin_1, &c_emlrtECI, sp);

  /* set up vel */
  velup = LP->size[0] * LP->size[1] * LP->size[2];
  LP->size[0] = init->size[0];
  LP->size[1] = init->size[1];
  LP->size[2] = init->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)LP, velup, sizeof(real_T),
                    &emlrtRTEI);
  ixstart = init->size[0] * init->size[1] * init->size[2];
  for (velup = 0; velup < ixstart; velup++) {
    LP->data[velup] = init->data[velup];
  }

  /* geodist to initialize greymatter */
  n = source->size[0] * (source->size[1] * source->size[2]);
  for (i = 0; i < n; i++) {
    if (source->data[i]) {
      velup = LP->size[0] * LP->size[1] * LP->size[2];
      if (!((i + 1 >= 1) && (i + 1 <= velup))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &l_emlrtBCI, sp);
      }

      LP->data[i] = 0.0;
    }
  }

  n = sink->size[0] * (sink->size[1] * sink->size[2]);
  for (i = 0; i < n; i++) {
    if (sink->data[i]) {
      velup = LP->size[0] * LP->size[1] * LP->size[2];
      if (!((i + 1 >= 1) && (i + 1 <= velup))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &k_emlrtBCI, sp);
      }

      LP->data[i] = 1.0;
    }
  }

  n = r0->size[0] * (r0->size[1] * r0->size[2]);
  for (i = 0; i < n; i++) {
    if (r0->data[i] && r1->data[i]) {
      velup = LP->size[0] * LP->size[1] * LP->size[2];
      if (!((i + 1 >= 1) && (i + 1 <= velup))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &j_emlrtBCI, sp);
      }

      LP->data[i] = 0.0;
    }
  }

  /* must be insulated after filtering */
  velup = iter_change->size[0] * iter_change->size[1];
  iter_change->size[0] = 1;
  if (!(maxiters >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxiters, &b_emlrtDCI, sp);
  }

  if (maxiters != (int32_T)muDoubleScalarFloor(maxiters)) {
    emlrtIntegerCheckR2012b(maxiters, &emlrtDCI, sp);
  }

  iter_change->size[1] = (int32_T)maxiters;
  emxEnsureCapacity(sp, (emxArray__common *)iter_change, velup, sizeof(real_T),
                    &emlrtRTEI);
  if (!(maxiters >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxiters, &b_emlrtDCI, sp);
  }

  if (maxiters != (int32_T)muDoubleScalarFloor(maxiters)) {
    emlrtIntegerCheckR2012b(maxiters, &emlrtDCI, sp);
  }

  ixstart = (int32_T)maxiters;
  for (velup = 0; velup < ixstart; velup++) {
    iter_change->data[velup] = 0.0;
  }

  /*  apply filter */
  iters = 0U;
  emxInit_real_T(sp, &b_velup, 3, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &insulate_correction, 3, &c_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_x, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_varargin_1, 1, &emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (iters < maxiters)) {
    /* max iterations */
    iters++;
    velup = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
    b_velup->size[0] = LP->size[0];
    b_velup->size[1] = LP->size[1];
    b_velup->size[2] = LP->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)b_velup, velup, sizeof(real_T),
                      &emlrtRTEI);
    ixstart = LP->size[0] * LP->size[1] * LP->size[2];
    for (velup = 0; velup < ixstart; velup++) {
      b_velup->data[velup] = LP->data[velup];
    }

    st.site = &b_emlrtRSI;
    imfilter(&st, b_velup);

    /* apply averaging filter */
    /* insulate the grey matter so gradient doesn't pass between folds - */
    /* inspired by ndnanfilter */
    velup = insulate_correction->size[0] * insulate_correction->size[1] *
      insulate_correction->size[2];
    insulate_correction->size[0] = r0->size[0];
    insulate_correction->size[1] = r0->size[1];
    insulate_correction->size[2] = r0->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)insulate_correction, velup, sizeof
                      (real_T), &emlrtRTEI);
    ixstart = r0->size[0] * r0->size[1] * r0->size[2];
    for (velup = 0; velup < ixstart; velup++) {
      insulate_correction->data[velup] = !(r0->data[velup] && r1->data[velup]);
    }

    st.site = &c_emlrtRSI;
    imfilter(&st, insulate_correction);
    st.site = &d_emlrtRSI;
    for (velup = 0; velup < 3; velup++) {
      varargin_1[velup] = b_velup->size[velup];
      varargin_2[velup] = insulate_correction->size[velup];
    }

    overflow = false;
    p = true;
    ixstart = 0;
    exitg2 = false;
    while ((!exitg2) && (ixstart < 3)) {
      if (!(varargin_1[ixstart] == varargin_2[ixstart])) {
        p = false;
        exitg2 = true;
      } else {
        ixstart++;
      }
    }

    if (p) {
      overflow = true;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&st, &m_emlrtRTEI, "MATLAB:dimagree", 0);
    }

    velup = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
    emxEnsureCapacity(&st, (emxArray__common *)b_velup, velup, sizeof(real_T),
                      &emlrtRTEI);
    ixstart = b_velup->size[0];
    n = b_velup->size[1];
    velup = b_velup->size[2];
    ixstart = ixstart * n * velup;
    for (velup = 0; velup < ixstart; velup++) {
      b_velup->data[velup] /= insulate_correction->data[velup];
    }

    for (velup = 0; velup < 3; velup++) {
      varargin_2[velup] = r0->size[velup];
    }

    for (velup = 0; velup < 3; velup++) {
      varargin_1[velup] = source->size[velup];
    }

    emlrtSizeEqCheckNDR2012b(varargin_2, varargin_1, &b_emlrtECI, sp);
    n = r0->size[0] * (r0->size[1] * r0->size[2]);
    for (i = 0; i < n; i++) {
      if ((r0->data[i] && r1->data[i]) || source->data[i]) {
        velup = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
        if (!((i + 1 >= 1) && (i + 1 <= velup))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &i_emlrtBCI, sp);
        }

        b_velup->data[i] = 0.0;
      }
    }

    n = sink->size[0] * (sink->size[1] * sink->size[2]);
    for (i = 0; i < n; i++) {
      if (sink->data[i]) {
        velup = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
        if (!((i + 1 >= 1) && (i + 1 <= velup))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &h_emlrtBCI, sp);
        }

        b_velup->data[i] = 1.0;
      }
    }

    /* stopping condition */
    st.site = &e_emlrtRSI;
    indexShapeCheck(&st, *(int32_T (*)[3])LP->size, init->size[0] * init->size[1]
                    * init->size[2]);
    st.site = &e_emlrtRSI;
    indexShapeCheck(&st, *(int32_T (*)[3])b_velup->size, init->size[0] *
                    init->size[1] * init->size[2]);
    n = init->size[0] * init->size[1] * init->size[2];
    for (i = 0; i < n; i++) {
      if (init->data[i] >= 0.0) {
        velup = LP->size[0] * LP->size[1] * LP->size[2];
        if (!((i + 1 >= 1) && (i + 1 <= velup))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &c_emlrtBCI, sp);
        }
      }
    }

    n = init->size[0] * init->size[1] * init->size[2];
    for (i = 0; i < n; i++) {
      if (init->data[i] >= 0.0) {
        velup = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
        if (!((i + 1 >= 1) && (i + 1 <= velup))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &b_emlrtBCI, sp);
        }
      }
    }

    n = init->size[0] * init->size[1] * init->size[2];
    ixstart = 0;
    for (i = 0; i < n; i++) {
      if (init->data[i] >= 0.0) {
        ixstart++;
      }
    }

    n = init->size[0] * init->size[1] * init->size[2];
    velup = 0;
    for (i = 0; i < n; i++) {
      if (init->data[i] >= 0.0) {
        velup++;
      }
    }

    if (ixstart != velup) {
      emlrtSizeEqCheck1DR2012b(ixstart, velup, &emlrtECI, sp);
    }

    n = init->size[0] * init->size[1] * init->size[2] - 1;
    ixstart = 0;
    for (i = 0; i <= n; i++) {
      if (init->data[i] >= 0.0) {
        ixstart++;
      }
    }

    velup = r2->size[0];
    r2->size[0] = ixstart;
    emxEnsureCapacity(sp, (emxArray__common *)r2, velup, sizeof(int32_T),
                      &emlrtRTEI);
    ixstart = 0;
    for (i = 0; i <= n; i++) {
      if (init->data[i] >= 0.0) {
        r2->data[ixstart] = i + 1;
        ixstart++;
      }
    }

    st.site = &e_emlrtRSI;
    velup = b_x->size[0];
    b_x->size[0] = r2->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)b_x, velup, sizeof(real_T),
                      &emlrtRTEI);
    ixstart = r2->size[0];
    for (velup = 0; velup < ixstart; velup++) {
      b_x->data[velup] = LP->data[r2->data[velup] - 1] - b_velup->data[r2->
        data[velup] - 1];
    }

    b_st.site = &x_emlrtRSI;
    x_idx_0 = (uint32_T)b_x->size[0];
    velup = b_varargin_1->size[0];
    b_varargin_1->size[0] = (int32_T)x_idx_0;
    emxEnsureCapacity(&b_st, (emxArray__common *)b_varargin_1, velup, sizeof
                      (real_T), &emlrtRTEI);
    c_st.site = &y_emlrtRSI;
    overflow = ((!(1 > b_x->size[0])) && (b_x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ixstart = 0; ixstart + 1 <= b_x->size[0]; ixstart++) {
      b_varargin_1->data[ixstart] = muDoubleScalarAbs(b_x->data[ixstart]);
    }

    st.site = &e_emlrtRSI;
    b_st.site = &ab_emlrtRSI;
    if ((b_varargin_1->size[0] == 1) || (b_varargin_1->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (b_varargin_1->size[0] == 0) {
      y = 0.0;
    } else {
      y = 0.0;
      c_st.site = &bb_emlrtRSI;
      overflow = (b_varargin_1->size[0] > 2147483646);
      if (overflow) {
        d_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (ixstart = 1; ixstart <= b_varargin_1->size[0]; ixstart++) {
        velup = b_varargin_1->size[0];
        if (!((ixstart >= 1) && (ixstart <= velup))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, velup, &emlrtBCI, &b_st);
        }

        if (!muDoubleScalarIsNaN(b_varargin_1->data[ixstart - 1])) {
          velup = b_varargin_1->size[0];
          if (!((ixstart >= 1) && (ixstart <= velup))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, velup, &d_emlrtBCI, &b_st);
          }

          y += b_varargin_1->data[ixstart - 1];
        }
      }
    }

    velup = iter_change->size[1];
    ixstart = (int32_T)iters;
    if (!((ixstart >= 1) && (ixstart <= velup))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, velup, &e_emlrtBCI, sp);
    }

    iter_change->data[ixstart - 1] = y;

    /* compute change from last iteration */
    velup = LP->size[0] * LP->size[1] * LP->size[2];
    LP->size[0] = b_velup->size[0];
    LP->size[1] = b_velup->size[1];
    LP->size[2] = b_velup->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)LP, velup, sizeof(real_T),
                      &emlrtRTEI);
    ixstart = b_velup->size[0] * b_velup->size[1] * b_velup->size[2];
    for (velup = 0; velup < ixstart; velup++) {
      LP->data[velup] = b_velup->data[velup];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    velup = iter_change->size[1];
    ixstart = (int32_T)iters;
    if (!((ixstart >= 1) && (ixstart <= velup))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, velup, &f_emlrtBCI, sp);
    }

    if (iter_change->data[ixstart - 1] < total_vol) {
      exitg1 = true;
    }
  }

  emxFree_real_T(&b_varargin_1);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&r0);
  emxFree_real_T(&insulate_correction);
  emxFree_real_T(&b_velup);
  st.site = &f_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  if ((LP->size[0] * LP->size[1] * LP->size[2] == 1) || (LP->size[0] * LP->size
       [1] * LP->size[2] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (!(LP->size[0] * LP->size[1] * LP->size[2] > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &j_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &eb_emlrtRSI;
  ixstart = 1;
  n = LP->size[0] * LP->size[1] * LP->size[2];
  total_vol = LP->data[0];
  if (LP->size[0] * LP->size[1] * LP->size[2] > 1) {
    if (muDoubleScalarIsNaN(LP->data[0])) {
      e_st.site = &gb_emlrtRSI;
      overflow = ((!(2 > LP->size[0] * LP->size[1] * LP->size[2])) && (LP->size
        [0] * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        f_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      velup = 2;
      exitg1 = false;
      while ((!exitg1) && (velup <= n)) {
        ixstart = velup;
        if (!muDoubleScalarIsNaN(LP->data[velup - 1])) {
          total_vol = LP->data[velup - 1];
          exitg1 = true;
        } else {
          velup++;
        }
      }
    }

    if (ixstart < LP->size[0] * LP->size[1] * LP->size[2]) {
      e_st.site = &fb_emlrtRSI;
      overflow = ((!(ixstart + 1 > LP->size[0] * LP->size[1] * LP->size[2])) &&
                  (LP->size[0] * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        f_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (LP->data[ixstart] > total_vol) {
          total_vol = LP->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  velup = LP->size[0] * LP->size[1] * LP->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)LP, velup, sizeof(real_T),
                    &emlrtRTEI);
  velup = LP->size[0];
  ixstart = LP->size[1];
  n = LP->size[2];
  ixstart = velup * ixstart * n;
  for (velup = 0; velup < ixstart; velup++) {
    LP->data[velup] /= total_vol;
  }

  n = init->size[0] * init->size[1] * init->size[2];
  for (i = 0; i < n; i++) {
    if (!(init->data[i] >= 0.0)) {
      velup = LP->size[0] * LP->size[1] * LP->size[2];
      if (!((i + 1 >= 1) && (i + 1 <= velup))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, velup, &g_emlrtBCI, sp);
      }

      LP->data[i] = rtNaN;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (laplace_iters.c) */
