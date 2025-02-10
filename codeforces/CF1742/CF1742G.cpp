#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool vis[65];
void solve(){
	memset(vis,0,sizeof(vis));
	vector<int>bis[70];
	map<int,int>m;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]++;//第一位肯定是最高位
	vector<int>ans;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=60;j++){
			if((a[i]>>j)&1)bis[j].push_back(a[i]);
		}
	}
	int temp=0;
	for(int i=60;i>=0;i--){
		if(bis[i].empty()||vis[i])continue;
		int mx=0;
		for(int j=0;j<bis[i].size();j++){
			if(m[bis[i][j]]==0)continue;
			if((temp|bis[i][mx])<(temp|bis[i][j])){
				mx=j;
			}
		}
		temp|=bis[i][mx];
		ans.push_back(bis[i][mx]);
		m[bis[i][mx]]--;
		for(int j=0;j<=i;j++){
			if(bis[i][mx]>>j&1)vis[j]=1;
		}
	}
	for(auto x=m.begin();x!=m.end();x++){
		while(x->second!=0){
			ans.push_back(x->first);
			x->second--;
		}
	}
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
