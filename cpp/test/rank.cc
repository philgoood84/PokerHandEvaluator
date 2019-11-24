#include <cstdio>
#include <cassert>
#include <algorithm>
#include <phevaluator/phevaluator.h>
#include "gtest/gtest.h"
#include "kev/kev_eval.h"

using namespace phevaluator;

TEST(RankTest, TestValue) {
  Rank a = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "Qc", "6c");
	Rank b = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "2c", "9h");

  ASSERT_EQ(a.value(), 292);
  ASSERT_EQ(b.value(), 236);
}

TEST(RankTest, TestComparison) {
  Rank a = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "Qc", "6c");
	Rank b = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "2c", "9h");

  ASSERT_GT(b, a);
  ASSERT_GE(b, a);
  ASSERT_LT(a, b);
  ASSERT_LE(a, b);
  ASSERT_NE(a, b);
  ASSERT_TRUE(a != b);
}
