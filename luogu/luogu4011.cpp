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
constexpr int maxn=20;
constexpr int Max=1e18;
int tt[maxn][maxn][maxn][maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve(){
    int n,m,p;cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		for(int pp=1;pp<=n;pp++){
    			for(int q=1;q<=m;q++)tt[i][j][pp][q]=-2;
    		}
    	}
    }
    int k;cin>>k;
    for(int i=1;i<=k;i++){
    	int x1,y1,x2,y2,g;cin>>x1>>y1>>x2>>y2>>g;
    	g--;
    	tt[x1][y1][x2][y2]=g;
    	tt[x2][y2][x1][y1]=g;
    }
    vector key(n+1,vector(m+1,vector<int>()));
    cin>>k;
    for(int i=1;i<=k;i++){
    	int x,y,q;cin>>x>>y>>q;
    	q--;
    	key[x][y].push_back(q);
    }
    auto bfs = [&](int sx,int sy)->void{
    	queue<array<int,3>>q;
    	vector dis(1<<p,vector(n+1,vector<int>(m+1,Max)));
    	vector vis(1<<p,vector(n+1,vector<int>(m+1)));
    	dis[0][sx][sy]=0;
    	vis[0][sx][sy]=1;
    	q.push({0,sx,sy});
    	while(!q.empty()){
    		auto [t,x,y]=q.front();
    		//dbg(t,x,y);
    		q.pop();
    		for(int i=0;i<4;i++){
    			int tx=x+dx[i];
    			int ty=y+dy[i];
    			if(tx<1||tx>n||ty<1||ty>m)continue;
    			if(vis[t][tx][ty])continue;
    			if(tt[x][y][tx][ty]==-1)continue;
    			else if(tt[x][y][tx][ty]==-2){
    				dis[t][tx][ty]=dis[t][x][y]+1;
    				vis[t][tx][ty]=1;
    				q.push({t,tx,ty});
    				int last=t;
	    			for(auto pp:key[tx][ty])last|=(1<<pp);
	    			if(vis[last][tx][ty])continue;
	    			dis[last][tx][ty]=dis[t][x][y]+1;
	    			vis[last][tx][ty]=1;
	    			q.push({last,tx,ty});
    			}else{
    				int pp=tt[x][y][tx][ty];
    				if(t>>pp&1){
    					dis[t][tx][ty]=dis[t][x][y]+1;
    					vis[t][tx][ty]=1;
    					q.push({t,tx,ty});
    					int last=t;
		    			for(auto ppp:key[tx][ty])last|=(1<<ppp);
		    			if(vis[last][tx][ty])continue;
		    			dis[last][tx][ty]=dis[t][x][y]+1;
		    			vis[last][tx][ty]=1;
		    			q.push({last,tx,ty});
    				}
    			}
    		}
    	}
    	int mi=Max;
    	for(int i=0;i<(1<<p);i++){
    		mi=min(dis[i][n][m],mi);
    	}
    	if(mi==Max)cout<<-1<<'\n';
    	else cout<<mi<<'\n';
    };
    bfs(1,1);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}