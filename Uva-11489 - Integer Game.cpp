
/// Time-0.000s
/// Simulation problem on Game Theory 
/// Comments lines are enough to make you understand 

#include<bits/stdc++.h>

using namespace std;


 char s[1001];
 int num_of_digits_multiple_of_three;
/// S first move and T second move

bool is_it_possible_to_move(int sum)
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if( (sum-(s[i]-'0'))%3==0) /// possible to make a move
        {
            return true;
        }
    }
    return false;
}

int get_sum_of_digits()
{
    int ln=strlen(s);
    int sum=0;
    for(int i=0;i<ln;i++)
    {
            sum+=(s[i]-'0');
    if((s[i]-'0')%3==0)
    {
        num_of_digits_multiple_of_three++;
    }

    }
    return sum;
}

int main()

{
    int tc;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        num_of_digits_multiple_of_three=0;/// initialize with zero
        scanf("%s",s);
        printf("Case %d: ",caso);
        caso++;
        int ln=strlen(s);
        int sum=get_sum_of_digits();
        if(ln==1) {printf("S\n");} /// There will be only one move , game will be closed
///if sum is already divisible by 3 then, find it's digits which are multiple of three ,because only these multiples(of three) can make next string be divisible being eliminated otherwise not .
        else if(sum%3==0)
        {
            if(num_of_digits_multiple_of_three%2==0) /// then it is obvious that after S's turn all digits will be finished ,S will loose or there is no multiples of three then S first player will not move i.e. T wins
            {
                printf("T\n");
            }
            else
            {
                printf("S\n");
            }
        }

        else
        {
            if(is_it_possible_to_move(sum))/// Now again it is like the first problem , sum%3==0 ,then check num_of_multiples_of_three ,nothing else

            {
/// Then the non_multiple digit which will make next sum (be multiple of zero) will be taken by S ,now all multiples of three will be counted one by one
                if(num_of_digits_multiple_of_three%2==1)
            {
                printf("T\n");
            }

            else
            {
                printf("S\n");
            }

            }
            else
            {
                printf("T\n");/// There is no move so S will not be able to move i.e. T will win.
            }
        }

    }
    return 0;
}
