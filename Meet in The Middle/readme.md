
# Theory : 

   [GeeksforGeeks](https://www.geeksforgeeks.org/meet-in-the-middle/)
   
  [Quora](https://www.quora.com/What-is-meet-in-the-middle-algorithm-w-r-t-competitive-programming)


# Implementation:

```cpp
int main(){FIO;     
     ll n,m;cin>>n>>m;
     ll ara[n];
     for(ll i=0;i<n;i++)cin>>ara[i];
     ll c1=n/2;
     ll c2=n-c1;
     vector<ll>sum1(1<<c1),sum2(1<<c2);
     for(ll i=0;i<(1<<c1);i++){
          for(ll j=0;j<c1;j++){
               if(checkbit(i,j))
                    sum1[i]+=ara[j];
          }
     }
     for(ll i=0;i<(1<<c2);i++){
          for(ll j=0;j<n;j++){
               if(checkbit(i,j))
                    sum2[i]+=ara[j+c1];
          }
     }
     ll cc=0;
     sort(all(sum2));
     for(ll i=0;i<(1<<c1);i++){
          ll x=m-sum1[i];
          if(x>=0){
               cc+=upper_bound(all(sum2),x)-sum2.begin();
          }
     }
     cout<<cc<<edl;
return 0;
}
