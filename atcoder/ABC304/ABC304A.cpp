#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<pair<string,int>>a(n);
	for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
	int p=-1;
	for(int i=0;i<n;i++){
		if(p==-1||a[i].second<a[p].second)p=i;
	}
	for(int i=0;i<n;i++){
		int res=(p+i)%n;
		cout<<a[res].first<<'\n';
	}
	return 0;
}
