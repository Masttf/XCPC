#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=2e5+5;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;string s;
	cin>>n>>s;
	s=' '+s;
	int len=s.size();
	map<int,int>p;
	p[1]=0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			p[i]=0;
			p[n/i]=0;
		}
	}
	int ans=0;
	for(auto it=p.begin();it!=p.end();it++){
		vector<int> a(it->first+1);
		for(int i=1;i<len;i++){
			if(s[i]=='.'){
				int d=i%it->first;
				if(d==0)d=it->first;
				a[d]=1;
			}
		}
		int cnt=0;
		for(int i=1;i<=it->first;i++){
			if(a[i]==0)cnt++;
		}
		int d=qmi(2,cnt);
		d+=it->second;
		ans+=d;
		ans%=mod;
		ans=(ans+mod)%mod;
		auto k=it;
		k++;
		for(;k!=p.end();k++){
			if(k->first%it->first==0){
				k->second-=d;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
