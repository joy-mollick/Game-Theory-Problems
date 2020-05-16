
/// Time-0.001s
/// Same game of standard game because ,who can all time make Xsum zero is the winner can also take the last one 
/// So , when he will take last time stone for his turn
/// Then he will keep one  stone willingly so that later one can take that and loose
/// But , briefly different when all piles are composed of only stone 
/// Try this for own 

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int tc,k;
    int v;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        scanf("%d",&k);
        int Xsum=0;
        bool all_one=true;
        for(int i=0;i<k;i++) {scanf("%d",&v);if(v!=1) all_one=false;Xsum^=v;}
        printf("Case %d: ",caso);
        caso++;
        if(all_one)
        {
            if(k%2==0) {printf("Alice\n");}
            else {printf("Bob\n");}
        }
        else if(Xsum==0)/// The game can't be won by Alice ,first one
        {
            printf("Bob\n");
        }
        else
        {
            printf("Alice\n");
        }
    }
    return 0;
}
