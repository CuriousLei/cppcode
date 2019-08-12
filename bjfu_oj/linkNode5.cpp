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
void findMax(LNode L){
	LNode p;
	queue <book> max;
	p=L->next->next;
	max.push(L->next->data);
	while(p){
		if(p->data.price>max.front().price){
			while(!max.empty()){
				max.pop();	
			}
			max.push(p->data);
		}else if(p->data.price==max.front().price){
			max.push(p->data);
		}
		p=p->next;
	}
	cout<<max.size()<<endl;
	while(!max.empty()){
		cout<<max.front().no<<" "<<max.front().name<<" "<<fixed<<setprecision(2)<<max.front().price<<endl;
		max.pop();
	}
	
}
int main(){
	LNode L;
	initNode(L);
	createList(L);
	findMax(L);
	return 0;
}
