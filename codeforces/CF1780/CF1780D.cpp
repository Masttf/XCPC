#include<bits/stdc++.h>
#define int long long
using namespace std;
int ask(int x){
	cout<<"- "<<x<<endl;
	if(x==-1){
		exit(0);
	}
	cin>>x;
	return x;
}
void solve(){
	int cnt;cin>>cnt;//每减1如果位数增加k说明这位是1<<(k-cnt+1)上是1，那么下次要减要这些多余的所以合并
	int ans=0;
	int was=0;
	while(cnt){
		int nw=ask(was+1);
		int b=nw-cnt+1;
		ans+=(1<<b);
		was=(1<<b)-1;
		cnt=nw-b;
	}
	cout<<"! "<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
