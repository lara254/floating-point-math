#include <iostream>
#define SHIFT_POW 27

using namespace std;
void velkampt_splitting(double x, int sp, double *x_high, double *x_low)
{
  unsigned long C = (1UL << sp) + 1; // C = 2^sp + 1
  double gamma = C * x;
  double delta = x - gamma;
  *x_high = gamma + delta;
  *x_low = x - *x_high;
}
void dekker_product(double x, double y, double *r_1, double *r_2) {
  double x_high, x_low;
  double y_high, y_low;
  double t_1;
  double t_2;
  double t_3;
  velkampt_splitting(x, SHIFT_POW, &x_high, &x_low);
  velkampt_splitting(y, SHIFT_POW, &y_high, &y_low);

  cout << "x_high =" << x_high << endl;
  cout << "x_low =" << x_low << endl;

  cout << "y_high =" << y_high << endl;
  cout << "y_low =" << y_low << endl;

  *r_1 = -*r_1 + x_high * y_high;
  t_1 = t_1 + x_high * y_low;
  t_2 = t_1 + x_high * y_low;
  t_3 = t_2 + x_low * y_high;
  *r_2 = t_3 + x_low * y_low;
}


int main() {
  double x, y, r_1, r_2;
  x = 3.0;
  y = 5.0;
  cout << "x =" << x << endl;
  cout << "y =" << y << endl;

  dekker_product(x, y, &r_1, &r_2);
    cout << "r_1 =" << r_1 << endl;
  cout << "r_2 =" << r_2 << endl;
}
  
