#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	if(n==1){
		cout<<abs(a[2]-a[1])<<'\n';
		return ;
	}
	int res=LONG_LONG_MAX;
	if(n==2){
		int sum=0;
		for(int i=1;i<=2*n;i++){
			sum+=abs(a[i]-2);
		}
		res=min(res,sum);
	}
	if(n%2==0){
		int sum=0;
		for(int i=1;i<=2*n;i++){
			sum+=abs(a[i]+1);
		}
		for(int i=1;i<=2*n;i++){
			res=min(res,sum-abs(a[i]+1)+abs(a[i]-n));
		}
	}
	int sum=0;
	for(int i=1;i<=2*n;i++){
		sum+=abs(a[i]);
	}
	res=min(res,sum);
	cout<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
