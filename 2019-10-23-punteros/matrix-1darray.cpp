// compile as : g++ -Wall -g -fsanitize=address matrix-1darray.cpp

#include <iostream>
#include <cmath>
const int M = 5000, N = 30;

void test_transposition (int M[], int MT[], int m, int n);
void print(int M[], int m , int n);

int main(void)
{
  // declarar las matrices

  int A[M*N] = {0};
  int AT[N*M] = {0};
  int ii, jj;
  
  for(ii=0; ii < M; ++ii){
    for(jj=0; jj < N; ++jj){
      A[ii*N+jj] = ii*N + jj;  
    }
  }

  std::cout << "# Original Matrix : \n";
  // print(A, M, N);
  
  // procesarla : transponerla
  for(ii=0; ii < M; ++ii){
    for(jj=0; jj < N; ++jj){
      AT[jj*M +ii] = A[ii*N + jj];
    }
  }
  

  // imprimirla
  std::cout << "# Transposed Matrix : \n";
  // print(AT, N, M);
  test_transposition (A, AT, M, N);
  return 0;
}

// solamente funciona para arreglos cuadrados
void print(int M[], int m , int n)
{
  for(int ii=0; ii < m; ++ii){
    for(int jj=0; jj < n; ++jj){
      std::cout << M[ii*n +jj] << "   ";
    }
    std::cout << "\n";
  }
}
void test_transposition (int M[], int MT[], int m, int n)
{
  int suma =0;
  for (int ii=0; ii<m; ++ii){
    for (int jj=0;jj < n; ++jj){

      suma += std::fabs(M[ii*n + jj] - MT[jj*m +ii]);

    }
  }
  double avg = 1.0*suma/(m+n);
  std::cout << "# dif = " << avg << "\n";
}
