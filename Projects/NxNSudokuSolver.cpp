#include <bits/stdc++.h>
using namespace std;

void Show(int *grid, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i*n+j]<<" ";
        }
        cout<<endl;
    }
}

bool Full(int *grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i*n+j] != 0){
                return false;
            }
        }
    }
    return true;
}

vector<int> possibilityArray(int *grid,int i,int j,int n){

    vector<int> arr(10,0);

    for(int h=0;h<n;h++){
        if(grid[i*n+h] != 0){
            arr[grid[i*n+h]] =1;
        }
    }

    for(int k=0;k<n;k++){
        if(grid[k*n+j] != 0){
            arr[grid[k*n+j]] = 1;
        }
    }

    int m,p;
    if(i >= 0 && i<=2){
        m =0;
    }
    else if(i >= 3 && i <= 5){
        m = 3;
    }
    else{
        m = 6;
    }
     if(j >= 0 && j<=2){
        p =0;
    }
    else if(j >= 3 && j <= 5){
        p = 3;
    }
    else{
        p = 6;
    }

    for(int u = m;u<m+3;u++){
        for(int v = p; v< p+3; v++){
            if(grid[u*3+v] != 0){
                arr[grid[u*3+v]] =1;
            }
        }
    }

    for(int x=1;x<10;x++){
        if(arr[x] == 0){
            arr[x] = x;
        }
        else{
            arr[x] = 0;
        }
    }

    return arr;

}

void sudokuSolver(int *grid, int n){

    vector<int> arr(10,0);  
    int i=0;
    int j=0;
    int flag = 0;

    if(Full((int *)grid,n)){
        cout<<"Successfully done"<<endl;
        Show((int *)grid,n);
    }
    else{

        for(int x = 0; x < n ; x++){
            for(int y =0;y<n;y++){
                if( grid[x*n+y] == 0){
                    i = x;
                    j = y;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }

        arr = possibilityArray((int *)grid,i,j,n);

        for(int k=1;k<10;k++){
            if(arr[k] != 0){
                grid[i*n+j] = arr[k];
                sudokuSolver((int *)grid,n);
            }
        }

        grid[i*n+j] = 0;

    }

}

int main(){
    cout<<"Enter the grid size (N)"<<endl;
    int k,h,ele,n;
    cin>>n;
    int grid[n][n];
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid[i][j] = 0;
        }
    }
    do{
        cout<<"Enter the ele position to insert and the element also"<<endl;
        cin>>k>>h>>ele;
        grid[k][h] = ele;
        cout<<"Do you want to insert more Y/n"<<endl;
        char y;
        cin>>y;
        if(y != 'Y'){
            ok = false;
        }

        
    }
    while(ok);
    Show((int *)grid,n);
    sudokuSolver((int *)grid,n);
    return 0;
}