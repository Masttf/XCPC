#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(0);
	int n=100;int q=2;
	cout<<n<<' '<<q<<'\n';
	for(int i=1;i<=n;i++){
		int x=rand()%50000;
		x+=1;
		int d=rand()%2;
		if(d==1)x=-x;
		cout<<x<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=n;i++){
		int x=rand()%n;
		x+=1;
		cout<<x<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=q;i++){
		int a=rand()%50000;
		int b=rand()%50000;
		int d1=rand()%2;
		int d2=rand()%2;
		a+=1;
		b+=1;
		if(d1==1)a=-a;
		if(d2==1)b=-b;
		
		cout<<a<<' '<<b<<'\n';
	}
	return 0;
}