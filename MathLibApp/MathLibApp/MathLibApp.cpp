#include <iostream>
#include "Matrix.h"

void printMat(T3DMatrix &tMat){
    for(int i=0; i<4; i++){
        printf(" ");
        for(int j=0; j<4; j++){
            printf(" %lf", tMat.m[i][j]);
        }
        printf("\n");
    }
}

void print_3D_Vec(T3DVector &tVect){
    printf("Vect (x: %lf, y: %lf, z: %lf)\n", tVect.x,tVect.y,tVect.z);
}

void print_2D_Vec(T2DVector &tVect){
    printf("Vect (x: %lf, y: %lf)\n", tVect.x,tVect.y);
}

int main()
{
    T3DVector tVec1, tVec2;
    T3DMatrix tIMat;
    int DISCRI;
    double QuadEquation[3] ={0.0,0.0,0.0};
    int Mode = 0; // -1: Shutdown | 1: Quadratic | 2: Trigonometric | 3: Vector | 4 : Matrix
    int FucntionNum;
    double tri_value;
    double result_Disc = 0;
    double result_first = 0.0;
    double result_second = 0.0;

    vec_3d_set(tVec1, 1.0, 1.0, 1.0);
    vec_3d_set(tVec2, -1.0, -1.0, 1.0);
    vec_3d_norm(tVec1);
    mat_Ident(tIMat);

    print_3D_Vec(tVec1);
    printMat(tIMat);
    printf("TRUE: %d\n", TRUE);
    
    // Program Start
    printf(" - Welcome Now beginning Assingment...\n");

    while( Mode != -1){
        // Select Mode
        printf("    Mode 1 : Quadratic Equation\n");
        printf("    Mode 2 : Trigonometric Functions\n");
        printf("    Mode 3 : Vector Fuctions\n");
        printf("    Mode 4 : Matrix Fuctions\n");
        printf("    Mode -1 : Shut Down...\n");
        printf(" - Select Your Mode: ");scanf_s("%d", &Mode);

        // Mode 1 : Quadratic Equation
        if( Mode == 1){
            printf("=================== Assignmet Input ======================\n");
            // Get Quadratic Equation Coefficients
            printf(" - Second order Coeffincient: ");scanf_s("%lf", &QuadEquation[0]);
            printf(" - First order Coeffincient: ");scanf_s("%lf", &QuadEquation[1]);
            printf(" - Constant: ");scanf_s("%lf", &QuadEquation[2]);
            // End Get
            printf("===================== Input End ==========================\n\n");

            printf("=================== Assignmet Result =====================\n");
            // Use Discriminant
            result_Disc = discriminant(QuadEquation[0], QuadEquation[1], QuadEquation[2], DISCRI);
            // Two different roots
            if(DISCRI == DIFFERENTROOT){
                quadratic_equation_DIFF(QuadEquation[0], QuadEquation[1], result_Disc, result_first, result_second);
                printf("    DIIFERENTROOT %lf, %lf\n", result_first, result_second);
            } // End Differnt root

            // Double root 
            else if(DISCRI == DOUBLEROOT){
                printf("    DOUBLEROOT %lf \n",quadratic_equation_DOUBLE(QuadEquation[0], QuadEquation[1], QuadEquation[2]));
            } // End Double root

            // No roots
            else if(DISCRI == NOROOT){
                printf("    There is no root in real number form.\n");
            } // End No roots

            printf("===================== Result End =========================\n\n");
        } // End Mode 1

        // Mode 2 : Trigonometric Functions
        else if(Mode == 2){
            // Function variables
            int function_input =TRUE;
            int dgree_type_input =TRUE;
            int dgree_type =0;

            printf("=================== Assignmet Input ======================\n");

            // Select Function to Opterate(SIN, COS, TAN, etc.)
            while(function_input){
                printf("Select Function to Operate\n");
                printf("    1: SIN     /     2: COS     /     3: TAN\n    4: SEC     /     5: CSC     /     6: COT\n    7: ARCSIN  /    8: ARCCOS   /    9: ARCTAN\n   10: ARCCSC  /   11: ARCSEC   /    12: ARCOT\n");
                printf(" - Function Number: ");scanf_s("%d", &FucntionNum);
                switch (FucntionNum){
                    case 1: 
                        printf("    You selected SIN.\n");
                        function_input = FALSE;
                        break;
                    case 2:
                        printf("    You selected COS.\n");
                        function_input = FALSE;
                        break;
                    case 3: 
                        printf("    You selected TAN.\n");
                        function_input = FALSE;
                        break;
                    case 4: printf("    You selected SEC.\n");
                        function_input = FALSE;
                        break;
                    case 5: printf("    You selected CSC.\n");
                        function_input = FALSE;
                        break;
                    case 6: printf("    You selected COT.\n");
                        function_input = FALSE;
                        break;
                    case 7: printf("    You selected ARCSIN.\n");
                        function_input = FALSE;
                        break;
                    case 8: printf("    You selected ARCCOS.\n");
                        function_input = FALSE;
                        break;
                    case 9: printf("    You selected ARCTAN.\n");
                        function_input = FALSE;
                        break;
                    case 10: printf("    You selected ARCCSC.\n");
                        function_input = FALSE;
                        break;
                    case 11: printf("    You selected ARCSEC.\n");
                        function_input = FALSE;
                        break;
                    case 12: printf("    You selected ARCOT.\n");
                        function_input = FALSE;
                        break;
                    default: printf("------- Invalid Function Number.\n");
                        break;
                }
            } // End function selection

            // Get Degree type
            if(FucntionNum < 7){
                while(dgree_type_input){
                printf(" - Select your input form(1-rad, 2-degree): ");scanf_s("%d",&dgree_type);
                if(dgree_type !=1 && dgree_type != 2){
                    printf("------- Invalid input. Try again.\n");
                }
                else
                    dgree_type_input = FALSE;
                } 
            } // End degree type get
            

            // Get input
            printf(" - Your input: ");scanf_s("%lf", &tri_value);

            // if input in Degree form convert to radian
            if(dgree_type==2){
                tri_value = CVT_DEG2RAG(tri_value);
            } // End conversion

            printf("===================== Input End ==========================\n\n");

            printf("=================== Assignmet Result =====================\n");

            double tri_result;
            switch (FucntionNum){
                // Normal funcitons
                case 1: tri_result = SIN(tri_value);
                    break;
                case 2: tri_result = COS(tri_value);
                    break;
                case 3: tri_result = TAN(tri_value);
                    break;
                case 4: tri_result = SEC(tri_value);
                    break;
                case 5: tri_result = CSC(tri_value);
                    break;
                case 6: tri_result = COT(tri_value);
                    break;
                // Arc fucntions
                case 7: tri_result = CVT_RAD2DEG(ARCSIN(tri_value));
                    break;
                case 8: tri_result = CVT_RAD2DEG(ARCCOS(tri_value));
                    break;
                case 9: tri_result = CVT_RAD2DEG(ARCTAN(tri_value));
                    break;
                case 10: tri_result = CVT_RAD2DEG(ARCCSC(tri_value));
                    break;
                case 11: tri_result = CVT_RAD2DEG(ARCSEC(tri_value));
                    break;
                case 12: tri_result = CVT_RAD2DEG(ARCOT(tri_value));
                    break;
            }
            
            printf("Result: %lf\n", tri_result);
            printf("===================== Result End =========================\n\n");
        } // End Mode 2
        // Mode 3 : Vector(2D & 3D) Functions
        else if(Mode == 3){
            int demension = 0;
            printf("Select Demetion(2/3): ");
            scanf_s("%d", &demension);
            if(demension == 2){
                printf("2D\n");
            }
            else if(demension == 3){
                printf("3D\n");
            }
            else{
                printf("Wrong Demention.\n");
            }
        }
        // Mode 4 : Matrix(4x4) Functions
        else if(Mode == 4){

        }
        // Shut Down
        else if(Mode == -1){
            printf("------- Now Shut Down...\n");
        }    
        // Wrong Mode input
        else{
            printf("------- Worng Mode Selection. Please select mode again.\n");
        }
        
    } // End Program
    
    return 0;
}
