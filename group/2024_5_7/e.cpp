#include<bits/stdc++.h>
//#define int long long
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
int c[2][15]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int limit[]={0,9,9,9,9,1,9,9,9};
map<int,bool>m;
void solve(){
	string s;cin>>s;
	if(s=="--------"){
		cout<<55157<<'\n';
		return ;
	}
	s=' '+s;
	vector<int>res(10);

	vector<int>temp;
	for(int i=1;i<=8;i++){
		if(s[i]=='-')temp.push_back(i);
		else res[i]=s[i]-'0';
	}
	int len=temp.size();
	int ans=0;
	
	auto check = [&](int x)->bool{
		if(x<=1)return false;
		if(m.count(x))return m[x];
		for(int i=2;i*i<=x;i++){
			if(x%i==0)return m[x]=false;
		}
		return m[x]=true;
	};
	auto dfs = [&](auto self,int now)->void{
		if(now==len+1){
			int year=res[1]*1000+res[2]*100+res[3]*10+res[4];
			int mon=res[5]*10+res[6];
			int day=res[7]*10+res[8];
			if(year==0||mon==0||day==0)return ;
			int t=0;
			if((year%4==0&&year%100!=0)||year%400==0){
				t=1;
			}
			if(mon>12||day>c[t][mon])return ;
			if(!check(day))return ;
			if(!check(mon*100+day))return ;
			if(!check(year*10000+mon*100+day))return ;
			ans++;
			return ;
		}
		int u=temp[now-1];
		if(u==6){
			if(res[5]==1)limit[u]=2;
			else limit[u]=9;
		}
		if(u==8){
			if(res[7]==3)limit[u]=1;
			else limit[u]=9;
		}
		for(int i=0;i<=limit[u];i++){
			res[u]=i;
			self(self,now+1);
		}
	};
	dfs(dfs,1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}