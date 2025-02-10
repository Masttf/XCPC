#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=30;
int a[maxn],b[maxn];//每段用同一个字母填，然后多的用abc轮换
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>b[i];
	int ok=1;
	for(int i=1;i<=k;i++){
		if(i!=1){
			if(b[i]-b[i-1]>a[i]-a[i-1])ok=0;
		}
		if(b[i]>a[i])ok=0;
	}
	if(!ok){
		cout<<"NO\n";
		return ;
	}
	int now=0,r=3;
	string ans="";
	for(int i=1;i<=b[1]-2;i++)ans+='a';
	ans+="bc";
	for(int i=1;i<=a[1]-b[1];i++){
		ans+=(char)(now+'a');
		now++;
		now%=3;
	}
	for(int i=2;i<=k;i++){
		ok=0;
		for(int j=1;j<=b[i]-b[i-1];j++){
			ok=1;
			ans+=(char)(r+'a');
		}
		if(ok)r++;
		for(int j=1;j<=a[i]-a[i-1]-(b[i]-b[i-1]);j++){
			ans+=char(now+'a');
			now++;
			now%=3;
		}
	}
	cout<<"YES\n";
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
