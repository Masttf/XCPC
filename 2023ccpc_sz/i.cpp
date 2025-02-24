#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,k;cin>>n>>k;
	int ok=1;
	auto qmi = [&](__int128 a,__int128 b)->__int128{
		__int128 res=1;
		while(b){
			if(res>n||res<0)ok=0;
			if(a>n||a<0)ok=0;
			if(b&1){
				res=res*a;
			}
			b>>=1;
			a=a*a;
		}
		return res;
	};

	int len=1000000;
	int l=1,r=1000000;
	while(l<=r){
		ok=1;
		int mid=(l+r)>>1;
		int d=qmi(mid,k);
		if(!ok||qmi(mid,k)>n)len=mid,r=mid-1;
		else l=mid+1;
	}
	int rr=1;
	int p=1;
	while(p){
		__int128 d1=qmi(rr+p,k);
		__int128 d2=qmi(rr+p-1,k);
		if(d1-d2<=n){
			rr+=p;
			p*=2;
		}else p/=2;
	}


	int ans=0;
	for(int i=1;i<=len;i++){
		if(n%i!=0)continue;
		l=1,r=rr-i;
		while(l<=r){
			int mid=(l+r)>>1;
			__int128 d1=qmi(mid,k);
			__int128 d2=qmi(mid+i,k);
			if(d2-d1>n){
				r=mid-1;
			}else if(d2-d1==n){
				ans++;
				break;
			}else l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}