#include"iostream"
using namespace std;
typedef struct{
	int *V;
	int top[2],bot[2];
	int m;
}DblStack;
void push(DblStack &dbStack,int v,int id){
	dbStack.V[dbStack.top[id]]=v;
	if(id==0){
		dbStack.top[id]++;
	}else{
		dbStack.top[id]--;
	}
}
int pop(DblStack &dbStack,int id){
	int v;
	if(id==0){
		v=dbStack.V[dbStack.top[id]-1];
		dbStack.top[id]--;
	}else{
		v=dbStack.V[dbStack.top[id]+1];
		dbStack.top[id]++;
	}
	return v;
} 
bool empty(DblStack &dbStack,int id){
	if(dbStack.top[id]==dbStack.bot[id]){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n,e0,e1,d0,d1,i,v,p;
	DblStack dbStack;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		dbStack.V=new int[n];
		dbStack.m=n;
		dbStack.bot[0]=0;
		dbStack.top[0]=0;
		dbStack.bot[1]=n-1;
		dbStack.top[1]=n-1;
		cin>>e0>>e1>>d0>>d1;
		for(i=0;i<e0;i++){
			cin>>v;
			push(dbStack,v,0);
		}
		for(i=0;i<e1;i++){
			cin>>v;
			push(dbStack,v,1);
		}
		//ÅÐ¶ÏÊÇ·ñÕ»Âú
		if(dbStack.top[0]>dbStack.top[1]){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
		//³öÕ» 
		for(i=0;i<d0;i++){
			cout<<pop(dbStack,0)<<" ";
		}
		if(empty(dbStack,0)){
			cout<<"0"<<endl;
		}else{
			cout<<"1"<<endl;
		}
		for(i=0;i<d1;i++){
			cout<<pop(dbStack,1)<<" ";
		}
		
		if(empty(dbStack,1)){
			cout<<"0"<<endl;
		}else{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
