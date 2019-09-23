# PH Evaluator

[![Build Status](https://travis-ci.com/HenryRLee/PokerHandEvaluator.svg?branch=master)](https://travis-ci.com/HenryRLee/PokerHandEvaluator)

A Poker Hand Evaluator based on a Pefect Hash Algorithm

## Overview

Efficiently evaluating a poker hand has been an interesting and challenging
problem. Given two different poker hands, how to determine which one is
stronger? Or more generally, given one poker hand, can we assign a point to
it to indicate its strength?

Cactus Kev once gave [one answer](http://suffe.cool/poker/evaluator.html) for
a five card poker hand. With smart encoding, it ranks each hand to 7462
distinct values.

Still, Kev's solution is specific for a five card hand. To evaluate a seven
card poker hand (which is more pupular because of Texas Hold'em) using Kev's
algorithm, one brute force solution is to iterate all 7 choose 5 combination,
running his 5 card evaluation algorithm 21 times to find the best answer,
which is too time inefficient.

[PH Evaluator](https://github.com/HenryRLee/PokerHandEvaluator) is designed
for evaluating poker hands with more than 5 cards. Instead of traversing all
the combinations, it uses a perfect hash algorithm to get the hand strength
from a pre-computed hash table, which only costs very few CPU cycles and
considerably small memory (~100kb for the 7 card evaluation).

## Algorithm

The [documentation](Documentation/Algorithm.md) has the description of the
underlying algorithm.

## C/C++ Implementation

The [cpp](cpp) subdirectory has the C/C++ implementation of the algorithm.

## Other Implementations

There is a [javascript implementation](https://github.com/thlorenz/phe) using
the same algorithm.


