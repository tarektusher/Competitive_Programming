## These Problem are very interesting and important problem to learn Inclusion and Exclusion.<br>

### [Problem 01](https://cses.fi/problemset/task/2417)*[Here we find number of pairs in an array which gcd is 1]*
### [Problem 02](https://www.codechef.com/problems/COPRIME3)*[Here we find number of triplets in an array which gcd is 1]*
### [Problem 03](https://codeforces.com/contest/803/problem/F)*[Here we find number of subsequences in an array which gcd is 1]*


## Problem 01 Soln : 
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
vector<vector<ll>>divisor(maX);
ll vis[maX];
void seive(){
     for(ll i=2;i<maX;i+=1){
          if(!vis[i]){
               divisor[i].pb(i);
               for(ll j=2*i;j<maX;j+=i){
                    divisor[j].pb(i);
                    vis[j]=1;
               }
          }
     }
}
int main(){FIO;
     seive();
     ll n;cin>>n;
     vector<ll>ara(n);
     for(ll i=0;i<n;i++){
          cin>>ara[i];
     }
     ll total=n*(n-1)/2;
     ll bad=0;
     vector<ll>div(maX,0),prdiv(maX,0);
     for(ll i=0;i<n;i++){
          for(ll mask=1; mask< (1<<divisor[ara[i]].size()) ;mask++){
               ll cc=0,val=1;
               
               for(ll j=0;j<divisor[ara[i]].size();j++){
                    if(checkbit(mask,j)){
                         cc++;
                         val*=divisor[ara[i]][j];
                    }
               }
               div[val]++;
               prdiv[val]=cc;
          }
     }
     ll cc=0;
     for(ll i=0;i<maX;i++){
          if(prdiv[i]%2==1){
               cc=div[i]*(div[i]-1)/2;
               bad+=cc;
          }
          else {
               cc=div[i]*(div[i]-1)/2;
               bad-=cc;
          }
     }
     cout<<total-bad<<endl;
return 0;
}
```
## Problem 02 Soln :
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
vector<vector<ll>>divisor(maX);
ll vis[maX];
void seive(){
     for(ll i=2;i<maX;i+=1){
          if(!vis[i]){
               divisor[i].pb(i);
               for(ll j=2*i;j<maX;j+=i){
                    divisor[j].pb(i);
                    vis[j]=1;
               }
          }
     }
}
int main(){FIO;
     seive();
     ll n;cin>>n;
     vector<ll>ara(n);
     for(ll i=0;i<n;i++){
          cin>>ara[i];
     }
     ll total=n*(n-1)*(n-2)/6;
     ll bad=0;
     vector<ll>div(maX,0),prdiv(maX,0);
     for(ll i=0;i<n;i++){
          for(ll mask=1; mask< (1<<divisor[ara[i]].size()) ;mask++){
               ll cc=0,val=1;
               
               for(ll j=0;j<divisor[ara[i]].size();j++){
                    if(checkbit(mask,j)){
                         cc++;
                         val*=divisor[ara[i]][j];
                    }
               }
               div[val]++;
               prdiv[val]=cc;
          }
     }
     ll cc=0;
     for(ll i=0;i<maX;i++){
          if(prdiv[i]%2==1){
               cc=div[i]*(div[i]-1)*(div[i]-2)/6;
               bad+=cc;
          }
          else {
               cc=div[i]*(div[i]-1)*(div[i]-2)/6;
               bad-=cc;
          }
     }
     cout<<total-bad<<endl;
return 0;
}
```
## Problem 03 Soln :
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
const long long maX =1e5+10;
vector<vector<ll>>divisor(maX);
ll vis[maX];
void seive(){
     for(ll i=2;i<maX;i++){
          if(!vis[i]){
               divisor[i].pb(i);
               for(ll j=2*i;j<maX;j+=i){
                    divisor[j].pb(i);
                    vis[j]=1;
               }
          }
     }
}

ll exp(ll a,ll b){
     if(b==0)return 1;
     ll x=exp(a,b/2);
     x=(x*x)%mod;
     if(b&1)x=(x*a)%mod;
     return x;
}

int main(){FIO;
    seive();
    ll n;cin>>n;
    ll ara[n];
    for(ll i=0;i<n;i++)cin>>ara[i];
    ll total=exp(2,n)-1;
    total%=mod;
    ll bad=0;
     vector<ll>div(maX,0),prdiv(maX,0);
     for(ll i=0;i<n;i++){
          for(ll mask=1; mask< (1<<divisor[ara[i]].size()) ;mask++){
               ll cc=0,val=1;
               
               for(ll j=0;j<divisor[ara[i]].size();j++){
                    if(checkbit(mask,j)){
                         cc++;
                         val*=divisor[ara[i]][j];
                    }
               }
               div[val]++;
               prdiv[val]=cc;
          }
     }
     ll cc=0;
     for(ll i=0;i<maX;i++){
          if(prdiv[i]%2==1){
               cc=exp(2,div[i])-1;
               bad+=cc;
               bad%=mod;
          }
          else {
               cc=exp(2,div[i])-1;
               bad-=cc;
               bad+=mod;
               bad%=mod;
          }
     }
     ll x=total-bad+mod;
     x%=mod;
     cout<<x<<endl;
return 0;
}
```
