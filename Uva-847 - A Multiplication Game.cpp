
/// Time-0.000s
/// Basic one

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

/// Stan First -then Ollie Second

string winner()
{
    if(n==1ll) return "Stan"; /// when n is 1 mul is also 1 then loop will not be iterated ,so take care of this separately .
    ll cnt=0ll;
    ll mul=1ll;
    while(mul<n)
    {
        cnt++;
        /// It is very obvious that when by multiply 9 I can get more than n ,then I will multiply 9 otherwise he will select alltime 2
        if(cnt&1) /// stan turns,he will play optimally ,he is the first one
        {
            ll expected_score=mul*9ll;/// what can we get if multiply mul by 9
            if(expected_score<n) mul=mul*2ll; /// our range is 2<->9
            else mul=mul*9ll;
        }
        else ///Ollie has nothing to do , he can't resist Stan by putting 2 multiplication from winning state,so he will all time choose max multiplier 9
        {
            mul=mul*9ll;
        }
    }
    if(cnt%2==0) /// last move was done by Ollie
        return "Ollie";
    else if(cnt%2==1)
        return "Stan";
}

int main()

{

    while(cin>>n)
    {
       cout<<winner()<<" wins."<<endl;
    }

    return 0;
}
