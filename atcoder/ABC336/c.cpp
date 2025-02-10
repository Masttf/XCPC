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
	vector<int>res;
	while(n){
		res.push_back(n%5);
		n/=5;
	}
	vector<int>ans(res.size()+1);
	for(int i=0;i<res.size();i++){
		int x=res[i];
		if(i==0)x--;
		ans[i]=x;
	}
	for(int i=0;i<res.size();i++){
		if(ans[i]<0)ans[i]+=5,ans[i+1]--;
	}
	for(int i=res.size()-1;i>=0;i--){
		int x=ans[i];
		cout<<2*x;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}