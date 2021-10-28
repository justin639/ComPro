#pragma once
#include "Vector.h"

#ifndef DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#endif // !DLLEXPORT

// Define ================================================
// Axis
#define _MAT_X_AXIS 0
#define _MAT_Y_AXIS 1
#define _MAT_Z_AXIS 2

// Functions =============================================
#ifdef __cplusplus
extern "C"
{
#endif
    // Zero Matrix
    DLLEXPORT void mat_Zero(T3DMatrix &tMat);
    // Ident-Matrix
    DLLEXPORT void mat_Ident(T3DMatrix &tMat);
    // Inverse Matrix
    DLLEXPORT BOOL mat_Inv(T3DMatrix &tMat);
    // Mult Matrix
    DLLEXPORT void mat_Mult_mat(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat);
    // Mult Mat x Vect
    DLLEXPORT void mat_Mult_vect(T3DMatrix &tMat, T3DVector &tVec, T3DMatrix &tOutVec);
    // Copy Matrix
    DLLEXPORT void mat_Copy(T3DMatrix &tSMat, T3DMatrix &tDMat);
    // Trasnlate Matrix
    DLLEXPORT void mat_Traslate(double dx, double dy, double dz, T3DMatrix &tOutMat);
    // Rotation (X axis = 0)
    // nAxis : _MAT_AXIS_X : 0, _MAT_AXIS_Y : 1, _MAT_AXIS_Z : 2
    DLLEXPORT void mat_Rotate(int nAxis, T3DMatrix &tOutMat);
    // Get Scale Matrix 
    DLLEXPORT void mat_Scale(double fX, double fY, double fZ, T3DMatrix &tMat);
    // Input Matrix 
    DLLEXPORT void mat_Input(T3DMatrix &tMat, double faMat[16]);
    // Make Matrix Array
    DLLEXPORT void mat_2_Array(T3DMatrix &tMat, double faMat[16]);
    // Make Matrix Shadow
    DLLEXPORT void mat_Shadow(T3DMatrix *tpMat, T3DPlane *tpPlane, double fpLightPos[4]);
    // Add Matrix
    DLLEXPORT void mat_Add(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat);
    // Substract Matrix
    DLLEXPORT void mat_Sub(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat);
#ifdef __cplusplus
}
#endif