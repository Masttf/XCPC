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
	int n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	if(s.find(t)==-1){
		cout<<"No\n";
		return ;
	}
	if(s[0]!=t[0]||s[n-1]!=t[m-1]){
		cout<<"No\n";
		return ;
	}
	string t2=t;
	reverse(t2.begin(),t2.end());
	s=' '+s;
	t=' '+t;
	t2=' '+t2;
	vector<int>ne(m+1);
	ne[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[i]!=t[j+1])j=ne[j];
		if(t[i]==t[j+1])j++;
		ne[i]=j;
	}
	vector<int>ne2(m+1);
	ne2[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j&&t2[i]!=t2[j+1])j=ne2[j];
		if(t2[i]==t2[j+1])j++;
		ne2[i]=j;
	}
	vector<int>p(n+1);
	for(int i=1,j=0;i<=n;i++){
		while(j&&s[i]!=t[j+1])j=ne[j];
		if(s[i]==t[j+1])j++;
		p[i]=j;
		if(j==m){
			j=0;
		}
	}
	vector<int>p2(n+1);
	for(int i=n,j=0;i>=1;i--){
		while(j&&s[i]!=t2[j+1])j=ne2[j];
		if(s[i]==t2[j+1])j++;
		p2[i]=j;
		if(j==m){
			j=0;
		}
	}
	int ok=1;
	int last=-1;
	int f1=0;
	int f2=0;
	// for(int i=1;i<=n;i++)cout<<p[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++)cout<<p2[i]<<" \n"[i==n];
	vector<int>pre1(n+1);
	vector<int>pre2(n+5);
	for(int i=1;i<=n;i++)pre1[i]=pre1[i-1]+(p2[i]?1:0);
	for(int i=n;i>=1;i--)pre2[i]=pre2[i+1]+(p[i]?1:0);
	for(int i=1;i<=n;i++){
		if(p[i]==0)f1=1;
		if(p2[i]==0)f2=1;
		if(p[i]==m){
			if(last!=-1){
				int d=i-last-m;
				if(d&&d<m){
					string temp=s.substr(last+1,d);
					if(t.find(temp)==-1)ok=0;
				}else{
					int fff=0;
					int len1=0;
					int len2=i-m-last;
					for(int j=last;j<=i-m;j++){
						
						//dbg(j,len1,len2);
						int d1=pre1[j]-pre1[last];
						int d2=pre2[j+1]-pre2[i-m+1];
						//dbg(d1,d2);
						if(d1==len1&&d2==len2){
							fff=1;
						}
						len1++;
						len2--;
					}
					if(!fff)ok=0;
				}
			}else{
				if(f1)ok=0;
			}
			f1=0;
			f2=0;
			last=i;
		}
		//dbg(i,ok);
	}
	if(f2)ok=0;
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}