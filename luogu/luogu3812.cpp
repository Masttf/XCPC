#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>p(65);
	auto insert = [&](int x)->bool{
		for(int i=63;i>=0;i--){
			if((x>>i)&1){
				if(p[i])x^=p[i];
				else{
					p[i]=x;
					return true;
				}
			}
		}
		return false;
	};
	for(int i=1;i<=n;i++)insert(a[i]);
	int ans=0;
	for(int i=63;i>=0;i--){
		if((ans^p[i])>ans)ans^=p[i];
	}
	cout<<ans<<'\n';
	return 0;
}
