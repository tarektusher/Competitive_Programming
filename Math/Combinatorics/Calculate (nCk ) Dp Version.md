 # Link : 
 - [Theory](https://www.geeksforgeeks.org/binomial-coefficient-dp-9/)
 
 # Code : 
 
```cpp
ll dp[N+1][N+1];
memset(dp,0,sizeof(dp));
for(ll i=0;i<=N;i++){
    for(ll j=0;j<=i;j++){
        if(j==0 || j==i)dp[i][j]=1;
        else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
}
