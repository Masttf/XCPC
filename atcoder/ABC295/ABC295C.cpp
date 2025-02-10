#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		m[x]++;
	}
	int cnt=0;
	for(auto it=m.begin();it!=m.end();it++){
		cnt+=it->second/2;
	}
	cout<<cnt;
	return 0;
}
