#include <iostream>
using namespace std;

int getSize(const string& prompt) {
    int size;
    do {
        cout << prompt;
        cin >> size;
        if (size <= 0 || size > 10)
            cout << "size from 1 to 10.\n";
    } while (size <= 0 || size > 10);
    return size;
}


void inputMatrix(int** matrix, int lines, int cols) {
    cout << "enter a[1][1]: ";
    cin >> matrix[0][0];


for (int i = 0; i < lines; ++i)
        for (int j = 0; j < cols; ++j)
            if (i == 0 && j == 0) continue;
            else if ((i + j) % 2 == 0)
                matrix[i][j] = matrix[0][0];
            else {
                cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> matrix[i][j];
            }
}


void printMatrix(int** matrix, int lines, int cols) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}


int lineCharacteristic(int* line, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; ++j)
        if (line[j] > 0) sum += line[j];
    return sum;
}


void sortLines(int** matrix, int lines, int cols) {
    for (int i = 0; i < lines - 1; ++i)
        for (int k = i + 1; k < lines; ++k)
            if (lineCharacteristic(matrix[i], cols) > lineCharacteristic(matrix[k], cols)) {
                for (int j = 0; j < cols; ++j)
                    swap(matrix[i][j], matrix[k][j]);
            }
}


int countNeZeroColumns(int** matrix, int lines, int cols) {
    int count = 0;
    for (int j = 0; j < cols; ++j) {
        bool hasZero = false;
        for (int i = 0; i < lines; ++i)
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        if (!hasZero) ++count;
    }
    return count;
}

int main() {
    int lines = getSize("Enter number of lines: ");
    int cols = getSize("Enter number of columns: ");

int** matrix = new int*[lines];
    for (int i = 0; i < lines; ++i)
        matrix[i] = new int[cols];


inputMatrix(matrix, lines, cols);


cout << "original matrix"<< endl;
    printMatrix(matrix, lines, cols);


sortLines(matrix, lines, cols);
    cout << "matrix after sorting" << endl;
    printMatrix(matrix, lines, cols);


int neZeroCols = countNeZeroColumns(matrix, lines, cols);
    cout << "number of columns without 0: " << neZeroCols << endl;


for (int i = 0; i < lines; ++i)
        delete[] matrix[i];
    delete[] matrix;

return 0;
}
