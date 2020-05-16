
/// Time-0.004s
/// Nimble game ,turned into nim game
/// How many positions one position (grey or white) can travel can be the turned into number of coins on pile 

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int tc,k,posa,posb;
    int v;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        scanf("%d",&k);
        int Xsum=0;
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&posa,&posb);
            int v=posb-posa-1;
            Xsum^=v;
        }
        printf("Case %d: ",caso);
        caso++;
        if(Xsum) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
