## Approach 01 : (Normal Seive O(NloglogN))
```cpp
const long long maX =1e6+10;
vector<ll>pr;
ll vis[maX];
void Seive(){
     for(ll i=2;i<maX;i+=2)vis[i]=1;
     for(ll i=3;i*i<maX;i+=2){
          if(!vis[i]){
               for(ll j=i*i;j<maX;j+=2*i){
                    vis[j]=1;
               }
          }
     }
     pr.pb(2);
     for(ll i=3;i<maX;i+=2){
          if(!vis[i])pr.pb(i);
     }
}
```
## Approach 02 (Linear Seive O(N))
```cpp
const long long maX =1e7+10;
vector<ll>lp(maX),pr;
void linear_Seive(){
     for(ll i=2;i<maX;i+=1){
          if(lp[i]==0){
               lp[i]=i;
               pr.pb(i);
          }
          for(ll j=0;i*pr[j]<maX;j++){
               lp[i*pr[j]]=pr[j];
               if(lp[i]==pr[j]){
                    break;
               }
          }
     }
}
```
## Approach 03 : Bitwise Seive
```cpp
const long long maX=1e8+10;
vector<ll>prime,store;
ll flag[maX/32];
void bitwise_seive(){
    for(ll i=4;i<=maX;i+=2){
        flag[i>>5]=setbit(flag[i>>5],i&31);
    }
    prime.pb(2);
    for(ll i=3;i*i<=maX;i+=2){
        if(!checkbit(flag[i>>5],i&31)){
            for(ll j=i*i;j<=maX;j+=(i<<1)){
                flag[j>>5]=setbit(flag[j>>5],j&31);
            }
        }
    }
    for(ll i=3;i<=maX;i+=2){
        if(!checkbit(flag[i>>5],i&31))prime.pb(i);
    }
}
