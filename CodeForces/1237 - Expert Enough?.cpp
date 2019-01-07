#include <bits/stdc++.h>
using namespace std;

struct data
{
	int low, high;
	string name;
};

bool compare(data a, data b){
	return a.low<b.low;
}



int main(){

	//freopen("input.txt","r",stdin);

	int test;
	cin>>test;
	int kk=0;
	while(test--){
		vector<data>v;
		if(kk!=0)cout<<endl;

		kk++;


		int database;
		cin>>database;

		while(database--){
			string s;
			int lp, hp;
			cin>>s>>lp>>hp;


			data person;

			person.name = s;
			person.low = lp;
			person.high = hp;

			v.push_back(person); 
		}

		int q;
		cin>>q;
		while(q--){
			int price;
			cin>>price;

			int countt=0,j=0;

			for(int i= 0; i<v.size() ; i++){
				if(v[i].low <= price && price <= v[i].high){
					countt++;

					if(countt>1)break;
					j=i;
				}

			}

			if(countt==0 || countt >1){
				cout<<"UNDETERMINED"<<endl;
			}
			else{
				cout<<v[j].name<<endl;
			}
		}
	}
}