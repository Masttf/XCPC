#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	int ans=0;
	for(int i=a;i<=b;i++){
		if(b+i<=d){
			int start=b;
			int s=0;
			int e=d-c;
			if(b+i<=c)start+=c-(b+i);
			if(b+i>=c)s=b+i-c;
			int end=d-i;
			if(end>c){
				e-=(end-c);
				end=c;
			}
			int len=end-start+1;
			//dbg(start,end,len,s);
			ans+=len*(s+e)/2;
		}else{
			ans+=(d-c+1)*(c-b+1);
		}
		//dbg(ans);
		if(d-i<=c&&d-i>=b){
			int start=d-i;
			int len=c-start;
			ans+=len*(d-c+1);
		}
		//dbg(i,ans);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}