
/// Time-0.04s
/// turned into normal nim game
/*
First think about two numbers and only one numbers 
Here , Grandy(1,a) = 0 .Because when a row has two numbers ( 1 and a ) then after one valid move there will be 
possible state will be a .so mex(a)=0 . Grandy(1,a)=0 .
Now any state like two numbers Grandy(0,a)=Grandy(a)=a . Because if there is only one number in row so grandy number 
of its is the number itself . Then after some calculation , we will get grandy(a,b) = a-1 ,when a<=b and
grandy(a,b) = a when a>b . (Do work by your hand ) .Now when we add another number from left then , 
grandy (c , a, b) = grandy(c,grandy(a,b)) ,when c is new value added .for four numbers d , c ,a , b.
Equivalent Nim of four numbers = grandy(d,c,a,b)=grandy(d,grandy(c,grandy(a,b))).Find the xor of all 
equivalent-nim of evry rows . That is our nim-sum.
*/

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,val,m;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        int nim_sum=0;
        int grid[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
       for(int i=0;i<n;i++)
       {
           int nim_equivalent=grid[i][m-1];

           for(int j=m-2;j>=0;j--)
           {
               if(nim_equivalent<grid[i][j])
               {
                   nim_equivalent=grid[i][j];
               }
               else
               {
                   nim_equivalent=grid[i][j]-1;
               }
           }
           nim_sum^=nim_equivalent;
       }
       if(nim_sum) cout<<"FIRST"<<endl;
       else cout<<"SECOND"<<endl;
    }

    return 0;
}
