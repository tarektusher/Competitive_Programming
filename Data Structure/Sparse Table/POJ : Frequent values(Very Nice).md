# [Problem Link](https://codeforces.com/contest/475/problem/D)
# [Idea](https://www.programmerall.com/article/32981878078/)
# Code
```cpp
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
# define ll long long
const long long maX =1e6+10;
ll ara[maX],sp[maX][25];
ll n;

void build(){
     for(ll i=1;i<=n;i++){
          if(ara[i]==ara[i-1])sp[i][0]=sp[i-1][0]+1;
          else sp[i][0]=1;
     }
     ll k=log(1.0*n)/log(2.0);
     for(ll j=1;j<=k;j++){
          for(ll i=1;i+(1<<j)-1<=n;i++){
               sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
          }
     }
}
ll query(ll l,ll r){
     if(l>r)return 0;
     ll j=log(1.0*(r-l+1))/log(2.0);
     return max(sp[l][j],sp[r-(1<<j)+1][j]);
}
int main(){
     while(scanf("%lld",&n) && n != 0){
          ll q;scanf("%lld",&q);
          for(ll i=1;i<=n;i++)scanf("%lld",&ara[i]);
          build();
          while(q--){
               ll l,r;scanf("%lld %lld",&l,&r);
               ll test=l;
               while(test<=r && ara[test] == ara[test-1])test++;
               ll ans=query(test,r);
               ans=max(test-l,ans);
               printf("%lld\n",ans);
          }
     }
     
return 0;
}

