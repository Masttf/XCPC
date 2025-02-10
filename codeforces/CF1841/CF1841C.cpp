#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int p[]={1,10,100,1000,10000};
int a[maxn];
int mx[maxn];
int sum[maxn][10];
int cnt[maxn][10];
int post[maxn];
void solve(){
	string s;cin>>s;
	int n=s.size();
	for(int i=0;i<=n+1;i++)post[i]=0,mx[i]=0;
	for(int j=0;j<5;j++) for(int i=0;i<=n+1;i++)sum[i][j]=0,cnt[i][j]=0;
	for(int i=1;i<=n;i++){//让这些数尽可能的大 //可以改一个数
		if(s[i-1]=='A')a[i]=0;
		else if(s[i-1]=='B')a[i]=1;
		else if(s[i-1]=='C')a[i]=2;
		else if(s[i-1]=='D')a[i]=3;
		else if(s[i-1]=='E')a[i]=4;
	}
	int ans=-INT_MAX;
	int t=a[n];
	for(int j=0;j<=t;j++){
		a[n]=j;
		mx[n]=a[n];
		for(int i=n-1;i>=1;i--)mx[i]=max(mx[i+1],a[i]);
		sum[n][a[n]]=p[a[n]];
		post[n]=p[a[n]];
		if(j==t)cnt[n][a[n]]++;
		for(int i=n-1;i>=1;i--){
			if(a[i]>=mx[i])sum[i][a[i]]=p[a[i]];
			else sum[i][a[i]]=-p[a[i]];
			if(j==t)cnt[i][a[i]]++;
			post[i]=post[i+1]+sum[i][a[i]];
		}
		ans=max(ans,post[1]);
	}
	for(int j=0;j<5;j++) for(int i=1;i<=n;i++)sum[i][j]+=sum[i-1][j],cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=n;i++){
		int d=post[1];
		for(int j=mx[i+1];j<5;j++){
			int tem=d;
			tem-=post[i]-post[i+1];
			tem+=p[j];
			for(int k=0;k<j;k++){
				tem-=sum[i-1][k];
				tem-=cnt[i-1][k]*p[k];
			}
			ans=max(ans,tem);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
