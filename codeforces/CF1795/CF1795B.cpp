#include<bits/stdc++.h>
#define int long long
using namespace std;
int deff[55];
void solve(){
	memset(deff,0,sizeof (deff));
	int n,k;cin>>n>>k;
	int l,r;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		if(l<=k&&k<=r){
			deff[l]++;
			deff[r+1]--;
		}
	}
	for(int i=1;i<=50;i++)deff[i]+=deff[i-1];
	int cnt=0,mx=0;
	for(int i=1;i<=50;i++){
		if(deff[i]==deff[k])cnt++;
		mx=max(mx,deff[i]);
	}
	if(mx==deff[k]&&cnt==1)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
