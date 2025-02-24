#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[15];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	set<int>s;
	s.insert(0);
	for(int i=1;i<=k;i++){
		int it=*s.begin();
		s.erase(s.begin());
		for(int i=1;i<=n;i++){
			s.insert(a[i]+it);//纯暴力,每次拿出最小的数,怎么判断这个再把其他加权一下扔进去,为什么要把这个和所有数的加值都扔进去,原因是你不知道这个数的加值会不会影响你后面的
		}
	}
	cout<<*s.begin();
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
