#include"iostream"
using namespace std;
typedef struct TNode{
	TNode *left,*right;
	char v;	
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->left=NULL;
	T->right=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='#'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
int flag=1;
void ifSortTree(biTree &T){
	if(T){
		if(T->left){
			if(T->left->v>=T->v){
				flag=0;
			}
		}
		if(T->right){
			if(T->right->v<T->v){
				flag=0;
			}
		}
		ifSortTree(T->left); 
		ifSortTree(T->right);
	}
	
}
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="#"){
			break;
		}
		k=-1;
		createTree(T,s);
		ifSortTree(T);
		if(flag==0){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
