# [Problem Link](https://vjudge.net/contest/463790#problem/A)
## Code
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
const long long maX =1e3+10;

char str[maX][maX],pattern[maX][maX];
ll base1=233,base2=2333;
ll hash1[maX][maX],hash2[maX][maX];
int main(){FIO;
     ll test;cin>>test;
     while(test--){
          ll n,m;cin>>n>>m;
          for(ll i=1;i<=n;i++){
               for(ll j=1;j<=m;j++)cin>>str[i][j];
          }
          ll x,y;cin>>x>>y;
          for(ll i=1;i<=x;i++){
               for(ll j=1;j<=y;j++){
                    cin>>pattern[i][j];
               }
          }
          ll p1=1,p2=1;
          for(ll i=1;i<=x;i++)p2*=base2;
          for(ll i=1;i<=y;i++)p1*=base1;

          for(ll i=1;i<=x;i++){
               for(ll j=1;j<=y;j++){
                    hash2[i][j]=(pattern[i][j]-'a')+hash2[i][j-1]*base1+hash2[i-1][j]*base2-hash2[i-1][j-1]*base2*base1;
               }
          }
         // cout<<hash2[x][y]<<edl;
          ll cc=0;
          for(ll i=1;i<=n;i++){
               for(ll j=1;j<=m;j++){
                    hash1[i][j]=(str[i][j]-'a')+hash1[i-1][j]*base2+hash1[i][j-1]*base1-hash1[i-1][j-1]*base1*base2;
                    if(i>=x && j>=y && hash2[x][y]==hash1[i][j]-hash1[i-x][j]*p2-hash1[i][j-y]*p1+hash1[i-x][j-y]*p1*p2){
                         cc++;
                    }
               }
          }
          cout<<cc<<edl;
     }
return 0;
}
