#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7; 
int n,f[N],g[N],w[N],ans[N];
struct node{
	int x,y,t;
}s[N],e[N];
void add(int u){
	while(u<=n) w[u]++,u+=(u&(-u));
}
void sub(int u){
	while(u<=n) w[u]--,u+=(u&(-u));
}
int getans(int u){
	int ans=0; while(u>0) ans+=w[u],u-=(u&(-u)); return ans;
}
void solve1(int l,int r){
	if(l==r){
		s[l].x=n+1-f[l];
		s[l].y=n+1-g[l];
		s[l].t=l;
		return;
	}
	int d=(l+r)/2,t=l,f1=l,f2=d+1;
	solve1(l,d),solve1(d+1,r);
	while(f1<=d&&f2<=r){
		if(s[f1].x<=s[f2].x) ans[s[f1].t]+=getans(s[f1].y-1),e[t++]=s[f1++];
		else add(s[f2].y),e[t++]=s[f2++];
	}
	while(f1<=d) ans[s[f1].t]+=getans(s[f1].y-1),e[t++]=s[f1++];
	for(int i=d+1;i<f2;i++) sub(s[i].y);
	while(f2<=r) e[t++]=s[f2++];
	for(int i=l;i<=r;i++) s[i]=e[i];
}
void solve2(int l,int r){
	if(l==r){
		s[l].x=f[l];
		s[l].y=g[l];
		s[l].t=l;
		return;
	}
	int d=(l+r)/2,t=l,f1=l,f2=d+1;
	solve2(l,d),solve2(d+1,r);
	while(f1<=d&&f2<=r){
		if(s[f1].x<s[f2].x) add(s[f1].y),e[t++]=s[f1++];
		else ans[s[f2].t]-=getans(s[f2].y-1),e[t++]=s[f2++];
	}
	while(f2<=r) ans[s[f2].t]-=getans(s[f2].y-1),e[t++]=s[f2++];
	for(int i=l;i<f1;i++) sub(s[i].y);
	while(f1<=d) e[t++]=s[f1++];
	for(int i=l;i<=r;i++) s[i]=e[i];
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n; long long sum=1ll*n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++) cin>>g[i];
	for(int i=1;i<=n;i++) ans[i]=i-1;
	solve1(1,n);
	solve2(1,n);
	for(int i=1;i<=n;i++) sum-=1ll*ans[i]*(ans[i]-1)/2;
	cout<<sum<<endl; 
	return 0;
}
