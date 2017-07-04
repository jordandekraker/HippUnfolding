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
static emlrtRSInfo k_emlrtRSI = { 138, /* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 142, /* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 565, /* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 20,  /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 65,  /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 77,  /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 18,  /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 484, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 595, /* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 667, /* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 558,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 587,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  594,                                 /* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 575, /* lineNo */
  33,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo p_emlrtRTEI = { 44,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtDCInfo d_emlrtDCI = { 80,  /* lineNo */
  56,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
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
  int32_T i0;
  real_T sizeA[3];
  real_T varargin_1[3];
  uint32_T b_sizeA[3];
  int32_T k;
  uint32_T mtmp;
  int32_T exitg1;
  int32_T ix;
  boolean_T p;
  emxArray_int32_T *idxA;
  emxArray_uint32_T *y;
  real_T n;
  emxArray_uint32_T *idxDir;
  emxArray_int32_T *r3;
  emxArray_int32_T *b_idxDir;
  int32_T iv0[1];
  emxArray_int32_T *c_idxDir;
  emxArray_int32_T *d_idxDir;
  int32_T j;
  int32_T i1;
  int32_T i;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
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
  st.site = &m_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0) || (a_tmp->size[2] == 0)) {
    for (i0 = 0; i0 < 3; i0++) {
      sizeA[i0] = (real_T)a_tmp->size[i0] + 2.0 * pad[i0];
    }

    b_st.site = &o_emlrtRSI;
    varargin_1[0] = sizeA[0];
    varargin_1[1] = sizeA[1];
    varargin_1[2] = sizeA[2];
    c_st.site = &q_emlrtRSI;
    k = 0;
    do {
      exitg1 = 0;
      if (k < 3) {
        if (varargin_1[k] != varargin_1[k]) {
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
      emlrtErrorWithMessageIdR2012b(&c_st, &p_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
    }

    n = 1.0;
    for (k = 0; k < 3; k++) {
      n *= varargin_1[k];
    }

    if (!(2.147483647E+9 >= n)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    i0 = a->size[0] * a->size[1] * a->size[2];
    a->size[0] = (int32_T)sizeA[0];
    a->size[1] = (int32_T)sizeA[1];
    a->size[2] = (int32_T)sizeA[2];
    emxEnsureCapacity(&b_st, (emxArray__common *)a, i0, sizeof(real_T),
                      &e_emlrtRTEI);
    ix = (int32_T)sizeA[0] * (int32_T)sizeA[1] * (int32_T)sizeA[2];
    for (i0 = 0; i0 < ix; i0++) {
      a->data[i0] = 0.0;
    }
  } else {
    for (i0 = 0; i0 < 3; i0++) {
      sizeA[i0] = a_tmp->size[i0];
    }

    b_st.site = &p_emlrtRSI;
    c_st.site = &r_emlrtRSI;
    b_sizeA[0] = (uint32_T)sizeA[0];
    b_sizeA[1] = (uint32_T)sizeA[1];
    b_sizeA[2] = (uint32_T)sizeA[2];
    for (i0 = 0; i0 < 3; i0++) {
      varargin_1[i0] = 2.0 + (real_T)b_sizeA[i0];
    }

    mtmp = (uint32_T)varargin_1[0];
    for (ix = 0; ix < 2; ix++) {
      if ((uint32_T)varargin_1[ix + 1] > mtmp) {
        mtmp = (uint32_T)varargin_1[ix + 1];
      }
    }

    emxInit_int32_T1(&c_st, &idxA, 2, &f_emlrtRTEI, true);
    emxInit_uint32_T(&c_st, &y, 2, &e_emlrtRTEI, true);
    if ((real_T)mtmp != (int32_T)mtmp) {
      emlrtIntegerCheckR2012b(mtmp, &c_emlrtDCI, &c_st);
    }

    i0 = idxA->size[0] * idxA->size[1];
    idxA->size[0] = (int32_T)mtmp;
    idxA->size[1] = 3;
    emxEnsureCapacity(&c_st, (emxArray__common *)idxA, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)(uint32_T)sizeA[0];
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    ix = (int32_T)((uint32_T)sizeA[0] + MAX_uint32_T);
    for (i0 = 0; i0 <= ix; i0++) {
      y->data[y->size[0] * i0] = 1U + i0;
    }

    emxInit_uint32_T(&c_st, &idxDir, 2, &g_emlrtRTEI, true);
    i0 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      idxDir->data[idxDir->size[0] * (i0 + 1)] = y->data[y->size[0] * i0];
    }

    emxInit_int32_T(&c_st, &r3, 1, &e_emlrtRTEI, true);
    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[0];
    i0 = (int32_T)mtmp;
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i0))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &m_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i0 = r3->size[0];
    r3->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r3, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i0 = 0; i0 < ix; i0++) {
      r3->data[i0] = i0;
    }

    emxInit_int32_T1(&c_st, &b_idxDir, 2, &e_emlrtRTEI, true);
    iv0[0] = r3->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &d_emlrtECI, &c_st);
    i0 = b_idxDir->size[0] * b_idxDir->size[1];
    b_idxDir->size[0] = 1;
    b_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)b_idxDir, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    ix = idxDir->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      b_idxDir->data[b_idxDir->size[0] * i0] = (int32_T)idxDir->data
        [idxDir->size[0] * i0];
    }

    ix = r3->size[0];
    for (i0 = 0; i0 < ix; i0++) {
      idxA->data[r3->data[i0]] = b_idxDir->data[i0];
    }

    emxFree_int32_T(&b_idxDir);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)(uint32_T)sizeA[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    ix = (int32_T)((uint32_T)sizeA[1] + MAX_uint32_T);
    for (i0 = 0; i0 <= ix; i0++) {
      y->data[y->size[0] * i0] = 1U + i0;
    }

    i0 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      idxDir->data[idxDir->size[0] * (i0 + 1)] = y->data[y->size[0] * i0];
    }

    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[1];
    i0 = idxA->size[0];
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i0))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &m_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i0 = r3->size[0];
    r3->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r3, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    for (i0 = 0; i0 < ix; i0++) {
      r3->data[i0] = i0;
    }

    emxInit_int32_T1(&c_st, &c_idxDir, 2, &e_emlrtRTEI, true);
    iv0[0] = r3->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &d_emlrtECI, &c_st);
    i0 = c_idxDir->size[0] * c_idxDir->size[1];
    c_idxDir->size[0] = 1;
    c_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)c_idxDir, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    ix = idxDir->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      c_idxDir->data[c_idxDir->size[0] * i0] = (int32_T)idxDir->data
        [idxDir->size[0] * i0];
    }

    ix = r3->size[0];
    for (i0 = 0; i0 < ix; i0++) {
      idxA->data[r3->data[i0] + idxA->size[0]] = c_idxDir->data[i0];
    }

    emxFree_int32_T(&c_idxDir);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)(uint32_T)sizeA[2];
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    ix = (int32_T)((uint32_T)sizeA[2] + MAX_uint32_T);
    for (i0 = 0; i0 <= ix; i0++) {
      y->data[y->size[0] * i0] = 1U + i0;
    }

    i0 = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 2 + y->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)idxDir, i0, sizeof(uint32_T),
                      &e_emlrtRTEI);
    idxDir->data[0] = 1U;
    ix = y->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      idxDir->data[idxDir->size[0] * (i0 + 1)] = y->data[y->size[0] * i0];
    }

    idxDir->data[idxDir->size[0] * (1 + y->size[1])] = (uint32_T)sizeA[2];
    i0 = idxA->size[0];
    ix = idxDir->size[1];
    if (!((ix >= 1) && (ix <= i0))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &m_emlrtBCI, &c_st);
    }

    ix = idxDir->size[1];
    i0 = r3->size[0];
    r3->size[0] = ix;
    emxEnsureCapacity(&c_st, (emxArray__common *)r3, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    emxFree_uint32_T(&y);
    for (i0 = 0; i0 < ix; i0++) {
      r3->data[i0] = i0;
    }

    emxInit_int32_T1(&c_st, &d_idxDir, 2, &e_emlrtRTEI, true);
    iv0[0] = r3->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[2])idxDir->size, 2,
      &d_emlrtECI, &c_st);
    i0 = d_idxDir->size[0] * d_idxDir->size[1];
    d_idxDir->size[0] = 1;
    d_idxDir->size[1] = idxDir->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)d_idxDir, i0, sizeof(int32_T),
                      &e_emlrtRTEI);
    ix = idxDir->size[1];
    for (i0 = 0; i0 < ix; i0++) {
      d_idxDir->data[d_idxDir->size[0] * i0] = (int32_T)idxDir->data
        [idxDir->size[0] * i0];
    }

    emxFree_uint32_T(&idxDir);
    ix = r3->size[0];
    for (i0 = 0; i0 < ix; i0++) {
      idxA->data[r3->data[i0] + (idxA->size[0] << 1)] = d_idxDir->data[i0];
    }

    emxFree_int32_T(&d_idxDir);
    emxFree_int32_T(&r3);
    for (i0 = 0; i0 < 3; i0++) {
      n = (real_T)a_tmp->size[i0] + 2.0 * pad[i0];
      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &d_emlrtDCI, &st);
      }

      sizeA[i0] = n;
    }

    i0 = a->size[0] * a->size[1] * a->size[2];
    a->size[0] = (int32_T)sizeA[0];
    a->size[1] = (int32_T)sizeA[1];
    a->size[2] = (int32_T)sizeA[2];
    emxEnsureCapacity(&st, (emxArray__common *)a, i0, sizeof(real_T),
                      &e_emlrtRTEI);
    i0 = a->size[2];
    for (k = 1; k - 1 < i0; k++) {
      ix = a->size[1];
      for (j = 1; j - 1 < ix; j++) {
        i1 = a->size[0];
        for (i = 1; i - 1 < i1; i++) {
          i2 = a_tmp->size[0];
          i3 = idxA->size[0];
          if (!((i >= 1) && (i <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i3, &o_emlrtBCI, &st);
          }

          i3 = idxA->data[i - 1];
          if (!((i3 >= 1) && (i3 <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &n_emlrtBCI, &st);
          }

          i2 = a_tmp->size[1];
          i4 = idxA->size[0];
          if (!((j >= 1) && (j <= i4))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i4, &q_emlrtBCI, &st);
          }

          i4 = idxA->data[(j + idxA->size[0]) - 1];
          if (!((i4 >= 1) && (i4 <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i2, &p_emlrtBCI, &st);
          }

          i2 = a_tmp->size[2];
          i5 = idxA->size[0];
          if (!((k >= 1) && (k <= i5))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i5, &s_emlrtBCI, &st);
          }

          i5 = idxA->data[(k + (idxA->size[0] << 1)) - 1];
          if (!((i5 >= 1) && (i5 <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &r_emlrtBCI, &st);
          }

          i2 = a->size[0];
          if (!((i >= 1) && (i <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i2, &t_emlrtBCI, &st);
          }

          i2 = a->size[1];
          if (!((j >= 1) && (j <= i2))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i2, &u_emlrtBCI, &st);
          }

          i2 = a->size[2];
          if (!((k >= 1) && (k <= i2))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i2, &v_emlrtBCI, &st);
          }

          a->data[((i + a->size[0] * (j - 1)) + a->size[0] * a->size[1] * (k - 1))
            - 1] = a_tmp->data[((i3 + a_tmp->size[0] * (i4 - 1)) + a_tmp->size[0]
                                * a_tmp->size[1] * (i5 - 1)) - 1];
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
    emxInit_real_T(sp, &a, 3, &i_emlrtRTEI, true);
    st.site = &k_emlrtRSI;
    padImage(&st, varargin_1, pad, a);
    st.site = &l_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
    varargin_1->size[0] = (int32_T)finalSize[0];
    varargin_1->size[1] = (int32_T)finalSize[1];
    varargin_1->size[2] = (int32_T)finalSize[2];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i, sizeof(real_T),
                      &d_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      padSize[i] = a->size[i];
    }

    for (i = 0; i < 26; i++) {
      nonZeroKernel[i] = 0.038461538461538457;
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
