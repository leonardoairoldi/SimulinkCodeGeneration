#ifndef rt_matrixlib_h
#define rt_matrixlib_h

/* Copyright 2007-2013 The MathWorks, Inc.
 *
 * File    : rt_matrixlib.h
 * Abstract:
 *     Function prototypes for .c sources in rtw/c/src/matrixmath.
 *
 */


/*==========*
 * Includes *
 *==========*/

#include <stdint.h>
 #include <stdbool.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Matrix Multiplication Utility Functions */
extern void rt_MatMultRR_Dbl(double         *y, 
                             const double   *A, 
                             const double   *B, 
                             const int dims[3]);

#ifdef CREAL_T
extern void rt_MatMultRC_Dbl(creal_T       *y,
                             const double  *A,
                             const creal_T *B,
                             const int dims[3]);

extern void rt_MatMultCR_Dbl(creal_T       *y,
                             const creal_T *A,
                             const double  *B,
                             const int dims[3]);

extern void rt_MatMultCC_Dbl(creal_T       *y,
                             const creal_T *A,
                             const creal_T *B,
                             const int dims[3]);
#endif

extern void rt_MatMultRR_Sgl(float       *y,
                             const float *A,
                             const float *B,
                             const int  dims[3]);

#ifdef CREAL_T
extern void rt_MatMultRC_Sgl(creal32_T       *y,
                             const float  *A,
                             const creal32_T *B,
                             const int   dims[3]);

extern void rt_MatMultCR_Sgl(creal32_T       *y,
                             const creal32_T *A,
                             const float  *B,
                             const int   dims[3]);

extern void rt_MatMultCC_Sgl(creal32_T       *y,
                             const creal32_T *A,
                             const creal32_T *B,
                             const int   dims[3]);
#endif

extern void rt_MatMultAndIncRR_Dbl(double       *y,
                                   const double *A,
                                   const double *B,
                                   const int dims[3]);

#ifdef CREAL_T
extern void rt_MatMultAndIncRC_Dbl(creal_T       *y,
                                   const double  *A,
                                   const creal_T *B,
                                   const int dims[3]);

extern void rt_MatMultAndIncCR_Dbl(creal_T       *y,
                                   const creal_T *A,
                                   const double  *B,
                                   const int dims[3]);

extern void rt_MatMultAndIncCC_Dbl(creal_T       *y,
                                   const creal_T *A,
                                   const creal_T *B,
                                   const int dims[3]);
#endif
extern void rt_MatMultAndIncRR_Sgl(float       *y,
                                   const float *A,
                                   const float *B,
                                   const int  dims[3]);

#ifdef CREAL_T
extern void rt_MatMultAndIncRC_Sgl(creal32_T       *y,
                                   const float  *A,
                                   const creal32_T *B,
                                   const int   dims[3]);

extern void rt_MatMultAndIncCR_Sgl(creal32_T       *y,
                                   const creal32_T *A,
                                   const float  *B,
                                   const int   dims[3]);

extern void rt_MatMultAndIncCC_Sgl(creal32_T       *y,
                                   const creal32_T *A,
                                   const creal32_T *B,
                                   const int   dims[3]);
#endif 

/* Matrix Inversion Utility Functions */
extern void rt_lu_real(double      *A,
                       const int n,
                       int32_t     *piv);

#ifdef CREAL_T
extern void rt_lu_cplx(creal_T *A,
                       const int n,
                       int32_t *piv);
#endif

extern void rt_lu_real_sgl(float      *A,
                           const int n,
                           int32_t     *piv);

#ifdef CREAL_T
extern void rt_lu_cplx_sgl(creal32_T *A,
                           const int n,
                           int32_t *piv);
#endif

extern void rt_BackwardSubstitutionRR_Dbl(double          *pU,
                                          const double    *pb,
                                          double          *x,
                                          int            N,
                                          int            P,
                                          bool        unit_upper);

#ifdef CREAL_T
extern void rt_BackwardSubstitutionRC_Dbl(double          *pU,
                                          const creal_T   *pb,
                                          creal_T         *x,
                                          int            N,
                                          int            P,
                                          bool        unit_upper);

extern void rt_BackwardSubstitutionCC_Dbl(creal_T         *pU,
                                          const creal_T   *pb,
                                          creal_T         *x,
                                          int            N,
                                          int            P,
                                          bool        unit_upper);
#endif

extern void rt_ForwardSubstitutionRR_Dbl(double        *pL,
                                         const double  *pb,
                                         double        *x,
                                         int          N,
                                         int          P,
                                         const int32_t *piv,
                                         bool      unit_lower);

#ifdef CREAL_T
extern void rt_ForwardSubstitutionRC_Dbl(double        *pL,
                                         const creal_T   *pb,
                                         creal_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);

extern void rt_ForwardSubstitutionCR_Dbl(creal_T   *pL,
                                         const double    *pb,
                                         creal_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);

extern void rt_ForwardSubstitutionCC_Dbl(creal_T   *pL,
                                         const creal_T   *pb,
                                         creal_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);
#endif

extern void rt_BackwardSubstitutionRR_Sgl(float          *pU,
                                          const float    *pb,
                                          float          *x,
                                          int              N,
                                          int              P,
                                          bool          unit_upper);

#ifdef CREAL_T
extern void rt_BackwardSubstitutionRC_Sgl(float          *pU,
                                          const creal32_T   *pb,
                                          creal32_T         *x,
                                          int              N,
                                          int              P,
                                          bool          unit_upper);

extern void rt_BackwardSubstitutionCC_Sgl(creal32_T         *pU,
                                          const creal32_T   *pb,
                                          creal32_T         *x,
                                          int              N,
                                          int              P,
                                          bool          unit_upper);
#endif

extern void rt_ForwardSubstitutionRR_Sgl(float    *pL,
                                         const float    *pb,
                                         float    *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);

#ifdef CREAL_T
extern void rt_ForwardSubstitutionRC_Sgl(float    *pL,
                                         const creal32_T   *pb,
                                         creal32_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);

extern void rt_ForwardSubstitutionCR_Sgl(creal32_T   *pL,
                                         const float    *pb,
                                         creal32_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);

extern void rt_ForwardSubstitutionCC_Sgl(creal32_T   *pL,
                                         const creal32_T   *pb,
                                         creal32_T   *x,
                                         int     N,
                                         int     P,
                                         const int32_t   *piv,
                                         bool unit_lower);
#endif


extern void rt_MatDivRR_Dbl(double        *Out,
                            const double  *In1,
                            const double  *In2,
                            double        *lu,
                            int32_t       *piv,
                            double        *x,
                            const int    dims[3]);

#ifdef CREAL_T
extern void rt_MatDivRC_Dbl(creal_T       *Out,
                            const double  *In1,
                            const creal_T *In2,
                            double        *lu,
                            int32_t       *piv,
                            creal_T       *x,
                            const int    dims[3]);

extern void rt_MatDivCR_Dbl(creal_T       *Out,
                            const creal_T *In1,
                            const double  *In2,
                            creal_T       *lu,
                            int32_t       *piv,
                            creal_T       *x,
                            const int    dims[3]);

extern void rt_MatDivCC_Dbl(creal_T       *Out,
                            const creal_T *In1,
                            const creal_T *In2,
                            creal_T       *lu,
                            int32_t       *piv,
                            creal_T       *x,
                            const int    dims[3]);
#endif

extern void rt_MatDivRR_Sgl(float        *Out,
                            const float  *In1,
                            const float  *In2,
                            float        *lu,
                            int32_t         *piv,
                            float        *x,
                            const int      dims[3]);

#ifdef CREAL_T
extern void rt_MatDivRC_Sgl(creal32_T       *Out,
                            const float  *In1,
                            const creal32_T *In2,
                            float        *lu,
                            int32_t         *piv,
                            creal32_T       *x,
                            const int      dims[3]);

extern void rt_MatDivCR_Sgl(creal32_T       *Out,
                            const creal32_T *In1,
                            const float  *In2,
                            creal32_T       *lu,
                            int32_t         *piv,
                            creal32_T       *x,
                            const int      dims[3]);

extern void rt_MatDivCC_Sgl(creal32_T       *Out,
                            const creal32_T *In1,
                            const creal32_T *In2,
                            creal32_T       *lu,
                            int32_t         *piv,
                            creal32_T       *x,
                            const int      dims[3]);
#endif


/* Matrix multiplication defines */

/* Quick (approximate) complex absolute value: */
#define CQABS(X) (fabs((X).re) + fabs((X).im))

/* Quick (approximate) complex absolute value for singles: */
#define CQABSSGL(X) (float)(fabs( (double) (X).re) + fabs( (double) (X).im)) 

#ifdef CREAL_T
extern void rt_ComplexTimes_Dbl(creal_T       *Out,
                                const creal_T In1,
                                const creal_T In2);

extern void rt_ComplexRDivide_Dbl(creal_T       *Out,
                                  const creal_T In1,
                                  const creal_T In2);

extern void rt_ComplexReciprocal_Dbl(creal_T       *Out,
                                     const creal_T In1);

extern void rt_ComplexTimes_Sgl(creal32_T       *Out,
                                const creal32_T In1,
                                const creal32_T In2);

extern void rt_ComplexRDivide_Sgl(creal32_T       *Out,
                                  const creal32_T In1,
                                  const creal32_T In2);

extern void rt_ComplexReciprocal_Sgl(creal32_T       *Out,
                                     const creal32_T In1);

#endif

extern double rt_Hypot_Dbl(double In1,
                           double In2);

extern float rt_Hypot_Sgl(float In1,
                             float In2);

#ifdef __cplusplus
}
#endif

#endif /* rt_matrixlib_h */
