#include <iostream>
#include <string>
#include <vector>

struct complex {
  std::string name = "Complex";
	       double x = 0.0;
	       double y = 0.0;
};


int main (void)
{
  complex z;
  z.x= -1;
  z.y = 4.5;
  std::cout << z.name << std::endl;
  std::cout << z.x << std::endl;
  std::cout << z.y << std:: endl;
  


  return 0;
}
