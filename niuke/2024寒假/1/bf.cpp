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
void solve(int n){
	srand(time(0));
	int sumx=0,sumy=0,sumr=0;
	for(int i=1;i<=n;i++){
		int ok=1;
		int x,y,r;
		x=rand()%199-99;
			y=rand()%199-99;
		do{
			
			r=rand()%100+1;
			//dbg(x,y,r);
			if(x-r>=-100&&x+r<=100&&y-r>=-100&&y+r<=100)ok=0;
		}while(ok);
		sumx+=x;
		sumy+=y;
		sumr+=r;
		//dbg(x,y,r);
	}
	dbg(sumx,sumy,sumr);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=10;i++)solve(100000);
	return 0;
}