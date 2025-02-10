#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int MX=N-5;
const int MX_Q=1e6+5;
ll lcm(int x,int y){return (ll)x*y/__gcd(x,y);}
struct Query{
	int r,x,idx;
	bool operator <(const Query &rhs)const{
		return x<rhs.x;
	}
}qs[MX_Q];
struct Fenwick{
	int n,a[N];
	void init(int _n){n=_n;rep(i,0,n)a[i]=0;}
	int lowbit(int x){return x&-x;}
	int query(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=a[x];
		return ret;
	}
	int query(int l,int r){return query(r)-query(l-1);}
	void add(int x,int v){
		for(;x<=n;x+=lowbit(x))a[x]+=v;
	}
}tr;

int n,Q;
int fa[N],son[N],top[N],sz[N],dep[N],dfl[N],dfr[N],dfn;
int ans[MX_Q];
vector<vector<int>> G;
vector<int> divisor[N];
vector<pair<int,int>> pos[N];

void dfs1(int x){
	sz[x]=1;son[x]=0;
	for(auto to:G[x])if(to!=fa[x]){
		dep[to]=dep[x]+1;
		fa[to]=x;
		dfs1(to);
		sz[x]+=sz[to];
		if(sz[to]>sz[son[x]])son[x]=to;
	}
}
void dfs2(int x,int t){
	dfl[x]=++dfn;top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(auto to:G[x])if(to!=fa[x]&&to!=son[x])
		dfs2(to,to);
	dfr[x]=dfn;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if(fa[top[a]]<fa[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b])swap(a,b);
	return a;
}
int main(){
	fastio;
	rep(i,1,MX)for(int L=i;L<=MX;L+=i)divisor[L].push_back(i);
	rep(i,1,MX)for(int L=i;L<=MX;L+=i)
		for(auto j:divisor[L])if(j<=i&&lcm(i,j)==L)
			pos[L].push_back(make_pair(i,j));

	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		tr.init(n);
		dfn=0;
		G=vector<vector<int>>(n+5);

		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1);dfs2(1,1);
		cin>>Q;
		rep(i,1,Q)cin>>qs[i].r>>qs[i].x,qs[i].idx=i,ans[i]=0;
		sort(qs+1,qs+Q+1);
		int L=0;
		rep(i,1,Q){
			while(L<qs[i].x){
				L++;
				for(auto itr:pos[L]){
					int a=itr.first,b=itr.second;
					if(a<=n)tr.add(dfl[lca(a,b)],1+(a!=b));
				}
			}
			ans[qs[i].idx]=tr.query(dfl[qs[i].r],dfr[qs[i].r]);
		}
		rep(i,1,Q){
			cout<<ans[i];
			if(i!=Q)cout<<' ';
			else cout<<endl;
		}
	}
	return 0;
}