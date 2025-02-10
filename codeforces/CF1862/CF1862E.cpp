#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,d;
	cin>>n>>m>>d;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	vector<int>pre(n+1);
	priority_queue<int,vector<int>,greater<int>>q;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			if(q.size()<m)q.push(a[i]),sum+=a[i];
			else{
				if(a[i]>q.top()){
					sum+=a[i]-q.top();
					q.pop();
					q.push(a[i]);
				}
			}
		}
		pre[i]=sum;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,pre[i]-i*d);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
