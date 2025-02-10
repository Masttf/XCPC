//把，每个二进制位统计，如果对于某个数他的二进制位都出现两次说明会有一个组合非它不变
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>res[maxn];
void solve(){
	map<int,int>cnt;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		res[i].clear();
		int k;cin>>k;
		while(k--){
			int x;cin>>x;
			cnt[x]++;
			res[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		int ok=1;
		for(int j=0;j<res[i].size();j++){
			if(cnt[res[i][j]]==1){
				ok=0;break;
			}
		}
		if(ok){
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
