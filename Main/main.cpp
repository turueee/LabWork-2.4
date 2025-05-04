#include "TMatrix.h"
#include "TVector.h"

int main()
{
  system("chcp 1251> nul");
  TMatrix<double> g, f(2,3);
  TVector<double> d,h;
  cin >> d;
  cin >> g;
  h = g.Gauss(d);
  cout << h;
}