#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	int ans=0;
	for(int i=a;i<=b;i++){
		int len=i-1;
		int r1=b+len;
		if(r1>=d){
			ans+=(c-b+1)*(d-c+1);
		}else{
			int l=b;
			if(r1<=c){
				l+=c-r1;
				r1=c;
			}
			int r2=c+len;
			int s=l+len-c+1;
			//dbg(r2);
			if(r2<=d){
				ans+=(s+r2-c+1)*(c-l+1)/2;
			}else{
				int l2=d-len;
				ans+=(s+d-c+1)*(l2-l+1)/2;
				l2++;
				ans+=(c-l2+1)*(d-c+1);
			}
		}
		//dbg(i,ans);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}