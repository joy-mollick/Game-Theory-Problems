
/// Time-0.016s
/// turned into standard nim game
/// Skip the second gap from the last one ,because both makes a pair with sliding 
/// Second gap will be closed by left swip ,then question is a nim game considering the first gap skipping second one from the right 

#include<cstdio>
#include<algorithm>
using namespace std;

int main()

{
    int pos[1002];
    int tc,n;
    int v;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int Xsum=0;
        for(int i=0;i<n;i++)
        {
           scanf("%d",&pos[i]);
        }
        pos[n++]=0;
        sort(pos,pos+n);
        for(int i=n-2;i>=0;i-=2)
        {
            Xsum=Xsum^(pos[i+1]-pos[i]-1);
        }
        if(Xsum) printf("Georgia will win\n");
            else printf("Bob will win\n");
    }
    return 0;
}
