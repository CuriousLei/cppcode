#include"iostream"
using namespace std;
void insert(char *s,char *t,int pos){
	char str[200];
	int i;
	for(i=0;i<pos-1;i++,s++){
		str[i]=*s;
	}
	for(;*t;t++,i++){
		str[i]=*t;
	}
	for(;*s;s++,i++){
		cout<<*s<<endl;
		str[i]=*s;
	}
	str[i]='\0';
	cout<<str<<endl;
}
int main(){
	char s[100],t[100];
	int pos;
	while(1){
		cin>>pos;
		if(pos==0){
			break;
		}
		cin>>s>>t;
		insert(s,t,pos);
	}
	return 0;
}
