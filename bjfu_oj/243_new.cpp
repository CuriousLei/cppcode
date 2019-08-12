#include"iostream"
using namespace std;
typedef struct{
	int *base;
	int *top;
	int stackSize;
}sqStack;
typedef struct{
	int *list;
	int len;
}sqList;
void pop(sqStack &S,int &e){
	if(S.base!=S.top){
		e=*--S.top;
	}else{
		e=-1;
	}
}
void push(sqStack &S,int v){
	*S.top++=v;
}
int  main(){
	sqStack S;//Õ» 
	sqList L;//³öÕ»ÐòÁÐ 
	int n,v;
	while(1){
		L.list=new int[10000];
		L.len=0;
		S.base=new int[10000];
		S.top=S.base;
		cin>>n;
		if(n==0){
			break;
		}
		for(int i=0;i<n;i++){
			cin>>v;
			if(v==-1){
				pop(S,L.list[L.len]);
				L.len++;
			}else{
				push(S,v);
			}
		}
		for(int i=0;i<L.len;i++){
			if(L.list[i]==-1){
				cout<<"POP ERROR"<<endl;
				break;
			}else{
				cout<<L.list[i]<<endl;	
			}
		}
	}
	return 0;
}
