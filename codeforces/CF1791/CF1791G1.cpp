#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){//考虑一下每个点应该给谁吃
	int n,c;cin>>n>>c;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++){//前一半的点应该从0开始吃，后一半的点应该从n+1开始吃
		cin>>a[i];//所以前一半最少吃一个
		q.push(i+a[i]);
	}
	int ans=0;
	while(c){
		if(q.empty()||q.top()>c)break;
		c-=q.top();
		q.pop();
		ans++;
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
