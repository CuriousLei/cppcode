#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
struct LNode{
	book data;
	LNode *next;
};
void initList(LNode *&L){
	L=new LNode;
	L->next=NULL;
}
//ºó²å·¨ 
int createList(LNode *L){
	LNode *node,*p;
	string no,name;
	float price;
	int k=0;
	p=L;
	cin>>no>>name>>price;
	while(no!="0"&&name!="0"&&price!=0){
		initList(node);
		node->data.no=no;
		node->data.name=name;
		node->data.price=price;
		p->next=node;
		p=p->next;
		k++;
		cin>>no>>name>>price;
	}
	return k;
}
void getList(LNode *L){
	LNode *p;
	p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	}
}
int main(){
	LNode *L;
	initList(L);
	cout<<createList(L)<<endl;
	getList(L);
	return 0;
}
