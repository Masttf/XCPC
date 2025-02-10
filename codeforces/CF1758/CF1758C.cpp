#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,x;cin>>n>>x;
	if(n%x==0){
		vector<int>ans;
		ans.push_back(x);
		for(int i=2;i<=n-1;i++)ans.push_back(i);
		ans.push_back(1);
		vector<int>p;
		int t=n/x;//质因数分解
		for(int i=2;i<=t/i;i++){
			while(t%i==0){
				p.push_back(i);
				t/=i;
			}	
		}
		if(t>1)p.push_back(t);
		int s=x;
		for(auto k:p){
			ans[s-1]=s*k;
			s*=k;
		}
		for(int i=0;i<n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
