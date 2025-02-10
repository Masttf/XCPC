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
	vector<int>a(2*n+1);
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		if(x>y)swap(x,y);
		a[x]=i;
		a[y]=-i;
	}
	vector<int>stk;
	int ok=0;
	for(int i=1;i<=2*n;i++){
		if(a[i]<0){
			if(stk.back()!=-a[i]){
				ok=1;
				break;
			}else stk.pop_back();
		}else{
			stk.push_back(a[i]);
		}
	}
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}