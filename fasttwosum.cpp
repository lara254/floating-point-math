#include <iostream>

void fast_two_sum(double a, double b, double *s, double *t)
{
  double z;
  *s = a + b;
  z = *s - a;
  *t = b - z;
}


void mul(double a, double b, double *r1, double *r2)
{
  *r1 = a * b;
  *r2 = r1 - r1;
}
int main() {
  double a;
  double b;
  double s;
  double t;
  double r1;
  double r2;
  
  a = 3.0;
  b = 5.0;

  fast_two_sum(a, b, &s, &t);
  mul(a, b, &r1, &r2);
  std::cout << s << std::endl;
  std::cout << t << std::endl;

   std::cout << r1 << std::endl;
   std::cout << r2 << std::endl;
}
