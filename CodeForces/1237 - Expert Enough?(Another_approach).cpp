#include <bits/stdc++.h>
using namespace std;

struct data
{
	data(string s, int l, int h){name=s, low= l, high=h;}
	data(int x){
		low = x;
	}
	int low, high;
	string name;
};

bool compare(data a, data b){
	return a.low<b.low;
}

vector<data>getHigherBound(vector<data> &v, int price){

	vector<data>:: iterator it;


	cout<<"asas"<<endl;
	it = lower_bound(v.begin(), v.end(), data{price},compare);
	cout<<int(it-v.begin())<<endl;
	cout<<"asasasasas"<<endl;
}

int main(){

	freopen("input.txt","r",stdin);

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


			data person(s,lp,hp);

			v.push_back(person); 
		}

		sort(v.begin(), v.end(), compare);
		int q;
		cin>>q;
		while(q--){
			int price;
			cin>>price;
			vector<data> a(getHigherBound(v,price));

		}
	}
}