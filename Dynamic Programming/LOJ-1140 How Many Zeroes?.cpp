Problem link : https://lightoj.com/problem/how-many-zeroes

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
const long long maX =1e6+10;
vector<ll>vc;
ll N,dp[12][2][2][12];
ll DP(ll indx,ll small,ll started ,ll zeroes){
    if(indx==N)return zeroes;
    if(dp[indx][small][started][zeroes] != -1)return dp[indx][small][started][zeroes];
    ll till ,ans=0;
    if(small)till=9;
    else till=vc[indx];
    if(started){
        if(small || 0<vc[indx]){
            ans+=DP(indx+1,1,started,zeroes+1);/// jodi indx er value 0 theke choto ba amder create number ta given value theke choto hoy thkn amra eta bosabo 
        }
        else {
            ans+=DP(indx+1,0,started,zeroes+1);
        }
        for(ll i=1;i<=till;i++){
            if(small || i<vc[indx]){
                ans+=DP(indx+1,1,1,zeroes);
            }
            else{
                ans+=DP(indx+1,0,1,zeroes);
            }
        }
    }
    else{
        /// jodi starting position hoy ; 
        for(ll i=1;i<=till;i++){
            if(small || i<vc[indx]){
                ans+=DP(indx+1,1,1,zeroes); 
            }
            else ans+=DP(indx+1,0,1,zeroes);
        }
        ans+=DP(indx+1,1,0,zeroes);/// starting position e kono digit bosai nai ;
    }
    dp[indx][small][started][zeroes]=ans;
    return ans;
}

ll solve(ll n){
    if(n<0)return 0;
    if(n<10)return 1;
    vc.clear();
    N=0;
    ll x=n;
    while(n){
        vc.pb(n%10);
        n/=10;
        N++;
    }
    reverse(all(vc));
    //cout<<x<<endl;
   // for(auto it: vc)cout<<it<<spc;
    ll ans=DP(0,0,0,0)+1;
   // cout<<ans<<endl;
    return ans;
}
int main(){FIO;
    ll test;ll cs=1;
    cin>>test;
    while(test--){
        ll n,m;cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        ll ans=solve(m);
        memset(dp,-1,sizeof(dp));
        ans-=solve(n-1);
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
return 0;
}

