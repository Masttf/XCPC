#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int chinese;
	int math;
	int english;
	int grade;
}s[1005];
bool cmp(student x,student y){
	return x.name<y.name;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].name>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].grade=s[i].chinese+s[i].math+s[i].english;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(fabs(s[i].chinese-s[j].chinese)<=5&&fabs(s[i].math-s[j].math)<=5&&fabs(s[i].english-s[j].english)<=5&&fabs(s[i].grade-s[j].grade)<=10){
				cout<<s[i].name<<' '<<s[j].name<<'\n';
			}
		}
	}
	return 0;
}
