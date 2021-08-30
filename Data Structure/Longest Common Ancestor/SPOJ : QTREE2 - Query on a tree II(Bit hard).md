# [Problem Link](https://www.spoj.com/problems/QTREE2/)
# Idea : Find distance and kth node
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
const long long maX =1e6+10;
ll depth[maX],parent[maX],dist[maX],sp[maX][25];
vector<ll>graph[maX],cost[maX];
ll n;
void dfs(ll u,ll p,ll d){
     depth[u]=d+1;
     parent[u]=p;
     for(ll i=0;i<graph[u].size();i++){
          ll v=graph[u][i];
          if(p==v)cn;
          dist[v]=dist[u]+cost[u][i];
          dfs(v,u,d+1);
     }
}

void Build_Lca(){
     memset(sp,-1,sizeof(sp));
     for(ll i=1;i<=n;i++)sp[i][0]=parent[i];
     for(ll j=1;(1<<j)<n;j++){
          for(ll i=1;i<=n;i++){
               if(sp[i][j-1] != -1)
                    sp[i][j]=sp[sp[i][j-1]][j-1];
          }
     }
}

ll find_Lca(ll u,ll v){
     if(depth[u]<depth[v])swap(u,v);
     ll lg=log2(depth[u]);
     for(ll i=lg;i>=0;i--){
          if(depth[u]-(1<<i) >=depth[v])u=sp[u][i];
     }
     if(u==v)return v;
     for(ll i=lg;i>=0;i--){
          if(sp[u][i] != -1 && sp[u][i] != sp[v][i]){
               u=sp[u][i];
               v=sp[v][i];
          }
     }
     return parent[u];
}

ll find_kth_node(ll u,ll k){
     ll lg=log2(depth[u]);
     for(ll i=lg;i>=0;i--){
          if(depth[u]-(1<<i)>=k)u=sp[u][i];
     }
     return u;
}
int main(){FIO;
     ll test;cin>>test;
     while(test--){
          cin>>n;

          for(ll i=1;i<=n;i++){
               graph[i].clear();
               cost[i].clear();
               depth[i]=parent[i]=dist[i]=0;
          }

          for(ll i=1;i<n;i++){
               ll u,v,w;cin>>u>>v>>w;
               graph[u].pb(v),graph[v].pb(u);
               cost[u].pb(w),cost[v].pb(w);
          }

          dfs(1,-1,0);
          Build_Lca();
          string str;
          while(true){
               cin>>str;
               if(str=="DONE")break;
               ll u,v;cin>>u>>v;
               ll lca=find_Lca(u,v);
               if(str=="DIST"){
                    cout<<dist[u]+dist[v]-2*dist[lca]<<edl;
               }
               else{
                    ll k;cin>>k;
                    ll val;
                    if(depth[u]-depth[lca]+1>=k)val=find_kth_node(u,depth[u]-k+1);
                    else val=find_kth_node(v,2*depth[lca]+k-depth[u]-1);
                    cout<<val<<edl;
               }
          }
     }
return 0;
}
