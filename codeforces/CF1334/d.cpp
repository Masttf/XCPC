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
	int n,l,r;cin>>n>>l>>r;
	int now=0;
	int flag=0;
	//dbg(l,r);
	for(int i=1;i<=n;i++){
		int d=(n-i)*2;
		if(i==n)d++;
		if(now+d>=l){
			flag=1;
		}
		if(flag){
			//dbg(i);
			int nn=i;
			int nx=i+1;
			if(i==n){
				nn=1;
			}
			now++;
			int t=0;
			while(now<=r){
				//dbg(now,nn,nx);
				if(now>=l){
					if(!t)cout<<nn<<' ';
					else cout<<nx<<' ';
				}
				if(!t)t=1;
				else{
					nx++;
					if(nx>n){
						nn++;
						nx=nn+1;
						if(nn==n)nn=1;
					}
					t=0;
				}
				now++;
			}
			break;
		}
		now+=d;
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}