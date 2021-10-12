#include<iostream>
#include<process.h>
using namespace std;

int matrx[9][9]={
    {0,0,0,0,0,0,0,0,0},
    {5,0,0,0,0,9,0,0,0},
    {0,0,6,0,0,0,0,0,0},
    {0,0,0,7,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,8,0,0,0,0},
    {0,0,0,0,0,0,9,0,0},
    {0,0,0,0,3,0,0,0,0}
};

int nearPair(int v){
    if(v>=0 && v<=2)
        return 2;
    else if(v>=3 && v<=5){
        return 5;
    }
    else{
        return 8;
    }
}

int nearest(int v){
    if(v>=0 && v<=2)
        return 0;
    else if(v>=3 && v<=5){
        return 3;
    }
    else{
        return 6;
    }
}



void display(){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
        	if(j==3 || j==6)
                cout<<" "<<matrx[i][j]<<" ";
            else
                cout<<matrx[i][j]<<" ";
        }
        if(i==2 || i==5)
            cout<<endl<<endl;
        else
            cout<<endl;
    }
}


bool isPos(int a,int b, int n){
    int i,j;
    for(i=0;i<9;i++){
        if(matrx[a][i]==n){
            return false;
        }
        if(matrx[i][b]==n){
            return false;
        }
    }
    for(i=nearest(a);i<=nearPair(a);i++){
        for(j=nearest(b);j<=nearPair(b);j++){
            if(matrx[i][j]==n)
                return false;
        }
    }
    return true;
}


bool sud_solver(){
    int i,j,k;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matrx[i][j]==0){
                for(k=1;k<10;k++){
                    if(isPos(i,j,k)){
                        matrx[i][j]=k;
                        if(sud_solver()){
                        	return true;
						}
						matrx[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    display();
    cout<<endl;
    sud_solver();
    display();
}