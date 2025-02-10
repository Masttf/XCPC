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
	int d1=x1+y1;
	int d2=max(x2,y2);
	if(d1<=d2){
		cout<<"Polycarp\n";
	}else{
		int temp=x2+y2-d2;
		int ok=0;
		for(int i=1;i<=temp;i++){
			x2--;
			y2--;
			if(x2<=x1&&y2<=y1){
				int dd=x1-x2+y1-y2;
				if(dd==i)ok=1;
			}
		}
		if(ok)cout<<"Polycarp\n";
		else cout<<"Vasiliy\n";
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