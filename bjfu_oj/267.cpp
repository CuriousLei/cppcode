#include"iostream"
using namespace std;
typedef struct node{
	node *left,*right;
	char v;	
}*biTree;
typedef struct{
	string s;
	int n;
}sqItem;
typedef struct{
	sqItem *elem;
	int len;
}sqList;
void initNode(biTree &T){
	T=new node;
	T->left=NULL;
	T->right=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
void traverse(biTree T,int k,string s,sqList &L){
	if(T){
		traverse(T->left,k+1,s+T->v,L);
		traverse(T->right,k+1,s+T->v,L);
	}else{
		
		L.elem[L.len].n=k;
		L.elem[L.len].s=s;
		L.len++;
	}
}
int main(){
	biTree T;
	sqList L;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		T=NULL;
		k=-1;
		createTree(T,s);
		L.elem=new sqItem[k];
		L.len=0;
		traverse(T,0,"",L);
		sqItem max;
		max.n=0;
		for(int i=0;i<L.len;i++){
			if(L.elem[i].n>max.n){
				max=L.elem[i];
			}
		}
		cout<<max.n<<endl<<max.s<<endl;
	}
	return 0;
} 
