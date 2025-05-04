#pragma once

#include <iostream>

using namespace std;

template<class T>
class TMatrix {
protected:
  int n;
  int m;
  T** matrix;
public:
  TMatrix();
  TMatrix(int n_, int m_);
  TMatrix(const TMatrix& table);
  TMatrix(TMatrix&& table);
  ~TMatrix();

  int GetN();
  int GetM();
  void GetMatrix(T*** array);

  void SetN(int n_);
  void SetM(int m_);
  void SetMatrix(T**array);

  /// 1 level
  
  /// 2 level
 
  /// 3 level
  TMatrix<T> Transposition();
  TMatrix<T> Minor(int string, int column);
  TMatrix<T> Attached();
  TMatrix<T> Inverse();
  T Determinant();
  TMatrix<T> Gauss();
  int CountOfIncludes(T num);
  TMatrix<T> IndexesOfIncludes(T num);
  TMatrix<T> Pow(int st);

  TMatrix operator+(const TMatrix<T>& table);
  TMatrix operator-(const TMatrix<T>& table);
  TMatrix operator*(const TMatrix<T>& table);
  TMatrix operator*(T num);
  TMatrix operator/(T num);
  TMatrix operator=(const TMatrix<T>& table);
  bool operator==(const TMatrix<T>& table);
  T*& operator[](int index);

  template <class O>
  friend ostream& operator<<(ostream& o, TMatrix<O>& t);
  template <class I>
  friend istream& operator>>(istream& i, TMatrix<I>& t);
};


template<class T>
inline TMatrix<T>::TMatrix()
{
  n = 0;
  m = 0;
  matrix = nullptr;
}


template<class T>
inline TMatrix<T>::TMatrix(int n_, int m_)
{
  if (n_ < 0)
    throw 'n<0';
  if (m_ < 0)
    throw "m<0";
  n = n_;
  m = m_;
  if (n == 0 || m == 0)
  {
    matrix = nullptr;
    n = 0;
    m = 0;
  }
  else
  {
    matrix = new T * [n];
    for (int i = 0; i < n; ++i)
      matrix[i] = new T[m];
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (i == j)
          matrix[i][j] = 1;
        else
          matrix[i][j] = 0;
      }
    }
  }
}


template<class T>
inline TMatrix<T>::TMatrix(const TMatrix& table)
{
  n = table.n;
  m = table.m;
  if (n == 0 || m == 0)
    matrix = nullptr;
  else
  {
    matrix = new T * [n];
    for (int i = 0; i < n; ++i)
    {
      matrix[i] = new T[m];
      for (int j = 0; j < m; ++j)
      {
        matrix[i][j] = table.matrix[i][j];
      }
    }
  }
}


template<class T>
inline TMatrix<T>::TMatrix(TMatrix&& table)
{
  n = table.n;
  m = table.m;
  matrix = table.matrix;
  table.n = 0; 
  table.m = 0;
  for (int i = 0; i < n; ++i)
    matrix[i] = nullptr;
  matrix = nullptr;
}


template<class T>
inline TMatrix<T>::~TMatrix()
{
  if (matrix != nullptr)
  {
    for (int i = 0; i < n; ++i)
      delete[] matrix[i];
    delete[] matrix;
  }
}


template<class T>
inline int TMatrix<T>::GetN()
{
  return n;
}


template<class T>
inline int TMatrix<T>::GetM()
{
  return m;
}


template<class T>
inline void TMatrix<T>::GetMatrix(T*** array)
{
  if (matrix == nullptr)
  {
    (*array) == nullptr;
  }
  else
  {
    (*array) = new T * [n];
    for (int i = 0; i < n; ++i)
    {
      (*array)[i] = new T[m];
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        (*array)[i][j] = matrix[i][j];
    }
  }
}


template<class T>
inline void TMatrix<T>::SetN(int n_)
{
  if (n_ < 0)
    throw "n_<0";
  else if (n_ == 0)
  {
    n = 0;
    m = 0;
    matrix = nullptr;
  }
  else if (n == n_)
    return;
  else
  {
    T** array;
    this->GetMatrix(&array);
    for (int i = 0; i < n; ++i)
      delete[] matrix[i];
    delete[] matrix;
    if (n_ < n)
    {
      n = n_;
      matrix = new T * [n];
      for (int i = 0; i < n; ++i)
        matrix[i] = new T[m];
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < m; ++j)
          matrix[i][j] = array[i][j];
        delete[] array[i];
      }
      delete[] array;
    }
    else
    {
      matrix = new T * [n_];
      for (int i = 0; i < n_; ++i)
        matrix[i] = new T[m];
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < m; ++j)
          matrix[i][j] = array[i][j];
        delete[] array[i];
      }
      delete[] array;
      for (int i = n; i < n_; ++i)
      {
        for (int j = 0; j < m; ++j)
          matrix[i][j] = 0;
      }
      n = n_;
    }
  }
}


template<class T>
inline void TMatrix<T>::SetM(int m_)
{
  if (m == m_)
    return;
  else if (m_ < 0)
    throw"m_<0";
  else if (m_ == 0)
  {
    n = 0;
    m = 0;
    matrix = nullptr;
  }
  else
  {
    T* vector;
    if (m_ < m)
    {
      for (int i = 0; i < n; ++i)
      {
        m = m_;
        vector = new T[m];
        for (int j = 0; j < m; ++j)
        {
          vector[j] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = new T[m];
        for (int j = 0; j < m; ++j)
        {
          matrix[i][j] = vector[j];
        }
        delete[] vector;
      }
    }
    else
    {
      for (int i = 0; i < n; ++i)
      {
        vector = new T[m];
        for (int j = 0; j < m; ++j)
        {
          vector[j] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = new T[m_];
        for (int j = 0; j < m; ++j)
        {
          matrix[i][j] = vector[j];
        }
        for (int j = m; j < m_; ++j)
        {
          matrix[i][j] = 0;
        }
        delete[] vector;
      }
      m = m_;
    }
  }
}


template<class T>
inline void TMatrix<T>::SetMatrix(T** array)
{
  if (matrix == nullptr)
    return;
  else
  {
    try
    {
      T test = array[n - 1][m - 1];
    }
    catch (...)
    {
      throw "size error";
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        matrix[i][j] = array[i][j];
      }
    }
  }
}


template<class T>
inline TMatrix<T> TMatrix<T>::Transposition()
{
  if (matrix == nullptr)
    throw "matrix == nullptr";
  TMatrix<T> table(m,n);
  for (int j = 0; j < m; ++j)
  {
    for (int i = 0; i < n; ++i)
    {
      table.matrix[j][i] = matrix[i][j];
    }
  }
  return table;
}


template<class T>
inline TMatrix<T> TMatrix<T>::Minor(int string, int column)
{
  if (n != m)
    throw"n!=m";
  if (matrix == nullptr)
    throw"matrix==nullptr";
  TMatrix<T> cp(n - 1, m - 1);
  int newi = 0;
  for (int i = 0; i < n; ++i)
  {
    if (i != column)
    {
      int newj = 0;
      for (int j = 0; j < m; ++j)
      {
        if (j != string)
        {
          cp.matrix[newi][newj] = matrix[i][j];
          newj++;
        }
      }
      newi++;
    }
  }
  return cp;
}


template<class T>
inline TMatrix<T> TMatrix<T>::Attached()
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (n != m || n==1)
    throw"n!=m";
  else
  {
    TMatrix<T> cp(n, m);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        TMatrix<T> d = this->Minor(i, j);
        cp.matrix[i][j] = d.Determinant() * pow(-1, i + j);
      }
    }
    return cp;
  }
}


template<class T>
inline TMatrix<T> TMatrix<T>::Inverse()
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (n != m)
    throw"n!=m";
  else if (this->Determinant() == 0)
    throw"det = 0";
  else if (n == 1)
  {
    TMatrix<T> cp;
    cp.matrix[0][0] = 1 / matrix[0][0];
    return cp;
  }
  else if (n>=2)
  {
    TMatrix<T> cp = this->Attached();
    return cp / this->Determinant();
  }
}

template<class T>
inline TMatrix<T> TMatrix<T>::Gauss()
{
  if (n != m)
    throw("n!=m");
  else
  {
    TMatrix<T> t(*this);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (i != j)
        {
          T mul = t.matrix[j][i];
          for (int k = 0; k < n; ++k)
          {
            if (t.matrix[j][k]!=0)
              t.matrix[j][k] = t.matrix[j][k] * t.matrix[i][i] - t.matrix[i][k] * mul;
          }
        }
      }
    }
    return t;
  }
}


template<class T>
inline T TMatrix<T>::Determinant()
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (n != m)
    throw "n!=m";
  if (n == 1)
    return matrix[0][0];
  else if (n == 2)
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
  else
  {
    TMatrix<T> t(*this);
    for (int i = 0; i < n; ++i)
    {
      for (int j = i+1; j < n; ++j)
      {
        T mul = t.matrix[j][i];
        for (int k = 0; k < n; ++k)
        {
          if (t.matrix[j][k] != 0)
            t.matrix[j][k] = t.matrix[j][k] * t.matrix[i][i] - t.matrix[i][k] * mul;
        }
      }
    }
    T det = 1;
    for (int i = 0; i < n;++i)
      det *= t.matrix[i][i];
    return det;
  }
}


template<class T>
inline int TMatrix<T>::CountOfIncludes(T num)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (matrix[i][j] == num)
        count++;
    }
  }
  return count;
}


template<class T>
inline TMatrix<T> TMatrix<T>::IndexesOfIncludes(T num)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  int count = 0;
  TMatrix<T> res(this->CountOfIncludes(num),2);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (matrix[i][j] == num)
      {
        res.matrix[count][0] = T(j);
        res.matrix[count][1] = T(i);
        count++;
      }
    }
  }
  return res;
}


template<class T>
inline TMatrix<T> TMatrix<T>::Pow(int st)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  else if (n != m)
    throw "n!=m";
  else if (st == 0)
  {
    TMatrix<T> a(n, n);
    return a;
  }
  else if (st > 0)
  {
    TMatrix<T> a(*this),res(*this);
    for (int i = 1; i < st; ++i)
      res = res * a;
    return res;
  }
  else
  {
    TMatrix<T> a(*this), res(*this);
    a = a.Inverse();
    res = a;
    for (int i = 1; i < st; ++i)
      res = res * a;
    return res;
  }
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix& table)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (table.matrix == nullptr)
    throw "table.matrix==nullptr";
  if (n != n or m != m)
    throw "n!=n or m!=m";
  else
  {
    TMatrix<T> cp(n, m);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        cp.matrix[i][j] = matrix[i][j] + table.matrix[i][j];
    }
    return cp;
  }  
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& table)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (table.matrix == nullptr)
    throw "table.matrix==nullptr";
  if (n != n or m != m)
    throw "n!=n or m!=m";
  else
  {
    TMatrix<T> cp(n, m);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        cp.matrix[i][j] = matrix[i][j] - table.matrix[i][j];
    }
    return cp;
  }
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& table)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (table.matrix == nullptr)
    throw "table.matrix==nullptr";
  if (m != table.n)
    throw "m!=table.n";
  else
  {
    TMatrix<T> cp(n, table.m);
    for (int i = 0;i<cp.n;++i)
    {
      for (int j = 0; j < cp.m; ++j)
      {
        for (int k = 0; k < m; ++k)
          cp.matrix[i][j] += matrix[i][k] * table.matrix[k][j];
      }
    }
    return cp;
  }
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator*(T num)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  TMatrix<T> cp(n,m);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      cp.matrix[i][j] = num * matrix[i][j];
  }
  return cp;
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator/(T num)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  TMatrix<T> cp(n, m);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      cp.matrix[i][j] = matrix[i][j] / num;
  }
  return cp;
}


template<class T>
inline TMatrix<T> TMatrix<T>::operator=(const TMatrix& table)
{
  if (table.matrix == nullptr)
    throw "table.matrix==nullptr";
  n = table.n;
  m = table.m;
  matrix = new T * [n];
  for (int i = 0; i < n; ++i)
  {
    matrix[i] = new T[m];
    for (int j = 0; j < m; ++j)
      matrix[i][j] = table.matrix[i][j];
  }
  return *this;
}


template<class T>
inline bool TMatrix<T>::operator==(const TMatrix& table)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (table.matrix == nullptr)
    throw "table.matrix==nullptr";
  if (n != table.n || m != table.m)
    return false;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m;++j)
    {
      if (matrix[i][j] != table.matrix[i][j])
        return false;
    }
  }
  return true;
}


template<class T>
inline T*& TMatrix<T>::operator[](int index)
{
  if (matrix == nullptr)
    throw "matrix==nullptr";
  if (index >= n)
    throw"index>=n";
  return matrix[index];
}


template<typename O>
inline ostream& operator<<(ostream& o, TMatrix<O>& t)
{
  if (t.matrix == nullptr)
  {
    o << "Size: " << 0 << " * " << 0 << ".\n"<<"[]";
  }
  else
  {
    o << "Size: " << t.n << " * " << t.m << ".\n";
    for (int i = 0; i < t.n; ++i)
    {
      o << "\t";
      for (int j = 0; j < t.m; ++j)
      {
        o << t.matrix[i][j] << "\t";
      }
      o << endl;
    }
  }
  return o;
}


template <typename I>
inline istream& operator>>(istream& i, TMatrix<I>& t)
{
  cout << "Enter the count of strings: ";
  cin >> t.n;
  cout << "Enter the count of columns: ";
  cin >> t.m;
  if (t.m == 0 || t.n == 0)
    t.matrix = nullptr;
  else
  {
    t.matrix = new I * [t.n];
    for (int i = 0; i < t.n; ++i)
    {
      t.matrix[i] = new I[t.m];
      for (int j = 0; j < t.m; ++j)
      {
        cout << "matrix[" << i << "][" << j << "] = ";
        cin >> t.matrix[i][j];
      }
    }
  }
  return i;
}