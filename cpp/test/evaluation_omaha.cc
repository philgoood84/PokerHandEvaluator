#include <cstdio>
#include <cassert>
#include <algorithm>
#include <phevaluator/phevaluator.h>
#include "gtest/gtest.h"
#include "kev/kev_eval.h"

using namespace phevaluator;

static int percentage(long long numerator, long long denominator) {
  return numerator * 100 / denominator;
}

TEST(EvaluationTest, TestOmahaCards) {
  long long count = 0;
  int progress = 0;
  const long long total = 3679075400;

  std::printf("Start testing Omaha cards\n");

  for(int a = 0; a < 44; a ++)
  {
    for(int b = a + 1; b < 45; b++)
    {
      for(int c = b + 1; c < 46; c++)
      {
        for(int d = c + 1; d < 47; d++)
        {
          for(int e = d + 1; e < 48; e++)
          {
            for(int f = e + 1; f < 49; f++)
            {
              for(int g = f + 1; g < 50; g++)
              {
                for(int h = g + 1; h < 51; h++)
                {
                  for(int i = h + 1; i < 52; i++)
                  {
                    short best = 20000;

                    int board[10][3] = {
                      {a, b, c},
                      {a, b, d},
                      {a, b, e},
                      {a, c, d},
                      {a, c, e},
                      {a, d, e},
                      {b, c, d},
                      {b, c, e},
                      {b, d, e},
                      {c, d, e},
                    };
                    int hole[6][2] = {
                      {f, g},
                      {f, h},
                      {f, i},
                      {g, h},
                      {g, i},
                      {h, i},
                    };

                    for (int j = 0; j < 10; j++) {
                      for (int k = 0; k < 6; k++) {
                        best = std::min(kev_eval_5cards(board[j][0], board[j][1], board[j][2],
                            hole[k][0], hole[k][1]), best);
                      }
                    }
                    int ph_eval = EvaluateOmahaCards(a, b, c, d, e, f, g, h, i).value();

                    EXPECT_EQ(ph_eval, best) << "Cards are: "
                      << a << ", " << b << ", " << c << ", " << d << ", "
                      << e << ", " << f << ", " << g << ", " << h << ", "
                      << i << ", ";

                    count++;

                    if (percentage(count, total) > progress) {
                      progress = percentage(count, total);
                      if (progress % 2 == 0) {
                        std::printf("Test progress: %d%%\n", progress);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing Omaha cards\n");
  std::printf("Tested %lld hands in total\n", count);
}

