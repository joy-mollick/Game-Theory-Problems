
/// Time-0.004s
/// turned into normal nim game

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,val;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        int x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x==0) continue;
            if(x%2==1) ans=ans^i;/// i means how many options for ith position to move left side
        }
        if(ans) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
}
