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
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
//求二叉树的高度 
int getDepth(biTree T){
	int m,n;
	if(T){
		m=getDepth(T->left);
		n=getDepth(T->right);
		if(m>n){
			return m+1;
		}else{
			return n+1; 
		}
	}else{
		return 0;
	}
}
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		k=-1;
		createTree(T,s);
		cout<<getDepth(T)<<endl;
	}
	return 0;
}
