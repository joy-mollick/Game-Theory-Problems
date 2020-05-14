
/// Only one pile and k coins can be removed  ,damn easy one 
/// Time- 1.52604s

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, k;
        scanf("%lld %lld", &n, &k);
        if(n&1)
            printf("A wins\n");
        else
            printf("B wins\n");
    }
}
