#include <bits/stdc++.h>
using namespace std;


//for making the lps array
void making_lps(vector<int>&lps, int sizeOfPattern, string pattern){
	int index =0;
	for(int i=1; i < sizeOfPattern;){
		if(pattern[i] == pattern[index]){
			lps[i] = index + 1;
			index++;
			i++;
		}else{
			if(index != 0){
				index = lps[index-1];
			}else{
				lps[i] =0;
				i++;
			}
		}
	}
}

bool KMP_ALgorithm(string text, string pattern){
	vector<int>lps(pattern.size(),0);

	making_lps(lps, pattern.size(), pattern);

	for(int i= 0 ;i<lps.size(); i++){
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	int i = 0, j = 0;

	while(i < text.size() && j< pattern.size()){
		if(pattern[i] ==  text[i]){
			i++,j++;
		}
		else{
			if(j!=0){
				j = lps[j-1]; 
			}
			else{
				i++;
			}
		}
	}
	if(j == pattern.size())return true;
	return false;
}

int main(){
	string text, pattern;
	text = "AABAACAADAABAABA";
	pattern = "abcabcabcabc";

	cout<<KMP_ALgorithm(text, pattern);
}