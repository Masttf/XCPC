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
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    if(x1<0){
    	int d=(abs(x1)+3)/4*4;
    	x1+=d;
    	x2+=d;
    }else{
    	int d=x1/4*4;
    	x1-=d;
    	x2-=d;
    }
    if(y1<0){
    	int d=(abs(y1)+1)/2*2;
    	y1+=d;
    	y2+=d;
    }else{
    	int d=y1/2*2;
    	y1-=d;
    	y2-=d;
    }
    //dbg(x1,y1,x2,y2);
    auto get = [&](int x,int y)->int{
    	int res=0;
    	int d1=x/4;
    	int d2=y/2;
    	res+=8*d1*d2;
    	//dbg("1",res);
    	int xx=x%4;
    	if(y%2==1){
    		res+=4*d1;
    		if(xx==1){
    			res+=2;
    		}else if(xx==2){
    			res+=3;
    		}else if(xx==3){
    			res+=3;
    		}
            y--;
    	}
    	//dbg("2",res);
        int yy=y/2;
    	if(xx==1){
    		res+=3*yy;
    	}else if(xx==2){
    		res+=6*yy;
    	}else if(xx==3){
    		res+=7*yy;
    	}
    	//dbg(res);
    	return res;
    };
    int ans=get(x2,y2)-get(x1,y2)-get(x2,y1)+get(x1,y1);
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}