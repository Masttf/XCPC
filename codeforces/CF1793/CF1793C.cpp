#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mi=1,mx=n,l=1,r=n;
	while(l<r&&((a[l]==mi||a[l]==mx)||(a[r]==mi||a[r]==mx))){
		if(a[l]==mi)mi++,l++;
		else if(a[l]==mx)mx--,l++;
		else if(a[r]==mi)mi++,r--;
		else mx--,r--;
	}
	if(r>l)cout<<l<<' '<<r<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

