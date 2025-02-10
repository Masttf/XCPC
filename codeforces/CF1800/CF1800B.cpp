#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1[30],c2[30];
void solve(){
	for(int i=0;i<30;i++)c1[i]=0,c2[i]=0;
	int n,k;cin>>n>>k;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]>='a'&&s[i]<='z')c1[s[i]-'a']++;
		else c2[s[i]-'A']++;
	}
	int ans=0;
	for(int i=0;i<27;i++){
		int t=abs(c1[i]-c2[i]);
		t/=2;
		ans+=min(k,t);
		k-=t;
		if(k<0)k=0;
		ans+=min(c1[i],c2[i]);
	}
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
