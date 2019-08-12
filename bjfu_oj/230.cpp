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
int main(){
	LNode p,L,e,a,b;
	int n;
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
		a=L->next;
		b=a;
		while(a){
			if(a->c>b->c){
				b=a;
			}
			a=a->next;
		}
		cout<<b->c<<endl;
		cin>>n;
	}
	return 0;
}
