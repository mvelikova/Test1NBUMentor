#include <iostream>
using namespace std;
int main() {
    //Въвеждаме броя на редовете и колоните
    int rows,cols;
    cin>>rows>>cols;

    //Създаваме динамичен двумерен масив  и въвеждаме стойности в него
    double ** matrix=new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i]=new double[cols];
        for (int j = 0; j < cols; ++j) {
            cin>>matrix[i][j];
        }

    }
    //Създаване на транспонентна матрица
    double** trans=new double *[cols];
    for(int i=0; i < cols; i++)
    {
        trans[i]=new double[rows];
    }

    //Попълване на новата транспонирана матрица
    for (int l = 0; l < rows; ++l) {
        for (int i = 0; i < cols; ++i) {
            trans[i][l]=matrix[l][i];
        }
    }
    // Принтиране на новата матрица
    for (int k = 0; k < cols; ++k) {
        for (int i = 0; i <rows; ++i) {
            cout<<trans[k][i]<<" ";
        }
        cout<<endl;
    }
    //Осводождаване на заетата памет от 2те матрици
    for(int i=0; i < cols; i++)
    {
        delete[] trans[i];
    }
    delete[] trans;

    for(int i=0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}