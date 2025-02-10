#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b;cin>>a>>b;//2的使用频率如果大于1则2更好
	int ans=LONG_LONG_MAX;
	int len=1;
	for(int i=1;i<=100000;i++){
		ans=min(ans,(a+len-1)/len+(b+len-1)/len+len-1);
		len++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
