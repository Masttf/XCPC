#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
int n,m;
int f[maxn],ll[maxn],rr[maxn];
pair<int,int>a[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	ll[fb]=min(ll[fa],ll[fb]);
	rr[fb]=max(rr[fa],rr[fb]);
	return ;
}
double js(int x,int y,int p,int q){
	return sqrt((x-p)*(x-p)+(y-q)*(y-q));
}
bool check(double x){
	for(int i=1;i<=m;i++){
		f[i]=i;
		ll[i]=a[i].first-x;
		rr[i]=a[i].first+x;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(js(a[i].first,a[i].second,a[j].first,a[j].second)<=2*x)merge(i,j);
		}
	}
	int flag=0;
	for(int i=1;i<=m;i++)find(i);
	for(int i=1;i<=m;i++){
		if(f[i]==i&&ll[i]<=0&&rr[i]>=n)flag=1;
	}
	return flag;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].first>>a[i].second;
	}
	double ans=-1,l=0.0,r=n;
	for(int i=1;i<=100;i++){//判断0号与n号连不连通 
		double mid=(l+r)/2;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
