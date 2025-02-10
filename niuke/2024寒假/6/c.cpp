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
const int maxn=1e9;
vector<int>num;
void init(){
	num.push_back(0);
	num.push_back(1);
	int p1=0,p2=1;
	while(p2<=maxn){
		int temp=p1+p2;
		p1=p2;
		p2=temp;
		num.push_back(temp);
	}
}
void solve(){
	int n;cin>>n;
	vector<int>ans;
	for(int i=1;i<=3;i++){
		int p=upper_bound(num.begin(),num.end(),n)-num.begin();
		p--;
		ans.push_back(num[p]);
		n-=num[p];
	}
	if(n)cout<<-1<<'\n';
	else{
		for(auto x:ans)cout<<x<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}