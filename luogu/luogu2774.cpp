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
                if(h[v]==-1&&w>0){
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
    vector<int> mincut(int s,int t){
        vector<int>res;
        for(int i=0;i<n;i++){
            if(h[i]!=-1)res.push_back(i);
        }
        return res;
    }
};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve(){
    int n,m;cin>>n>>m;
    vector a(n+1,vector<int>(m+1));
    int ans=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
    		ans+=a[i][j];
    	}
    }
	auto get = [&](int i,int j)->int{
		return (i-1)*m+j;
	};
	Max_Flow g(n*m+2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int id=get(i,j);
			if((i+j)%2==0){
				g.add(0,id,a[i][j]);
				for(int k=0;k<4;k++){
					int x=i+dx[k];
					int y=j+dy[k];
					if(x<1||x>n||y<1||y>m)continue;
					int id2=get(x,y);
					g.add(id,id2,Max);
				}
			}
			else g.add(id,n*m+1,a[i][j]);
		}
	}
	ans-=g.flow(0,n*m+1);
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