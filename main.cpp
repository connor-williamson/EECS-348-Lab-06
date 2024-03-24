#include <iostream>
#include <fstream>
using namespace std;

#define N 3

void readMatriciesFromFile(const string& filename, int matrix1[][N], int matrix2[][N]);
void printMatrix(int matrix[][N]);

void matrixAddition(int matrix1[][N], int matrix2[][N], int sum[][N]);
void matrixMultiplication(int matrix1[][N], int matrix2[][N], int product[N][N]);
void matrixSubtraction(int matrix1[][N], int matrix2[][N], int difference[][N]);

void updateElement(int matrix[][N], int row, int column, int newElement);
int getMaxValue(int matrix[][N]);
void transposeMatrix(int matrix[][N]);

int main() {
    int matrix1[N][N] = {0}, matrix2[N][N] = {0};
    int sum[N][N] = {0}, product[N][N] = {0}, difference[N][N] = {0}, transposedMatrix[N][N] = {0};
    int maxValue, newElement, row, column;

    readMatriciesFromFile("input-file.txt", matrix1, matrix2);
    matrixAddition(matrix1, matrix2, sum);
    matrixMultiplication(matrix1, matrix2, product);
    matrixSubtraction(matrix1, matrix2, difference);

    cout << "Matrix 1:" << endl;
    printMatrix(matrix1); 
    cout << endl << "Matrix 2:" << endl;
    printMatrix(matrix2);
    cout << endl << "Matrix 1 + Matrix 2:" << endl;
    printMatrix(sum);
    cout << endl << "Matrix 1 * Matrix 2:" << endl;
    printMatrix(product);
    cout << endl << "Matrix 1 - Matrix 2:" << endl;
    printMatrix(difference);

    cout << endl << "Original Matrix 1:" << endl;
    printMatrix(matrix1);

    cout << "Enter a row:";
	cin >> row;
	cout << "Enter a column:";
	cin >> column;
	cout << "Enter a value:";
	cin >> newElement;
    updateElement(matrix1, row, column, newElement);
    cout << endl << "Updated Matrix 1:" << endl;
    printMatrix(matrix1);

    maxValue = getMaxValue(matrix1);
    cout << endl << "Max value of Matrix 1: " << maxValue;

    return 0;
}

void readMatriciesFromFile(const string& filename, int matrix1[][N], int matrix2[][N]) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix1[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix2[i][j];
        }
    }
    
    file.close();
}

void printMatrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixAddition(int matrix1[][N], int matrix2[][N], int sum[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixMultiplication(int matrix1[][N], int matrix2[][N], int product[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			product[i][j] = 0;
			for (int k = 0; k < N; k++) {
				product[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

void matrixSubtraction(int matrix1[][N], int matrix2[][N], int difference[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void updateElement(int matrix[][N], int row, int column, int newElement) {
    if (row >= 0 && row < N && column >= 0 && column < N) {
        matrix[row][column] = newElement;
    } else {
        cout << "Error: Position out of bounds." << endl;
    }
}

int getMaxValue(int matrix[][N]) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}

void transposeMatrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
