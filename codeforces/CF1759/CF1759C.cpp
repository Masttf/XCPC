//先讨论a b是否相等
//再讨论a 和b能否由区间内的一个数变来 即a-l,r-a的最大值不超过x则不能
//如果可以讨论 a与b之间的距离是不是大于x如果是就是1
//如果不是讨论a是否可以向下变化同时b能否由下面的数变来//同理向上则2
//如果不能则其中一个需要先往反方向变化一下所以是3
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		int l,r,x;
		cin>>l>>r>>x;
		int a,b,d;
		cin>>a>>b;
		if(a==b)cout<<0<<'\n';
		else{
			d=max(a-l,r-a);
			if(d<x)cout<<-1<<'\n';
			else{
				d=max(b-l,r-b);
				if(d<x)cout<<-1<<'\n';
				else{
					d=a-b;if(d<=0)d=-d;
					if(d>=x)cout<<1<<'\n';
					else{
						if(a-l>=x&&b-l>=x)cout<<2<<'\n';
						else if(r-a>=x&&r-b>=x)cout<<2<<'\n';
						else cout<<3<<'\n';
					}
				}
			}
		}  
	}
	return 0;
}
