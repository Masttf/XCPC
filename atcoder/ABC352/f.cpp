#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n;cin>>n;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=1;i<=n;i++){
    	int u,v,w;cin>>u>>v>>w;
    	g[u].push_back({v,w});
    } 
    vector<set<int>>res(n+1);
    vector<int>f(n+1),sz(n+1);
    for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
    auto find = [&](auto self,int x)->int{
    	return f[x]==x?x:f[x]=self(self,f[x]);
    };
    auto merge = [&](int a,int b)->void{
    	int fa=find(find,a);
    	int fb=find(find,b);
    	if(fa==fb)return ;
    	sz[fa]+=sz[fb];
    	f[fb]=fa;
    };
    for(int i=1;i<=n;i++){
    	for(auto [v,w]:g[i]){
    		merge(i,v);
    	}
    }

    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}