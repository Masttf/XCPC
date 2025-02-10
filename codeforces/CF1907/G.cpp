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
	string s;cin>>s;
	s=' '+s;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>dfn(n+1),low(n+1);
	int tot=0;
	int cnt=0;
	vector<int>f(n+1);
	vector<vector<int>>bl(n+1);
	stack<int>ss;
	auto tarjan = [&](auto self,int now)->void{
		dfn[now]=low[now]=++tot;
		ss.push(now);
		if(!dfn[a[now]]){
			self(self,a[now]);
			low[now]=min(low[now],low[a[now]]);
		}else if(!f[a[now]]){
			low[now]=min(low[now],dfn[a[now]]);
		}
		if(dfn[now]==low[now]){
			int temp;
			cnt++;
			do{
				temp=ss.top();
				ss.pop();
				f[temp]=cnt;
				bl[cnt].push_back(temp);
			}while(temp!=now);
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i);
	}
	vector<int>res(cnt+1);
	vector<int>ans;
	for(int i=cnt;i>=1;i--){
		if(bl[i].size()==1){
			int u=bl[i][0];
			if(s[u]=='1'){
				s[a[u]]='1'-s[a[u]]+'0';
				s[u]='0';
				ans.push_back(u);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			res[f[i]]++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(res[i]%2==1){
			cout<<-1<<'\n';
			return ;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(bl[i].size()==1)continue;
		else if(res[i]==0)continue;
		int len=bl[i].size();
		vector<int>temp(len+2);
		temp[1]=bl[i][0];
		int cur=2;
		int u=bl[i][0];
		while(1){
			if(s[u]=='1'){
				temp[1]=u;
				break;
			}
			u=a[u];
		}
		int tt=u;
		u=a[u];
		while(u!=tt){
			temp[cur++]=u;
			u=a[u];
		}
		temp[cur]=temp[1];
		int res=0;
		int last=0;
		for(int i=1;i<=len;i++){
			if(s[temp[i]]=='0')continue;
			if(last)res+=i-last,last=0;
			else last=i;
		}
		int sum=0;
		last=0;
		for(int i=2;i<=len+1;i++){
			if(s[temp[i]]=='0')continue;
			if(last)sum+=i-last,last=0;
			else last=i;
		}
		last=0;
		//dbg(res,sum);
		if(res>sum){
			for(int i=2;i<=len+1;i++){
				if(last)ans.push_back(temp[i-1]);
				if(s[temp[i]]=='0')continue;
				if(last){
					last=0;
				}else last=i;
			}
		}else{
			for(int i=1;i<=len;i++){
				if(last)ans.push_back(temp[i-1]);
				if(s[temp[i]]=='0')continue;
				if(last){
					last=0;
				}else last=i;
			}

		}
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
/*
8
5
11101
4 3 4 2 2
2
10
2 1
10
0000000011
9 10 10 7 10 9 9 9 10 2
10
1000111101
9 3 8 9 2 1 3 7 2 7
10
0001101010
5 7 6 10 8 3 6 6 2 2
10
0101100010
8 7 7 9 9 4 1 4 2 7
10
1010111010
7 9 10 7 7 2 8 6 10 4
10
1110000001
3 10 10 1 10 8 6 3 2 1

1
10
1001101101
2 3 4 5 6 7 8 9 4 3

1
10
1110000111
9 8 4 1 8 3 9 6 2 5
*/
