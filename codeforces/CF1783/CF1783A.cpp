#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int res[maxn];
bool vis[55];
void solve(){
	memset(vis,0,sizeof(vis));
	vector<int>track;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];
	sort(res+1,res+1+n);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(sum!=res[j]&&!vis[j]){
				sum+=res[j];
				vis[j]=1;
				track.push_back(res[j]);
			}
		}
	}
	if(track.size()<n)cout<<"NO"<<'\n';
	else{
		cout<<"YES"<<'\n';
		for(int i=0;i<n;i++){
			cout<<track[i]<<' ';
		}
		cout<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
