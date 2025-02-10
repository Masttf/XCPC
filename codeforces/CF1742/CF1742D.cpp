#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]=i;
	int mx=-1;
	for(auto x=m.begin();x!=m.end();x++){
		for(auto k=m.begin();k!=m.end();k++){
			if(__gcd(x->first,k->first)==1)mx=max(mx,x->second+k->second);
		}
	}
	cout<<mx<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
