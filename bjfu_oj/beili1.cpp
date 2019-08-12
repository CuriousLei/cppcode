#include"iostream"
using namespace std;
char y[11]={'1','0','x','9','8','7','6','5','4','3','2'};
char w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(){
	string str;
	int x=0;
	cin>>str;
	
	for(int i=0;i<17;i++){
		x+=(str[i]-'0')*w[i];
	}
	x=x%11;
	if(y[x]==str[17]){
		cout<<str<<endl;
	}else{
		cout<<str.substr(0,17)<<y[x]<<"ÕýÈ·"<<endl;
	}
	return 0;
}
