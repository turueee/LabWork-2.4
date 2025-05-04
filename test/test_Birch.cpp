#include "TString.h"

#include <gtest.h>


///Тесты для класса TAllInstruments
TEST(TString, can_create_String_with_positive_len)
{
  ASSERT_NO_THROW(TString s("abdsfd",3));
}


TEST(TString, throw_create_string_with_negative_len)
{
  ASSERT_ANY_THROW(TString s("dddfjf",-5));
}


TEST(TString, throw_copy_string_by_nullptr)
{
  char* d = nullptr;
  ASSERT_ANY_THROW(TString s(d));
}


TEST(TString, can_copy)
{
  TString s("dfg",3);
  TString sc(s);
  EXPECT_NEAR(1, s==sc, 0.000001);
}


TEST(TString, can_get_string)
{
  TString z("abdsfd", 3);
  char* stl;
  ASSERT_NO_THROW(z.GetStr(&stl));
}


TEST(TString, can_get_len)
{
  TString s("dfg", 3);
  EXPECT_NEAR(3, s.GetLen(), 0.000001);
}


TEST(TString, can_set_str)
{
  TString s("dfg", 3);
  TString z;
  z.SetStr("dfg");
  EXPECT_NEAR(1, s==z, 0.000001);
}


TEST(TString, throw_set_str)
{
  TString s("dfg", 3);
  ASSERT_ANY_THROW(s.SetStr(nullptr));
}


TEST(TString, can_set_len)
{
  TString s("dfg", 3);
  s.SetLen(2);
  EXPECT_NEAR(2, s.GetLen(), 0.000001);
}


TEST(TString, throw_set_len)
{
  TString s("dfg", 3);
  ASSERT_ANY_THROW(s.SetLen(-5));
}


TEST(TString, can_add)
{
  TString s("dfg", 3),u("uio",3),add("dfguio",6);
  EXPECT_NEAR(1,s+u==add, 0.000001);
}


TEST(TString, can_mul)
{
  TString s("dfg"), mul ("dfgdfgdfg");
  EXPECT_NEAR(1, s * 3 == mul, 0.000001);
}


TEST(TString, throw_mul)
{
  TString s("dfg");
  ASSERT_ANY_THROW(s*-3);
}


TEST(TString, can_equality)
{
  TString s("dfg"), mul;
  mul = s;
  EXPECT_NEAR(1, s == mul, 0.000001);
}


TEST(TString, can_equal)
{
  TString s("dfg"), mul("dfg");
  EXPECT_NEAR(1, s == mul, 0.000001);
}


TEST(TString, can_non_equal)
{
  TString s("dfg"), mul("fg");
  EXPECT_NEAR(1, s != mul, 0.000001);
}


TEST(TString, can_more)
{
  TString s("dfg"), mul("fg");
  EXPECT_NEAR(1, s > mul, 0.000001);
}


TEST(TString, can_few)
{
  TString s("df"), mul("dfg");
  EXPECT_NEAR(1, s < mul, 0.000001);
}


TEST(TString, can_index)
{
  TString s("df");
  EXPECT_NEAR(1, s[1]=="f", 0.000001);
}


TEST(TString, throw_index)
{
  TString s("df");
  ASSERT_ANY_THROW(s[4]);
}


TEST(TString, can_search_word)
{
  TString s("dfabaddkdaba");
  EXPECT_NEAR(2, s.WordSearch("aba"), 0.000001);
}


TEST(TString, can_search_letter)
{
  TString s("dfabaddkdaba");
  EXPECT_NEAR(2, s.LetterSearch('a'), 0.000001);
}


TEST(TString, can_split)
{
  TString s("dfabaddkdaba"),c("df"),ab("aba");
  char** sp;
  int l;
  s.Split(ab, &sp, &l);
  TString res(sp[0]);
  EXPECT_NEAR(1, res==c, 0.000001);
}


TEST(TString, can_search_all_word)
{
  TString s("dfabaddkdaba");
  int* ind;
  s.AllIndexWordSearch("aba", &ind);
  EXPECT_NEAR(9, ind[1], 0.000001);
}


TEST(TString, can_search_more_popular_letter)
{
  TString s("aaadfabaddkdaba");
  EXPECT_NEAR(1,'a' == s.MostPopularLetter(), 0.000001);
}


TEST(TString, can_set_unic)
{
  TString s("abcab");
  char* unic;
  s.SetOfLetters(&unic);
  TString d(unic), res("abc");
  EXPECT_NEAR(1, d==res, 0.000001);
}


TEST(TString, can_set_counts)
{
  TString s("abcab");
  int* unic;
  s.CountsOfLetters(&unic);
  EXPECT_NEAR(2, unic[0], 0.000001);
}
