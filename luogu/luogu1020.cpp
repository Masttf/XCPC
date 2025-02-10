#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+5;
int res[maxn],n=1;
int dp[maxn],ans=1,temp[maxn],cnt=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>res[n]){n++;}
	n--;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(res[i]<=res[j])dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
	temp[++cnt]=res[1];
	for(int i=2;i<=n;i++){
		int p=lower_bound(temp+1,temp+1+cnt,res[i])-temp;
		if(p==cnt+1){
			temp[++cnt]=res[i];
		}else{
			temp[p]=res[i];
		}
	}
	cout<<cnt;
	return 0;
}
