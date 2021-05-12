#include <iostream>

 const int M = 5, N = 5;
void print (int M[][N], int m, int n);
int main (void)
{
  //declarar las matrices
  int A [M][N] = {{0}};
  int AT [N][M] = {{0}};
  int ii, jj = 0;

  for (ii = 0; ii < M; ++ii){
    for (jj = 0; jj < N; ++jj){
      A[ii][jj] = ii*N + jj;
    }
  }
  std::cout << "original matrix : \n";
  print (A, M, N);
 
  //procesarla : transponerla

 for (ii = 0; ii < M; ++ii){
    for (jj = 0; jj < N; ++jj){
      AT[jj][ii] = A[ii][jj];
    }
  }
 
  //imprimirla

 std::cout << "transposed  matrix : \n";
 print (AT, M, N);
  return 0;
}

// funcion para arreglos cuadrados
void print (int M[][N], int m, int n)
{

 for (int ii = 0; ii < m; ++ii){
    for (int jj = 0; jj < n; ++jj){
      std::cout << M[ii][jj] << "  ";
    }
    std::cout << "\n";
    }
}

