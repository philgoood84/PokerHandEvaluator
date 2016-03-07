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
#include "tables.h"
#include "hash.h"

int fast_hash(unsigned long long handid, int k)
{
	int hash = 0;
	unsigned char * a = (unsigned char *)&handid;

	assert(k >= 0);

	hash += dp_8bit[a[7]][7][k];
	k -= bitcount[a[7]];

	assert(k >= 0);

	hash += dp_8bit[a[6]][6][k];
	k -= bitcount[a[6]];

	assert(k >= 0);

	hash += dp_8bit[a[5]][5][k];
	k -= bitcount[a[5]];

	assert(k >= 0);

	hash += dp_8bit[a[4]][4][k];
	k -= bitcount[a[4]];

	assert(k >= 0);

	hash += dp_8bit[a[3]][3][k];
	k -= bitcount[a[3]];

	assert(k >= 0);

	hash += dp_8bit[a[2]][2][k];
	k -= bitcount[a[2]];

	assert(k >= 0);

	hash += dp_8bit[a[1]][1][k];
	k -= bitcount[a[1]];

	assert(k >= 0);

	hash += dp_8bit[a[0]][0][k];

	assert(k == bitcount[a[0]]);

	return hash;
}


