/*
111000
011100
产生3个1
111000
011010
也就是说只和两个1的相对位置有关
产生4个1
即找到规律
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c;cin>>a>>b>>c;
	if(c==0){
		for(int i=1;i<=a;i++)cout<<1;
		for(int i=1;i<=b;i++)cout<<0;
		cout<<'\n';
		for(int i=1;i<=a;i++)cout<<1;
		for(int i=1;i<=b;i++)cout<<0;
	}
	else{
		if(a==0||b==0||c>=a+b)cout<<-1;
		else if(c<a){
			for(int i=1;i<=a;i++)cout<<1;
			for(int i=1;i<=b;i++)cout<<0;
			cout<<'\n';
			for(int i=1;i<=a-c;i++)cout<<1;
			cout<<0;
			for(int i=1;i<=c;i++)cout<<1;
			for(int i=1;i<=b-1;i++)cout<<0;
			
		}else if(c>=a){//大于b则先用a补，然后就是一样的问题
			for(int i=1;i<=a;i++)cout<<1;
			for(int i=1;i<=b;i++)cout<<0;
			cout<<'\n';
			cout<<0;
			for(int i=1;i<=a-1;i++)cout<<1;//已经造了a个1
			for(int i=1;i<=c-a;i++)cout<<0;//下一个本身就带一个
			cout<<1;
			for(int i=1;i<=b-1-c+a;i++)cout<<0;
		}
	}
	return 0;
}
