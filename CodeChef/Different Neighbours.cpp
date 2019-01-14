#include <bits/stdc++.h>
using namespace std;
int mat[55][55];
void solve(int n, int m){
	
	bool flag[5]={false};

	for(int i= 1 ;i<=n;i++){
		for(int j=1 ; j<=m ;j++){
			int left = j-2;
			int upperLeftX = i-1, upperLeftY = j-1;
			int upperRightX = i-1, upperRightY = j+1;
			int upper = i-2;



			if( i==1 && j<=2 ){
				mat[i][j] = 1;
			}
			else if( i == 1 && j>2){
				mat[i][j] = (mat[i][left] == 1) ?2 :1 ;
			}
			else {

				memset(flag, false, sizeof(flag));
				if(left >= 1 && upperRightX>=1 && upperRightY<=m && upperLeftX>=1 && upperLeftY<=m && upper>=1 ){
					flag[mat[i][left]] = true;
					flag[mat[upperLeftX][upperLeftY]] = true; 
					flag[mat[upperRightX][upperRightY]] = true;
					flag[mat[upper][j]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if(upperRightX>=1 && upperRightY<=m && upperLeftX>=1 && upperLeftY<=m && upper>=1){
					flag[mat[upperLeftX][upperLeftY]] = true; 
					flag[mat[upperRightX][upperRightY]] = true;
					flag[mat[upper][j]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}	
				}
				else if(left >= 1 &&  upperLeftX>=1 && upperLeftY<=m  && upper>=1){
					flag[mat[upperLeftX][upperLeftY]] = true; 
					flag[mat[i][left]] = true;
					flag[mat[upper][j]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if(left >= 1 && upperRightX>=1 && upperRightY<=m && upperLeftX>=1 && upperLeftY<=m){
					flag[mat[i][left]] = true;
					flag[mat[upperLeftX][upperLeftY]] = true; 
					flag[mat[upperRightX][upperRightY]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}	
				}
				else if(upperRightX>=1 && upperRightY<=m  && upper>=1){
					flag[mat[upperRightX][upperRightY]] = true;
					flag[mat[upper][j]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if( upperRightX>=1 && upperRightY<=m && upperLeftX>=1 && upperLeftY<=m ){
					flag[mat[upperLeftX][upperLeftY]] = true; 
					flag[mat[upperRightX][upperRightY]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if(left >= 1 &&  upperLeftX>=1 && upperLeftY<=m ){
					flag[mat[i][left]] = true;
					flag[mat[upperLeftX][upperLeftY]] = true; 
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if(upperRightX>=1 && upperRightY<=m){
					flag[mat[upperRightX][upperRightY]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
				else if(upperLeftX>=1 && upperLeftY>=1){
					flag[mat[upperLeftX][upperLeftY]] = true;
					
					for(int k = 4; k>=1 ;k--){
						if(!flag[k]){
							mat[i][j] = k;
							break;
						}
					}
				}
			}
		}
	}


	for(int i = 1;i<= n;i++){
		for(int j = 1 ;j<=m;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){

		int n,m;
		cin>>n>>m;

		solve(n,m);
	}

}