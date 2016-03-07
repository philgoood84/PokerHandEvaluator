/*
 *  Copyright 2016 Henry Lee
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

#include <stdio.h>
#include <assert.h>
#include "hash.h"
#include "tables.h"

/*
 * Card id, ranged from 0 to 51.
 * The two least significant bits represent the suit, ranged from 0-3.
 * The rest of it represent the rank, ranged from 0-12.
 * 13 * 4 gives 52 ids.
 */
int evaluate_5cards_fast(int a, int b, int c, int d, int e)
{
	unsigned long long handid = 0x00;
	int hash;

	handid = shift[a] | shift[b] | shift[c] | shift[d] | shift[e];

	hash = fast_hash(handid, 5);

	return hashtable5[hash];
}

int evaluate_5cards_hand_fast(unsigned long long handid)
{
	int hash = fast_hash(handid, 5);

	return hashtable5[hash];
}


