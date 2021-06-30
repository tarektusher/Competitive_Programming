# Problem Link: https://lightoj.com/problem/a-new-function

# Idea : 
Let P =  1 - 25

![image](https://user-images.githubusercontent.com/57767316/123996553-44d3a980-d9f1-11eb-93d3-90748940506c.png)


Total: 173


Given Number P = 25, i = 2 , j= P/i = 12
From above calculation, we can find out two relations
First Relation
2+3+4+5+6+7+8+9+10+11+12
= 1+2+3+4+5+6+7+8+9+10+11+12-1 
= j*(j+1)/2 - (i-1)*(i-1+1)/2  
= j*(j+1)/2 - (i-1)*(i)/2
= (j^2+j - i^2 + i)/2
= ((j-i)(j+i)+(j+i))/2
= ((j+i)(j-i+1))/2  (General Form)
= (14 * 11 )/2 = 77

Second Relation
2x10 = i*(j-i)  (General Form)
     = 20

Again
 i  = 3 ,  j = P/i = 8

First Relation
3+4+5+6+7+8
= (1+2+3+4+5+6+7+8) - (1+2)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (11 * 6 )/2 = 33

Second Relation
3x5 = i*(j-i)
    = 15

Again
 i  = 4 ,  j = P/i = 6

First Relation
4+5+6
= (1+2+3+4+5+6) - (1+2+3)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 3 )/2 = 15

Second Relation
4x2 = i*(j-i)
    = 8

Again
 i  = 5 ,  j = P/i = 5

First Relation
5
= (1+2+3+4+5) - (1+2+3+4)
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 1 )/2 = 5

Second Relation
5x0 = i*(j-i)
    = 0

SUM = 77+20+33+15+15+8+5+0 = 173

# Code :

``` 
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


int main(){FIO;
    ll test;cin>>test;
    ll cs=1;
    while(test--){
        ll n;cin>>n;
        ll cc=0;
        for(ll i=2;i*i<=n;i++){
            ll x=n/i;
            cc+=(x-i)*i;
            cc+=(x*(x+1)/2-((i-1)*((i-1)+1))/2);
        }
        cout<<"Case "<<cs++<<": "<<cc<<edl;
    }
return 0;
}


