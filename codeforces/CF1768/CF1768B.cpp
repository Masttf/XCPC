#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
void solve(){
	int n,k;cin>>n>>k;
	int start=1;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		if(start==res[i])start++;
	}
	start--;
	if(start==n)cout<<0<<'\n';
	else{
		if((n-start)%k==0)cout<<(n-start)/k<<'\n';
		else cout<<(n-start)/k+1<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
