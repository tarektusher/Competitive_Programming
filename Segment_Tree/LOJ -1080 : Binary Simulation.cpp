Problem link : https://lightoj.com/problem/binary-simulation
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
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, int> pint;
typedef vector<int> vi;
typedef vector<pi> vpi;
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
vector<ll>ara(maX),Xor(maX);
ll tr[4*maX];
ll global;
char str[maX];

void build(ll u,ll b,ll e,ll i,ll j)
{
    if(b==i && e==j){
        tr[u]++;
        return;
    }
    ll mid=(b+e)>>1;
    if(j<=mid)build(2*u,b,mid,i,j);
    else if(i>mid)build(2*u+1,mid+1,e,i,j);
    else {
        build(2*u,b,mid,i,mid);
        build(2*u+1,mid+1,e,mid+1,j);
    }
}

ll query(ll u,ll b,ll e,ll idx)
{
    if(b==idx && e==idx){
        return tr[u];
    }
    ll mid=(b+e)>>1;
    if(idx<=mid)return tr[u]+query(2*u,b,mid,idx);
    else return tr[u]+query(2*u+1,mid+1,e,idx);
}

int main()
{
    ll test;scanf("%lld",&test);ll cs=1;
    while(test--){
        memset(tr,0,sizeof(tr));
        scanf("%s",str);
        ll len=strlen(str);
        for(ll i=0;i<len;i++){
            if(str[i]=='1'){
                build(1,1,len,i+1,i+1);
            }
        }
        ll q;scanf("%lld",&q);
        csprint2;
        while(q--){
            char ch[3];scanf("%s",ch);
            if(ch[0]=='I'){
                    ll x,y;scanf("%lld %lld",&x,&y);
                build(1,1,len,x,y);
            }
            else {
                ll x;scanf("%lld",&x);
                printf("%lld\n",query(1,1,len,x)%2);

            }
        }
    }
}
