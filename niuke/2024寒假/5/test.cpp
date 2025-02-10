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
const int mod=1e9+1;
bool isprim(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
void solve(int n){
	dbg(n);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)a[i]=i;
	do{
		int ok=1;
		for(int i=1;i<=n;i++){
			if(!isprim(a[i]+i)){
				ok=0;
				break;
			}
		}
		if(ok){
			for(int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<'\n';
			
			for(int i=1;i<=n;i++)cout<<a[i]+i<<' ';
			cout<<'\n';
			dbg("............");
			//break;
		}
	}while(next_permutation(a.begin()+1,a.end()));
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	//while(t--)solve();
	for(int i=1;i<=20;i+=2)solve(i);
	return 0;
}