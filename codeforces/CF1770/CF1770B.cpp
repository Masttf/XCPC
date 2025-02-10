#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	if(k==1||k==n){
		for(int i=1;i<=n;i++)cout<<i<<' ';
	}else{//特殊例子交错输出
		int flag=1;
		int mx=n,mi=1;
		while(n--){
			if(flag)cout<<mx<<' ',mx--;
			else cout<<mi<<' ',mi++;
			flag=1-flag;
		}
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
