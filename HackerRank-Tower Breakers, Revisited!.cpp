
/*
A number can be expressed as in the form of p1 * p2 * ............where p1 ,p2... etc. are prime factors of that number .

Think about a real number 90 . It can be expressed in the form of -> 3 x 2 x 5 x 3 .

Think this like a pile of stones.

This number can be made to below numbers by one valid move according to question ..................

          90 ->(3x2x5x3)
2 -> ( 2 ) ---- ( we remove 3 ,5,3 ) -> removed 3 stones
3 -> ( 3 )----( we remove 2,5,3) -> removed 3 stones
5 -> ( 5 )----(we remove 3,3,2) -> removed 3 stones
6 -> ( 3 x 2 )-----( we remove 5,2 )->removed 2 stones
9 -> ( 3 x 3 ) -----( we remove 5,2) -> removed 2 stones
10 ->( 5 x 2 )-----(we remove 3,3 )->removed 2 stones
15 -> ( 5 x 3 )----( we remove 3,2)->removed 2 stones
18 -> ( 3 x 3 x 2 )-----(we remove 5)->removed 1 stone
30 -> ( 3 x 5 x 2 )---(we remove 3)->removed 1 stone
45 -> ( 3 x 5 x 3 ) ---(we remove 2)->removed 1 stone
1 -> ( 1 ) ------------(we remove 3,2,5,3)->removed 4 stones
Now think carefully such a way that , if we reduce a number X to its divisor Y . Then It eliminates some of its prime-factors .It can be turned into our standard nim game where prime factors of the number are considered to be number of stones of that particular pile. So every time when we made it equal to its divisor which in turn eliminate one or more stones from that pile . Now ,one question .

Why were the number of divisors not be evaluated to stones number of this pile ? 
So , think about 6,9,10 ( All have two prime factors which means state of two stones ,these three states should be treated as same ) 
there are same number of possible ways to divide it till 1(you can check with your hand) .
So number of prime factor can be treated as number of stones of that pile .
When all prime numbers will be eliminated then the state of 1 is grandy(1)=0 which in turn makes sense to us that grandy (0)=0 i.e. 
there is no stones (loosing state) of pile of stone .

*/


#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxi=1e6+5;

int cnt[maxi],b[maxi];
int p,q,ans,n,t,tmp,xs,m;

void solve()
{
  scanf("%d",&n);

   xs=0;
  for (int i=0;i<n;i++)
   {
       scanf("%d",&p);
       xs=xs^cnt[p];
    }

    if (xs==0) printf("2\n"); else printf("1\n");
}

void sito()
{
    cnt[1]=0;

    for (int i=2;i<maxi;i++)
    {
        if (b[i]==0)
        {
          for (int j=i;j<maxi;j+=i)
          {
              m=j;
              b[j]=1;
              while (m%i==0)
              {
                cnt[j]++;
                m=m/i;
              }

          }
        }
    }
}

int main()
{
    scanf("%d",&t);

    sito();

    while (t--)
       solve();

  return 0;
}
