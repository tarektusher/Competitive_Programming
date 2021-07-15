Problem link : https://lightoj.com/problem/ghajini

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
ll ara[maX];
ll mx[2*maX];
ll mn[2*maX];
ll global;
void build (ll u,ll b,ll e)
{
    if(b==e){
        mx[u]=ara[b];
        mn[u]=ara[b];
        return;
    }
    ll mid=(b+e)>>1;
    build(2*u,b,mid);
    build(2*u+1,mid+1,e);
    mx[u]=max(mx[2*u],mx[2*u+1]);
    mn[u]=min(mn[2*u],mn[2*u+1]);
}

//void update(ll u,ll b,ll e ,ll idx ,ll x)
//{
//    if(b==e){
//        tr[b]^=1;
//        return;
//    }
//    ll mid=(b+e)>>1;
//    if(idx<=mid)update(2*u,b,mid,idx,x,a);
//    else update(2*u+1,mid+1,e,idx,x,a);
//    tr[u]=tr[2*u]+tr[2*u+1];
//
//}

ll query(ll u,ll b,ll e,ll i,ll j)
{
    if(b>j || i>e)return -1;
    if(b>=i && e<=j)return mx[u];
    ll mid=(b+e)>>1;
    ll x= query(2*u,b,mid,i,j);
    ll y=query(2*u+1,mid+1,e,i,j);
    return max(x,y);
}
ll query1(ll u,ll b,ll e,ll i,ll j)
{
    if(b>j || i>e)return infinity;
    if(b>=i && e<=j)return mn[u];
    ll mid=(b+e)>>1;
    ll x= query1(2*u,b,mid,i,j);
    ll y=query1(2*u+1,mid+1,e,i,j);
    return min(x,y);
}
int main()
{
    FIO;
    ll test;
    scanf("%lld",&test);
    ll cs=1;
    while(test--){
        ll n,d;
        scanf("%lld %lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&ara[i]);
        }
        for(ll i=1;i<=n;i++){
            mx[i]=-1;
            mn[i]=infinity;
        }
        build(1,1,n);
        //for(ll i=1;i<=25;i++)cout<<i<<spc<<mn[i]<<endl;
        ll dif=-1;
        csprint1;
        for(ll i=1;i+d-1<=n;i++){
            ll x=query(1,1,n,i,i+d-1);
            ll y=query1(1,1,n,i,i+d-1);
            //cout<<x<<spc<<y<<endl;
            dif=max(dif,x-y);

        }printf("%lld\n",dif);
    }
return 0;
}
