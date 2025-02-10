#include<bits/stdc++.h>
#define int int long long
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
struct node{
	int l,r,id;
};
bool cmp1(node &x,node &y){
	return x.r>y.r;
}
bool cmp2(node &x,node &y){
	return x.r<y.r;
}
void solve(){
	int n;cin>>n;
	vector<node>a(n+1);
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		a[i]={l,r,i};
	}
	vector<node>t1,t2;
	for(int i=1;i<=n;i++){
		if(a[i].l<a[i].r)t1.push_back(a[i]);
		else t2.push_back(a[i]);
	}
	sort(t1.begin(),t1.end(),cmp1);
	sort(t2.begin(),t2.end(),cmp2);
	if(t1.size()>t2.size()){
		cout<<t1.size()<<'\n';
		for(auto [l,r,id]:t1)cout<<id<<' ';
		cout<<'\n';
	}else{
		cout<<t2.size()<<'\n';
		for(auto [l,r,id]:t2)cout<<id<<' ';
		cout<<'\n';
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