#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[2*maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++)cin>>a[i],c[++k]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],c[++k]=b[i];
	sort(c+1,c+1+k);
	for(int i=1;i<=n;i++){
		cout<<lower_bound(c+1,c+1+k,a[i])-c<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=m;i++){
		cout<<lower_bound(c+1,c+1+k,b[i])-c<<' ';
	}
	return 0;
}
