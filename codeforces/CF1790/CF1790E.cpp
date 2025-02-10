#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
void solve(){
	int x;cin>>x;
	if(x%2!=0)cout<<-1<<'\n';
	else{//即x/2能否由x二进制0的数拼起来
		int a=x/2;
		if((a&x)==0){
			cout<<x+a<<' '<<a<<'\n';
		}else cout<<-1<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
