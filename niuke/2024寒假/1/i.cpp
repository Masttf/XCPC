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
	int n;cin>>n;
	int sumx=0;
	int sumy=0;
	int sumr=0;
	for(int i=1;i<=n;i++){
		int x,y,r;cin>>x>>y>>r;
		sumx+=x;
		sumy+=y;
		sumr+=r;

	}
	sumr/=n;
	sumx/=n;
	sumy/=n;
	if(sumr>=20)cout<<"buaa-noob\n";
	else cout<<"bit-noob\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}