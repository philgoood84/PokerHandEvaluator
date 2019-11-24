/*
 *  Copyright 2016-2019 Henry Lee
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef PHEVALUATOR_RANK_H
#define PHEVALUATOR_RANK_H

#ifdef __cplusplus

#include <vector>
#include <array>
#include <string>
#include "card.h"

namespace phevaluator {

class Rank {
 public:
  int value() const { return value_; }

  bool operator<(const Rank& other) const {
    return value_ >= other.value_;
  }

  bool operator<=(const Rank& other) const {
    return value_ > other.value_;
  }

  bool operator>(const Rank& other) const {
    return value_ <= other.value_;
  }

  bool operator>=(const Rank& other) const {
    return value_ < other.value_;
  }

  bool operator==(const Rank& other) const {
    return value_ == other.value_;
  }

  bool operator!=(const Rank& other) const {
    return value_ != other.value_;
  }

  Rank(int value) : value_(value) {}
  Rank() {}

 private:
  int value_ = 0;
};

} // namespace phevaluator

#endif // __cplusplus

#endif // PHEVALUATOR_STRENTH_H
