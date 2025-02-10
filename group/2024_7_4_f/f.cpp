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
pair<int,int> res[11]={{1,1},{548,1},{866,-1},{892,-1},{64,1},{1303,1},{97,-1},{1278,-1},{1278,-1},{960,1},{934,1}};
void solve(){
	int n;cin>>n;
	int flag=1;
	int now=1;
	int s=1;
	int d=1e8;
	if(n>d){
		for(int i=1;i<10;i++){
			if(n<(i+1)*d){
				s=i*d;
				now=res[i].first;
				flag=res[i].second;
				break;
			}
		}
	}
	
	vector<int>p(10);
	p[0]=1;
	for(int i=1;i<10;i++)p[i]=p[i-1]*10;
	for(int i=s;i<n;i++){
		//dbg(i,now);
		int ok=0;
		int temp=i;
		int cnt=0;
		while(temp){
			if(temp%10==7){
				if(cnt&&i+p[cnt]<n)i+=p[cnt];
				else ok=1;
			}
			temp/=10;
			cnt++;
		}
		if(i%7==0||ok)flag=-flag;
		now+=flag;
		if(now==0)now=1337;
		if(now>1337)now=1;
	}
	cout<<now<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}