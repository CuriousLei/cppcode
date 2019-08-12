#include"iostream"
using namespace std;
void insert(char *s,char *t,int pos){
	char str[100];
	char *c;
	int k=0;
	c=str;
	while(pos!=1){
		*c=*s;
		s++;
		c++;
		pos--;
		k++;
	}
	while(*t){
		*c=*t;
		t++;
		c++;
		k++;
	}
	while(*s){
		*c=*s;
		c++;
		s++;
		k++;
	}
	for(int i=0;i<k;i++){
		cout<<str[i];	
	}
	cout<<endl;
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
