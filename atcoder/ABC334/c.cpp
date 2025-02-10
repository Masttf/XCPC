#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>cnt(n+1,2);
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		cnt[x]--;
	}
	vector<int>p;
	for(int i=1;i<=n;i++){
		if(cnt[i]==1)p.push_back(i);
	}
	int len=p.size();
	if(len%2==0){
		int ans=0;
		for(int i=0;i<len;i+=2){
			ans+=p[i+1]-p[i];
		}
		cout<<ans<<'\n';
	}else{
		vector<int>pre(n+1);
		vector<int>suf(n+5);
		for(int i=1;i<len;i++){
			pre[i]=pre[i-1];
			if(i%2==1){
				pre[i]+=p[i]-p[i-1];
			}
		}
		for(int i=len-1;i>=0;i--){
			suf[i]=suf[i+1];
			if(i%2==1){
				if(i+1!=len)suf[i]+=p[i+1]-p[i];
			}
		}
		int ans=pre[len-1];
		for(int i=0;i<len;i++){
			if(i%2==0){
				ans=min(ans,(i==0?0:pre[i-1])+suf[i+1]);
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}