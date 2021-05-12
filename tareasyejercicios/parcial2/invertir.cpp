#include <iostream>
#include <string>

int main(void)
{

  std::string a;
  std::cout << "escribe algo y te lo devolveré al revez." << std::endl;
  std::getline (std::cin, a);
  int n = a.length();
  for (int i = 0; i<n ; i++){
    std::cout << a.at(n-1-i);
  }
  std::cout << "" << std::endl;

  return 0;
}
