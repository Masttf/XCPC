#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int suan[maxn];
int ku[maxn];
int c1=1,c2=0;
int ans=1e9;
int n;
void dfs(int x){
	if(x==n+1)return ;
	dfs(x+1);//不选
	c1*=suan[x],c2+=ku[x];//选
	ans=min(ans,abs(c1-c2));
	dfs(x+1);
	c1/=suan[x],c2-=ku[x];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>suan[i],cin>>ku[i];
	if(n==1){
		c1=suan[1],c2=ku[1];
		ans=abs(c1-c2);
	}
	else dfs(1);
	cout<<ans;
	return 0;
}
