#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>ans;
	for(int i=1;i<=112222222233;i=i*10+1){
		for(int j=1;j<=112222222233;j=j*10+1){
			for(int k=1;k<=112222222233;k=k*10+1){
				ans.push_back(i+j+k);
			}
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans[n-1];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}