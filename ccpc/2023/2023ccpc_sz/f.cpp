#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
	std::cout << std::endl;
}
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
    int n;cin>>n;
    vector<int>du(n+1);
    vector<int>du2(n+1);
    vector g(n+1,vector<int>());
    map<pair<int,int>,int>s;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        du[u]++;
        du[v]++;
        du2[u]++;
        du2[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        s[{u,v}]=1;
    }

    queue<int>q;
    vector<int>cnt(10);
    for(int i=1;i<=n;i++){
        cnt[du[i]]++;
        if(du[i]==1)q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(s.count({u,v}))s.erase({u,v});
            else if(s.count({v,u}))s.erase({v,u});
            du[v]--;
            if(du[v]==1)q.push(v);
        }
    }
    int ans=0;
    //dbg(s.size());
    for(auto it=s.begin();it!=s.end();it++){
        int u=it->first.first;
        int v=it->first.second;
        cnt[du2[u]]--;
        cnt[du2[v]]--;
        cnt[du2[u]-1]++;
        cnt[du2[v]-1]++;
        if(!cnt[5]){
            ans+=cnt[1]+cnt[2]+cnt[3];
            //dbg(ans);
        }
        cnt[du2[u]]++;
        cnt[du2[u]-1]--;
        cnt[du2[v]]++;
        cnt[du2[v]-1]--;

    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}