#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	if(a[n]==a[1])cout<<-1<<'\n';
	else{
		vector<int>tem1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[1])tem1.push_back(a[i]);
		}
		vector<int>tem2;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[1])tem2.push_back(a[i]);
		}
		cout<<tem1.size()<<' '<<tem2.size()<<'\n';
		for(auto x:tem1)cout<<x<<' ';
		cout<<'\n';
		for(auto x:tem2)cout<<x<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
