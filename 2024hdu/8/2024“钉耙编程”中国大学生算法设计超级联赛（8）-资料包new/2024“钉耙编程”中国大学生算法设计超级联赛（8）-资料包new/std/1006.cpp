#include<bits/stdc++.h>
using namespace std;
vector<int>fa[100000];
int cnt[300000],ans[300000];
int findfa(int x,int t){
	if(fa[x][t]==x)return x;
	int f=findfa(fa[x][t],t);
	fa[x][t]=f;
	return f;
}
void combine(int x,int y,int t){
	x=findfa(x,t);
	y=findfa(y,t);
	fa[x][t]=y;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,m,c,i,j,u,v,l,r,mid;;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>m;
		c=m/(n-1);
		for(i=0;i<n;i++)
		{
			for(j=0;j<c;j++)fa[i].push_back(i);
		}
		for(i=0;i<c;i++)cnt[i]=0;
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			u--;
			v--;
			l=-1;
			r=c;
			while(r-l>1)
			{
				mid=(l+r+1)/2;
				if(findfa(u,mid)==findfa(v,mid))l=mid;
				else r=mid;
			}
			if(r<c)
			{
				combine(u,v,r);
				cnt[r]++;
			}
			ans[i]=r;
		}
		for(i=0;i<m;i++)
		{
			if(ans[i]==c||cnt[ans[i]]!=n-1)cout<<"-1";
			else cout<<ans[i]+1;
			if(i<m-1)cout<<' ';
			else cout<<'\n';
		}
		for(i=0;i<n;i++)fa[i].clear();
	}
	return 0;
}
