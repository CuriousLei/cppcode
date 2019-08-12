#include"iostream"
#include"string"
#include"sstream"
#include"stack"
#include"iomanip"
using namespace std;
char database[8][8]={{'t','+','-','*','/','(',')','='},
					{'+','>','>','<','<','<','>','>'},
					{'-','>','>','<','<','<','>','>'},
					{'*','>','>','<','<','<','>','>'},
					{'/','>','>','>','>','<','>','>'},
					{'(','<','<','<','<','<','=',' '},
					{')','>','>','>','>',' ','>','>'},
					{'=','<','<','<','<','<',' ','='}};
template <class type>
type stringToType(string s){
	istringstream iss(s);
	type num;
	iss>>num;
	return num;
}
bool ifOperater(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '=':
			return true;
	}
	return false;
}
int sListLen;
void toList(string s,string sList[]){
	string str("");
	int k=0;
	for(int i=0;i<s.length();i++){
		if(!ifOperater(s[i])){
			str+=s[i];
		}else{
			if(str==""){
				sList[k]=s[i];
				k++;
			}else{
				sList[k]=str;
				sList[k+1]=s[i];
				k=k+2;
			}
			str="";
		}
	}
	sListLen=k;
}
char compare(char a,char b){
	int i,j;
	for(i=0;i<8;i++){
		if(database[i][0]==a){
			break;
		}
	}
	for(j=0;j<8;j++){
		if(database[0][j]==b){
			break;
		}
	}
	return database[i][j];
}
float caculate(float a,float b,char c){
	switch(c){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}
void operate(string sList[]){
	stack <float> opnd;
	stack <char> optr;
	int i;
	optr.push('=');
	for(i=0;i<sListLen;i++){
		if(!ifOperater(sList[i][0])){
			opnd.push(stringToType<float>(sList[i]));
		}else{
			switch(compare(optr.top(),sList[i][0])){
				case '>':
					float a,b;
					a=opnd.top();
					opnd.pop();
					b=opnd.top();
					opnd.pop();
					opnd.push(caculate(b,a,optr.top()));
					optr.pop();
					i--;
					break;
				case '<':
					optr.push(sList[i][0]);
					break;
				case '=':
					optr.pop();
					break;
			}
		}
	}
	cout<<fixed<<setprecision(2)<<opnd.top()<<endl;
}
int main(){
	string s,*sList;
	while(1){
		cin>>s;
		if(s=="="){
			break;
		}
		sList=new string[s.length()];
		toList(s,sList);
		operate(sList);
	}
	return 0;
}
