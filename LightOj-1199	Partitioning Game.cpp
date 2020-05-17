
/// Time- 1.376s

/// If you know about finding the Grandy - Value,then it is not hard one 
/// Here mex is the minimum number which is not situated in a set 

#include <bits/stdc++.h>

using namespace std;

int grandy_value[10001]; /// it will be used for memoization

int sg(int n)
{
    if(n<=2) return 0;
    if(grandy_value[n]!=-1) return grandy_value[n];
    set<int>s;
    for(int part1=1,part2=n-1;part1<part2;part1++,part2--)
    {
        s.insert(sg(part1)^sg(part2));/// here piles are divided into different parts so take xor of grandy values of them,and make mex of them 
    }
    int mex=0;
    while(s.find(mex)!=s.end()) mex++;
    grandy_value[n]=mex;/// mex is the grandy value of n
    return grandy_value[n];
}


int main()
{
    memset(grandy_value,-1,sizeof(grandy_value));/// initialize with -1
	int t, n;
	cin >> t;
	int k = 1;
	while(t --)
	{
		cin>>n;
		int ans=0,x;
		for(int i = 1; i <= n; ++ i)
		{
			cin>>x;
			if(grandy_value[x]==-1)/// if it is not computed till now
			ans^=sg(x);
			else /// it is computed ,so take value from pre-computed array
            ans=(ans^grandy_value[x]);
		}
		printf("Case %d: ", k ++);
		if(ans)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
	return 0;
}
