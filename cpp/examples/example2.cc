#include "phevaluator/phevaluator.h"
#include <iostream>

int main()
{
	/*
	 * This demonstrated scenario is the same as the one shown in example 1.
	 * Community cards: 9c 4c 4s 9d 4h (both player share this cards)
	 * Player 1: Qc 6c
	 * Player 2: 2c 9h
	 */

	int x = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "Qc", "6c");
	int y = phevaluator::EvaluateCards("9c", "4c", "4s", "9d", "4h", "2c", "9h");

	// expected 292
	std::cout << "The rank of the hand in player 1 is " << x << std::endl;
	// expected 236
	std::cout << "The rank of the hand in player 2 is " << y << std::endl;
    std::cout << "Player 2 has a stronger hand" << std::endl;

	// As the value of player 2 is less than player 1, the hand of player 2 is
	// considered to be a stronger one.
}
