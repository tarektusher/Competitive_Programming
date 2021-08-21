# [Problem Link](https://www.spoj.com/problems/MKTHNUM/)
# Code 
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
#define fi 2*acos(0.0)
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
#define csprint1 printf("Case %lld: ", cs++);
#define csprint2 printf("Case %lld:\n", cs++);
#define sf(a) scanf("%lld", &a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
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
 
int fx[]={0,0,+1,-1};
int fy[]={+1,-1,0,0};
 
/// KNIGHT MOVE
 
int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};
 
///=====================================///
const int maX=1e5+10;
vector<ll>tr[4*maX];
pl ara[maX];
ll str[maX];
 
void build(ll u,ll b,ll e)
{
    if(b==e){
        tr[u].pb(ara[b].ss);
        return;
    }
    ll mid=(b+e)>>1;
    build(2*u,b,mid);
    build(2*u+1,mid+1,e);
    merge(all(tr[2*u]),all(tr[2*u+1]),back_inserter(tr[u]));
}
 
ll query(ll u,ll b,ll e,ll l,ll r,ll k)
{
    if(b==e){
        return tr[u].back();
    }
    ll mid=(b+e)>>1;
    ll x=upper_bound(all(tr[2*u]),r)-lower_bound(all(tr[2*u]),l);
    //error(x,k)
    if(x>=k)return query(2*u,b,mid,l,r,k);
    else return query(2*u+1,mid+1,e,l,r,k-x);
}
 
int main()
{
    ll n,q;sff(n,q);
    for(ll i=1;i<=n;i++){
        sf(ara[i].ff);
        ara[i].ss=i;
        str[i]=ara[i].ff;
    }
    sort(ara+1,ara+n+1);
    build(1,1,n);
    while(q--){
        ll l,r,k;
        sfff(l,r,k);
        ll x=query(1,1,n,l,r,k);
        //cout<<x<<endl;
        printf("%lld\n",str[x]);
    }
}
