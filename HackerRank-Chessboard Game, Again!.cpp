

///Here ,one base case is when knight reach (1,1) co-ordinate ,there is no move so grandy value of this co-ordinate is 0
/// Here additional constraint is chessboard is 15x15 so , care of this constraint 
///And to find the grandy value of other co-ordinates,you have to find recursively other co-ordinates

#include <bits/stdc++.h>

using namespace std;

/// possible moves from any cell of chessboard
/*
 ( -2,1  )
 ( -2,-1 )
 ( -1,-2 )
 ( 1,-2  )
*/

int dx[4]={-2, -2, -1, 1};
int dy[4]={ 1, -1, -2,-2};

int grandy_value[20][20]; /// it will be used for memoization for grandy_value of co-ordinates

int sg(int x,int y)
{
    if((x==1&&y==1))
    {
        return 0;
/// (0,0) it is base case ,because from here there is no move,so grandy value of this state is zero
    }
    if(grandy_value[x][y]!=-1) /// if grandy value is already computed just return it , no need to calculate it
    {
        return grandy_value[x][y];
    }
    set<int>s;
    for(int i=0;i<4;i++)
    {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=1&&newy>=1&&newx<=15&&newy<=15)///if newx and newy is beyond (0,0) then this recursion will be recursively run ,there is no end .So (0,0) should be the terminal point
        {
            s.insert(sg(newx,newy));
        }
    }
    int mex=0;
    while(s.find(mex)!=s.end()) mex++;
    grandy_value[x][y]=mex;///assigning mex [not included minimum element in the set of grandy value of possible co-ordinates]
    return grandy_value[x][y];/// return grandy_value
}


int main()
{
        int n;
        memset(grandy_value,-1,sizeof(grandy_value));/// initialize with -1
        int tc;
        cin>>tc;
        while(tc--)
        {
		cin>>n;
		int ans=0,x,y;
		for(int i = 1; i <= n; ++ i)
		{
			cin>>x>>y;
			ans^=sg(x,y);
		}
		if(ans) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
	    return 0;
}
