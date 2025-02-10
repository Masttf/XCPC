#include<bits/stdc++.h>
using namespace std;
int r1[25],r2[25],r3[25],r4[25];
int mx=0;
int a=999999999,b=999999999,c=9999999,d=99999999;
void dfs1(int res[],int x,int len,int sum1,int sum2){
	if(x==len+1){
		int ans;
		ans=max(sum1,sum2);
		a=min(a,ans);
		return ;
	}
	sum1+=res[x];
	dfs1(res,x+1,len,sum1,sum2);
	sum1-=res[x];
	sum2+=res[x];
	dfs1(res,x+1,len,sum1,sum2);
	sum2-=res[x];
	return ;
}
void dfs2(int res[],int x,int len,int sum1,int sum2){
	if(x==len+1){
		int ans;
		ans=max(sum1,sum2);
		b=min(b,ans);
		return ;
	}
	sum1+=res[x];
	dfs2(res,x+1,len,sum1,sum2);
	sum1-=res[x];
	sum2+=res[x];
	dfs2(res,x+1,len,sum1,sum2);
	sum2-=res[x];
	return ;
}
void dfs3(int res[],int x,int len,int sum1,int sum2){
	if(x==len+1){
		int ans;
		ans=max(sum1,sum2);
		c=min(c,ans);
		return ;
	}
	sum1+=res[x];
	dfs3(res,x+1,len,sum1,sum2);
	sum1-=res[x];
	sum2+=res[x];
	dfs3(res,x+1,len,sum1,sum2);
	sum2-=res[x];
	return ;
}
void dfs4(int res[],int x,int len,int sum1,int sum2){
	if(x==len+1){
		int ans;
		ans=max(sum1,sum2);
		d=min(d,ans);
		return ;
	}
	sum1+=res[x];
	dfs4(res,x+1,len,sum1,sum2);
	sum1-=res[x];
	sum2+=res[x];
	dfs4(res,x+1,len,sum1,sum2);
	sum2-=res[x];
	return ;
}
int main(){
	int s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	int r1[25]={0},r2[25]={0},r3[25]={0},r4[25]={0};
	for(int i=1;i<=s1;i++)cin>>r1[i];
	for(int i=1;i<=s2;i++)cin>>r2[i];
	for(int i=1;i<=s3;i++)cin>>r3[i];
	for(int i=1;i<=s4;i++)cin>>r4[i];
	dfs1(r1,1,s1,0,0);
	dfs2(r2,1,s2,0,0);
	dfs3(r3,1,s3,0,0);
	dfs4(r4,1,s4,0,0);
	cout<<a+b+c+d;
	return 0;
}
