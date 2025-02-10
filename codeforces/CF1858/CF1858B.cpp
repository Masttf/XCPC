#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,d;cin>>n>>m>>d;
	vector<int>s(m+5);
	for(int i=1;i<=m;i++)cin>>s[i];
	vector<int>pre(m+5);
	int l=1;
	for(int i=1;i<=m;i++){
		if(i==1){
			if(s[i]==1)pre[i]=1;
			else{
				pre[i]=(s[i]-1-1)/d+2;
			}
		}else{
			pre[i]+=pre[i-1];
			pre[i]+=(s[i]-1-l)/d+1;
		}
		l=s[i];
	}
	int ans=pre[m]-pre[2]+(s[2]-1-1)/d+2+(n-s[m])/d;
	ans=min(ans,pre[m-1]+(n-s[m-1])/d);
	for(int i=3;i<=m;i++){
		int temp=pre[i-2]+pre[m]-pre[i]+(s[i]-1-s[i-2])/d+1+(n-s[m])/d;
		ans=min(ans,temp);
	}
	int sum=0;
	if(ans==pre[m]-pre[2]+(s[2]-1-1)/d+2+(n-s[m])/d)sum++;
	if(ans==pre[m-1]+(n-s[m-1])/d)sum++;
	for(int i=3;i<=m;i++){
		int temp=pre[i-2]+pre[m]-pre[i]+(s[i]-1-s[i-2])/d+1+(n-s[m])/d;
		if(ans==temp)sum++;
	}
	cout<<ans<<' '<<sum<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
