#include"iostream"
#include"string"
#include"iomanip"
#include"queue"
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
void find(LNode L,queue <string> nameL){
	while(!nameL.empty()){
		string name = nameL.front();
		queue <book> temp;
		nameL.pop();
		LNode p=L->next;
		while(p){
			if(p->data.name==name){
				temp.push(p->data);
			}
			p=p->next;
		}
		if(temp.size()==0){
			cout<<"Sorry£¬there is no your favourite!"<<endl;
		}else{
			cout<<temp.size()<<endl;
			while(!temp.empty()){
				cout<<temp.front().no<<" "<<temp.front().name<<" "<<fixed<<setprecision(2)<<temp.front().price<<endl;
				temp.pop();
			}
		}
	}
}
int main(){
	LNode L;
	int n;
	string str;
	queue <string> nameL;
	initNode(L);
	createList(L);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		nameL.push(str);
	}
	find(L,nameL);
	return 0;
}
