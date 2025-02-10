#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];//在零之前要有一张牌
	int ans=0;
	priority_queue<int>q;
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			q.push(a[i]);
			continue;
		}
		if(!q.empty()){
			ans+=q.top();
			q.pop();
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
