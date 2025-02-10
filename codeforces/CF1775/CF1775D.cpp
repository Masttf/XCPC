#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int pre[maxn],a[maxn];
int vis[maxn],v2[maxn],v1[maxn];
vector<int>g[maxn];
queue<int>q;
void pl(int s,int t){
	if(s==t){cout<<s<<' ';return ;}
	pl(s,pre[t]);
	cout<<t<<' ';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),vis[a[i]]=i;
	for(int i=2;i<=mx;i++){
		if(v1[i])continue;
		for(int j=i*2;j<=mx;j+=i){
			v1[j]=1;
			if(vis[i]&&vis[j]){
				g[vis[j]].push_back(vis[i]);
				g[vis[i]].push_back(vis[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto x:g[i])cout<<x<<' ';
		cout<<'\n';
	}
	int s,ed;cin>>s>>ed;
//	q.push(s);
//	int cnt=1;
//	int flag=0;
//	while(!q.empty()){
//		int root=q.front();q.pop();
//		for(auto x:g[root]){
//			if(vis[x])continue;
//			vis[x]=1;
//			q.push(x);
//			pre[x]=root;
//			if(x==ed){
//				flag=1;break;	
//			}
//		}
//		if(flag)break;
//		cnt++;
//	}
//	cout<<cnt<<'\n';
//	pl(s,ed);
	return 0;
}
