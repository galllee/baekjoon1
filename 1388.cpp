#include <iostream>
using namespace std;

int main(){
    int n, m, count=0, k=0;
    char arr[50][50];
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='-'){
                count++;
                for(k=j+1; k<m; k++){
                    if(arr[i][k]=='-') continue; 
                    else if(arr[i][k]=='|') {j=k; break;} 
                }
                if(k==m)break;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[j][i]=='|'){
                count++;
                for(k=j+1; k<n; k++){
                    if(arr[k][i]=='|') continue; 
                    else if(arr[k][i]=='-') {j=k; break;} 
                }
                if(k==n)break;
            }
        }
    }
    cout<<count;
    return 0;
}