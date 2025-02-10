#include<bits/stdc++.h>
using namespace std;
int f[100005];
int find(int x){
	return f[x]==x? x: f[x]=find(f[x]); 
}
void unit(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		f[x]=y;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	int p,q;
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		unit(p,q);
	}
	for(int i=1;i<=n;i++)find(i);
	sort(f+1,f+1+n);
	int slow=1,fast=1;//维护[1，slow]为无重
	while(fast<=n){
		if(f[fast]!=f[slow]){
			f[++slow]=f[fast];
		}
		fast++;
	}
	cout<<slow;
	return 0;
}
