#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int a[maxn][15],b[maxn][15];
void solve(){
	int n,m;cin>>n>>m;//即寻找长度相同的直接hash//以后数组里找相同直接hash
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[i][a[i][j]]=j;
		}
	}
	set<vector<int>>se[11];
	for(int i=1;i<=n;i++){
		vector<int>t;
		for(int j=1;j<=m;j++){
			t.push_back(b[i][j]);
			se[j].insert(t);
		}
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		vector<int>t;
		for(int j=1;j<=m;j++){
			t.push_back(a[i][j]);
			if(se[j].count(t))ans++;
			else break;
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
