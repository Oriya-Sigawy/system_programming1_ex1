#ifndef _my_mat_h                                        
#define _my_mat_h
#define MATRIX_SIZE 10
void acceptMatrixValues(int**, int);                     //its int** because its a matrix
int isTherePath(int**, int, int);                       //returns 0 if there isn't, 1 if there is
int weightOfShortestPath(int**, int, int, int);       //returns the weight of lightest path    
#endif