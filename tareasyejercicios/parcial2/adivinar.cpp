#include <iostream>
#include <string>



int main (void)
{
  int x=0;
  std::string a,b,c,d,e,f;
  const std::string y= "yes";
  const std::string n= "no";
  std::cout << "think of a number from 1 to 100 that I will atempt to guess." << "\n" <<
    "Remenber to imput only yes or no as an answare" << std::endl;
  std::cout << "if you want, you can write the number here so you can remember it." << "\n" << "if you dont trust me just press enter and be honest." << "\n" << "I have maximun 7 atempts to guess."<< std::endl;
  std::cin >> x;
  
    std::cout << "is your number less than 50?" << std::endl;
    std::cin >> a;
    if (a == y){std::cout << "is your number less than 25?" << std::endl;}
    else
      {std::cout << "is your number less than 75?" << std::endl;}
    std::cin >> b;
    if (a == y and b == y){std::cout << "is your number less than 12?" << std::endl;}
    if (a == y and b!= y){std::cout << "is your number less than 37?" << std::endl;}
    if (a!= y and b == y){std::cout << "is your number less than 62?" << std::endl;}
    if (a!= y and b!= y){std::cout << "is your number less than 87?" << std::endl;}
    std::cin >> c;
    if (a== y and b == y and c==y){std::cout << "is your number less than 6?" << std::endl;}
    if (a== y and b == y and c!=y){std::cout << "is your number less than 9?" << std::endl;}
    if (a== y and b != y and c==y){std::cout << "is your number less than 31?" << std::endl;}
    if (a== y and b != y and c!=y){std::cout << "is your number less than 43?" << std::endl;}
    if (a!= y and b == y and c==y){std::cout << "is your number less than 56?" << std::endl;}
    if (a!= y and b == y and c!=y){std::cout << "is your number less than 68?" << std::endl;}
    if (a!= y and b != y and c==y){std::cout << "is your number less than 81?" << std::endl;}
    if (a!= y and b != y and c!=y){std::cout << "is your number less than 93?" << std::endl;}
    std::cin >> d;
    if (a!= y and b != y and c!=y and d!=y){std::cout << "is your number less than 96?" << std::endl;}
    if (a!= y and b != y and c!=y and d==y){std::cout << "is your number less than 90?" << std::endl;}
    if (a!= y and b != y and c==y and d!=y){std::cout << "is your number less than 84?" << std::endl;}
    if (a!= y and b != y and c==y and d==y){std::cout << "is your number less than 79?" << std::endl;}
    if (a!= y and b == y and c!=y and d!=y){std::cout << "is your number less than 71?" << std::endl;}
    if (a!= y and b == y and c!=y and d==y){std::cout << "is your number less than 65?" << std::endl;}
    if (a!= y and b == y and c==y and d!=y){std::cout << "is your number less than 59?" << std::endl;}
    if (a!= y and b == y and c==y and d==y){std::cout << "is your number less than 53?" << std::endl;}
    if (a== y and b == y and c==y and d==y){std::cout << "is your number less than 3?" << std::endl;}
    if (a== y and b == y and c==y and d!=y){std::cout << "is your number less than 9?" << std::endl;}
    if (a== y and b == y and c!=y and d==y){std::cout << "is your number less than 15?" << std::endl;}
    if (a== y and b == y and c!=y and d!=y){std::cout << "is your number less than 21?" << std::endl;}
    if (a== y and b != y and c==y and d==y){std::cout << "is your number less than 28?" << std::endl;}
    if (a== y and b != y and c==y and d!=y){std::cout << "is your number less than 34?" << std::endl;}
    if (a== y and b != y and c!=y and d!=y){std::cout << "is your number less than 46?" << std::endl;}
    if (a== y and b != y and c!=y and d==y){std::cout << "is your number less than 40?" << std::endl;}
    std::cin >> e;
   if (a!= y and b != y and c!=y and d!=y and e!= y){std::cout << "is your number less than 98?" << std::endl;}
   if (a!= y and b != y and c!=y and d!=y and e== y){std::cout << "is your number less than 94?" << std::endl;}
   if (a!= y and b != y and c!=y and d==y and e!= y){std::cout << "is your number less than 91?" << std::endl;}
   if (a!= y and b != y and c!=y and d==y and e== y){std::cout << "is your number less than 88?" << std::endl;}
   if (a!= y and b != y and c==y and d!=y and e!= y){std::cout << "is your number less than 88?" << std::endl;}
     
     
    
}
