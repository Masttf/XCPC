#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn],cnt[maxn];
void solve(){
	int n;cin>>n;
	for(int i=0;i<=100;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	int ok=1;
	for(int i=1;i<=100;i++){
		if(cnt[i]){
			if(cnt[i]>cnt[i-1])ok=0;
		}
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
