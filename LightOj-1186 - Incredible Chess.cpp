
/// Time-0.004s
/// turned into normal nim game

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int tc,k,posa,posb,n;
    int v;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        scanf("%d",&n);
        int column_white[n];
        int Xsum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&column_white[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v);
            Xsum^=(v-column_white[i]-1);
        }
        printf("Case %d: ",caso);
        caso++;
        if(Xsum) printf("white wins\n");
        else printf("black wins\n");
    }
    return 0;
}
