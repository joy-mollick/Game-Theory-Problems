

/// Nice problem based on grandy value 

#include <bits/stdc++.h>

using namespace std;

const int mx=100001;

int grandy[mx];

vector<int>divisors[mx];

/// sieve of finding divisors of every number till mx
void sieve()
{
    for(int i=2;i<mx;i++)
    {
        for(int j=i;j<mx;j=j+i)
        {
            divisors[j].push_back(i);/// all numbers (j) has a divisor i obviously
        }
    }
}

int sg(int X)
{
    if(X==1)/// when the X is 1 there is no move ,grandy value is zero 
    {
        return 0;
    }
    if(grandy[X]!=-1)/// if grandy value is already computed just return it , no need to calculate it
    {
        return grandy[X];
    }
    set<int>s;
    for(int i=0;i<divisors[X].size();i++)
    {
        int Y=divisors[X][i];/// the tower will be broken down into Y towers ,Y>1
        /// 1 is not included into any number's list of divisors during sieve ,so this Y will not be 1 never
        int Z=X/Y;/// Each of Y towers has height of Z , may be also height of 1 which will terminate our program by finding our grandy value of every X,as X=1 is base condition .
        if(Y%2==0) /// The number of towers are even then ,obviously its all tower's size will be canceled out as being of equal for Xor technique,grandy value will be 0 .
            s.insert(0);
        else  /// The number of towers are odd,obviously take only grandy value of one tower's size (Z).rest of the towers are canceled out by each other for xor technique.
            s.insert(sg(Z));
    }
    int mex=0;
    while(s.find(mex)!=s.end()) mex++;///checking which smallest number not included in the set.
    grandy[X]=mex;///assigning mex[not included minimum element in the set of grandy value of possible towers]
    return grandy[X];/// return grandy
}


int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sieve();
        int n;
        memset(grandy,-1,sizeof(grandy));/// initialize with -1
        int tc;
        cin>>tc;
        while(tc--)
        {
        cin>>n;
        int ans=0,h;
        for(int i = 1; i <= n; ++ i)
        {
            cin>>h;
            ans^=sg(h);
        }
        if(ans) cout<<"1"<<endl;/// First player won
            else cout<<"2"<<endl;/// Second player won
        }
        return 0;
}
