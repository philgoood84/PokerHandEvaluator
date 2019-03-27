# PHEvaluator

[![Build Status](https://travis-ci.com/HenryRLee/PokerHandEvaluator.svg?branch=master)](https://travis-ci.com/HenryRLee/PokerHandEvaluator)

PH stands for Poker Hand, as well as Perfect Hashing.

A poker hand evaluation algorithm with perfect hash functions and dynamic
programming.

Copyright 2016 Henry Lee (lee0906@hotmail.com)

---------
Overview
---------
It's a brand new algorithm, which avoids traversing all 7 choose 5 combinations
when evaluating a 7-card poker hand, using a perfect hash function instead.

The implementation supports both 5-card and 7-card evaluation, where the 7-card
version beats many other algorithms in the execution time, and it's also using
a considerably small memory (~100kb for the 7-card evaluation).

Their return value is identical to the Cactus Kev's Poker Hand Evaluator
(http://suffe.cool/poker/evaluator.html), where basically a stronger hand has a
lower return value. However, one can modify the hash table to support any kind
of evaluation system he likes.

`Documentation` contains the description of the algorithms used in the
evaluators.

The `examples` directory has some examples that demonstrates how to use the
interface.

---------
Compile and test
---------
Simply run `make` can compile the libraries and the unit test programs.

If you'd like to add some more flags in gcc, you may export the flags to the
environment variable `CFLAGS`. One example is `export CLFAGS="-Ofast"`.

After the compilation, it generates two unit test programs `five` and `seven`.
These test programs loop over all possible hands and compare the result with
the Cactus Kev's evaluator.

To compile those example codes, simply `cd examples` and running `make` will
compile all the examples.

---------
Interfaces
---------
The file `include/evaluator.h` contains the interfaces you need to call.

```
int evaluate_7cards(int a, int b, int c, int d, int e, int f, int g);
int evaluate_6cards(int a, int b, int c, int d, int e, int f);
int evaluate_5cards(int a, int b, int c, int d, int e);
```

The inputs are card ids ranged [0, 52). The card id modulo 4 gives the suit.
It doesn't really matter how you assign the four numbers to the 4 suits, as
long as they use distinct numbers. The card id divided by 4 gives the rank,
where ace has the highest value 12 and deuce has the lowest value 0.

The return value is identical to the Cactus Kev's evaluator. The strongest hands
(Royal straight flush) are returned with 1, and the second strongest hands (King
high straight flush) are returned with 2 and so on. The weakest hands have the
return value 7462.

You can find more about Cactus Kev's evaluation system from these websites.

http://suffe.cool/poker/evaluator.html
http://suffe.cool/poker/7462.html

---------
Card Id
---------
We use an integer to represent a card. The two least significant bits
represent the 4 suits, ranged from 0-3. The rest of it represent the 13
ranks, ranged from 0-12.

More specifically:
deuce = 0, trey = 1, four = 2, five = 3, six = 4, seven = 5, eight = 6,
nine = 7, ten = 8, jack = 9, queen = 10, king = 11, ace = 12.

13 * 4 gives all 52 ids.
 
So the complete card Id representation is:

|   | C | D | H | S |
|---|---|---|---|---|
| 2 | 0 | 1 | 2 | 3 |
| 3 | 4 | 5 | 6 | 7 |
| 4 | 8 | 9 | 10| 11|
| 5 | 12| 13| 14| 15|
| 6 | 16| 17| 18| 19|
| 7 | 20| 21| 22| 23|
| 8 | 24| 25| 26| 27|
| 9 | 28| 29| 30| 31|
| T | 32| 33| 34| 35|
| J | 36| 37| 38| 39|
| Q | 40| 41| 42| 43|
| K | 44| 45| 46| 47|
| A | 48| 49| 50| 51|

---------
Other Implementations
---------
There is a javascript implementation using the same algorithm.

https://github.com/thlorenz/phe
