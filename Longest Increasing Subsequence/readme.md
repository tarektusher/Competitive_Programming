# [Theroy Link](https://cp-algorithms.com/sequences/longest_increasing_subsequence.html)

### Type of Problems :<br>
1.Increasing Subsequence<br>
2.Restoring Increasing Subsequence<br>
3.Number of Longest Increasing Subsequence<br>


## Dynamic Programming Implementation O(N^2)<br>
### Length of Longest Increasing Subsequence<br>
```cpp
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }

    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}
```
### Restoring the Subsequence
```cpp
vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}
```

# Implementation Using DP+Binary Search O(Nlog(N))<br>
## Length of longest Increasing Subsequence
###  Approach 01 
```cpp
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
```
### Approach 02(Only for strictly increasing subsequence)
```cpp
int main(){FIO;
     ll n;cin>>n;
     vector<ll>vc;
     for(ll i=0;i<n;i++){
          ll x;cin>>x;
          auto it=lower_bound(all(vc),x);
          if(it==vc.end())vc.pb(x);
          else vc[it-vc.begin()]=x;
     }
     cout<<vc.size()<<edl;
return 0;
}
