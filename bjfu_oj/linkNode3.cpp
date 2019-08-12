#include"iostream"
#include"iomanip"
#include"string"
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
	LNode p,q;
	string no,name;
	float price;
	q=L;
	cin>>no>>name>>price;
	while(no!="0"||name!="0"||price!=0){
		initNode(p);
		q->next=p;
		p->data.no=no;
		p->data.name=name;
		p->data.price=price;
		p->next=NULL;
		q=p;
		cin>>no>>name>>price;
	}
}
void change(LNode L){
	LNode p;
	float med=0,k=0;
	p=L->next;
	while(p){
		med+=p->data.price;
		p=p->next;
		k++;
	}
	med=med/k;
	p=L->next;
	while(p){
		if(p->data.price<med){
			p->data.price=p->data.price*1.2;
		}else{
			p->data.price=p->data.price*1.1;
		}
		p=p->next;
	}
	cout<<fixed<<setprecision(2)<<med<<endl;
	
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
	change(L);
	getList(L);
	return 0;
}
