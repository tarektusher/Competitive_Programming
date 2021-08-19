# [Theory Part](https://cp-algorithms.com/string/manacher.html)
# Implementation 
```cpp
const long long maX =1e6+10;
ll odd[maX],even[maX];
string str,ans;
ll mx=-1,pos;
bool ok=false;
void odd_cal(){
     ll l=0,r=-1,n=str.size();
     for(ll i=0;i<n;i++){
          ll j=(i>r) ? 1 : min(odd[l+r-i],r-i+1);
          while(i-j>=0 && i+j<n && str[i-j]==str[i+j])j++;
          odd[i]=j--;
          if(i+j>r){
               l=i-j;
               r=i+j;
          }
          if(odd[i]*2-1>mx){
               mx=odd[i]*2-1;
               pos=i-odd[i]+1;
               ok=true;
          }
     }
}

void even_cal(){
     ll l=0,r=-1,n=str.size();
     for(ll i=0;i<n;i++){
          ll j=(i>r)? 0 : min(even[l+r-i+1],r-i+1);
          while(i-j-1>=0 && i+j<n && str[i-j-1]==str[i+j])j++;
          even[i]=j--;
          if(i+j>r){
               l=i-j-1;
               r=i+j;
          }
          if(even[i]*2>mx){
               mx=even[i]*2;
               pos=i-even[i];
               ok=true;
          }
     }
}

int main(){FIO;
     cin>>str;
     odd_cal();
     ans=str.substr(pos,mx);
     ok=false;
     even_cal();
     if(ok)ans=str.substr(pos,mx);
     cout<<ans<<edl;
return 0;
}
