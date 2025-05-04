#include "TMatrix.h"

#include <gtest.h>


TEST(TMatrix, can_create_matrix_with_nonegative_parametrs)
{
  ASSERT_NO_THROW(TMatrix <double> table(3, 3));
}


TEST(TMatrix, throw_create_matrix_with_negative_strings)
{
  ASSERT_ANY_THROW(TMatrix<double> table(-3,2));
}


TEST(TMatrix, throw_create_matrix_with_negative_columns)
{
  ASSERT_ANY_THROW(TMatrix<double> table(3, -2));
}


TEST(TMatrix, can_copy)
{
  TMatrix<double> table(2, 3);
  TMatrix<double> tablec(table);
  EXPECT_NEAR(1, table==tablec, 0.000001);
}


TEST(TMatrix, can_get_n)
{
  TMatrix<int> a(2, 3);
  EXPECT_NEAR(2,a.GetN(), 0.000001);
}


TEST(TMatrix, can_get_m)
{
  TMatrix<int> a(2, 3);
  EXPECT_NEAR(3, a.GetM(), 0.000001);
}


TEST(TMatrix, can_set_n)
{
  TMatrix<int> s(2,3);
  s.SetN(4);
  EXPECT_NEAR(4, s.GetN(), 0.000001);
}


TEST(TMatrix, throw_set_n)
{
  TMatrix<int> s(2,3);
  ASSERT_ANY_THROW(s.SetN(-2));
}


TEST(TMatrix, can_set_m)
{
  TMatrix<int> s(2, 3);
  s.SetM(4);
  EXPECT_NEAR(4, s.GetM(), 0.000001);
}


TEST(TMatrix, throw_set_m)
{
  TMatrix<int> s(2, 3);
  ASSERT_ANY_THROW(s.SetM(-2));
}


TEST(TMatrix, can_add)
{
  TMatrix<int> s(2,2),u(2,2),add(2,2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = 6;
  add[0] [1] = 8;
  add[1][0] = 10;
  add[1][1] = 6;
  EXPECT_NEAR(1,s+u==add, 0.000001);
}


TEST(TMatrix, throw_add_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2,2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u+s);
}


TEST(TMatrix, throw_add_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s+u);
}


TEST(TMatrix, throw_add_size_error)
{
  TMatrix<int> s(2,3), u(2, 2);
  ASSERT_ANY_THROW(s + u);
}


TEST(TMatrix, can_sub)
{
  TMatrix<int> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = -4;
  add[0][1] = -4;
  add[1][0] = -4;
  add[1][1] = -4;
  EXPECT_NEAR(1, s - u == add, 0.000001);
}


TEST(TMatrix, throw_sub_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u - s);
}


TEST(TMatrix, throw_sub_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s - u);
}


TEST(TMatrix, throw_sub_size_error)
{
  TMatrix<int> s(2, 3), u(2, 2);
  ASSERT_ANY_THROW(s - u);
}


TEST(TMatrix, can_mul_by_matrix)
{
  TMatrix<int> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = 19;
  add[0][1] = 16;
  add[1][0] = 22;
  add[1][1] = 23;
  EXPECT_NEAR(1, s * u == add, 0.000001);
}


TEST(TMatrix, throw_mul_by_matrix_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u * s);
}


TEST(TMatrix, throw_mul_by_matrix_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s * u);
}


TEST(TMatrix, throw_mul_by_matrix_size_error)
{
  TMatrix<int> s(2, 3), u(2, 2);
  ASSERT_ANY_THROW(s * u);
}


TEST(TMatrix, can_mul_by_num)
{
  TMatrix<int> s(2, 2),add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 3;
  add[0][1] = 6;
  add[1][0] = 9;
  add[1][1] = 3;
  EXPECT_NEAR(1, s * 3 == add, 0.000001);
}


TEST(TMatrix, throw_mul_by_num_matrix_is_nullptr)
{
  TMatrix<int> u;
  ASSERT_ANY_THROW(u * 2);
}


TEST(TMatrix, can_devide_by_num)
{
  TMatrix<int> s(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 3;
  add[0][1] = 6;
  add[1][0] = 9;
  add[1][1] = 3;
  EXPECT_NEAR(1, add / 3 == s, 0.000001);
}


TEST(TMatrix, throw_devide_by_num_matrix_is_nullptr)
{
  TMatrix<int> u;
  ASSERT_ANY_THROW(u / 2);
}


TEST(TMatrix, throw_devide_by_zero)
{
  TMatrix<int> u(2,2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u / 0);
}


TEST(TMatrix, can_equip_by_num)
{
  TMatrix<int> s(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  EXPECT_NEAR(1, add == s, 0.000001);
}


TEST(TMatrix, throw_equip_first_nullptr)
{
  TMatrix<int> s, add(2, 2);

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  ASSERT_ANY_THROW(s==add);
}


TEST(TMatrix, throw_equip_second_nullptr)
{
  TMatrix<int> s, add(2, 2);

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  ASSERT_ANY_THROW(add == s);
}


TEST(TMatrix, can_equipment)
{
  TMatrix<int> s(2, 2), add;
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  add = s;
  EXPECT_NEAR(1, add == s, 0.000001);
}


TEST(TMatrix, can_get_by_index)
{
  TMatrix<int> s(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  EXPECT_NEAR(2, s[0][1], 0.000001);
}


TEST(TMatrix, throw_get_index_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s[0]);
}


TEST(TMatrix, throw_get_index_more_than_in_matrix)
{
  TMatrix<int> s(2,2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  ASSERT_ANY_THROW(s[3]);
}


TEST(TMatrix, can_transposition)
{
  TMatrix<int> s(2, 2),u(2,2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 1;
  u[0][1] = 3;
  u[1][0] = 2;
  u[1][1] = 1;
  EXPECT_NEAR(1, s.Transposition()==u, 0.000001);
}


TEST(TMatrix, throw_transposition_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Transposition());
}


TEST(TMatrix, can_get_minor)
{
  TMatrix<int> s(2, 2), u(1, 1);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 1;
  EXPECT_NEAR(1, s.Minor(1,1) == u, 0.000001);
}


TEST(TMatrix, throw_minor_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Minor(0,0));
}


TEST(TMatrix, throw_minor_by_nonquadro)
{
  TMatrix<int> s(2,5);
  ASSERT_ANY_THROW(s.Minor(0, 0));
}


TEST(TMatrix, can_get_attached)
{
  TMatrix<int> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;

  u[0][0] = 4;
  u[0][1] = -3;
  u[1][0] = -2;
  u[1][1] = 1;
  EXPECT_NEAR(1, s.Attached() == u, 0.000001);
}


TEST(TMatrix, throw_attached_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Attached());
}


TEST(TMatrix, throw_attached_by_nonquadro)
{
  TMatrix<int> s(2, 5);
  ASSERT_ANY_THROW(s.Attached());
}


TEST(TMatrix, can_get_inverse)
{
  TMatrix<double> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;

  u[0][0] = -2;
  u[0][1] = 1;
  u[1][0] = 1.5;
  u[1][1] = -0.5;
  EXPECT_NEAR(1, s.Inverse() == u, 0.000001);
}


TEST(TMatrix, throw_inverse_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Inverse());
}


TEST(TMatrix, throw_inverse_by_nonquadro)
{
  TMatrix<int> s(2, 5);
  ASSERT_ANY_THROW(s.Inverse());
}


TEST(TMatrix, throw_inverse_zero)
{
  TMatrix<int> s(2, 2);
  ASSERT_ANY_THROW(s.Inverse());
}


