# [Problem Link](https://cses.fi/problemset/task/2205)
# [Theory Link1](https://www.geeksforgeeks.org/generate-n-bit-gray-codes/)
# Code :
```cpp
int main(){FIO;
     ll n;cin>>n;
     vector<string>ara;
     ara.pb("0");
     ara.pb("1");
     for(ll i=2;i<(1<<n);i=(i<<1)){
          for(ll j=i-1;j>=0;j--)ara.pb(ara[j]);
          for(ll j=0;j<i;j++)ara[j]="0"+ara[j];
          for(ll j=i;j<2*i;j++)ara[j]="1"+ara[j];
          
     }
     for(ll i=0;i<ara.size();i++)cout<<ara[i]<<edl;
return 0;
}
```
# [Theory Link2](https://cp-algorithms.com/algebra/gray-code.html)
```cpp
int main(){FIO;
     ll n;cin>>n;
     vector<ll>ans;
     for(ll i=0;i<(1<<n);i++){
          ans.pb(i^(i>>1));
     }
     for(auto it : ans)cout<<it<<spc;
return 0;
}
