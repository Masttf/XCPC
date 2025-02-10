#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=1005;
int n,k,s,t,u[N],a[N*5];
int b[N];
struct E{
	int x,y;
};
vector<E> G1,G2;
struct Dinic{
    int m,s,t;
	struct E{int to;ll c;};
    vector<E> edge;
    vector<vector<int>> G;
    vector<int> d,cur;
    void init(int n,int s,int t){
        this->s=s,this->t=t;
        G.clear(),edge.clear();m=0;
        G.resize(n+1),d.resize(n+1),cur.resize(n+1);
    }
    void add(int u,int v,ll c){
        edge.pb({v,c}),edge.pb({u,0});
        G[u].pb(m++),G[v].pb(m++);
    }
    bool bfs(){
        fill(d.begin(),d.end(),0);
        queue<int> q;
        q.push(s);d[s]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int&j:G[x]){
                E&e=edge[j];
                if(!d[e.to]&&e.c>0){
                    d[e.to]=d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return d[t];
    }
    ll dfs(int u,ll c){
        if(u==t||!c)return c;
        ll tmp=c,f;
        for(int&j=cur[u];j<G[u].size();++j){
            E&e=edge[G[u][j]];
            if(d[u]+1==d[e.to]){
                f=dfs(e.to,min(c,e.c)),
                e.c-=f,
                edge[G[u][j]^1].c+=f,
                c-=f;
                if(!c)break;
            }
        }
        return tmp-c;
    }
    ll dinic(){
        ll flow=0;
        while(bfs()){
            fill(cur.begin(),cur.end(),0);
            flow+=dfs(s,1e18);//INF
        }
        return flow;
    }
};
int main()
{
	//freopen("carnivalcat.in","r",stdin);
	//freopen("carnivalcat.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
{
    Dinic DC;
    scanf("%d%d",&n,&k);
    s=3*k+1,t=3*k+2;
    DC.init(t,s,t);
    int ans=0,INF=1000*40;//attention!!!
    for(int i=1;i<=k;++i)scanf("%d",&u[i]),b[u[i]]=i;
    //G1.resize(n+1),G2.resize(n+1);
	int ii=k;
	for(int i=1;i<n;++i){
    	int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(b[x]&&b[y]){
			ans+=z;
			a[b[x]]-=z,a[b[y]]-=z;
			a[++ii]=z;
			DC.add(ii,b[x],INF),DC.add(ii,b[y],INF);
		}
	}
	for(int i=1;i<n;++i){
    	int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
    	if(b[x]&&b[y]){
			a[++ii]=z;
			DC.add(ii,b[x],INF),DC.add(ii,b[y],INF);
		}
	}
    for(int i=1;i<=t-2;++i)
    if(a[i]<0){
        DC.add(i,t,-a[i]);
    }
    else{
        DC.add(s,i,a[i]);
        ans+=a[i];
    }
    ans-=DC.dinic();
    printf("%d\n",ans);
    memset(b,0,(n+2)*4);memset(a,0,(k+2)*3*5);
}
    return 0;
}
