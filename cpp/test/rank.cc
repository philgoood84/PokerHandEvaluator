#include <cstdio>
#include <cassert>
#include <algorithm>
#include <phevaluator/phevaluator.h>
#include "gtest/gtest.h"
#include "kev/kev_eval.h"

using namespace phevaluator;

TEST(RankTest, TestValue) {
  Rank a = EvaluateCards("9c", "4c", "4s", "9d", "4h");
	Rank b = EvaluateCards("9c", "4c", "4s", "9d", "9h");

  ASSERT_EQ(a.value(), 292);
  ASSERT_EQ(b.value(), 236);
}

TEST(RankTest, TestComparison) {
  Rank a = EvaluateCards("9c", "4c", "4s", "9d", "4h");
	Rank b = EvaluateCards("9c", "4c", "4s", "9d", "9h");

  ASSERT_GT(b, a);
  ASSERT_GE(b, a);
  ASSERT_LT(a, b);
  ASSERT_LE(a, b);
  ASSERT_NE(a, b);
  ASSERT_TRUE(a != b);
}

TEST(RankTest, TestRankCategory) {
  Rank a = EvaluateCards("9c", "4c", "4s", "9d", "4h");
	Rank b = EvaluateCards("As", "Ks", "Qs", "Js", "Ts");

  ASSERT_EQ(a.category(), FULL_HOUSE);
  ASSERT_EQ(b.category(), STRAIGHT_FLUSH);

  ASSERT_EQ(a.describeCategory(), "Full House");
  ASSERT_EQ(b.describeCategory(), "Straight Flush");
}

TEST(RankTest, TestSampleHand) {
  Rank a = EvaluateCards("9c", "4c", "4s", "9d", "4h");
	Rank b = EvaluateCards("As", "Ks", "Qs", "Js", "Ts");

  ASSERT_EQ(a.describeSampleHand(), "44499");
  ASSERT_EQ(b.describeSampleHand(), "AKQJT");

  ASSERT_FALSE(a.isFlush());
  ASSERT_TRUE(b.isFlush());
}
