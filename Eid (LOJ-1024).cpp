#Problem link : https://lightoj.com/problem/eid

Its an simple LCM problem but interesting thing is it can be solve using String Multiplication process.
  
 Code : 
  

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
const long long maX =1e4+10;
vector<ll>prime;
ll vis[maX];
string str;
void multiply(string nums) {
   int n = nums.size();
   int m = str.size();
   string ans(n + m, '0');
   for(int i = n - 1; i>=0; i--){
      for(int j = m - 1; j >= 0; j--){
         int p = (nums[i] - '0') * (str[j] - '0') + (ans[i + j +
         1] - '0');
         ans[i+j+1] = p % 10 + '0';
         ans[i+j] += p / 10 ;
      }
   }
   for(int i = 0; i < m + n; i++){
      if(ans[i] !='0'){
          str= ans.substr(i);
          break;
      }
   }
}
void cal(){
    for(ll i=3;i*i<maX;i+=2){
        if(!vis[i]){
            for(ll j=i*i;j<maX;j+=2*i)vis[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3;i<maX;i+=2){
        if(!vis[i])prime.pb(i);
    }
}
int main(){FIO;
    ll test;cin>>test;
    ll cs=1;cal();
    while(test--){
        ll n;cin>>n;
        map<ll,ll>check;
        str.clear();
        str="1";
        for(ll i=0;i<n;i++){
            ll x;cin>>x;
            for(ll j=0;j<prime.size()&& prime[j]*prime[j]<=x;j++){
                if(x%prime[j]==0){
                    ll cc=0;
                    while(x%prime[j]==0){
                        cc++;
                        x/=prime[j];
                    }
                    check[prime[j]]=max(check[prime[j]],cc);
                }
            }
            if(x>1)check[x]=max(check[x],1ll);
        }
        for(auto it : check){
            ll x=it.ff;
            ll y=it.ss;
            ll z=pow(x,y);
            string ara;
            while(z){
                ll rem=z%10;
                z/=10;
                ara+=rem+'0';
            }
            reverse(all(ara));
            multiply(ara);
        }
        cout<<"Case "<<cs++<<": "<<str<<edl;

       
    }
return 0;
}
