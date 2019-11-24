#include <cstdio>
#include <cassert>
#include "phevaluator/phevaluator.h"
#include "benchmark/benchmark.h"

using namespace phevaluator;

static void EvaluateAllFiveCards(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 48; a++) {
      for(int b = a + 1; b < 49; b++) {
        for(int c = b + 1; c < 50; c++) {
          for(int d = c + 1; d < 51; d++) {
            for(int e = d + 1; e < 52; e++) {
              EvaluateCards(a, b, c, d, e);
            }
          }
        }
      }
    }
  }
}
BENCHMARK(EvaluateAllFiveCards);

static void EvaluateAllSixCards(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 47; a++) {
      for(int b = a + 1; b < 48; b++) {
        for(int c = b + 1; c < 49; c++) {
          for(int d = c + 1; d < 50; d++) {
            for(int e = d + 1; e < 51; e++) {
              for(int f = e + 1; f < 52; f++) {
                EvaluateCards(a, b, c, d, e, f);
              }
            }
          }
        }
      }
    }
  }
}
BENCHMARK(EvaluateAllSixCards);

static void EvaluateAllSevenCards(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 46; a++) {
      for(int b = a + 1; b < 47; b++) {
        for(int c = b + 1; c < 48; c++) {
          for(int d = c + 1; d < 49; d++) {
            for(int e = d + 1; e < 50; e++) {
              for(int f = e + 1; f < 51; f++) {
                for(int g = f + 1; g < 52; g++) {
                  EvaluateCards(a, b, c, d, e, f, g);
                }
              }
            }
          }
        }
      }
    }
  }
}
BENCHMARK(EvaluateAllSevenCards);

static void EvaluateAllEightCards(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 45; a++) {
      for(int b = a + 1; b < 46; b++) {
        for(int c = b + 1; c < 47; c++) {
          for(int d = c + 1; d < 48; d++) {
            for(int e = d + 1; e < 49; e++) {
              for(int f = e + 1; f < 50; f++) {
                for(int g = f + 1; g < 51; g++) {
                  for(int h = g + 1; h < 52; h++) {
                    EvaluateCards(a, b, c, d, e, f, g, h);
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
BENCHMARK(EvaluateAllEightCards);

static void EvaluateAllNineCards(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 44; a++) {
      for(int b = a + 1; b < 45; b++) {
        for(int c = b + 1; c < 46; c++) {
          for(int d = c + 1; d < 47; d++) {
            for(int e = d + 1; e < 48; e++) {
              for(int f = e + 1; f < 49; f++) {
                for(int g = f + 1; g < 50; g++) {
                  for(int h = g + 1; h < 51; h++) {
                    for(int i = h + 1; i < 52; i++) {
                      EvaluateCards(a, b, c, d, e, f, g, h, i);
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
BENCHMARK(EvaluateAllNineCards);

static void EvaluateAllFiveCardHands(benchmark::State& state) {
  for (auto _ : state) {
    for(int a = 0; a < 48; a++) {
      for(int b = a + 1; b < 49; b++) {
        for(int c = b + 1; c < 50; c++) {
          for(int d = c + 1; d < 51; d++) {
            for(int e = d + 1; e < 52; e++) {
              EvaluateHand(Hand({a, b, c, d, e}));
            }
          }
        }
      }
    }
  }
}
//BENCHMARK(EvaluateAllFiveCardHands);

BENCHMARK_MAIN();

