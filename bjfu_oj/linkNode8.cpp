#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct  linkNode{
	linkNode *next;
	book data;
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
void getList(LNode L){
	LNode p;
	p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	}
}
int main(){
	LNode L,p,q;
	initNode(L);
	createList(L);
	int id;
	book newBook;
	cin>>id;
	cin>>newBook.no>>newBook.name>>newBook.price;
	p=L;
	while(p){
		id--;
		if(id==0){
			initNode(q);
			q->data=newBook;
			q->next=p->next;
			p->next=q;
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		cout<<"抱歉，入库位置非法！"<<endl;
	}else{
		getList(L);
	}
	return 0;
}
