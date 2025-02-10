#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int c1[maxn];
bool vis[30];
void solve(){
	for(int i=0;i<30;i++)vis[i]=0;
	int n;cin>>n;
	string s;cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(!vis[s[i]-'a']){
			cnt++;
			vis[s[i]-'a']=1;
		}
		c1[i]=cnt;
	}
	cnt=0;
	int ans=0;
	for(int i=0;i<30;i++)vis[i]=0;
	for(int i=n-1;i>=0;i--){
		if(!vis[s[i]-'a']){
			cnt++;
			vis[s[i]-'a']=1;
		}
		if(i==0)ans=max(ans,cnt);
		else ans=max(ans,cnt+c1[i-1]);
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
