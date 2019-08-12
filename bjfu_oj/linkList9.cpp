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
	LNode p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	}
}
int main(){
	LNode L,p,e;
	initNode(L);
	createList(L);
	int id;
	cin>>id;
	p=L;
	while(p){
		id--;
		if(id==0){
			e=p->next;
			p->next=e->next;
			delete e;
			break;
		}
		p=p->next;
	}
	if(p!=NULL){
		getList(L);
	}
	return 0;
}
