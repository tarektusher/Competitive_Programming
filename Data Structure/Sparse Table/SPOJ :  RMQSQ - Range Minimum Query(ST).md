# [Problem Link](https://www.spoj.com/problems/RMQSQ/)
# Code 
```cpp
/*                        ______
 _______   /\     |``\   |        |  /
    |     /  \    |__/   |____    |/
    |    / _ _\   |  \   |        |\
    |   /      \  |   \  |______  |  \
 
            Dept. of CSE
        Comilla  University
 
*/
#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Node struct node
#define spc " "
#define  E  2.71828182845904523536
#define pb push_back
#define pp pop_back
#define valid(nx,ny) nx>=0 && nx<n && ny>=0 && ny<m
#define e endl
#define pii pair<int,int>
#define infinity 10000000000000000
#define mod 1000000007
#define ee cout<<endl
int fx[]={0,0,+1,-1};
int fy[]={+1,-1,0,0};
 
using namespace std;
///check n=1;
///check corner case;
const int maX=1e5+5;
ll BiT[32][maX];
ll ara[maX];
 
void compute_ST(ll n)
{
    for(int i=0;i<n;i++)BiT[0][i]=i;
    for(ll k=1;(1<<k)<n;k++){
        for(ll i=0;i+(1<<k)<=n;i++){
            ll x=BiT[k-1][i];
            ll y=BiT[k-1][i+(1<<k-1)];
            BiT[k][i]=ara[x]<=ara[y] ? x : y;
        }
    }
}
 
 
ll query(ll i,ll j)
{
    ll k=log2(j-i);
    ll x=BiT[k][i];
    ll y=BiT[k][j-(1<<k)+1];
    return ara[x]<=ara[y] ? x: y;
}
 
int main()
{
    ll n,i,j,cc=0,q;
    cin>>n;
    for(i=0;i<n;i++)cin>>ara[i];
    cin>>q;
    compute_ST(n);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<ara[query(x,y)]<<endl;
    }
    ee;
return 0;
}
