
# code 

## Approch 01 : 
  
```cpp

ll prime(ll n)
{
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
ll po(ll a,ll b)
{
    if(b==0)return 1;
    ll x=po(a,b/2);
    x=x*x;
    if(b&1)x=x*a;
    return x;
}

ll  prime_factoriazation(ll n)
{
    if(prime(n))return n-1;
    ll ans=1;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll cc=0;
            while(n%i==0){
                cc++;
                n/=i;
            }
            ans*=po(i,cc-1)*(i-1);
        }
    }
    if(n != 1){
        ans*=(n-1);
    }
    return ans;
}
int main()
{
    ll n,i,j,cc=0;
    cin>>n;
    cout<<prime_factoriazation(n)<<endl;
}
```

## Approach 02 : 
```cpp
ll eular_toient(ll n)
{
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans-=ans/i;
        }
    }
    if(n!= 1)ans-=ans/n;
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    cout<<eular_toient(n)<<endl;
}
```
## Approach 03 : (Using Seive)

```cpp
ll pi[maX];
ll eular_toient(ll n)
{
    for(ll i=0;i<maX;i++)pi[i]=i;
    for(ll i=2;i<maX;i++){
        if(pi[i]==i){
            for(ll j=i;j<maX;j+=i)pi[j]-=pi[j]/i;
        }
    }
}
```
