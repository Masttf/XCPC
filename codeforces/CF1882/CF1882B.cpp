#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	set<int>s;
	vector<vector<int>>a(n+1,vector<int>());
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int y;cin>>y;
			a[i].push_back(y);
			s.insert(y);
		}
	}
	int ans=0;
	for(auto it=s.begin();it!=s.end();it++){
		int rt=*it;
		set<int>temp;
		for(int i=1;i<=n;i++){
			int ok=1;
			for(auto x:a[i]){
				if(x==rt){
					ok=0;
					break;
				}
			}
			if(ok){
				for(auto x:a[i])temp.insert(x);
			}
		}
		ans=max(ans,(long long)temp.size());
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
