#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "evaluator.h"
#include "kev/kev_eval.h"

int main(void)
{
    int a, b, c, d, e;
    int count = 0;

    // loop over every possible five-card hand
	for(a=0; a<48; a++)
	{
		for(b=a+1; b<49; b++)
		{
			for(c=b+1; c<50; c++)
			{
				for(d=c+1; d<51; d++)
				{
					for(e=d+1; e<52; e++)
					{
						int ph_eval = evaluate_5cards(a, b, c, d, e);
						int kev_eval = kev_eval_5cards(a, b, c, d, e);

                        assert(ph_eval == kev_eval);

                        count++;
					}
				}
			}
		}
	}

    printf("Test completed. Tested %d hands in total\n", count);

	return 0;
}
