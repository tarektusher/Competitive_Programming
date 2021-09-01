# [Problem Link](https://codeforces.com/contest/25/problem/E)
# Code :
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
const long long maX =3e6+10;
ll d[3][3];
vector<ll>pi(maX),len(3);
void KMP(string &ans ,string &s1,string &s2){
     string str=s2+"#"+s1;
     ll n=str.size();
     pi[0]=0;
     bool ok=false;
     for(ll i=1;i<n;i++){
          ll j=pi[i-1];
          while(j>0 && str[i] != str[j]){
               j=pi[j-1];
          }
          if(str[i]==str[j])j++;
          pi[i]=j;
          if(pi[i]==s2.length()){
               ok=true;
          }
     }
     if(ok){
          ans=s1;
          return;
     }
     ans=s1+s2.substr(pi[n-1],n-pi[n-1]);
}

int main(){FIO;
          vector<string>str(3);
          cin>>str[0]>>str[1]>>str[2];
          ll mn=infinity;
          for(ll i=0;i<3;i++){
               for(ll j=0;j<3;j++){
                    if(i==j)cn;
                    string ans;
                    KMP(ans,str[i],str[j]);
                    for(ll k=0;k<3;k++){
                         if(i==k || j==k)cn;
                         string final_ans;
                         KMP(final_ans,ans,str[k]);
                         if(mn>final_ans.size()){
                              mn=final_ans.size();
                         }
                    }
               }
          }
          cout<<mn<<edl;
          
return 0;
}
