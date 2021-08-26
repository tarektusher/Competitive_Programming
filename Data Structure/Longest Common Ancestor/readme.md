# [Theory Link](http://www.shafaetsplanet.com/?p=1831)

# Implementation
```cpp
const long long maX =1e3+10;
vector<ll>graph[maX];
ll depth[maX],parent[maX],sp[maX][25];
bool visited[maX];
ll n;

void dfs(ll u,ll p,ll d){
     visited[u]=true;
     parent[u]=p;
     depth[u]=d;
     for(auto  v : graph[u]){
          if(v==p || visited[v])cn;
          dfs(v,u,d+1);
     }
}

void Build_LCA(){
     for(ll i=1;i<=n;i++){
          sp[i][0]=parent[i];
     }
     for(ll j=1;(1<<j)<n;j++){
          for(ll i=1;i<=n;i++){
               if(sp[i][j-1] != -1)sp[i][j]=sp[sp[i][j-1]][j-1];
          }
     }
}

ll LCA_Query(ll u,ll v){
     if(depth[u]<depth[v])swap(u,v);
     ll lg=1;
    while(1){
         if((1<<(lg+1))>depth[u])break;
          lg++;
     }
     for(ll i=lg;i>=0;i--){
          if(depth[u]-(1<<i)>=depth[v])u=sp[u][i];
     }
     if(u==v)return v;
     for(ll i=lg;i>=0;i--){
          if(sp[u][i] != -1 && sp[u][i] != sp[v][i])u=sp[u][i],v=sp[v][i];
     }
     return parent[u];
}
