#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int ok=0;
	vector<int>a(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)ok=1;
		if(a[i]<0)cnt++;
	}
	if(ok){
		cout<<0<<'\n';
	}else{
		
		if(cnt==0){
			cout<<1<<'\n';
			cout<<1<<' '<<0<<'\n';
		}else if(cnt%2==1){
			cout<<0<<'\n';
		}else{
			cout<<1<<'\n';
			cout<<1<<' '<<0<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}