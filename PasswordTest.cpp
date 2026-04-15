// Google Test unit tests for Password
#include "Password.h"
#include <gtest/gtest.h>

TEST(CountLeadingCharacters, EmptyString) {
  Password p;
  EXPECT_EQ(p.count_leading_characters(""), 0);
}

TEST(CountLeadingCharacters, SingleChar) {
  Password p;
  EXPECT_EQ(p.count_leading_characters("a"), 1);
}

TEST(CountLeadingCharacters, AllSame) {
  Password p;
  EXPECT_EQ(p.count_leading_characters("aaaaa"), 5);
}

TEST(CountLeadingCharacters, MixedStart) {
  Password p;
  EXPECT_EQ(p.count_leading_characters("aaaabbb"), 4);
  EXPECT_EQ(p.count_leading_characters("bbbaaa"), 3);
}

TEST(CountLeadingCharacters, CaseSensitive) {
  Password p;
  EXPECT_EQ(p.count_leading_characters("AAaa"), 2);
}

TEST(HasMixedCase, EmptyStringFalse) {
  Password p;
  EXPECT_FALSE(p.has_mixed_case(""));
}

TEST(HasMixedCase, AllLowerFalse) {
  Password p;
  EXPECT_FALSE(p.has_mixed_case("lowercase"));
}

TEST(HasMixedCase, AllUpperFalse) {
  Password p;
  EXPECT_FALSE(p.has_mixed_case("UPPERCASE"));
}

TEST(HasMixedCase, MixedTrue) {
  Password p;
  EXPECT_TRUE(p.has_mixed_case("MixedCase"));
  EXPECT_TRUE(p.has_mixed_case("aB"));
  EXPECT_TRUE(p.has_mixed_case("A1b"));
}

TEST(HasMixedCase, NonAlphabetIgnored) {
  Password p;
  EXPECT_FALSE(p.has_mixed_case("1234!@#"));
  EXPECT_TRUE(p.has_mixed_case("1aA"));
}