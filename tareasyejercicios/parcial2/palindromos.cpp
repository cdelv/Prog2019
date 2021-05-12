#include <iostream>
#include <string>
#include <vector>

int main (void)
{
  std::string a;
  std::cout << "Escribe algo y te dire si es palíndromo" << std::endl;
  std::getline(std::cin,a);
   const std::string pal = a;
  int n = pal.length();
  int k = 0;

  if (n%2 == 0){
    {for (int i = 0 ; i < n/2 ; i++){
	if (pal.at(i) == pal.at(n-1-i))k +=1;}}}
  else {for (int i = 0; i< (n-1)/2; i++){
      if (pal.at(i) == pal.at(n-1-i))k +=1;}}

  if(0==n%2 and k== n/2){std::cout << "Es palíndromo" << std::endl;}
  if (0==(n+1)%2 and k==(n-1)/2){std::cout << "Es palíndromo" << std::endl;} 
  if ((0==n%2 and k!=n/2) or (0==(n+1)%2 and k!=(n-1)/2 )){
    std::cout << "No es palíndromo" << std::endl;}
  return 0;
}


