//带权值的并查集
//d[]数组表示该点到父节点的距离，计算方式利用向量的计数方式
#include<bits/stdc++.h>
using namespace std;
const int maxn=30005;
int f[maxn],d[maxn],sz[maxn];//sz表示该节点下有多少个节点
int find(int x){
	if(f[x]!=x){
		int t=f[x];//记录父节点
		f[x]=find(f[x]);
		d[x]+=d[t];
	}
	return f[x];
}
void unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	d[fa]=sz[fb]+d[fb];
	sz[fb]+=sz[fa];
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<maxn;i++)f[i]=i,sz[i]=1;
	int t;cin>>t;
	char ty;
	int a,b;
	for(int i=1;i<=t;i++){
		cin>>ty>>a>>b;
		if(ty=='M'){
			unit(a,b);
		}else{
			if(find(a)==find(b)){
				cout<<abs(d[b]-d[a])-1<<'\n';
			}else cout<<-1<<'\n';
		}
	}
	return 0;
}
