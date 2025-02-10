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
	int q;cin>>q;
	int n=q;
	vector<int>res;
	for(int i=2;i*i<=q;i++){
		if(q%i==0){
			while(q%i==0){
				q/=i;
				res.push_back(i);
			}
		}
	}
	if(q!=1)res.push_back(q);
	if(res.size()==2)cout<<2<<'\n';
	else{
		if(res.size()==1){
			cout<<1<<'\n'<<0<<'\n';
			return ;
		}
		cout<<1<<'\n'<<res[0]*res[1]<<'\n';
		
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