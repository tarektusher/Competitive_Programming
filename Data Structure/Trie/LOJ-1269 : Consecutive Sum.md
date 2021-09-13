# [Problem Link](https://lightoj.com/problem/consecutive-sum)
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
const long long maX =3e6+10;
const long long pr=331;
ll power[40];
ll mx;
ll to[2*maX][2];
ll tot_node=1;
void build(ll val){
    ll cur=1;
    for(ll i=31;i>=0;i--){
        ll x=checkbit(val,i);
        if(to[cur][x]==0)to[cur][x]=++tot_node;
        cur=to[cur][x];
    }
}
ll mxvalue(ll num){
    ll cur=1;
    ll val=0;
    for(ll i=31;i>=0;i--){
        ll x=checkbit(num,i);
        if(to[cur][1^x]){
            val+=power[i];
            cur=to[cur][1^x];
        }
        else {
            cur=to[cur][x];
        }
    }
    return val;
}
ll mnvalue(ll num){
    ll cur=1;
    ll val=0;
    for(ll i=31;i>=0;i--){
        ll x=checkbit(num,i);
        if(to[cur][x])cur=to[cur][x];
        else {
            val+=power[i];
            cur=to[cur][1^x];
        }
    }
   // cout<<val<<spc<<num<<edl;
    return val;
}
void clean(){
    memset(to,0,sizeof(to));
}
int main(){FIO;
    ll test;cin>>test;
    ll cs=1;
    power[0]=1;
    for(ll i=1;i<=33;i++)power[i]=2*power[i-1];
    while(test--){
        ll n;cin>>n;
        clean();
        build(0);
        ll Xor=0;
        ll mx=-infinity;
        ll mn=infinity;
        for(ll i=0;i<n;i++){
            ll x;cin>>x;
            Xor^=x;
            mx=max(mx,mxvalue(Xor));
            mn=min(mn,mnvalue(Xor));
            build(Xor);
        }
        cout<<"Case "<<cs++<<": ";
        cout<<mx<<spc<<mn<<edl;
    }
return 0;
}
