# [Problem Link](https://cses.fi/problemset/task/1110/)
# [Idea](https://codeforces.com/blog/entry/79979)
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
const long long maX =2e6+10;
ll p=131;
ll Hash[maX],revpo[maX];

ll exp(ll a,ll b){
     ll r=1;
     while(b){
          if(b&1)
          r=(r*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
  return r;
}
ll get(ll l,ll r){
     return ((Hash[r]-Hash[l-1]+mod)*revpo[l-1])%mod;
}
int main(){FIO;
     string str;cin>>str;
     str+=str;
     ll n=str.size();
     ll x=1;
     for(ll i=0;i<n;i++){
          revpo[i]=exp(x,mod-2);
          x*=p;
          x%=mod;
     }
     x=1;
     for(ll i=0;i<n;i++){
          Hash[i+1]=(Hash[i]+((str[i]-'a'+1)*x))%mod;
          x*=p;
          x%=mod;
     }
     n/=2;
     ll k=1;
     for(ll i=2;i<=n;i++){
          ll lo=0,hi=n-1;
          while(lo<=hi){
               ll mid=(lo+hi)/2;
               if(get(i,i+mid)==get(k,k+mid))lo=mid+1;
               else hi=mid-1;
          }
          if(lo<=n-1){
               if(str[i+lo-1]<str[k+lo-1])k=i;
          }
     }
     cout<<str.substr(k-1,n)<<edl;
return 0;
}
