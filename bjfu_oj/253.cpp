#include"iostream"
#include"iomanip"
using namespace std;
typedef struct node{
	node *next;
	float value;
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void createList(LNode L,int n){
	LNode p,e;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		e->next=p;
		e=p;
	}
}
float med(LNode p,int n){
	if(p==NULL){
		return 0;
	}
	return p->value/n+med(p->next,n);
}
int main(){
	LNode L;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		L->value=n;
		createList(L,n);
		cout<<fixed<<setprecision(2)<<med(L->next,n)<<endl;
	}
	return 0;
}
