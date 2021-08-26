# [Problem Link](https://lightoj.com/problem/min-max-roads)
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
#define infinity 1e9
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
vector<int>graph[maX],cost[maX];
int depth[maX],parent[maX],sp[maX][20],sp_max[maX][20],sp_min[maX][20],dis[maX];
int n;
void dfs(int u,int p,int d){
     depth[u]=d;
     parent[u]=p;
     for(int i=0;i<graph[u].size();i++){
          int v=graph[u][i];
          if(v==p)continue;
          dis[v]=cost[u][i];
          dfs(v,u,d+1);
     }
}

void build_LCA(){
     memset(sp,-1,sizeof(sp));
     for(int i=1;i<=n;i++){
          sp[i][0]=parent[i];
          sp_max[i][0]=dis[i];
          sp_min[i][0]=dis[i];
     }
     sp_max[1][0]=0,sp_min[1][0]=infinity;
     for(int j=1;(1<<j)<n;j++){
          for(int i=1;i<=n;i++){
               if(sp[i][j-1]==-1)continue;
               sp[i][j]=sp[sp[i][j-1]][j-1];
               sp_max[i][j]=max(sp_max[i][j-1],sp_max[sp[i][j-1]][j-1]);
               sp_min[i][j]=min(sp_min[i][j-1],sp_min[sp[i][j-1]][j-1]);
          }
     }
}

pair<int,int> LCA_query(int u,int v){
     if(depth[u]<depth[v])swap(u,v);
     int lg=log2(depth[u]);
     
     int mx=0,mn=infinity;
     for(int i=lg;i>=0;i--){
          if(depth[u]-(1<<i)>=depth[v]){
               mx=max(mx,sp_max[u][i]);
               mn=min(mn,sp_min[u][i]);
               u=sp[u][i];
          }
     }
     if(u==v)return make_pair(mx,mn);
     for(int i=lg;i>=0;i--){
          if(sp[u][i] != -1 && sp[u][i] != sp[v][i]){
               mx=max({mx,sp_max[u][i],sp_max[v][i]});
               mn=min({mn,sp_min[u][i],sp_min[v][i]});
               u=sp[u][i],v=sp[v][i];
          }
     }
     mx=max({mx,dis[u],dis[v]});
     mn=min({mn,dis[u],dis[v]});
     return make_pair(mx,mn);
}
int main(){
     int test;cin>>test;
     int cs=1;
     while(test--){
          cin>>n;
          for(int i=1;i<n;i++){
               int u,v,w;cin>>u>>v>>w;
               graph[u].pb(v),graph[v].pb(u);
               cost[u].pb(w),cost[v].pb(w);
          }
          dis[1]=0;
          dfs(1,-1,1);
          build_LCA();
          int q;cin>>q;
          cout<<"Case "<<cs++<<":"<<endl;
          while(q--){
               int u,v;cin>>u>>v;
               auto it=LCA_query(u,v);
               cout<<it.ss<<spc<<it.ff<<endl;
          }
          for(int i=1;i<=n;i++){
               graph[i].clear();
               cost[i].clear();
          }
          
     }
return 0;
}
