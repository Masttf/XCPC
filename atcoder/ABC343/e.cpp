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
	int a,b,c;cin>>a>>b>>c;
	int x1=0,y1=0,z1=0;
	vector<int>x(4);
	vector<int>y(4);
	vector<int>z(4);
	auto check = [&]()->bool{
		int lx,rx,ly,ry,lz,rz;
		lx=max({x[1],x[2],x[3]});
		rx=min({x[1]+7,x[2]+7,x[3]+7});
		ly=max({y[1],y[2],y[3]});
		ry=min({y[1]+7,y[2]+7,y[3]+7});
		lz=max({z[1],z[2],z[3]});
		rz=min({z[1]+7,z[2]+7,z[3]+7});
		int d=0;
		if(rx<=lx||ry<=ly||rz<=lz)d=0;
		else d=(rx-lx)*(ry-ly)*(rz-lz);
		//dbg(d);
		if(d!=c)return false;
		int sum2=0;
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				lx=max(x[i],x[j]);
				rx=min(x[i]+7,x[j]+7);
				ly=max(y[i],y[j]);
				ry=min(y[i]+7,y[j]+7);
				lz=max(z[i],z[j]);
				rz=min(z[i]+7,z[j]+7);
				if(rx<=lx||ry<=ly||rz<=lz)continue;
				else sum2+=(rx-lx)*(ry-ly)*(rz-lz);
			}
		}
		int sum1=1029-sum2+c;
		//dbg(sum1,sum2);
		//if(sum1!=a)return false;
		sum2-=3*d;
		//dbg(sum2);
		if(sum2!=b)return false;
		sum1-=b+c;
		if(sum1!=a)return false;
		return true;
	};
	y[2]=6;
	x[3]=6;
	//dbg(check());
	for(int x2=0;x2<=7;x2++){
		x[2]=x2;
		for(int y2=0;y2<=7;y2++){
			y[2]=y2;
			for(int z2=0;z2<=7;z2++){
				z[2]=z2;
				for(int x3=-7;x3<=14;x3++){
					x[3]=x3;
					for(int y3=-7;y3<=14;y3++){
						y[3]=y3;
						for(int z3=-7;z3<=14;z3++){
							z[3]=z3;
							if(check()){
								cout<<"Yes\n";
								for(int i=1;i<=3;i++){
									cout<<x[i]<<' '<<y[i]<<' '<<z[i]<<' ';
								}
								return ;
							}
						}
					}
				}
			}
		}
	}
	//dbg("yes");
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}