#include <iostream>
using namespace std;
bool isSafe(int board[10][10],int i,int j,int n){
    //col wise
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    //diagonal wise
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool nQueenRow(int board[10][10],int i,int n){

    //base case
    if(i==n){
        //print board
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                if(board[a][b]==1){
                    cout<<"Q ";
                }else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //rec case
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            bool nextQ=nQueenRow(board,i+1,n);
            if(nextQ==false){
                board[i][j]=0;
            }else{
                return true;
            }
        }
    }
    return false;
}
int main(){
 int n;
 cin>>n;
 int board[10][10]={0};
 nQueenRow(board,0 ,n);
}
