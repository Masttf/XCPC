#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cout<<1<<endl;
	int n=rand()%10;
	if(n<2)n=2;
	cout<<n<<' '<<10<<'\n';
	for(int i=1;i<=n-1;i++){
		int d=rand()%10;
		if(!d)d++;
		cout<<d<<' ';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		int d=rand()%10;
		if(!d)d++;
		cout<<d<<' ';
	}
	cout<<endl;
	return 0;
}