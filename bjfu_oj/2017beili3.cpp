#include"iostream"
#include"algorithm"
using namespace std;
typedef struct{
	string name;
	int A;
	int B;
	int C;
	float mid;
}Stu;
bool cmp(Stu a,Stu b){
	return a.mid>b.mid;
}
int main(){
	int n;
	cin>>n;
	Stu *stu=new Stu[n];
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].A>>stu[i].B>>stu[i].C;
		stu[i].mid=(float)(stu[i].A+stu[i].B+stu[i].C)/3;
	}

	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++){
		if(stu[i].A<60 || stu[i].B<60 || stu[i].C<60){
			cout<<"*"<<stu[i].name<<" "<<stu[i].A<<" "<<stu[i].B<<" "<<stu[i].C<<" "<<endl;
		}
	}
	for(int i=0;i<n;i++){
		cout<<stu[i].name<<" "<<stu[i].A<<" "<<stu[i].B<<" "<<stu[i].C<<" "<<stu[i].mid<<endl;
	}
	return 0;
}
