#pragma once

// ==========================
// Define
// ==========================
// => NOT RECOMMENDED
// #define _VEC_2d_SET(v, x, y)    (v.x = x; v.y = y)
// #define _VEC_3d_SET(v, x, y, z)    (v.x = x; v.y = y, v.z =z)
#define TRUE 1
#define FALSE 0

#define BOOL unsigned char

// ==========================
// Structure
// ==========================
typedef struct _T_2D_Vector
{
    double x;
    double y;
}T_2D_Vector;

typedef struct _T_3D_Vector
{
    double x;
    double y;
    double z;
}T_3D_Vector;

// ==========================
// Global Variable
// ==========================


// ==========================
// Global Functions
// ==========================
// Set Vector
void vec_2d_set(T_2D_Vector& tVec, double x, double y);
void vec_3d_set(T_3D_Vector& tVec, double x, double y, double z);

// Normalize
BOOL vec_2d_norm(T_2D_Vector& tVec);
BOOL vec_3d_norm(T_3D_Vector& tVec);

// Size
double vec_2d_size(T_2D_Vector& tVec);
double vec_3d_size(T_3D_Vector& tVec);

// Dot Product
double vec_2d_dot(T_2D_Vector& tVec1, T_2D_Vector& tVec2);
double vec_3d_dot(T_3D_Vector& tVec1, T_3D_Vector& tVec2);

// Cross Product
// input : 
// output : 
void vec_2d_cross(T_2D_Vector& tVec1, T_2D_Vector& tVec2, T_2D_Vector *tpResult);
void vec_3d_cross(T_3D_Vector& tVec1, T_3D_Vector& tVec2, T_3D_Vector *tpResult);