#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=105;
int f[maxn][maxn],nxt[maxn][30];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=0;i<26;i++)nxt[len+1][i]=len+1;
	for(int i=len;i>=1;i--){
		memcpy(nxt[i],nxt[i+1],sizeof nxt[i]);
		nxt[i][s[i]-'a']=i;
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		memset(f,0,sizeof f);
		for(int p=0;p<26;p++){//表示T1
			if(nxt[1][p]<=i&&nxt[i+1][p]<=len)f[nxt[1][p]][nxt[i+1][p]]=1;
		}
		for(int j=1;j<=i;j++){//开始填充
			for(int k=i+1;k<=len;k++){
				for(int p=0;p<26;p++){
					f[nxt[j+1][p]][nxt[k+1][p]]=(f[nxt[j+1][p]][nxt[k+1][p]]+f[j][k])%mod;
				}
			}
		}
		for(int k=i+1;k<=len;k++)ans=(ans+f[i][k])%mod;//以Si为Tn的方案数
	}
	cout<<ans;
	return 0;
}
