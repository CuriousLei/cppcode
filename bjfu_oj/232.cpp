#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int c;	
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void oprate(LNode L,int min,int max){
	LNode p,p0;
	p=L->next;
	p0=L;
	while(p){
		if(p->c>=min&&p->c<=max){
			p0->next=p->next;
			delete p;
			p=p0->next;
			continue;
		}
		p0=p0->next;
		p=p->next;
	}
}
void getList(LNode L){
	LNode p;
	p=L->next;
	while(p){
		cout<<p->c;
		p=p->next;
		if(p==NULL){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	LNode L,p,e;
	int n,min,max;
	cin>>n;
	while(n!=0){
		initNode(L);
		e=L;
		for(int i=0;i<n;i++){
			initNode(p);
			cin>>p->c;
			e->next=p;
			e=p;
		}
		cin>>min>>max;
		oprate(L,min,max);
		getList(L);
		cin>>n;
	}
	return 0;
}
