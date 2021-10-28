//%=============================================================================
// Common.h - 
// 일반 헤더
//%=============================================================================
#pragma once

//===== 헤더 ===================================================================
#include <windows.h>
//===== 변수 및 선언문 =========================================================

//----- 단위 관련 -------------------------------

#ifndef	NULL
#define	NULL	            0           
#endif 

#ifndef	TRUE
#define	TRUE	            1
#define	FALSE	            0
#endif 

#ifdef _EPS
#undef _EPS
#endif 
#define _EPS		        1e-5
#define _UEPS		        1e-6

#ifdef _INFINITY
#undef _INFINITY
#endif 
#define _INFINITY	        1e6

#ifndef PI
#define PI	            3.14159265358979323846
#define PI_2	            1.57079632679489661923   // 3.141592*0.5
#endif 

#ifndef _SQRT2
#define _SQRT2	        1.4142135623730951
#endif

// Normalize Zero Limit
#define NX_NORMALIZE_ZERO	1e-30

// ===== Structure ============================================================
// Matrix
typedef struct _T3DMatrix
{
    union
    {
        double m[4][4];
        struct
        {
            double _11, _12, _13, _14;
            double _21, _22, _23, _24;
            double _31, _32, _33, _34;
            double _41, _42, _43, _44;
        };
    };
} T3DMatrix, *LPT3DMatrix;

// Plane
typedef struct _T3DPLANE
{
	double a, b, c, d;
} T3DPlane, *LPT3DPlane;

// Vector
// 2D
typedef struct _T_2D_Vector
{
    double x;
    double y;
} T2DVector;

// 3D
typedef struct _T_3D_Vector
{
    double x;
    double y;
    double z;
} T3DVector;
//===== Data Type =============================================================
#define BOOL unsigned char

//===== macro funcitons =======================================================

// Degree -> Radian 
#define _TORAD(Deg)		((Deg) * 0.01745329251994329577)  
// Radian -> Degree 
#define _TODEG(Rad)		((Rad) * 57.2957795130823208768)  

// Inch -> mm
#define _TOMM(inch)		((inch) * 25.40)                  
// mm -> Inch
#define _TOINCH(mm)		((mm) * 0.03937007874)            

#define _MIN(x, y)		((x) > (y) ? (y) : (x))
#define _MAX(x, y)		((x) > (y) ? (x) : (y))

// Clip Value
#define _CLIP(type, Value, min, max) { type Result = Value; \
						if (Result < min) { \
							 Value=min; \
						} \
						else if (Result > max) { \
							 Value=max; \
						} \
					} 
// Roundup Value
#define _ROUND(x) ((int) ((x) + 0.5))

// Swap Value
#define _SWAP(type, x, y)	{ type temp = (x); (x) = (y); (y) = temp; }

#define _ABS(x)			((x) > 0 ? (x) : (-(x)))
#define _SQR(x)			((x) * (x))
#define _SIGN(x)			((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
