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
constexpr int Max=1e18;
struct Max_Flow{
    struct node{
        int v,w;
    };
    int n;
    vector<node>e;
    vector<vector<int>>g;
    vector<int>h,cur;
    Max_Flow(int n){
        init(n);
    }
    void add(int u,int v,int w){
        g[u].push_back(e.size());
        e.push_back({v,w});
        g[v].push_back(e.size());
        e.push_back({u,0});
    }
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs (int s,int t){
        h.assign(n,-1);
        queue<int>q;
        h[s]=0;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto i:g[u]){
                auto [v,w]=e[i];
                if(h[v]==-1&&w){
                    h[v]=h[u]+1;
                    if(v==t){
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u,int t,int val){
        if(u==t)return val;
        int res=val;
        for(auto &i=cur[u];i<(int)g[u].size();i++){
            int j=g[u][i];
            auto [v,w]=e[j];
            if(w>0&&h[v]==h[u]+1){
                int d=dfs(v,t,min(res,w));
                e[j].w-=d;
                e[j^1].w+=d;
                res-=d;
                if(res==0)return val;
            }
        }
        return val-res;
    }
    int flow(int s,int t){
        int ans=0;
        while(bfs(s,t)){
            cur.assign(n,0);
            ans+=dfs(s,t,Max);
        }
        return ans;
    }
};
void solve(){
    int k,n;cin>>k>>n;
    vector<int>cnt(k+1);
    int sum=0;
    for(int i=1;i<=k;i++)cin>>cnt[i],sum+=cnt[i];
    Max_Flow g(n+k+2);
	for(int i=1;i<=n;i++){
		g.add(0,i,1);
	}
	for(int i=1;i<=k;i++){
		g.add(n+i,n+k+1,cnt[i]);
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int v;cin>>v;
			g.add(i,v+n,1);
		}
	}
	int res=g.flow(0,n+k+1);
	if(res!=sum){
		cout<<"No Solution!\n";
		return ;
	}
	vector<vector<int>>ans(k+1);
	for(int i=(n+k)*2;i<g.e.size();i+=2){
		int u=g.e[i+1].v;
		int v=g.e[i].v;
		int w=g.e[i].w;
		if(w==0)ans[v-n].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cout<<i<<": ";
		for(auto x:ans[i])cout<<x<<' ';
		cout<<'\n';
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