#include <iostream>
#include <phevaluator/phevaluator.h>
#include <phevaluator/rank.h>

int main()
{
  /*
   * Community cards: 4c 5c 6c 7c 8c
   * Player 1: 2c 9c As Kd
   * Player 2: 6s 9s Ts Js
   */
  phevaluator::Rank rank1 =
    phevaluator::EvaluateOmahaCards("4c", "5c", "6c", "7c", "8c", "2c", "9c", "As", "Kd");
  phevaluator::Rank rank2 =
    phevaluator::EvaluateOmahaCards("4c", "5c", "6c", "7c", "8c", "6s", "9s", "Ts", "Js");


  /*
   * Even though there is a straight-flush in the community cards, neither player
   * can make a straight-flush in the end, because they can only choose exactly three
   * cards from the community cards.
   *
   * So the result is, Player 1 can make a 9-high flush in clubs, and Player 2 can
   * only make a 10-high straight.
   */
  std::cout << "Player 1 has:" << std::endl;
  std::cout << rank1.describeCategory() << std::endl;
  std::cout << rank1.describeRank() << std::endl;
  std::cout << rank1.describeSampleHand() << std::endl;
  std::cout << rank1.value() << std::endl;

  std::cout << std::endl;

  std::cout << "Player 2 has:" << std::endl;
  std::cout << rank2.describeCategory() << std::endl;
  std::cout << rank2.describeRank() << std::endl;
  std::cout << rank2.describeSampleHand() << std::endl;
  std::cout << rank2.value() << std::endl;

	return 0;
}
