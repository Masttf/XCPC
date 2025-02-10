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
	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	int d=abs(y2-y1);
	int l,r;
	if((x1+y1)%2==0){
		l=x1-d;
		r=x1+d+1;
	}else{
		l=x1-d-1;
		r=x1+d;
	}
	if(l<=x2&&x2<=r)cout<<d<<'\n';
	else{
		y1=y2;
		int ans=d;
		if(x2>x1){
			x1=r;
			if((x1+y1)%2==0)x1++;
			if((x2+y2)%2==1)x2--;
			if(x2<x1){
				cout<<ans<<'\n';
				return ;
			}
			ans+=(x2-x1-1)/2+1;
			assert((x2-x1-1)%2==0);
		}else{
			x1=l;
			if((x1+y1)%2==1)x1--;
			if((x2+y2)%2==0)x2++;
			if(x1<x2){
				cout<<ans<<'\n';
				return ;
			}
			ans+=(x1-x2-1)/2+1;
			assert((x1-x2-1)%2==0);
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}