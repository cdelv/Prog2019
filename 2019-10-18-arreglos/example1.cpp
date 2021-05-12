#include <iostream>
#include <cmath>

double mean (int x,int billy[x]);
int main (void)
{
  int x= 10;

  int billy [x] = {5,1,2,3,4,8,7,4};

  std::cout << mean ( x, billy[x]) << "\n";
  return 0;
}

double mean (int x,int billy[x]){
  int y=1;
  for (int i; i < x; ++i){
    int y = 0;
    y += billy[i];
  }
  return y/x;
}
