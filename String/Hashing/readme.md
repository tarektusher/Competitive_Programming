# Basic Code : 
```cpp
const long long maX =1e6+10;
ll p=31;
vector<ll>po(maX);
int main(){FIO;
    ll test;cin>>test;
    po[0]=1;
    for(ll i=1;i<maX;i++)po[i]=(po[i-1]*p)%mod;
    while(test--){
        string text,pattern;
        cin>>text>>pattern;
        ll t=text.size(),p=pattern.size();
        vector<ll>hash(t+1,0);
        hash[0]=1;
        for(ll i=0;i<t;i++){
            hash[i+1]=(hash[i]+(text[i]-'a'+1)*po[i])%mod;
        }
        ll pat_hash=0;
        for(ll i=0;i<p;i++){
            pat_hash=(pat_hash+(pattern[i]-'a'+1)*po[i])%mod;
        }
        vector<ll>vc;
        for(ll i=0;i+p-1<t;i++){
            ll cc=(hash[i+p]-hash[i]+mod)%mod;
            if(cc==(pat_hash*po[i])%mod)vc.pb(i);
        }
        if(vc.size()==0)cout<<"Not Found"<<edl;
        else {
            cout<<vc.size()<<edl;
            for(ll i=0;i<vc.size();i++)cout<<vc[i]+1<<spc;
            cout<<edl;
        }
        if(test)
        cout<<edl;
    }
return 0;
}
