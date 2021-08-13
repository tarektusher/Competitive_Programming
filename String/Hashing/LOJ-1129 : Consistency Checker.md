# [Problem Link](https://lightoj.com/problem/consistency-checker)

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
const long long maX =10+10;
ll p1=31,p2=97;
ll mod1=1e9+9;
vector<ll>po(maX),po1(maX);
int main(){FIO;
    po[0]=1;po1[0]=1;
    for(ll i=1;i<maX;i++){
        po[i]=(po[i-1]*p1)%mod;
        po1[i]=(po1[i-1]*p2)%mod1;
    }
    ll test;
    ll cs=1;
    cin>>test;
    while(test--){
        unordered_map<ll,ll>check1,check2;
        ll n;cin>>n;
        bool ok=true;
        vector<string>strr(n);
        for(ll i=0;i<n;i++){
            cin>>strr[i];
        }
        sort(all(strr));
        for(ll i=0;i<n;i++){
            string str=strr[i];
            ll hash1=0,hash2=0;
            for(ll i=0;i<str.size();i++){
                hash1=(hash1+str[i]*po[i])%mod;
                hash2=(hash2+str[i]*po1[i])%mod1;
                if(check1[hash1] && check2[hash2]){
                    ok=false;
                    //cout<<hash1<<spc<<hash2<<spc<<check1[hash1]<<spc<<check2[hash2]<<edl;
                }
            }
            check1[hash1]++;check2[hash2]++;
        }
        cout<<"Case "<<cs++<<": ";
        if(!ok)cout<<"NO"<<edl;
        else cout<<"YES"<<edl;
    }
    return 0;
} 