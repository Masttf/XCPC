//每个数的两条边应该出现在不同的集合，所以组成的图应该没有奇环
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>res[maxn];
int n,color[maxn],ok;
void traverse(int f,int c){
	color[f]=c;
	for(auto x:res[f]){
		if(color[f]==color[x]){
			ok=0;return ;
		}
		else if(!color[x])traverse(x,3-c);
	}
	return ;
}
void solve(){
	ok=1;
	cin>>n;
	for(int i=1;i<=n;i++)res[i].clear(),color[i]=0;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		res[a].push_back(b);
		res[b].push_back(a);
		if(a==b||res[a].size()>2||res[b].size()>2)ok=0;
	}
	for(int i=1;i<=n;i++){
		if(color[i])continue;
		traverse(i,1);
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
