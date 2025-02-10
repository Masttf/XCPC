#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...)\
do{\
	cout<<#x<<" -> ";\
	err(x);\
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts &...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];

	sort(a.begin()+2,a.end());
	sort(b.begin()+1,b.end());

	int res=0;
	for(int i=2,j=2;i<=n&&j<=n;i++,j++){
		while(j<=n&&a[i]>=b[j]){
			j++;
			res++;
		}
	}
	
	int res2=0;
	int p=-1;
	for(int i=2,j=1;j<=n-1&&i<=n;j++,i++){
		while(j<=n-1&&a[i]>=b[j]){
			p=j;
			j++;
			res2++;
		}
	}

	int ans=0;
	b[0]=1;
	//cout<<res<<' '<<res2<<endl;
	for(int i=1;i<=n;i++){
		int d=b[i]-b[i-1];
		if(m<b[i]){
			d=m-b[i-1]+1;
		}
		if(i<=p&&a[n-res2+1]<b[n])ans+=d*min(res,res2-1);
		else ans+=d*min(res,res2);
		//dbg(d,ans);
		if(i==1)res++;
		if(m<b[i])break;
		
	}
	if(m>=b[n])ans+=(m-b[n]+1)*res;
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
