#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	int flag=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int p=lower_bound(a+1,a+1+n,a[i]-x)-a;
		if(a[p]==a[i]-x)flag=1;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}

