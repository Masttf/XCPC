#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int f[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return true;
	f[fa]=fb;
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		string aa,bb;
		cin>>a>>aa>>b>>bb;
		if(merge(a,b))cnt++;
	}
	int c=0;
	for(int i=1;i<=n;i++){
		if(f[i]==i)c++;
	}
	cout<<cnt<<' '<<c-cnt;
	return 0;
}
