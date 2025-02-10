#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	int ok=0;
	vector<string>res;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		res.push_back(s);
	}
	string ans="vika";
	auto get = [&](auto get,int s,int p)->bool{
		for(int i=s;i<m;i++){
			int temp=0;
			for(int j=0;j<n;j++){
				if(res[j][i]==ans[p])temp=1;
			}
			if(!temp)continue;
			if(p==3)return true;
			else return get(get,i+1,p+1);
		}
		return false;
	};
	ok=get(get,0,0);
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
