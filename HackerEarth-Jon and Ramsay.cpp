
/// Time-0.61306s
/// turned into normal nim game
/// Very Basic understanding of Game of Nim  
/// When you try to make Xsum zero ,then all time try to reduce some numbers from those numbers with on-bit on position
/// where position is a right most position of binary number where the number of ones is odd 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx=100001;

ll H[mx];
ll xor_sum;
ll n;

ll getans()
{
    ll cont=0ll;
    ll pos;
    for(ll i=64;i>=0ll;i--)
    {
        if((1ll<<i)&(xor_sum))/// left most column with odd numbers of one
        {
            pos=i;
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        if((1ll<<pos)&(H[i])) cont++; /// now find how many numbers with on-bit on that pos 
    }

    return cont;
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        xor_sum=0;
        for(int i=0;i<n;i++) {cin>>H[i];xor_sum^=H[i];}
        ll ans=getans();
        cout<<ans<<'\n';
    }
    return 0;
}
