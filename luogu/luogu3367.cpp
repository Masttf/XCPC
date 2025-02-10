#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int f[maxn];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void unit(int x,int y){
	if(find(x)!=find(y)){
		f[find(x)]=y;
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	int z,x,y;
	for(int i=1;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1){
			unit(x,y);
		}else{
			if(find(x)==find(y))cout<<'Y'<<'\n';
			else cout<<'N'<<'\n';
		}
	}
	return 0;
}
