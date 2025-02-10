#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int>res;
	for(int i=0;i<=n/2-1;i++){
		if(s[i]!=s[n-i-1])res.push_back(n-i-1);
	}
	int flag=1;
	if(!res.empty()&&res.size()>1){
		sort(res.begin(),res.end());
		for(int i=0;i<res.size()-1;i++){
			if(res[i]!=res[i+1]-1){
				flag=0;
				break;
			}
		}
	}
	if(flag)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
