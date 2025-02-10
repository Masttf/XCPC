#include<bits/stdc++.h>
#define int long long
using namespace std;//__gcd肯定越求越小
int a[105];
void solve(){
	int n;cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(flag)cout<<"yes\n";
	else{
		int f=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=__gcd(a[i],a[j]);
				if(t<=2)f=1;
			}
		}
		if(f)cout<<"yes\n";
		else cout<<"no\n";
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
