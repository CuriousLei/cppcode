#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;

typedef struct linkNode{
	book data;
	linkNode *next;	
}*LNode;
void initNode(LNode &L){
	L=new linkNode;
	L->next=NULL;
}
void createList(LNode L){
	LNode p,e;
	int n;
	e=L;
	cin>>n;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->data.no>>p->data.name>>p->data.price;
		e->next=p;
		e=p;
	}	
}
void reverse(LNode L){
	LNode p,e;
	p=L->next;
	while(p->next){
		e=p->next;
		p->next=e->next;
		e->next=L->next;
		L->next=e;
	}
}
void getList(LNode L){
	LNode p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	}
}
int main(){
	LNode L;
	initNode(L);
	createList(L);
	reverse(L);
	getList(L);
	return 0;
}
