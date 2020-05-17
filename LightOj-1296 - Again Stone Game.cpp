
/// Time- 0.019s
/// If you know about finding the Grandy - Value 
/// Then try to find some grandy value of small value 
/// Then Use that pattern to find grandy value of every value and make xor of those values


#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
int sg[maxn];
bool vis[maxn];


/// Applying Sprague-Grundy theorem ,to get a pattern by finding grandy value for small value 
/// It has no use in this problem but only pseudo-code has been given 

void getsg()
{
	sg[0] = 0;/// base case
	for(int i = 1; i <= 100; ++ i)
	{
		memset(vis, false, sizeof(vis));
		for(int j = 1; j <= i / 2; ++ j)
		{
			vis[sg[i - j]] = true;///make all states (which are possible to be reached) = true from i
		}
		int cnt = 0;
		while(vis[cnt] != 0)
			cnt++;
		sg[i] = cnt;
	}
}

/// Getting this grandy_value pattern from grandy value based on observation of small value computed by sg array
int grandy_value(int n)
{
   while (n&1) n >>= 1;/// when n is odd ,make it round until it's even
    return n>>1;///when n is even , return its half
}

int main()
{
	int t, n;
	///getsg();
	cin >> t;
	int k = 1;
	while(t --)
	{
		scanf("%d", &n);
		int ans=0;
		for(int i = 1; i <= n; ++ i)
		{
			int x;
			scanf("%d", &x);
			ans^=grandy_value(x);
		}
		printf("Case %d: ", k ++);
		if(ans)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
	return 0;
}
