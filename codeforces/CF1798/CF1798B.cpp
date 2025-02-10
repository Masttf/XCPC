#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50005;
int num[maxn];
int ans[maxn];
int cnt[maxn];
vector<int>a[maxn];
void solve(){
	int m,n;cin>>m;
	for(int i=1;i<=m;i++)cnt[i]=0,ans[i]=0,a[i].clear();
	for(int i=1;i<=m;i++){
		int n;cin>>n;
		num[i]=n;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			a[i].push_back(x);
			cnt[x]++;
		}
	}
	int flag=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<num[i];j++){
			cnt[a[i][j]]--;
			if(cnt[a[i][j]]==0)ans[i]=a[i][j];
		}
		if(ans[i]==0)flag=0;

	}
	if(flag){
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}else cout<<-1<<'\n';
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
