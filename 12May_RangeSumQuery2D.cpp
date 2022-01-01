/*Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 */

#include<bits/stdc++.h>
using namespace std;

int sumRegion(vector<vector<int>> m, int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1; i<=row2; i++){
            sum=accumulate(m[i].begin()+col1, m[i].begin()+col2+1, sum);
        }
        return sum;
    }

 int main(){
 	int n,m,x,Row1, Col1, Row2, Col2;
	cout<<"Enter n,m:"<<endl;
	cin>>n>>m;
	cout<<"Array:"<<endl;
	vector<vector<int>> v1;

	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<m; j++){
			cin>>x;
			v.push_back(x);
		}
		v1.push_back(v);
	}
	cout<<"No of testcases:"<<endl;
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"Row1, Col1, Row2, Col2:"<<endl;
		cin>>Row1>>Col1>>Row2>>Col2;
		cout<<"Region sum is: "<<sumRegion(v1, Row1, Col1, Row2, Col2)<<endl;
	}
 }

 /*
5 5
3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5
3
2 1 4 3
1 1 2 2 
1 2 2 4
expected output: 8 11 12
 */