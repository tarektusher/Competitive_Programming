# [Problem Link](https://www.spoj.com/problems/ADACLEAN/)
# code 
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
const long long maX =1e5+10;
const  ll M=1e8+7;
ll po1[maX],Hash1[maX],revpo1[maX],po2[maX],Hash2[maX],revpo2[maX];
ll p=131;
ll pp=31;
ll exp(ll a,ll b,ll rem){
     ll x=1;
     while(b){
          if(b&1)x=(x*a)%rem;
          a=(a*a)%rem;
          b/=2;
     }
     return x;
}
int main(){FIO;
     ll test;cin>>test;
     po1[0]=po2[0]=1ll;
     revpo1[0]=exp(1,M-2,M);
     revpo2[0]=exp(1,mod-2,mod);
     for(ll i=1;i<maX;i++){
          po1[i]=(po1[i-1]*p)%M;
          revpo1[i]=exp(po1[i],M-2,M);
          po2[i]=(po2[i-1]*pp)%mod;
          revpo2[i]=exp(po2[i],mod-2,mod);
     }
     while(test--){
          ll n,k;cin>>n>>k;
          string str;cin>>str;
          map<pair<ll,ll>,ll>check;
          for(ll i=1;i<=n;i++){
               Hash1[i]=(Hash1[i-1]+(str[i-1]-'a'+1)*po1[i-1])%M;
               Hash2[i]=(Hash2[i-1]+(str[i-1]-'a'+1)*po2[i-1])%mod;
          }    
          for(ll i=1;i+k-1<=n;i++){
               ll x=(Hash1[i+k-1]-Hash1[i-1]+M)%M;
               ll y=(Hash2[i+k-1]-Hash2[i-1]+mod)%mod;
               y=(y*revpo2[i-1])%mod;
               x=(x*revpo1[i-1])%M;
               check[{x,y}]++;
          }
          cout<<check.size()<<edl;
     }
return 0;
} 
