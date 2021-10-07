# [Problem Link](https://leetcode.com/problems/partition-equal-subset-sum/)
## Code 
```cpp
#define ll long long
class Solution{
    public:
    bool canPartition(vector<int>ara){
        ll n=ara.size();
        ll sum=0;
        for(ll i=0;i<n;i++)sum+=ara[i];
        if(sum&1)return false;
        ll dp[500][10000];
    memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(ll  j=1;j<=n;j++){
        for(ll i=0;i<=sum/2;i++){
           if(i>=ara[j-1])dp[j][i]|=dp[j-1][i-ara[j-1]];
           dp[j][i]|=dp[j-1][i];
        }
    }
    sum=sum/2;
    for(ll i=1;i<=n;i++){
        if(dp[i][sum]){
            return true;
        }
    }
   return false;
    }
};
