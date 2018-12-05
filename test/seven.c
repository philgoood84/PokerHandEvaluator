#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "evaluator.h"
#include "kev/kev_eval.h"

int main(void)
{
    int a, b, c, d, e, f, g;

	for(a=0; a<46; a++)
	{
		for(b=a+1; b<47; b++)
		{
			for(c=b+1; c<48; c++)
			{
				for(d=c+1; d<49; d++)
				{
					for(e=d+1; e<50; e++)
					{
						for(f=e+1; f<51; f++)
						{
							for(g=f+1; g<52; g++)
							{
                                int ph_eval = evaluate_7cards(a, b, c, d, e, f, g);
                                int kev_eval = kev_eval_7cards(a, b, c, d, e, f, g);

                                assert(ph_eval == kev_eval);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
