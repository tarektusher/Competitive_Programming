
 # Link : 
 
- [Theory link](https://brilliant.org/wiki/derangements/?quiz=derangement#) 
- [Coding link](https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/)


# Code :

```cpp
ll dp[N];
dp[1]=0;
dp[2]=[1];
for(ll i=3;i<N;i++){
    dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
}

return dp[n];
