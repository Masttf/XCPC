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
	int n,k;cin>>n>>k;
	if(k>40||n==1){
		cout<<"Bob\n";
		return ;
	}
	vector<int>res;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				n/=i;
				cnt++;
			}
			if(cnt>=k)res.push_back(cnt);
		}
	}
	if(n!=1&&k==1)res.push_back(1);
	if(res.empty()){
		cout<<"Bob\n";
		return ;
	}else{
		cout<<"Alice\n";
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}