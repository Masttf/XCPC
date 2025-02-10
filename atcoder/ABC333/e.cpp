#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>res(n+5);
	vector cnt(n+5,vector<int>());
	vector<int>vis(n+5);
	vector<int>ty(n+1);
	for(int i=1;i<=n;i++){
		int t,x;cin>>t>>x;
		ty[i]=t;
		if(t==1){
			cnt[x].push_back(i);
		}else{
			if(cnt[x].empty()){
				cout<<-1<<'\n';
				return ;
			}else{
				res[cnt[x].back()]++;
				vis[cnt[x].back()]=1;
				res[i+1]--;
				cnt[x].pop_back();
			}
		}
	}
	for(int i=1;i<=n;i++)res[i]+=res[i-1];
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,res[i]);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		if(ty[i]==1)cout<<vis[i]<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}