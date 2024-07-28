#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    Matrix(const vector<vector<int>>& data) : data(data) {
        rows = data.size();
        cols = data[0].size();
    }
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices dimensions must be the same for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Number of columns of the first matrix must be equal to the number of rows of the second matrix.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                out << matrix.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns for matrix A: ";
    cin >> rows >> cols;
    Matrix A(rows, cols);
    cout << "Enter elements of matrix A:" << endl;
    cin >> A;

    cout << "Enter number of rows and columns for matrix B: ";
    cin >> rows >> cols;
    Matrix B(rows, cols);
    cout << "Enter elements of matrix B:" << endl;
    cin >> B;

    try {
        Matrix C = A + B;
        cout << "Matrix A + B:" << endl << C;
    } catch (const invalid_argument& e) {
        cout << "Addition error: " << e.what() << endl;
    }

    try {
        Matrix D = A * B;
        cout << "Matrix A * B:" << endl << D;
    } catch (const invalid_argument& e) {
        cout << "Multiplication error: " << e.what() << endl;
    }

    if (A == B) {
        cout << "Matrix A is equal to Matrix B." << endl;
    } else {
        cout << "Matrix A is not equal to Matrix B." << endl;
    }

    return 0;
}
