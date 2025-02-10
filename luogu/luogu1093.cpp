#include<bits/stdc++.h>
using namespace std;
struct student{
	int number;
	int chinese;
	int math;
	int english;
	int all;
}s[305];
bool cmp(student x,student y){
	if(x.all!=y.all) return x.all>y.all;
	else if(x.chinese!=y.chinese)return x.chinese>y.chinese;
	else if(x.number!=y.number)return x.number<y.number;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].number=i;
		s[i].all=s[i].chinese+s[i].math+s[i].english;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<s[i].number<<' '<<s[i].all<<'\n';
	}
	return 0;
}
