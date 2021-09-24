#include "math.h"
#include "Vector.h"

#define _SIZE_ZERO 0.00001

// ===============================================================
// Implemetation (Funtions)
// ===============================================================
// Set Vector
void vec_2d_set(T_2D_Vector& tVec, double x, double y){
    tVec.x = x;
    tVec.y = y;
}
void vec_3d_set(T_3D_Vector& tVec, double x, double y, double z){
    tVec.x = x;
    tVec.y = y;
    tVec.z = z;
}

// Normalize
BOOL vec_2d_norm(T_2D_Vector& tVec){
    double dSize;

    dSize = vec_2d_size(tVec);

    if(dSize < _SIZE_ZERO){
        
        return FALSE;
    }
    else{
        tVec.x = tVec.x / dSize;
        tVec.y = tVec.y / dSize;

        return TRUE;
    }

}
BOOL vec_3d_norm(T_3D_Vector& tVec){

    double dSize;

    dSize = vec_3d_size(tVec);

    if(dSize < _SIZE_ZERO){
        
        return FALSE;
    }
    else{
        tVec.x = tVec.x / dSize;
        tVec.y = tVec.y / dSize;
        tVec.z = tVec.z / dSize;

        return TRUE;
    }

}
// Size
double vec_2d_size(T_2D_Vector& tVec){
    double dSize;

    dSize = tVec.x * tVec.x * tVec.y * tVec.y;
    dSize = sqrt(dSize);
    
    return dSize;
}
double vec_3d_size(T_3D_Vector& tVec){
    double dSize;

    dSize = tVec.x * tVec.x * tVec.y * tVec.y * tVec.z * tVec.z;
    dSize = sqrt(dSize);

    return dSize;
}

// Dot Product
double vec_2d_dot(T_2D_Vector& tVec1, T_2D_Vector& tVec2){
    double dDot = 0.0;

    
    return dDot;
}
double vec_3d_dot(T_3D_Vector& tVec1, T_3D_Vector& tVec2){
    double dDot = 0.0;

    
    return dDot;

}

// Cross Product
// input : 
// output : 
void vec_2d_cross(T_2D_Vector& tVec1, T_2D_Vector& tVec2, T_2D_Vector *tpResult){

}
void vec_3d_cross(T_3D_Vector& tVec1, T_3D_Vector& tVec2, T_3D_Vector *tpResult){

}