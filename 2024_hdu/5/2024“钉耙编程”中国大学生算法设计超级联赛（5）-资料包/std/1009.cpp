#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int MX=1e7+5;
int n,a;
int pri[MX],cnt_p;
ll mu[MX],muk[MX];
unordered_map<int,ll> v1,v2;
bool not_pri[MX];

void init(){
	mu[1]=1;
	for(int i=2;i<MX;i++){
		if(!not_pri[i]){
			pri[++cnt_p]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt_p&&i*pri[j]<MX;j++){
			not_pri[i*pri[j]]=true;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}else mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<MX;i++){
		muk[i]=muk[i-1]+mu[i]*i;
		mu[i]+=mu[i-1];
	}
}
ll C2(int n){return (ll)n*(n+1);}
ll M1(int n){
	if(n<MX)return mu[n];
	if(v1.count(n))return v1[n];
	ll ret=0;
	for(int i=2,pos;i<=n;i=pos+1){
		pos=min(n,n/(n/i));
		ret+=(pos-i+1)*M1(n/i);
	}
	return v1[n]=1-ret;
}
ll M2(int n){
	if(n<MX)return muk[n];
	if(v2.count(n))return v2[n];
	ll ret=0;
	for(int i=2,pos;i<=n;i=pos+1){
		pos=min(n,n/(n/i));
		ret+=M2(n/i)*(C2(pos)-C2(i-1));
	}
	ret=ret/2;
	return v2[n]=1-ret;
}
ll S2(int n){
	ll ret=0;
	for(int i=1,pos;i<=min(a,n);i=pos+1){
		if(a/i)pos=min(n,a/(a/i));
		else pos=n;
		ret+=(a/i)*(M2(pos)-M2(i-1));
	}
	return ret;
}
int main(){
    fastio;
    init();
    int tc;cin>>tc;
    assert(tc==30);
    while(tc--){
        cin>>n>>a;
        assert(1<=n&&n<=1000000000);
        assert(1<=a&&a<=1000000000);
        cout<<a*M1(n)-S2(n)<<endl;
    }
    return 0;
}