#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,p;cin>>n>>p;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].second;
	for(int i=1;i<=n;i++)cin>>a[i].first;

	sort(a.begin()+1,a.end());

	int ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({p,n});
	for(int i=1;i<=n;i++){
		pair<int,int>temp=q.top();
		q.pop();
		ans+=temp.first;
		if(temp.second!=1)q.push({temp.first,temp.second-1});
		q.push({a[i].first,a[i].second});
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