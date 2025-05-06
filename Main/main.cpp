#include "TMatrix.h"
#include "TVector.h"

int main()
{
  system("chcp 1251> nul");
  TMatrix<double> g, f(2,3);
  TVector<double> d,h;
  cin >> d;
  /*for (auto k : d)
    std::cout << k << std::endl;
  d.Save();*/
  h = d.QuickSort(0, d.GetLen() - 1);
  cout << h;
}