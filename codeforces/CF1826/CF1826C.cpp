#include<bits/stdc++.h>
#define int long long
using namespace std;
bool isprim(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
void solve(){
	int n,m;cin>>n>>m;
	if(m==1||n==1)cout<<"YES\n";
	else{
		if(n%2==0||m>=n)cout<<"NO\n";
		else{
			if(isprim(n))cout<<"YES\n";
			else{
				int res;
				for(int i=2;i*i<=n;i++){
					if(n%i==0){
						res=i;
						break;
					}
				}
				if(res>m)cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
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
