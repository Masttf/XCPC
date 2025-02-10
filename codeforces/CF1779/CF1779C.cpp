#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int m,n;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0,cnt=0;
	priority_queue<int>qq;
	for(int i=m;i>=2;i--){
		sum+=a[i];
		qq.push(a[i]);
		if(sum>0){
			sum-=2*abs(qq.top());
			qq.pop();
			cnt++;
		}
	}
	sum=0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=m+1;i<=n;i++){
		sum+=a[i];
		q.push(a[i]);
		if(sum<0){
			sum+=2*abs(q.top());
			q.pop();
			cnt++;
		}
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
