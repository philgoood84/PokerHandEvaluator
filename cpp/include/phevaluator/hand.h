#ifndef PHEVALUATOR_HAND_H
#define PHEVALUATOR_HAND_H

#ifdef __cplusplus

#include <vector>
#include <string>

namespace phevaluator {

class Hand {
 public:
  Hand() {}

  operator int() const { return id_; }

 private:
  int id_;
};

} // namespace phevaluator

#endif // __cplusplus

#endif // PHEVALUATOR_HAND_H
