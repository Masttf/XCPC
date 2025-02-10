#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=1e5+5;
int T,n,m,fa[N],Ti,b[N];
vector<vector<int>> G,G1;
vector<int> a;
void dfsa(int x,int y){
	fa[x]=y;
	for(auto&i:G[x])if(i!=y)dfsa(i,x);
}
void dfs(int x){
	b[x]=Ti;a.pb(x);
	for(auto&i:G1[x])if(!b[i])dfs(i);
}
int main()
{
	//freopen("catarmy.in","r",stdin);
	//freopen("catarmy.out","w",stdout);
	cin>>T;
	while(T--)
{
	scanf("%d%d",&n,&m);
	vector<set<int>> s;
	G.resize(n+1),G1.resize(n+1);s.resize(n+1);
	for(int i=1;i<n;++i)
	{int x,y;scanf("%d%d",&x,&y);G[x].pb(y),G[y].pb(x);}
	dfsa(1,0);
	for(int i=1;i<=m;++i)
	{int x,y;scanf("%d%d",&x,&y);G1[x].pb(y),G1[y].pb(x);s[x].insert(y),s[y].insert(x);}
	int ans=0;
	for(Ti=1;Ti<=n;++Ti)
	if(!b[Ti]){
		dfs(Ti);
		++ans;
		for(auto i:a)
		if(b[fa[i]]==Ti&&s[i].find(fa[i])==s[i].end())
		{++ans;break;}
		a.clear();
	}
	printf("%d\n",ans);
	memset(b,0,(n+2)*4);
	G.clear(),G1.clear();
}
	return 0;
}
