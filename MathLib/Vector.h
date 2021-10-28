#pragma once
#include "Assignment1.h"

#ifndef DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#endif // !DLLEXPORT

// Functions =============================================
#ifdef __cplusplus
extern "C"
{
#endif

    // Set Zero Vector
    DLLEXPORT void vec_2d_Zero(T2DVector &tVec);
    DLLEXPORT void vec_3d_Zero(T3DVector &tVec);

    // Set Vector
    DLLEXPORT void vec_2d_set(T2DVector &tVec, double x, double y);
    DLLEXPORT void vec_3d_set(T3DVector &tVec, double x, double y, double z);

    // Normalize
    DLLEXPORT BOOL vec_2d_norm(T2DVector &tVec);
    DLLEXPORT BOOL vec_3d_norm(T3DVector &tVec);

    // Copy Vector
    DLLEXPORT void vec_2d_Copy(T2DVector &tDes, T2DVector &tSrc);
    DLLEXPORT void vec_3d_Copy(T3DVector &tDes, T3DVector &tSrc);

    // Plus Vector , tVec1+tVec2
    DLLEXPORT void vec_2d_Plus(T2DVector &tRes, T2DVector &tVec1, T2DVector &tVec2);
    DLLEXPORT void vec_3d_Plus(T3DVector &tRes, T3DVector &tVec1, T3DVector &tVec2);

    // Minus Vector , tVec1-tVec2
    DLLEXPORT void vec_2d_Minus(T2DVector &tRes, T2DVector &tVec1, T2DVector &tVec2);
    DLLEXPORT void vec_3d_Minus(T3DVector &tRes, T3DVector &tVec1, T3DVector &tVec2);

    // Size
    DLLEXPORT double vec_2d_size(T2DVector &tVec);
    DLLEXPORT double vec_3d_size(T3DVector &tVec);

    // Dot Product , tVec1 ¡¤ tVec2
    DLLEXPORT double vec_2d_dot(T2DVector &tVec1, T2DVector &tVec2);
    DLLEXPORT double vec_3d_dot(T3DVector &tVec1, T3DVector &tVec2);

    // Cross Product , tVec1 x tVec2
    DLLEXPORT void vec_3d_cross(T3DVector &tVec1, T3DVector &tVec2, T3DVector *tpResult);

    // Scaling Vector 
    DLLEXPORT void vec_2d_Scale(T2DVector &tVec, double Scale);
    DLLEXPORT void vec_3d_Scale(T3DVector &tVec, double Scale);

    // Get Angle of 2 Vector 
    DLLEXPORT double vec_2d_Angle(T2DVector &tVec1, T2DVector &tVec2);
    DLLEXPORT double vec_3d_Angle(T3DVector &tVec1, T3DVector &tVec2);

    // Gen Plane Struct 
    DLLEXPORT void GenPlaneFromNorm(T3DPlane *tpPlane, T3DVector *tpPos, T3DVector *tpNorm);

    // Gen Plane Struct 
    DLLEXPORT void GenPlaneFromPos(T3DPlane *tpPlane, T3DVector *tpPos1, T3DVector *tpPos2, T3DVector *tpPos3);

#ifdef __cplusplus
}
#endif