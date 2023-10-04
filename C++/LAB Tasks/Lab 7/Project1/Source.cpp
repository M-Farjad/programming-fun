//task 3
#include<iostream>
using namespace std;
const int ROW = 2;
const int COL = 2;

class Matrix {
private:
	int arr[ROW][COL];
public:
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	friend ostream& operator << (ostream& cout, Matrix& obj);
	friend istream& operator >> (istream& cout, Matrix& obj);
};

Matrix Matrix::operator + (const Matrix& right) {
	Matrix temp;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp.arr[i][j] = arr[i][j] + right.arr[i][j];
		}
	}
	return temp;
}
Matrix Matrix::operator - (const Matrix& right) {
	Matrix temp;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp.arr[i][j] = arr[i][j] - right.arr[i][j];
		}
	}
	return temp;
}
istream& operator >> (istream& strm, Matrix& obj) {
	for (int i = 0; i < ROW; i++) {

		for (int j = 0; j < COL; j++) {
			cout << "Enter val : ";
			cin >> obj.arr[i][j];
		}
		cout << endl;
	}
	return strm;
}
ostream& operator << (ostream& strm, Matrix& obj) {

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << obj.arr[i][j] << " ";
		}
		cout << endl;
	}
	return strm;
}
int main() {
	Matrix m1, m2, m3;
	cin >> m1;
	cin >> m2;
	m3 = m1 + m2;
	cout << "These are the values of addition";
	cout << m3;
	m3 = m1 - m2;
	cout << "These are the values of subtraction";
	cout << m3;
	return 0;
}