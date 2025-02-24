#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(3*n+1);
	vector<int>cnt(n+1);
	vector<pair<int,int>>ans(n+1);
	for(int i=1;i<=n;i++)ans[i].second=i;
	for(int i=1;i<=3*n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]==2){
			ans[a[i]].first=i;
		}
	}
	sort(ans.begin()+1,ans.end());
	for(int i=1;i<=n;i++)cout<<ans[i].second<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}