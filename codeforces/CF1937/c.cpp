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
	int mx=0;
	for(int i=0;i<n;i++){
		cout<<"? "<<mx<<' '<<mx<<' '<<i<<' '<<i<<endl;
		char t;cin>>t;
		if(t=='<')mx=i; 
	}
	vector<int>res;
	res.push_back(0);
	int mmx=0;
	for(int i=0;i<n;i++){
		cout<<"? "<<mmx<<' '<<mx<<' '<<i<<' '<<mx<<endl;
		char t;cin>>t;
		if(t=='<'){
			res.clear();
			mmx=i;
			res.push_back(i);
		}else if(t=='=')res.push_back(i);
	}
	
	int k=res[0];
	int sz=res.size();
	for(int i=1;i<sz;i++){
		cout<<"? "<<k<<' '<<k<<' '<<res[i]<<' '<<res[i]<<endl;
		char t;cin>>t;
		if(t=='>')k=res[i];
	}
	cout<<"! "<<k<<' '<<mx<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}