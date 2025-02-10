#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int f[maxn][5];
int d;
void traverse(int root,int deep){
	d=max(d,deep);
	if(f[root][1]!=0)traverse(f[root][1],deep+1);
	if(f[root][2]!=0)traverse(f[root][2],deep+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i][1]>>f[i][2];
	traverse(1,1);
	cout<<d;
	return 0;
}
