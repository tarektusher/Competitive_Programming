
# [Problem link](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737)

```cpp
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
const long long maX =1e6+10;
vector<ll>graph[maX];
ll vis[maX];
ll lo[maX],depth[maX];
ll cc;
vector<pair<ll,ll>>ans;
void dfs(ll u,ll p,ll d){
     vis[u]=1;
     lo[u]=depth[u]=d;
     for(int v : graph[u]){
          if(v==p)cn;
          if(vis[v]==0){
               dfs(v,u,d+1);
               lo[u]=min(lo[u],lo[v]);
               if(lo[v]>depth[u]){
                    cc++;
                    ll x=u,y=v;
                    if(x>y)swap(x,y);
                    ans.pb({x,y});
               }
          }
          else{
               
               lo[u]=min(lo[u],depth[v]);
               
          }
     }
     
}
int main(){FIO;
     ll n;
     while((scanf("%lld",&n)) == 1){
          cc=0;
          ans.clear();
          for(ll i=0;i<maX;i++){
               vis[i]=0;
               graph[i].clear();
               lo[i]=depth[i]=0;
          }
          for(ll i=1;i<=n;i++){
               vis[i-1]=0;
               ll x,y;
               scanf("%lld (%lld)",&x,&y);
               while(y--){
                    ll val;scanf("%lld",&val);
                    graph[x].pb(val);
                   // graph[val].pb(x);
               }
          }
          for(ll i=0;i<n;i++){
               if(vis[i]==0){
                    dfs(i,0,0);
               }
          }
          printf("%lld critical links\n",ans.size());
          sort(all(ans));
          for(auto it : ans){
               printf("%lld - %lld\n",it.ff,it.ss);
          }
          printf("\n");
     }
return 0;
}
