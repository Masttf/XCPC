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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=0;i<=n;i++){
		int x,y;cin>>x>>y;
		a[i]=(x^y)%2;
		//dbg(i,a[i]);
	}
	vector<int>cnt(2);
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	vector<set<int>>s(2);
	for(int i=1;i<=n;i++){
		s[a[i]].insert(i);
	}
	int t=a[0];
	auto p = [&]()->void{
		if(!s[1-t].empty()){
			cout<<*s[1-t].begin()<<endl;
			s[1-t].erase(s[1-t].begin());
		}else{
			cout<<*s[t].begin()<<endl;
			s[t].erase(s[t].begin());
		}
	};
	//dbg(a[0],cnt[a[0]]);
	if(cnt[a[0]]>=(n+1)/2){
		cout<<"First"<<endl;
		p();
		if(n%2==0){
			int x;cin>>x;
			s[a[x]].erase(x);
			for(int i=1;i<=(n/2)-1;i++){
				p();
				cin>>x;
				s[a[x]].erase(x);
			}
		}else{
			for(int i=1;i<=n/2;i++){
				int x;cin>>x;
				s[a[x]].erase(x);
				p();
			}
		}
		
	}else{
		t=1-t;
		cout<<"Second"<<endl;
		if(n%2==0){
			for(int i=1;i<=n/2;i++){
				int x;cin>>x;
				s[a[x]].erase(x);
				p();
			}
		}else{
			for(int i=1;i<=n/2;i++){
				int x;cin>>x;
				s[a[x]].erase(x);
				p();
			}
			int x;cin>>x;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}