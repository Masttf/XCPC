#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s1,s2;cin>>s1>>s2;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s1[i]!=s2[i])cnt++;
	}
	int res1=cnt;
	cnt=0;
	for(int i=0;i<n;i++){
		if(s1[i]!=s2[n-1-i])cnt++;
	}
	int res2=cnt;
	int ans=INT_MAX;
	if(res1==0){
		cout<<0<<'\n';
		return ;
	}
	if(res2==0){
		cout<<2<<'\n';
		return ;
	}
	if((res1-1)%2==0&&(res2-1)%2==1){
		ans=min(res1+res1-1,res2+res2-1);
	}else if((res1-1)%2==0){
		ans=min(res1+res1-1,res2+res2);
	}else if((res2-1)%2==1){
		ans=min(res1+res1,res2+res2-1);
	}else ans=min(res1+res1,res2+res2);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
