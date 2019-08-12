#include"iostream"
#include"string"
using namespace std;
typedef struct{
	char c;
	int num;	
}List;
typedef struct{
	List *list;
	int len;
}sqList;
void initList(sqList &L){
	L.list=new List[36];
	L.len=0;
}
int main(){
	sqList L;
	string str;
	while(1){
		cin>>str;
		if(str=="0"){
			break;
		}
		initList(L);
		for(int i=0;i<10;i++){
			L.list[i].c='0'+i;
			L.list[i].num=0;
			L.len++;
		}
		for(int i=10;i<36;i++){
			L.list[i].c='A'+i-10;
			L.list[i].num=0;
			L.len++;
		}
		for(int i=0;i<str.length();i++){
			for(int j=0;j<36;j++){
				if(str[i]==L.list[j].c){
					L.list[j].num++;
				}
			}
		}
		for(int j=0;j<36;j++){
			if(L.list[j].num!=0){
				cout<<L.list[j].c<<":"<<L.list[j].num<<endl;
			}
		}
	}
	return 0;
}
