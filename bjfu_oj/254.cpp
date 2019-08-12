#include"iostream"
#include"string"
#include"queue"
#include"stack"
using namespace std;
typedef struct{
	char *list;
	int length;
}sList;
char data[8][8]={{' ','+','-','*','/','(',')','#'},
{'+','>','>','<','<','<','>','>'},
{'-','>','>','<','<','<','>','>'},
{'*','>','>','>','>','<','>','>'},
{'/','>','>','>','>','<','>','>'},
{'(','<','<','<','<','<','=',' '},
{')','>','>','>','>',' ','>','>'},
{'#','<','<','<','<','<',' ','='}};
void initList(sList &L,int n){
	L.list=new char[n];
	L.length=0;
}
void split(string str,sList &L){
	for(int i=0;i<str.length();i++){
		
		L.list[L.length]=str[i];
		if(str[i]=='='){
			L.list[L.length]='#';
		}
		L.length++;
	}
}
bool isOperater(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '=':
		case '#':
			return true;
	}
	return false;
}
char cmp(char a,char b){
	int i,j;
	for(i=0;i<8;i++){
		if(data[i][0]==a){
			break;
		}
	}
	for(j=0;j<8;j++){
		if(data[0][j]==b){
			break;
		}
	}
	return data[i][j];
}
void operate(sList L,queue <char> &Q){
	stack <char> opnd,optr;
	optr.push('#');
	for(int i=0;i<L.length;i++){
		if(!isOperater(L.list[i])){
			opnd.push(L.list[i]);
			Q.push(L.list[i]);
		}else{
			if(cmp(optr.top(),L.list[i])=='<'){
				optr.push(L.list[i]);
			}else if(cmp(optr.top(),L.list[i])=='>'){
				Q.push(optr.top());
				optr.pop();
				i--;
			}else{
				optr.pop();
			}
		}
	}
}
void output(queue <char> Q){
	while(!Q.empty()){
		cout<<Q.front();
		Q.pop();
	}
	cout<<endl;
}
int main(){
	string str;
	sList L;
	while(1){
		cin>>str;
		if(str=="="){
			break;
		}
		initList(L,str.length());
		split(str,L);
		queue <char> Q;
		operate(L,Q);
		output(Q);
	}
	
	return 0;
}
