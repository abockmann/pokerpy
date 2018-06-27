#include <stdio.h>
#include <assert.h>


typedef struct
{
int suit; // 00, 01, 10, 11 representing hearts, diamonds, clubs and spades
int rank; // 4 bits necessary to represent all 13 ranks.  Starting at 2 and ending at 14 (ace)
} card;


int hand_rank_n(card a[], unsigned int size_of_a)
{
   int count[13] = {0};
   // sort
   for (int i=0; i<size_of_a; i++)
   {
	   assert(a[i].rank < 13);
	   count[a[i].rank] += 1;
   }
   // debug
   //for (unsigned int i=0; i<13; i++)
   //{
	//    printf("%d\n", rank[i]); 
   //}
   // iterate backwards
   int straight = 0;
   int flush = 0;
   int consecutive = 0;
   int prev_rank = 20;
   int suit_count[4] = {0};
   for (int i=12; i>=0; i--)
   {
	    // check for straight
	    if ((count[i]>0) && (count[i] == prev_rank-1)) {
			consecutive ++;
		} else {
			consecutive = 0;
		}
		
		if (consecutive == 4) {
			straight = 1;
		}
		
		// check for pairs
		
		
	    printf("%d\n", i);
		
		
		
		
		
		
		
		
		if (count[i]>0) 
		{
			prev_rank = i;
		}
   }
   return 0;
}
	   


int main()
{
	
	
	card cards[5];
	cards[0].suit = 3;
	cards[0].rank = 2;
	cards[1].suit = 3;
	cards[1].rank = 5;
	cards[2].suit = 3;
	cards[2].rank = 12;
	cards[3].suit = 0;
	cards[3].rank = 10;
	cards[4].suit = 0;
	cards[4].rank = 10;

	hand_rank_n(cards, 5);
	
	return 0;
}