#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int h=0;
	while(c>=0){
		if(a<h+1&&b<h+1){
			c-=2*h+2-a-b;
			if(c>=0)
				h++;
			a=0;
			b=0;
		}else if(a<h+1){
			c-=h+1-a;
			b-=h+1;
			if(c>=0)
				h++;
			a=0;
		}else if(b<h+1){
			c-=h+1-b;
			a-=h+1;
			if(c>=0)
				h++;
			b=0;
		}else{
			a-=h+1;
			b-=h+1;
			h++;
		}
	}
	cout<<h;
	return 0;
}
