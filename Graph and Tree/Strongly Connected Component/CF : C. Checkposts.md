## [Problem link](https://codeforces.com/contest/427/problem/C)
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
#define edl printf("\n")
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
#define endl "\n"

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

bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}

/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

///=====================================///
const long long maX=1e5+5;
vector<ll>vc[maX],vc_back[maX],dj;
ll mn;
bool vis[maX];
ll ara[maX];
map<ll,ll>check;
void dfs(ll u){
    vis[u]=1;
    for(auto v : vc[u]){
        if(!vis[v])dfs(v);
    }
    dj.pb(u);
}

void dfs1(ll u){
    if(ara[u]<=mn){
        mn=ara[u];
        check[mn]++;
    }
    vis[u]=1;
    for(auto it : vc_back[u]){
        if(!vis[it])dfs1(it);
    }
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>ara[i];
    ll m;cin>>m;
    while(m--){
        ll x,y;cin>>x>>y;
        vc[x].pb(y);
        vc_back[y].pb(x);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    // for(auto it : dj)cout<<it<<spc;
    // cout<<endl;
    memset(vis,0,sizeof(vis));
    reverse(all(dj));
    ll cc=0,way=1;
    for(ll i=0;i<dj.size();i++){
        if(vis[dj[i]]==0){
            mn=infinity;
            check.clear();
            dfs1(dj[i]);
            cc+=mn;
            way*=check[mn];
            way%=mod;
        }
    }
    cout<<cc<<spc<<way<<endl;
return 0;
}
