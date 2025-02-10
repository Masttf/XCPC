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
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<string>g(n);
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j]=='p'){
				
			}
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