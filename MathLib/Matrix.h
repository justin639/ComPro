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

// Set by enum
// enum{
//     _MAT_AXIS_X, // = 0 (default) | if = 1 (setted) | can be setted
//     _MAT_AXIS_Y, // = 1           |    = 2          | repectivly
//     _MAT_AXIS_Z  // = 2           |    = 3          |

// };

// Structure =============================================
typedef struct _T3DMatrix{
    // double daMat[4][4];
    // double arMat[16];

    union
    {
        float m[4][4];
        struct 
        {
            float _11, _12, _13, _14;   
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44; 
        };
    };
}T3DMatrix;

// Functions =============================================
#ifdef __cplusplus
extern "C" {
#endif

    // I-Matrix
    DLLEXPORT void mat_i_get(T3DMatrix& tMat);
    // Inverse
    DLLEXPORT void mat_inv_get(T3DMatrix& tMat);
    // Mult Mat
    DLLEXPORT void mat_mult_mat(T3DMatrix& tMat1, T3DMatrix& tMat2, T3DMatrix& tOutMat);
    // Mult Mat x Vect
    DLLEXPORT void mat_mult_vect(T3DMatrix& tMat, T_3D_Vector& tVec, T3DMatrix& tOutVec);
    // Copy Mat
    DLLEXPORT void mat_copy(T3DMatrix& tSMat, T3DMatrix& tDMat);
    // Trasnlate
    DLLEXPORT void mat_traslate(double dx, double dy, double dz, T3DMatrix& tOutMat);
    // Rotation (X axis = 0)
    // nAxis : _MAT_AXIS_X : 0, _MAT_AXIS_Y : 1, _MAT_AXIS_Z : 2 
    DLLEXPORT void mat_rotate( int nAxis, T3DMatrix& tOutMat);

#ifdef __cplusplus
}
#endif