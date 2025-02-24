#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>prim;
bool vis[107];
int n,p;
void init(){
	for(int i=2;i<=107;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<=105;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	return ;
}
void dfs(vector<int>&a,int sz,int num){
	for(int i=0;i<sz;i++){
		int tem=a[i];
		while(1){
			tem*=num;
			if(tem>n)break;
			a.push_back(tem);
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>p;
	init();
	int k=upper_bound(prim.begin(),prim.end(),p)-prim.begin()-1;
	vector<int>res1={1};
	vector<int>res2={1};
	for(int i=0;i<=k;i++){
		if(res1.size()<res2.size())dfs(res1,res1.size(),prim[i]);
		else dfs(res2,res2.size(),prim[i]);
	}
	sort(res2.begin(),res2.end());
	int ans=0;
	for(auto x:res1){
		ans+=upper_bound(res2.begin(),res2.end(),n/x)-res2.begin();
	}
	cout<<ans<<'\n';
	return 0;
}
