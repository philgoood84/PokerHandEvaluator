#include <algorithm>
#include <vector>
#include <set>
#include <chrono>
#include <random>
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

static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
static std::default_random_engine generator(seed);
static std::uniform_int_distribution<int> distribution(0, 51);

static std::vector<int> RandomCardSample(int size) {
  std::vector<int> ret;
  std::set<int> sample;

  while (sample.size() < size) {
    int number = distribution(generator);
    if (sample.find(number) == sample.end()) {
      ret.push_back(number);
      sample.insert(number);
    }
  }

  return ret;
}

static void EvaluateRandomFiveCards(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> randomCards = RandomCardSample(5);
    state.ResumeTiming();

    EvaluateCards(randomCards[0],
                  randomCards[1],
                  randomCards[2],
                  randomCards[3],
                  randomCards[4]);
  }
}
BENCHMARK(EvaluateRandomFiveCards);

static void EvaluateRandomSixCards(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> randomCards = RandomCardSample(6);
    state.ResumeTiming();

    EvaluateCards(randomCards[0],
                  randomCards[1],
                  randomCards[2],
                  randomCards[3],
                  randomCards[4],
                  randomCards[5]);
  }
}
BENCHMARK(EvaluateRandomSixCards);

static void EvaluateRandomSevenCards(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> randomCards = RandomCardSample(7);
    state.ResumeTiming();

    EvaluateCards(randomCards[0],
                  randomCards[1],
                  randomCards[2],
                  randomCards[3],
                  randomCards[4],
                  randomCards[5],
                  randomCards[6]);
  }
}
BENCHMARK(EvaluateRandomSevenCards);

static void EvaluateRandomOmahaCards(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> randomCards = RandomCardSample(9);
    state.ResumeTiming();

    EvaluateOmahaCards(randomCards[0],
                       randomCards[1],
                       randomCards[2],
                       randomCards[3],
                       randomCards[4],
                       randomCards[5],
                       randomCards[6],
                       randomCards[7],
                       randomCards[8]);
  }
}
BENCHMARK(EvaluateRandomOmahaCards);

BENCHMARK_MAIN();

