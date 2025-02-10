#include<bits/stdc++.h>//观察到性质相同奇偶位可以传递加值
#define int long long//所以变成 0,0,0,0,c1,c2,如果n为奇一定可以
//两个加，两减，如果假设a b c 三个数 先让b c加1 然后a b减1 就实现了b不变a-1，c+1
using namespace std;
const int maxn=3e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n%2!=0)cout<<"YES\n";
	else{
		int c1=0,c2=0;
		for(int i=1;i<=n;i++){
			if(i%2==0)c2+=a[i];
			else c1+=a[i];
		}
		if(c2>=c1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
