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
	cin>>n;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->data.no>>p->data.name>>p->data.price;
		e->next=p;
		e=p;
	}
}
void find(LNode L,int id){
	LNode p=L->next;
	while(p){
		id--;
		if(id==0){
			cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		cout<<"Sorry£¬the book on the best position doesn't exist!"<<endl;
	}
}
int main(){
	LNode L;
	int n,id;
	initNode(L);
	createList(L);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>id;
		find(L,id);
	}
	return 0;
}
