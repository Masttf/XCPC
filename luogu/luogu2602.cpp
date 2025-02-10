#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int cnta[maxn],cntb[maxn],ten[15],dp[maxn],num[15];
void init(){//初始化
	ten[0]=1;
	for(int i=1;i<=15;i++){
		dp[i]=dp[i-1]*10+ten[i-1];
		ten[i]=ten[i-1]*10;
	}
	return ;
}
void solve(int x,int* cnt){
	int len=0;
	while(x){
		num[++len]=x%10;
		x/=10;
	}
	for(int i=len;i>=1;i--){
		for(int j=0;j<=9;j++)cnt[j]+=dp[i-1]*num[i];//以324为例，先算最高位三，这个时候十位有三个00-99所以先加上这个数在这上面的个数
		for(int j=0;j<num[i];j++)cnt[j]+=ten[i-1];//然后算百位出现的数字
		int sum=0;
		for(int j=i-1;j>=1;j--)sum=sum*10+num[j];//最后算最高位 3多出现的次数
		cnt[num[i]]+=sum+1;
		cnt[0]-=ten[i-1];//去掉前导0
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;cin>>a>>b;
	init();
	solve(a-1,cnta),solve(b,cntb);
	for(int i=0;i<=9;i++)cout<<cntb[i]-cnta[i]<<' ';
	return 0;
}
