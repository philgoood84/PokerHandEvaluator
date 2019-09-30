#include <cstdio>
#include <cassert>
#include "phevaluator/phevaluator.h"
#include "kev/kev_eval.h"

using namespace phevaluator;

void TestFiveCards()
{
  int count = 0;

  std::printf("Start testing five cards\n");

  for(int a = 0; a < 48; a++)
  {
    for(int b = a + 1; b < 49; b++)
    {
      for(int c = b + 1; c < 50; c++)
      {
        for(int d = c + 1; d < 51; d++)
        {
          for(int e = d + 1; e < 52; e++)
          {
            int ph_eval = evaluate_5cards(a, b, c, d, e); // C method
            int ph_eval_cpp = EvaluateCards(a, b, c, d, e); // C++ method
            int kev_eval = kev_eval_5cards(a, b, c, d, e); // Kev's method

            assert(ph_eval == kev_eval);
            assert(ph_eval_cpp == kev_eval);

            count++;
          }
        }
      }
    }
  }

  std::printf("Complete testing five cards. ");
  std::printf("Tested %d hands in total\n", count);
}

void TestSixCards() {
  int count = 0;

  std::printf("Start testing six cards\n");

  for(int a = 0; a < 47; a++)
  {
    for(int b = a + 1; b < 48; b++)
    {
      for(int c = b + 1; c < 49; c++)
      {
        for(int d = c + 1; d < 50; d++)
        {
          for(int e = d + 1; e < 51; e++)
          {
            for(int f = e + 1; f < 52; f++)
            {
              int ph_eval = evaluate_6cards(a, b, c, d, e, f); // C method
              int ph_eval_cpp = EvaluateCards(a, b, c, d, e, f); // C++ method
              int kev_eval = kev_eval_6cards(a, b, c, d, e, f); // Kev's method

              assert(ph_eval == kev_eval);
              assert(ph_eval_cpp == kev_eval);

              count++;
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing six cards. ");
  std::printf("Tested %d hands in total\n", count);
}

void TestSevenCards()
{
  int count = 0;

  std::printf("Start testing seven cards\n");

  for(int a = 0; a < 46; a ++)
  {
    for(int b = a + 1; b < 47; b++)
    {
      for(int c = b + 1; c < 48; c++)
      {
        for(int d = c + 1; d < 49; d++)
        {
          for(int e = d + 1; e < 50; e++)
          {
            for(int f = e + 1; f < 51; f++)
            {
              for(int g = f + 1; g < 52; g++)
              {
                int ph_eval = evaluate_7cards(a, b, c, d, e, f, g);
                int ph_eval_cpp = EvaluateCards(a, b, c, d, e, f, g);
                int kev_eval = kev_eval_7cards(a, b, c, d, e, f, g);

                assert(ph_eval == kev_eval);
                assert(ph_eval_cpp == kev_eval);

                count++;
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing seven cards. ");
  std::printf("Tested %d hands in total\n", count);
}

void TestEightCards()
{
  int count = 0;

  std::printf("Start testing eight cards\n");

  for(int a = 0; a < 45; a ++)
  {
    for(int b = a + 1; b < 46; b++)
    {
      for(int c = b + 1; c < 47; c++)
      {
        for(int d = c + 1; d < 48; d++)
        {
          for(int e = d + 1; e < 49; e++)
          {
            for(int f = e + 1; f < 50; f++)
            {
              for(int g = f + 1; g < 51; g++)
              {
                for(int h = g + 1; h < 52; h++)
                {
                  int ph_eval = evaluate_8cards(a, b, c, d, e, f, g, h);
                  int ph_eval_cpp = EvaluateCards(a, b, c, d, e, f, g, h);
                  int kev_eval = kev_eval_8cards(a, b, c, d, e, f, g, h);

                  assert(ph_eval == kev_eval);
                  assert(ph_eval_cpp == kev_eval);

                  count++;
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing eight cards. ");
  std::printf("Tested %d hands in total\n", count);
}

void TestNineCards()
{
  int count = 0;

  std::printf("Start testing nine cards\n");

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
                    int ph_eval = evaluate_9cards(a, b, c, d, e, f, g, h, i);
                    int ph_eval_cpp = EvaluateCards(a, b, c, d, e, f, g, h, i);
                    int kev_eval = kev_eval_9cards(a, b, c, d, e, f, g, h, i);

                    assert(ph_eval == kev_eval);
                    assert(ph_eval_cpp == kev_eval);

                    count++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing nine cards. ");
  std::printf("Tested %d hands in total\n", count);
}

int main(void)
{
  TestFiveCards();
  TestSixCards();
  TestSevenCards();
  TestEightCards();
  TestNineCards();
  std::printf("All tests completed.\n");

  return 0;
}
