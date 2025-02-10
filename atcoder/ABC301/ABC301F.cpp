#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=3e5+5;
int f[maxn],inv[maxn];
int cnt[maxn][60];
int pre[maxn];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void init(){
	f[0]=1;
	inv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
	return ;
}
int c(int a,int b){
	return f[a]*inv[b]%mod*inv[a-b]%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	init();
	reverse(s.begin(),s.end());
	int len=s.size();
	s=' '+s;
	int tot=0;
	for(int i=len;i>=1;i--){
		for(int j=0;j<60;j++)cnt[i][j]+=cnt[i+1][j];
		if(s[i]=='?')tot++,pre[i]=1;
		else{
			if(s[i]>='A'&&s[i]<='Z')cnt[i][s[i]-'A'+26]++;
			else cnt[i][s[i]-'a']++;
		}
	}
	for(int i=1;i<=len;i++)pre[i]+=pre[i-1];
	int ans=qmi(52,tot);
	int lower_last=0,upper_first=0;
	int now=0;
	for(int i=1;i<=len;i++){
		now=pre[i];
		if((s[i]>='a'&&s[i]<='z')||s[i]=='?'){
			int f1;
			if(!upper_first)f1=qmi(26,now)*(pre[i-1]-pre[lower_last])%mod;
			else f1=qmi(26,now)*(pre[upper_first]-pre[lower_last]+1)%mod;
			int flag=0;
			int k=0;
			for(int j=26;j<52;j++){
				if(cnt[i][j]>=2)flag=1;
				if(!cnt[i][j])k++;
			}
			if(flag)ans-=f1*qmi(52,tot-now)%mod;
			else{
				int d=qmi(52,tot-now);
				for(int i=0;i<=min(k,tot-now);i++){
					d-=c(k,i)*c(tot-now,i)%mod*f[i]%mod*qmi(26,tot-now-i)%mod;
					d%=mod;
				}
				d=(d+mod)%mod;
				ans-=f1*d%mod;
			}
			ans%=mod;
			ans=(ans+mod)%mod;
			if(s[i]>='a'&&s[i]<='z')lower_last=i;
			if(upper_first&&lower_last>upper_first)break;
		}else if(s[i]>='A'&&s[i]<='Z'){
			if(!upper_first)upper_first=i;
		}
	}
	cout<<ans;
	return 0;
}

