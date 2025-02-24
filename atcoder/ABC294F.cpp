#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+5;
pair<double,double>a[maxn];
pair<double,double>b[maxn];
double bb[maxn];
int n,m,k;
bool check(double x){
	for(int i=1;i<=m;i++)bb[i]=(1-x)*b[i].first-x*b[i].second;
	sort(bb+1,bb+1+m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		double t=(1-x)*a[i].first-x*a[i].second;
		int len=upper_bound(bb+1,bb+1+m,-t)-bb;
		cnt+=m-len+1;
	}
	return cnt+1<=k;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=m;i++)cin>>b[i].first>>b[i].second;
	double ans=-1,l=0,r=1;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	ans*=100;
	cout<<fixed<<setprecision(16)<<ans;
	return 0;
}
