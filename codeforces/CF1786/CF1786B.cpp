#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
pair<int,int>bb[maxn];
void solve(){
	int n,w,h;cin>>n>>w>>h;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)bb[i].first=b[i]-h,bb[i].second=b[i]+h;
	int left=-INT_MAX,right=INT_MAX;
	for(int i=1;i<=n;i++){
		left=max(left,bb[i].second-a[i]-w);
		right=min(right,bb[i].first-a[i]+w);
	}
	if(right>=left)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
