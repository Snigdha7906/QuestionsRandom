/*Given a matrix of size R*C. Traverse the matrix in spiral form.

        Tr=0    {{1,  2,  3,  4},
                {5,  6,  7,  8},
                {9,  10, 11, 12},
        Br=n-1  {13, 14, 15, 16}}
                Lc=0         Rc=m-1
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int direction=0;
        
        // Right ->Down ->Left ->Top ->Right
        //   0      1       2     3      0
        
        
        int Tr=0, Br=n-1, Lc=0, Rc=m-1; //top bottom row & left right col 
        
        while(Lc<=Rc && Tr<=Br){
            
            if(direction==0){           //Left to right
                for(int i=Lc; i<=Rc; i++){
                    v.push_back(matrix[Tr][i]);
                }
                
                Tr++;           
                direction=1;    // moving to downward direction;
            }
            
            else if(direction==1){
                for(int i=Tr; i<=Br; i++){
                    v.push_back(matrix[i][Rc]);
                }
                
                Rc--;
                direction=2;    // moving to left direction
            }
            
            else if(direction==2){
                for(int i=Rc; i>=Lc; i--){
                    v.push_back(matrix[Br][i]);
                }
                
                Br--;
                direction=3;
            }
            
            else if(direction==3){
                for(int i=Br; i>=Tr; i--){
                    v.push_back(matrix[i][Lc]);
                }
                
                Lc++;
                direction=0;
            }
        }
        
        return v;
        
    }

int main(){
	int n,m,x;
	vector<vector<int>> v;
	for (int i = 0; i < n; ++i)
	{
		vector<int> v1;
		for (int j = 0; j < m; ++j)
		{
			cin>>x;
			v1.push_back(x);
		}
		v.push_back(v1);
	}
	vector<int> ans;
	ans= spiralOrder(v);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout<<v[i][j];
	}
}