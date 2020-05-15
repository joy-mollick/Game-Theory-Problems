
/// Time-0.008s

#include<bits/stdc++.h>

using namespace std;

/// here we can take only one(1) or two(2) marbles ,so think about its molecule i.e. means first think about only for 3 marbles
/// So , one package with three marbles is a single state to be considered.

/// Think about when game is started by Bob ,who takes last is winner .
/// When every player wants to get safe position ,then Bob will try to be in safe position means to make marbles zero
/// Then when marbles are 4 then n%3=1 then Bob will take 1 in his first move and Alice will take 2 or 1 marbles (Total taken =2/3 )
/// Remaining are 2 or 1 marbles which will be taken by Bob and Bob will win . Same modified case for when n=5 ,n%3=2
/// -> Now think inversely when Alice starts the game
/// If n=4 or n=5 i.e. n%3=1 or n%3=2 which means Alice can handle the game to be non -taker of last move means winner


int main()

{
    int t;
	int n;

	scanf("%d", &t);
    char s[10];
	for (int j = 1; j <= t; j++) {
		scanf("%d", &n);
		scanf("%s",s);

		n = n % 3;
		if(s[0]=='A') {
			if(n == 0 or n == 2) {
				printf("Case %d: Alice\n", j);
			}

			else {
				printf("Case %d: Bob\n", j);
			}

		}

		else
		{
			if(n == 1 or n == 2) {
				printf("Case %d: Bob\n", j);
			}

			else {
				printf("Case %d: Alice\n", j);

			}

		}


	}


    return 0;
}
