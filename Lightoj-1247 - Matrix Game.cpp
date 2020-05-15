
/// Time-0.018s
/// It's actually a nim game because every row numbers can be coins of ith pile 
/// Then check only Xsum ,nothing else 

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int tc,n,m;
    long long v;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        long long xsum=0;
        for(int i=0;i<n;i++)
        {
            long long piles_i=0;
            for(int j=0;j<m;j++)
            {
                scanf("%lld",&v);
                piles_i+=v;
            }
            xsum=xsum^piles_i;
        }
        printf("Case %d: ",caso);
        caso++;
        if(xsum==0) printf("Bob\n");
            else printf("Alice\n");
    }
    return 0;
}
