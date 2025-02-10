#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	map<int,int>p;
	int n,m,d;cin>>n>>m>>d;
	int x;
	for(int i=1;i<=n;i++)cin>>x,p[x]=i;
	for(int i=1;i<=m;i++)cin>>a[i];
	int flag=0; 
	int cnt=INT_MAX;
	for(int i=1;i<m;i++){
		int x1=p[a[i]],x2=p[a[i+1]];
		if(x1<x2&&x2<=x1+d){
			if(1+d>=n)cnt=min(cnt,abs(x1-x2));
			else cnt=min(cnt,min(abs(x1+d+1-x2),abs(x1-x2)));
		}else flag=1;
	}
	if(flag)cout<<0<<'\n';
	else cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
