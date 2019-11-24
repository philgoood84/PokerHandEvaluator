#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <phevaluator/phevaluator.h>
#include <phevaluator/rank.h>

/*
 * This C code is a demonstration of how to calculate the card id, which will
 * be used as the parameter in the evaluator. It also shows how to use the
 * return value to determine which hand is the stronger one.
 */
int main()
{
	/*
	 * The least two significant bits represents the suit.
	 * As long as they are distinct, it's OK.
	 * Here we use 0 for club, 1 for diamond, 2 for heart, and 3 for spade.
	 *
	 * The rest of the bits represents the rank, the rank values are:
	 * deuce = 0, trey = 1, four = 2, five = 3, six = 4, seven = 5, eight = 6,
	 * nine = 7, ten = 8, jack = 9, queen = 10, king = 11, ace = 12.
	 *
	 * We can use the formula `rank * 4 + suit` to get the card id.
	 *
	 *
	 * In this example we use a scenario in the game Texas Holdem:
	 * Community cards: 9c 4c 4s 9d 4h (both player share this cards)
	 * Player 1: Qc 6c
	 * Player 2: 2c 9h
	 *
	 * Both players have a full house, but player 1 only has a four full house
	 * while player 2 has a nine full house.
	 * The result should be player 2 has a stronger hand than player 1.
	 */

	// Community cards
	int a = 7 * 4 + 0; // 9c
	int b = 2 * 4 + 0; // 4c
	int c = 2 * 4 + 3; // 4s
	int d = 7 * 4 + 1; // 9d
	int e = 2 * 4 + 2; // 4h

	// Player 1
	int f = 10 * 4 + 0; // Qc
	int g = 4 * 4 + 0; // 6c

	// Player 2
	int h = 0 * 4 + 0; // 2c
	int i = 7 * 4 + 2; // 9h

	// Evaluating the hand of player 1
	int x = evaluate_7cards(a, b, c, d, e, f, g);
	// Evaluating the hand of player 2
	int y = evaluate_7cards(a, b, c, d, e, h, i);

  assert(x == 292);
  assert(y == 236);

	printf("The rank of the hand in player 1 is %d\n", x); // expected 292
	printf("The rank of the hand in player 2 is %d\n", y); // expected 236
	printf("Player 2 has a stronger hand\n");

	// Since the return value of the hand in player 2 is less than player 1,
	// it's considered to be a higher rank and stronger hand.
	// So player 2 beats player 1.

  int rank_category = get_rank_category(x);
  assert(rank_category == FULL_HOUSE);
  const char* rank_category_description = describe_rank_category(rank_category);
  assert(strcmp(rank_category_description, "Full House") == 0);

	return 0;
}
