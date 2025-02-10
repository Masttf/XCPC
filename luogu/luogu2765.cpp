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
    void resize(int sz){
    	for(int i=1;i<=sz;i++){
    		this->n = this->n+1;
	    	g.push_back({});
	    	h.push_back(0);
	    	cur.push_back(0);
    	}
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
void solve(){
    int n;cin>>n;
    Max_Flow g(2);
    int s=0,t=1;
    int num=2;
    int real=0;
    int tot=0;
    while(real-tot<=n){
    	real++;
    	g.resize(2);
    	g.add(num+1,t,1);
    	g.add(0,num,1);
    	for(int i=1;i<real;i++){
    		int d=i+real;
    		int pp=sqrt(d);
    		while(pp*pp<d)pp++;
    		while(pp*pp>d)pp--;
    		if(pp*pp==d){
    			g.add((i+1)*2,num+1,1);
    		}
    	}
    	tot+=g.flow(s,t);
    	num+=2;
    }
    real--;
    Max_Flow g2(real*2+2);
    for(int i=1;i<=real;i++){
    	g2.add(0,i,1);
    	g2.add(real+i,2*real+1,1);
    }
    for(int i=1;i<=real;i++){
    	for(int j=i+1;j<=real;j++){
    		int d=i+j;
    		int pp=sqrt(d);
    		while(pp*pp<d)pp++;
    		while(pp*pp>d)pp--;
    		if(pp*pp==d){
    			g2.add(i,real+j,1);
    		}
    	}
    }
    g2.flow(0,2*real+1);
    vector<vector<int>>res(real+1);
    vector<int>du(real+1);
    for(int i=4*real;i<g2.e.size();i+=2){
    	int u=g2.e[i+1].v;
    	int v=g2.e[i].v;
    	int w=g2.e[i].w;
    	//dbg(u,v,w);
    	if(w==0){
    		v-=real;
    		//dbg(u,v);
    		res[u].push_back(v);
    		du[v]++;
    	}
    }
    auto dfs = [&](auto self,int x)->void{
    	cout<<x<<' ';
    	if(!res[x].empty())self(self,res[x][0]);
    };
    cout<<real<<'\n';
    for(int i=1;i<=real;i++){
    	if(!du[i]){
    		dfs(dfs,i);
    		cout<<'\n';
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