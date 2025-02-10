#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[25][25][25];
int f(int a,int b,int c){
	if(a<=20&&b<=20&&c<=20&&a>=1&&b>=1&&c>=1)
		if(dp[a][b][c])return dp[a][b][c];
	if(a<=0||b<=0||c<=0)return 1;
	else if(a>20||b>20||c>20) return dp[20][20][20]=f(20,20,20);
	else if(a<b&&b<c) return dp[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
	else return dp[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
}
signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	while(a!=-1||b!=-1||c!=-1){
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,f(a,b,c));
		cin>>a>>b>>c;
	}
	return 0;
}
