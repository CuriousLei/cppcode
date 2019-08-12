#include"iostream"
using namespace std;
typedef struct node{
	int v;
	node *next;
}*linkStack;
typedef struct{
	int len;
	int *list;
}sqList;
void initNode(linkStack &S){
	S=new node;
	S->next=NULL;
}
void pop(linkStack &S,int &e){
	if(S){
		linkStack p=S;
		e=S->v;
		S=S->next;
		delete p;
	}else{
		e=-1;
	}
}
void push(linkStack &S,int e){
	linkStack p;
	initNode(p);
	p->v=e;
	p->next=S;
	S=p;
}
int main(){
	linkStack S,p;
	sqList L;
	int n,v;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		S=NULL;
		L.list=new int[1000];
		L.len=0;
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
