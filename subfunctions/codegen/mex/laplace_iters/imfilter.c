/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "imfilter.h"
#include "laplace_iters_emxutil.h"
#include "libmwimfilter.h"

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = { 138,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 142,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 565,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 20, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 65, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 77, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 18, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 484,/* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 595,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 667,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 558,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 587,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 44,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtDCInfo j_emlrtDCI = { 575, /* lineNo */
  33,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  594,                                 /* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtDCInfo k_emlrtDCI = { 80,  /* lineNo */
  56,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp, const
                     real_T pad[3], emxArray_real_T *a);

/* Function Definitions */
static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp, const
                     real_T pad[3], emxArray_real_T *a)
{
  int32_T i1;
  real_T sizeA[3];
  real_T varargin_1[3];
  uint32_T b_sizeA[3];
  int32_T k;
  uint32_T mtmp;
  int32_T exitg1;
  int32_T ix;
  boolean_T p;
  emxArray_int32_T *idxA;
  emxArray_real_T *y;
  real_T n;
  emxArray_uint32_T *idxDir;
  emxArray_int32_T *r0;
  uint32_T u0;
  emxArray_int32_T *b_idxDir;
  int32_T iv0[1];
  emxArray_int32_T *c_idxDir;
  emxArray_int32_T *d_idxDir;
  int32_T j;
  int32_T i2;
  int32_T i;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &sb_emlrtRSI;
  b_st.site = &tb_emlrtRSI;
  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0) || (a_tmp->size[2] == 0)) {
    for (i1 = 0; i1 < 3; i1++) {
      sizeA[i1] = (real_T)a_tmp->size[i1] + 2.0 * pad[i1];
    }

    b_st.site = &ub_emlrtRSI;
    varargin_1[0] = sizeA[0];
    varargin_1[1] = sizeA[1];
    varargin_1[2] = sizeA[2];
    c_st.site = &wb_emlrtRSI;
    k = 0;
    do {
      exitg1 = 0;
      if (k < 3) {
        if ((varargin_1[k] != varargin_1[k]) || muDoubleScalarIsInf(varargin_1[k]))
        {
          p = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (p) {
      k = 0;
      do {
        exitg1 = 0;
        if (k < 3) {
          if (2.147483647E+9 < varargin_1[k]) {
            p = false;
            exitg1 = 1;
          } else {
            k++;
          }
        } else {
          p = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (p) {
        p = true;
      } else {
        p = false;
      }
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eb_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
    }

    n = 1.0;
    for (k = 0; k < 3; k++) {
      n *= varargin_1[k];
    }

    if (!(2.147483647E+9 >= n)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &db_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    i1 = a->size[0] * a->size[1] * a->size[2];
    a->size[0] = (int32_T)sizeA[0];
    a->size[1] = (int32_T)sizeA[1];
    a->size[2] = (int32_T)sizeA[2];
    emxEnsureCapacity(&b_st, (emxArray__common *)a, i1, sizeof(real_T),
                      &k_emlrtRTEI);
    ix = (int32_T)sizeA[0] * (int32_T)sizeA[1] * (int32_T)sizeA[2];
    for (i1 = 0; i1 < ix; i1++) {
      a->data[i1] = 0.0;
    }
  } else {
    for (i1 = 0; i1 < 3; i1++) {
      sizeA[i1] = a_tmp->size[i1];
    }

    b_st.site = &vb_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    b_sizeA[0] = (uint32_T)sizeA[0];
    b_sizeA[1] = (uint32_T)sizeA[1];
    b_sizeA[2] = (uint32_T)sizeA[2];
    for (i1 = 0; i1 < 3; i1++) {
      varargin_1[i1] = 2.0 + (real_T)b_sizeA[i1];
    }

    mtmp = (uint32_T)varargin_1[0];
    for (ix = 1; ix + 1 < 4; ix++) {
      if ((uint32_T)varargin_1[ix] > mtmp) {
        mtmp = (uint32_T)varargin_1[ix];
      }
    }

    emxInit_int32_T1(&c_st, &idxA, 2, &l_emlrtRTEI, true);
    emxInit_real_T(&c_st, &y, 2, &k_emlrtRTEI, true);
    if ((real_T)mtmp != (int32_T)mtmp) {
      emlrtIntegerCheckR2012b(mtmp, &j_emlrtDCI, &c_st);
    }

    i1 = idxA->size[0] * idxA->size[1];
    idxA->size[0] = (int32_T)mtmp;
    idxA->size[1] = 3;
    emxEnsureCapacity(&c_st, (emxArray__common *)idxA, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)((real_T)(uint32_T)sizeA[0] - 1.0) + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i1, sizeof(real_T),
                      &k_emlrtRTEI);
    ix = (int32_T)((real_T)(uint32_T)sizeA[0] - 1.0);
    for (i1 = 0; i1 <= ix; i1++) {
      y->data[y->size[0] * i1] = 1.0 + (real_T)i1;
    }

    emxInit_uint32_T(&c_st, &idxDir, 2, &m_emlrtRTEI, true);
    i1 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i1, sizeof(uint32_T),
                      &k_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      n = muDoubleScalarRound(y->data[y->size[0] * i1]);
      if (n < 4.294967296E+9) {
        if (n >= 0.0) {
          u0 = (uint32_T)n;
        } else {
          u0 = 0U;
        }
      } else if (n >= 4.294967296E+9) {
        u0 = MAX_uint32_T;
      } else {
        u0 = 0U;
      }

      idxDir->data[idxDir->size[0] * (i1 + 1)] = u0;
    }

    emxInit_int32_T(&c_st, &r0, 1, &k_emlrtRTEI, true);
    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[0];
    i1 = (int32_T)mtmp;
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i1, &p_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r0, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    emxInit_int32_T1(&c_st, &b_idxDir, 2, &k_emlrtRTEI, true);
    iv0[0] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &c_emlrtECI, &c_st);
    i1 = b_idxDir->size[0] * b_idxDir->size[1];
    b_idxDir->size[0] = 1;
    b_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)b_idxDir, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    ix = idxDir->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      b_idxDir->data[b_idxDir->size[0] * i1] = (int32_T)idxDir->data
        [idxDir->size[0] * i1];
    }

    ix = r0->size[0];
    for (i1 = 0; i1 < ix; i1++) {
      idxA->data[r0->data[i1]] = b_idxDir->data[i1];
    }

    emxFree_int32_T(&b_idxDir);
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)((real_T)(uint32_T)sizeA[1] - 1.0) + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i1, sizeof(real_T),
                      &k_emlrtRTEI);
    ix = (int32_T)((real_T)(uint32_T)sizeA[1] - 1.0);
    for (i1 = 0; i1 <= ix; i1++) {
      y->data[y->size[0] * i1] = 1.0 + (real_T)i1;
    }

    i1 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i1, sizeof(uint32_T),
                      &k_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      n = muDoubleScalarRound(y->data[y->size[0] * i1]);
      if (n < 4.294967296E+9) {
        if (n >= 0.0) {
          u0 = (uint32_T)n;
        } else {
          u0 = 0U;
        }
      } else if (n >= 4.294967296E+9) {
        u0 = MAX_uint32_T;
      } else {
        u0 = 0U;
      }

      idxDir->data[idxDir->size[0] * (i1 + 1)] = u0;
    }

    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[1];
    i1 = idxA->size[0];
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i1, &p_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r0, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    emxInit_int32_T1(&c_st, &c_idxDir, 2, &k_emlrtRTEI, true);
    iv0[0] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &c_emlrtECI, &c_st);
    i1 = c_idxDir->size[0] * c_idxDir->size[1];
    c_idxDir->size[0] = 1;
    c_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)c_idxDir, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    ix = idxDir->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      c_idxDir->data[c_idxDir->size[0] * i1] = (int32_T)idxDir->data
        [idxDir->size[0] * i1];
    }

    ix = r0->size[0];
    for (i1 = 0; i1 < ix; i1++) {
      idxA->data[r0->data[i1] + idxA->size[0]] = c_idxDir->data[i1];
    }

    emxFree_int32_T(&c_idxDir);
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)((real_T)(uint32_T)sizeA[2] - 1.0) + 1;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i1, sizeof(real_T),
                      &k_emlrtRTEI);
    ix = (int32_T)((real_T)(uint32_T)sizeA[2] - 1.0);
    for (i1 = 0; i1 <= ix; i1++) {
      y->data[y->size[0] * i1] = 1.0 + (real_T)i1;
    }

    i1 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i1, sizeof(uint32_T),
                      &k_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      n = muDoubleScalarRound(y->data[y->size[0] * i1]);
      if (n < 4.294967296E+9) {
        if (n >= 0.0) {
          u0 = (uint32_T)n;
        } else {
          u0 = 0U;
        }
      } else if (n >= 4.294967296E+9) {
        u0 = MAX_uint32_T;
      } else {
        u0 = 0U;
      }

      idxDir->data[idxDir->size[0] * (i1 + 1)] = u0;
    }

    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[2];
    i1 = idxA->size[0];
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i1, &p_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r0, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    emxFree_real_T(&y);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    emxInit_int32_T1(&c_st, &d_idxDir, 2, &k_emlrtRTEI, true);
    iv0[0] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &c_emlrtECI, &c_st);
    i1 = d_idxDir->size[0] * d_idxDir->size[1];
    d_idxDir->size[0] = 1;
    d_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)d_idxDir, i1, sizeof(int32_T),
                      &k_emlrtRTEI);
    ix = idxDir->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      d_idxDir->data[d_idxDir->size[0] * i1] = (int32_T)idxDir->data
        [idxDir->size[0] * i1];
    }

    emxFree_uint32_T(&idxDir);
    ix = r0->size[0];
    for (i1 = 0; i1 < ix; i1++) {
      idxA->data[r0->data[i1] + (idxA->size[0] << 1)] = d_idxDir->data[i1];
    }

    emxFree_int32_T(&d_idxDir);
    emxFree_int32_T(&r0);
    for (i1 = 0; i1 < 3; i1++) {
      n = (real_T)a_tmp->size[i1] + 2.0 * pad[i1];
      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &k_emlrtDCI, &st);
      }

      sizeA[i1] = n;
    }

    i1 = a->size[0] * a->size[1] * a->size[2];
    a->size[0] = (int32_T)sizeA[0];
    a->size[1] = (int32_T)sizeA[1];
    a->size[2] = (int32_T)sizeA[2];
    emxEnsureCapacity(&st, (emxArray__common *)a, i1, sizeof(real_T),
                      &k_emlrtRTEI);
    i1 = a->size[2];
    for (k = 1; k - 1 < i1; k++) {
      ix = a->size[1];
      for (j = 1; j - 1 < ix; j++) {
        i2 = a->size[0];
        for (i = 1; i - 1 < i2; i++) {
          i3 = a_tmp->size[0];
          i4 = idxA->size[0];
          if (!((i >= 1) && (i <= i4))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i4, &r_emlrtBCI, &st);
          }

          i4 = idxA->data[i - 1];
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &q_emlrtBCI, &st);
          }

          i3 = a_tmp->size[1];
          i5 = idxA->size[0];
          if (!((j >= 1) && (j <= i5))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i5, &t_emlrtBCI, &st);
          }

          i5 = idxA->data[(j + idxA->size[0]) - 1];
          if (!((i5 >= 1) && (i5 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i3, &s_emlrtBCI, &st);
          }

          i3 = a_tmp->size[2];
          i6 = idxA->size[0];
          if (!((k >= 1) && (k <= i6))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i6, &v_emlrtBCI, &st);
          }

          i6 = idxA->data[(k + (idxA->size[0] << 1)) - 1];
          if (!((i6 >= 1) && (i6 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i6, 1, i3, &u_emlrtBCI, &st);
          }

          i3 = a->size[0];
          if (!((i >= 1) && (i <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i3, &w_emlrtBCI, &st);
          }

          i3 = a->size[1];
          if (!((j >= 1) && (j <= i3))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i3, &x_emlrtBCI, &st);
          }

          i3 = a->size[2];
          if (!((k >= 1) && (k <= i3))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i3, &y_emlrtBCI, &st);
          }

          a->data[((i + a->size[0] * (j - 1)) + a->size[0] * a->size[1] * (k - 1))
            - 1] = a_tmp->data[((i4 + a_tmp->size[0] * (i5 - 1)) + a_tmp->size[0]
                                * a_tmp->size[1] * (i6 - 1)) - 1];
        }
      }
    }

    emxFree_int32_T(&idxA);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void imfilter(const emlrtStack *sp, emxArray_real_T *varargin_1)
{
  real_T finalSize[3];
  real_T pad[3];
  emxArray_real_T *a;
  int32_T i;
  real_T padSize[3];
  real_T nonZeroKernel[26];
  real_T connDims[3];
  static const boolean_T conn[27] = { true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, true, true, true, true, true,
    true, true, true, true, true, true, true, true };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  finalSize[0] = varargin_1->size[0];
  pad[0] = 1.0;
  finalSize[1] = varargin_1->size[1];
  pad[1] = 1.0;
  finalSize[2] = varargin_1->size[2];
  pad[2] = 1.0;
  if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0) ||
        (varargin_1->size[2] == 0))) {
    emxInit_real_T2(sp, &a, 3, &t_emlrtRTEI, true);
    st.site = &qb_emlrtRSI;
    padImage(&st, varargin_1, pad, a);
    st.site = &rb_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    c_st.site = &ac_emlrtRSI;
    i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
    varargin_1->size[0] = (int32_T)finalSize[0];
    varargin_1->size[1] = (int32_T)finalSize[1];
    varargin_1->size[2] = (int32_T)finalSize[2];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i, sizeof(real_T),
                      &j_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      padSize[i] = a->size[i];
    }

    for (i = 0; i < 26; i++) {
      nonZeroKernel[i] = 0.038461538461538464;
    }

    for (i = 0; i < 3; i++) {
      connDims[i] = 3.0;
    }

    imfilter_real64(&a->data[0], &varargin_1->data[0], 3.0, finalSize, 3.0,
                    padSize, nonZeroKernel, 26.0, conn, 3.0, connDims, pad, 3.0,
                    true, true);
    emxFree_real_T(&a);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (imfilter.c) */
