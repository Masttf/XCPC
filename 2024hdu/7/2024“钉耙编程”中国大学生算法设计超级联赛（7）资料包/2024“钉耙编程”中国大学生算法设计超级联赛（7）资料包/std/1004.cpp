#include<bits/stdc++.h>
using namespace std;
vector<int> E[100010];
int n,s,r1,r2,len,id,dis[100010];
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	for(auto v:E[u])
	{
		if(v!=fa)
			dfs(v,u);
	}
	return;
}
int main()
{
	int i,u,v,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&s,&r1,&r2);
		for(i=1;i<=n-1;++i)
		{
			scanf("%d %d",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		dfs(1,0);
		id=1;
		for(i=2;i<=n;++i)
		{
			if(dis[i]>dis[id])
				id=i;
		}
		dfs(id,0);
		len=0;
		for(i=1;i<=n;++i)
			len=max(len,dis[i]);
		if(r1*2+1>=len)
			printf("Kangaroo_Splay\n");
		else
		{
			if(r1*2>=r2)
				printf("Kangaroo_Splay\n");
			else
				printf("General_Kangaroo\n");
		}
		for(i=1;i<=n;++i)
			E[i].clear();
	}
	return 0;
}
