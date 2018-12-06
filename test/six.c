#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "evaluator.h"
#include "kev/kev_eval.h"

int main(void)
{
    int a, b, c, d, e, f;

	for(a=0; a<47; a++)
	{
		for(b=a+1; b<48; b++)
		{
			for(c=b+1; c<49; c++)
			{
				for(d=c+1; d<50; d++)
				{
					for(e=d+1; e<51; e++)
					{
						for(f=e+1; f<52; f++)
						{
                            int ph_eval = evaluate_6cards(a, b, c, d, e, f);
                            int kev_eval = kev_eval_6cards(a, b, c, d, e, f);

                            assert(ph_eval == kev_eval);
                        }
					}
				}
			}
		}
	}

	return 0;
}
