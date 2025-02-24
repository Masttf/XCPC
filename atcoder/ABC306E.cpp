#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,k,q;cin>>n>>k>>q;
	vector<int>a(n+1);
	map<int,int>m1;
	map<int,int,greater<int> >m2;
	int ans=0;
	m1[0]=k;
	m2[0]=n-k;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		m2[y]++;
		if(m1.count(a[x])){
			m1[a[x]]--;
			if(m1[a[x]]==0)m1.erase(a[x]);
			auto it =m2.begin();
			//dbg(it->first);
			ans-=a[x];
			ans+=it->first;
			m1[it->first]++;
			m2[it->first]--;
			if(m2[it->first]==0)m2.erase(it->first);
		}else{
			m2[a[x]]--;
			if(m2[a[x]]==0)m2.erase(a[x]);
		}
		auto it = m1.begin();
		auto it2 = m2.begin();
		if(it->first<it2->first){
			m1[it->first]--;
			m2[it->first]++;
			if(m1[it->first]==0)m1.erase(it->first);
			ans-=it->first;
			ans+=it2->first;
			//dbg(it->first,it2->first);
			m2[it2->first]--;
			m1[it2->first]++;
			if(m2[it2->first]==0)m2.erase(it2->first);
		}
		a[x]=y;
		//for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
		cout<<ans<<'\n';
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