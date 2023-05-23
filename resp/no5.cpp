#include <iostream>
using namespace std;
int row, col, matrix[100][100];

void input();
void lower();
void upper();

int main (){
    cout<<"Masukkan baris dan kolom";
    cin>>row>>col;
    input ();
}

void input (){
    cout<<"input matrix"<<endl;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cin>>matrix[i][j];
        }
    }
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout<<matrix[i][j];
        } cout<<endl;
    }
    lower ();
    upper ();
} 

void lower (){
    cout<<"Lower Triangular"<<endl;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (i>=j){
                cout<<" "<<matrix[i][j];
            }  
            else cout<<" 0";
        }cout<<endl;
    }
}

void upper (){
    cout<<"Upper Triangular"<<endl;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (i<=j){
                cout<<" "<<matrix[i][j];
            }
            else cout<<" 0";
        }cout<<endl;
    }
}