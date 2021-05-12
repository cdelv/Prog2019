  #include <iostream>
  #include <vector>
  #include <cmath>

const int N = 4;
  bool is_orthogonal(const std::vector<double> &  M, const double eps);
  
  int main(void)
  {
    const int N = 4;
     std::vector<double> A = {1, 0, 0, 0,
  			     0, 0.8, 0.3, -0.52,
  			     0, -0.6, 0.4, -0.69,
  			     0, 0, 0.86, 0.5};
    std::cout << is_orthogonal(A, 0.001) << std::endl;
    std::cout << is_orthogonal(A, 0.012) << std::endl;
    std::cout << is_orthogonal(A, 0.1) << std::endl;
    
    return 0;
  }
  bool is_orthogonal(const std::vector<double> &  M, const double eps)
{
  std::vector<int> MT(N*N), MULT(N*N), I(N*N);
  
  // calcule la transpuesta
  
    for(int bb = 0; bb < N; ++bb){
     for(int cc = 0; cc < N; ++cc){
      MT[cc*N + bb] = M[bb*N + cc];
     }
    }
    const std::vector <int> J = MT;
  // haga la multiplicacion en otro arreglo
    
      for(int kk=0; kk < N; kk++){
	for (int ll = 0; ll < N; ll++){
	  for (int mm = 0; mm < N; mm++){
	    MULT[kk*N + ll] += M[ll*N + mm]*J[mm*N + kk];

	  }
	}
      }
    
  // calcule la diferencia comparando con la identidad
      
                           I = {1, 0, 0, 0,
  			        0, 1, 0, 0,
  			        0, 0, 1, 0,
  			        0, 0, 0, 1};
     int sum = 0;
     int test =0;
     
    for (int aa = 0; aa < N; aa++){
      if ((MULT[aa] - I[aa]) <= eps){ sum += 1;}
      else {break;}
    }
  // retorne true o false de acuerdo a lo anterior
    if (sum == N*N){test = 1;}
    return test;
}
