#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector a(n+1,vector<int>(n+1));
	vector<int>mx(n+1);
	vector<int>res(n+1);
	vector<int>cnt(30);
	for(int i=1;i<=n;i++){
		cnt.assign(30,0);
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			a[i][j]=x;
			for(int k=29;k>=0;k--){
				if(a[i][j]>>k&1)cnt[k]++;
			}
		}
		for(int k=29;k>=0;k--){
			if(cnt[k]==n-1)res[i]+=1<<k;
		}
	}
	int ok=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i][j]!=(res[i]|res[j]))ok=0;
		}
	}
	if(ok){
		cout<<"Yes\n";
		for(int i=1;i<=n;i++)cout<<res[i]<<" \n"[i==n];
	}
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}