#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10;
string a[maxn];
int n,m;
bool vis[maxn];
vector<int>track;
int flag=0;
bool check(){
	int ok=1;
	for(int i=0;i<n-1;i++){
		int cnt=0;
		for(int j=0;j<m;j++){
			if(a[track[i]][j]!=a[track[i+1]][j])cnt++;
		}
		if(cnt!=1)ok=0;
	}
	return ok;
}
void dfs(){
	if(flag)return ;
	if(track.size()==n){
		if(check())flag=1;
		return ;
	}
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		vis[i]=1;
		track.push_back(i);
		dfs();
		vis[i]=0;
		track.pop_back();
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs();
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}
