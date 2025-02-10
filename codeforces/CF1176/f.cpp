#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector dp(10,vector<int>(n+1,-LONG_LONG_MAX));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<int>p1;
		int mx2=0;
		int mx3=0;
		for(int j=1;j<=k;j++){
			int c,w;cin>>c>>w;
			if(c==1)p1.push_back(w);
			else if(c==2)mx2=max(mx2,w);
			else mx3=max(mx3,w);
		}
		sort(p1.begin(),p1.end(),greater<int>());

		for(int j=0;j<=9;j++)dp[j][i]=dp[j][i-1];
		for(int j=0;j<=9;j++){

			if(p1.size()>=3){
				int sum=p1[0]+p1[1]+p1[2];
				if(j<=2)sum+=p1[0];
				dp[j][i]=max(dp[j][i],dp[(j-3+10)%10][i-1]+sum);
			}
			int res=-1;
			int res2=-1;
			if(p1.size()>=2)res=max(res,p1[0]+p1[1]),res2=max(res2,p1[0]*2+p1[1]);
			if(mx2&&p1.size()>=1)res=max(res,p1[0]+mx2),res2=max(res2,max(mx2,p1[0])*2+min(mx2,p1[0]));

			if(res!=-1){
				if(j<=1)res=res2;
				dp[j][i]=max(dp[j][i],dp[(j-2+10)%10][i-1]+res);
			}

			res=-1;
			if(p1.size()>=1)res=max(res,p1[0]);
			if(mx2)res=max(res,mx2);
			if(mx3)res=max(res,mx3);
			if(res!=-1){
				if(j==0)res*=2;
				dp[j][i]=max(dp[j][i],dp[(j-1+10)%10][i-1]+res);
			}
		}
	}
	int mx=0;
	
	for(int i=0;i<=9;i++)mx=max(mx,dp[i][n]);
	cout<<mx<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}