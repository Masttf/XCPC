#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int l[maxn],r[maxn];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>l[i];
	for(int i=1;i<=n;i++)cin>>r[i];
	int sum=0;
	for(int i=1;i<=n;i++)sum+=r[i]-l[i]+1;
	if(sum<k){
		cout<<-1<<'\n';
		return ;
	}
	priority_queue<int,vector<int>,greater<int>>q;
	sum=0;
	int ans=INT_MAX;
	for(int i=1;i<=n;i++){//每次这个区间必选然后看要吃掉几个区间
		sum+=r[i]-l[i]+1;
		q.push(r[i]-l[i]+1);
		while(sum>=k){
			int t=k-(sum-r[i]+l[i]-1)+l[i]-1;
			int sz=q.size();
			ans=min(ans,t+2*sz);
			sum-=q.top();
			q.pop();
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
