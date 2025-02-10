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
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a,b;
	int cnt=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x)a.push_back(x);
		else cnt++;
	}
	for(int k=1;k<n;k++){
		if(a.empty())break;
		b.clear();
		if(cnt)b.push_back(a[0]),cnt--;
		for(int i=1;i<a.size();i++){
			int d=a[i]-a[i-1];
			if(d)b.push_back(d);
			else cnt++;
		}
		sort(b.begin(),b.end());
		swap(a,b);
	}
	if(a.empty())cout<<0<<'\n';
	else cout<<a[0]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}