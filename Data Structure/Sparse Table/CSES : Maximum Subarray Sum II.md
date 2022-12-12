# [Problem Link](https://cses.fi/problemset/task/1644)
# Code 
```cpp
/*
    Problem Link : 
    
*/

////=====BIsmillahir Rahmanir Rahim =====////
/*                        ______
 _______   /\     |``\   |        |  /
    |     /  \    |__/   |____    |/
    |    / _ _\   |  \   |        |\
    |   /      \  |   \  |______  |  \

            Dept. of CSE
         Comilla University

*/
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
#define fi 2*acos(0.0)
#define ee 2.71828
#define ll  long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Node struct node
#define spc " "
#define  E  2.71828182845904523536
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define valid(nx,ny) nx>=0 && nx<n && ny>=0 && ny<m
#define edl "\n"
#define infinity 1e16
#define mod 1000000007
#define cn continue
#define csprint1 printf("Case %lld: ", cs++)
#define csprint2 printf("Case %lld:\n", cs++)
#define sf(a) scanf("%lld", &a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define all(v) v.begin(),v.end()
#define pfn(a) printf("%lld\n",a)
#define pfs(a) printf("%lld ",a)

// using namespace __gnu_pbds;
using namespace std;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pl> vpi;
typedef vector<pl> vpl;
// typedef tree<pair<ll, int> , null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ost;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a <<","<< spc;
    err(++it, args...);
    cout<<edl;
}
///Bit manipulation

bool checkbit(ll mask,ll bit){return mask & (1ll<<bit);}
int setbit(ll mask,ll bit){ return mask | (1ll<<bit) ; }
int clearbit(ll mask,ll bit){return mask & ~(1ll<<bit);}
int togglebit(ll mask,ll bit){return mask ^ (1ll<<bit);}
int bitno(ll mask) {return (ll)__builtin_popcount(mask);}

/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

///=====================================///
const long long maX =2e5+10;
ll bit[maX][20];
ll ara[maX];
ll n,a,b;
void ST(){
     for(ll i=1;i<=n;i++){
          bit[i][0]=ara[i];
     }
     for(ll k=1;(1<<k)<=n;k++){
          for(ll i=1;i+(1<<k)-1<=n;i++){
               ll x=bit[i][k-1];
               ll y=bit[i+(1<<k-1)][k-1];
               bit[i][k]=max(x,y);
          }
     }
}

ll query(ll u,ll v){
     ll k=log2(v-u+1);
     ll val=bit[u][k];
     ll val2=bit[v-(1<<k)+1][k];
     return max(val,val2);
}
int main(){FIO;
     cin>>n>>a>>b;
     for(ll i=1;i<=n;i++)cin>>ara[i];
     for(ll i=1;i<=n;i++)ara[i]+=ara[i-1];
     ST();
     // for(ll i=0;i<=n;i++){
     //      for(ll j=0;j<=4;j++)cout<<bit[i][j]<<spc;
     //      cout<<edl;
     // }
     ll mx=-infinity;
     ll x=0;
     for(ll i=1;i<=n-a+1;i++){
          ll val=query(i+a-1,min(i+b-1,n));
          //cout<<i+a-1<<spc<<i+b-1<<spc<<val<<endl;
          val-=ara[i-1];
          mx=max(mx,val);
     }
     cout<<mx<<endl;
return 0;
}
