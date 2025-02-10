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
	int n=10;
	cout<<n<<' ';
	cout<<37<<'\n';
	mt19937_64 rd(time(0));
	vector<int>a(n+1);
	vector<int>pp;
	for(int i=1;i<=n;i++){
		a[i]=rd()%(1000000000)+1;
		pp.push_back(a[i]);
	}
	sort(pp.begin(),pp.end());
    pp.erase(unique(pp.begin(),pp.end()),pp.end());
    for(int i=1;i<=n;i++){
    	a[i]=lower_bound(pp.begin(),pp.end(),a[i])-pp.begin()+1;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	int q=10;
	cout<<q<<'\n';
	for(int i=1;i<=5;i++){
		cout<<1<<' '<<rd()%(n-2)+1<<'\n';
	}
	for(int i=1;i<=5;i++){
		cout<<2<<' ';
		int l=rd()%(n-1)+1;
		int r=rd()%(n-1)+1;
		while(r<l)r=rd()%(n-1)+1;
		cout<<l<<' '<<r<<'\n';
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