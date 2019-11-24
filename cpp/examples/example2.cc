#include <phevaluator/phevaluator.h>
#include <iostream>
#include <cassert>

int main()
{
	/*
	 * This demonstrated scenario is the same as the one shown in example 1.
	 * Community cards: 9c 4c 4s 9d 4h (both players share these cards)
	 * Player a: Qc 6c
	 * Player b: 2c 9h
	 */
	phevaluator::Rank a = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "Qc", "6c");
	phevaluator::Rank b = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "2c", "9h");

	// expected 292
  assert(a.value() == 292);
	std::cout << "The rank of the hand in player a is " << a.value() << std::endl;
	// expected 236
  assert(b.value() == 236);
	std::cout << "The rank of the hand in player b is " << b.value() << std::endl;

  assert(a < b);
  std::cout << "Player b has a stronger hand" << std::endl;

}
