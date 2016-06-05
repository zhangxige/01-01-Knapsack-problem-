#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<queue>  
#include<climits>  
#include<cstring>  
using namespace std;  
const int c = 14;             //背包的容量  
const int w[] = {0,5, 4, 6, 3};//物品的重量，其中0号位置不使用 。   
const int v[] = {0,10, 40, 30, 50};//物品对应的待加，0号位置置为空。  
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //n为物品的个数  
int x[n+1]; 

void answer2(int m[][c+1],const int n)   //x存放哪些被选中
{  
    int j = c-1;  
    int i;  
    for(i = n; i > 1; i--)  
        if(m[i][j] == m[i-1][j]) x[i] = 0;  
        else                    {   
                                 x[i] = 1;  
                                 j = j - w[i];  
                                 }      
    x[1] = m[i][j] ? 1 : 0;   
} 

void way2_package0_1(int M[][c+1],const int w[],const int v[],const int n)//n代表物品的个数 
{
	for(int i=0;i<n+1;i++)
		for(int j=0;j<c+1;j++)
			M[i][j]=0;
	for(int i=1;i<n+1;i++)
		for(int j=1;j<=c;j++){
			if(j-w[i]<0) M[i][j]=M[i-1][j];
			else M[i][j]=M[i-1][j]>(M[i-1][j-w[i]]+v[i])?M[i-1][j]:M[i-1][j-w[i]]+v[i];
		}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<c+1;j++)
			cout<<M[i][j]<<"   ";
		cout<<endl;
	}
}

int main()
{
	int M[n+1][c+1];
	way2_package0_1(M,w,v,n);
	answer2(M,n);
	for(int i = 1; i <= n; i++)  
	cout << x[i] << " "; 
	system("pause");
	return 0;
}
