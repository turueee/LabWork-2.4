#include "TMatrix.h"
#include "TVector.h"

int main()
{
  system("chcp 1251> nul");
  double* z = new double[3] {1, 2, 45};
  TVector<double> g, f;
  cin >> g;
  cout << g;
  g.SetLen(-6);
  cout << g;
}