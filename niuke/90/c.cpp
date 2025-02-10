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
	vector<int>temp;
	while(n){
		temp.push_back(n%10);
		n/=10;
	}
	reverse(temp.begin(),temp.end());
	int res=0;
	int sz=temp.size();
	for(int i=0;i<sz;i++){
		int x=temp[i];
		if(i==sz-1&&res==0){
			if(x==0)res=res*10+1;
			else{
				if(x==1)res=2;
				else res=1;
			}
		}else{
			if(x==0)res=res*10+1;
			else res=res*10;
		}
		
	}
	cout<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;cin>>t;
	while(t--)solve();
	return 0;
}