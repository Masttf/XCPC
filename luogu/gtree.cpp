#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n=100;
	int m=100;
	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;i++){
		cout<<rand()%1000<<' ';
	}
	cout<<'\n';
	for(int i=2;i<=n;i++){
		int u=rand()%(i-1)+1;
		cout<<u<<' '<<i<<'\n';
	}
	for(int i=1;i<=m;i++){
		int t=rand()%2+1;
		if(t==1){
			int d=rand()%n+1;
			int x=rand()%1000;
			cout<<t<<' '<<d<<' '<<x<<'\n';
		}else{
			int u=rand()%n+1;
			int v=rand()%n+1;
			int x=rand()%1000;
			cout<<t<<' '<<u<<' '<<v<<' '<<x<<'\n';
		}
	}
	return 0;
}