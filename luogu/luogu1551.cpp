#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int f[maxn];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void unit(int x,int y){
	if(find(x)!=find(y)){
		f[find(x)]=y;
	}
	return ;
}
int main(){
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=n;i++)f[i]=i;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		unit(x,y);
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(find(x)==find(y))cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
	return 0;
}
