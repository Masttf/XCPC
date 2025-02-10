#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].second>>a[i].first;
	sort(a.begin()+1,a.end());
	vector<int>p(65);
	auto insert = [&](int x)->bool{
		for(int i=63;i>=0;i--){
			if(x>>i&1){
				if(p[i])x^=p[i];
				else{
					p[i]=x;
					return true;
				}
			}
		}
		return false;
	};
	int sum=0;
	for(int i=n;i>=1;i--){
		if(insert(a[i].second))sum+=a[i].first;
	}
	cout<<sum<<'\n';
	return 0;
}
