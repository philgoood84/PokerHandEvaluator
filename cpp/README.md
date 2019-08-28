# C/C++ Library

## Compile and test

Run `make` to build the `unit_tests` binaray.

Run `make test` to build the unit test and run it.

Run `make libpheval.a` to build the library.

## Use the library

After building the library `libpheval.a`, you can add the `./include`
directory to your includes path (e.g. `g++ -I ./include`).

PH Evaluator was originally coded in C, so it still preserves the C functions.

```
int evaluate_5cards(int a, int b, int c, int d, int e);
int evaluate_6cards(int a, int b, int c, int d, int e, int f);
int evaluate_7cards(int a, int b, int c, int d, int e, int f, int g);
```

However using these functions, user needs to convert his card into an integer
ranged `[0, 52)`. You can find the mapping in the section [Card Id](#cardid).

The return value is identical to the Cactus Kev's evaluator. The strongest
hands (Royal straight flush) returns 1, and the second strongest hands (King
high straight flush) returns 2 and so on. The weakest hands have the return
value 7462.

<a name="cardid"></a>
## Card Id

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
