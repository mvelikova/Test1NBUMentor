#include <iostream>
using namespace std;
int main() {
    int rows;
    cin>>rows;
    //Създаваме динамичен двумерен масив  и въвеждаме стойности в него
    double ** matrix=new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i]=new double[rows];
        for (int j = 0; j < rows; ++j) {
            cin>>matrix[i][j];
        }
    }

   //Проверяваме дали матрицата е единична
    bool isIdentityMatrix=true;
    for (int k = 0; k < rows; ++k) {
        for (int i = 0; i < rows; ++i) {
            if(k==i && matrix[k][i]!=1){
               isIdentityMatrix= false;
                break;
            } else if(k!=i && matrix[k][i]!=0){
                isIdentityMatrix=false;
                break;
            }
        }
        if(!isIdentityMatrix) break;
    }

    if(isIdentityMatrix) cout<<"This is an identity matrix"<<endl;
    else cout<<"This is NOT an identity matrix"<<endl;

    for(int i=0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}