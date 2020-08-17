#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//introduce a function to calculate the value of x to the power i divided by the factorial i
double dvdfactorial(double i, double x)
{
  double producti =1, xpowi;
  //calculate the factorial of i
  for (int j = 1; j<= i; j++)
  {
    producti *= j;
  }
  xpowi = pow(x,i);

  return xpowi/producti;

}

//calculate the value of e to the power x given n
void cale (double &a, int b, int c)
{
  a = 1;

//caculate x^n/n! for n in range (1,i) and sum up to get e^x
  for (int i=1; i<=c; i++)
   {
     a += dvdfactorial(i, b);
   }
}

int main()
{
  double e;
  int x, n;
  //input the value of x,n
  cin >> x >> n;
  for (int i =0; i<=n; i++)
  {
    //calculate the values of e^x as n increases
    cale(e, x, i);
    //set the precision of output to 8 digits and keep the trailing zeros

    cout << i << " ";
    cout << fixed << setprecision (8) << e << endl;
  }
  return 0;
}
