#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>pw(n+1);
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*2%mod;
	}
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	vector<int>mx(n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=i;j++){
			if(i%j==0){
				int x=j;
				int y=i/j;
				mx[x]=max(mx[x],a[i]);
				mx[y]=max(mx[y],a[i]);
			}
		}
	}

	// for(int i=1;i<=n;i++){
	// 	cout<<mx[i]<<" \n"[i==n];
	// }
	sort(mx.begin()+1,mx.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=mx[i]*pw[i-1]%mod;
		ans%=mod;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}