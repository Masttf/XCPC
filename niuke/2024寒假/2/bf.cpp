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
const int mod=1e9+7;
void solve(){
	int ans=0;
	for(int i=10000;i<=99999;i++){
		if(i%8==0){
			set<int>s;
			s.insert(i/10000);
			s.insert(i%10000/1000);
			s.insert(i%1000/100);
			s.insert(i%100/10);
			if(s.size()==4){
				ans++;
				//dbg(i);
			}
			//dbg(i);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}