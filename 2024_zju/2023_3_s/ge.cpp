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
	int n=100,q=n*(n+1)/2;
	cout<<n<<' '<<q<<'\n';
	mt19937_64 rd(time(0));
	//srand(time(0));
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			int val=rd()%(1000000000);
			while(a[i-1]<=val){
				val=rd()%(1000000000);
			}
			a[i]=val;
		}else{
			int val=rd()%(1000000000);
			while(a[i-1]>val){
				val=rd()%(1000000000);
			}
			a[i]=val;
		}
		cout<<a[i]<<" \n"[i==n];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int val=rd()%(1000000000);
			cout<<2<<' '<<i<<' '<<j<<' '<<val<<'\n';
		}
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