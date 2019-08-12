#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	node *pre;
	int value;
}*LNode;
void initNode(LNode &L){
	L=new node;
}
void getList(LNode L){
	LNode p;
	p=L->next;
	while(p!=L){
		cout<<p->value;
		p=p->next;
		if(p==L){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
void createList(LNode &L,int n){
	LNode p,e;
	initNode(L);
	L->next=L;
	L->pre=L;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		p->next=L;
		e->next=p;
		p->pre=e;
		L->pre=p;
		e=p;
	}
}
void replace(LNode L,int id){
	LNode p;
	p=L;
	for(;id>0;id--){
		p=p->next;
	}
	p->pre->next=p->next;
	p->next->pre=p->pre;
	p->pre=p->pre->pre;
	p->next=p->pre->next;
	p->pre->next=p;
}

int main(){
	LNode L;
	int n,id;
	while(cin>>n){
		if(n==0){
			break;
		}
		createList(L,n);
		cin>>id;
		replace(L,id);
		getList(L);
	}
	return 0;
}
