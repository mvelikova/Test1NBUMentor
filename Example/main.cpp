#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int currentSum = 0;
    // upper part
    for (int row = 0; row <= ceil(n / 2.0) - 2; ++row) {
        for (int col = 1 + row; col < n - row - 1; ++col) {
            currentSum += matrix[row][col];
        }
    }
//cout<<currentSum<<endl;
    int bestSum = currentSum;

    //left part
    currentSum = 0;
    for (int col = 0; col <= ceil(n / 2.0) - 2; ++col) {
        for (int row = 1 + col; row < n - col - 1; ++row) {
            currentSum += matrix[row][col];
        }
    }
    // cout<<currentSum<<endl;

    if (bestSum < currentSum)bestSum = currentSum;
    // bottom part
    currentSum = 0;
    for (int row = n - 1; row > n / 2; --row) {
        for (int col = n - row; col <= row - 1; ++col) {

            currentSum += matrix[row][col];
        }
    }
    //cout<<currentSum<<endl;

    if (bestSum < currentSum)bestSum = currentSum;
    //right part
    currentSum = 0;

    for (int col = n - 1; col > n / 2; --col) {
        for (int row = n - col; row <= col - 1; ++row) {
           // cout << matrix[row][col] << endl;
            currentSum += matrix[row][col];
        }
    }
   // cout << currentSum << endl;

    if (bestSum < currentSum)bestSum = currentSum;

    for(int i=0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    cout << bestSum << endl;
    return 0;
}

