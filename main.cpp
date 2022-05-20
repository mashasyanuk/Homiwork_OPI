#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
public:
	Matrix(const int _size, const int _startRange, const int _endRange) {
		m_startRange = _startRange;
		m_endRange = _endRange;
		if (_size > M_MMS) m_size = M_MMS;
		else m_size = _size;
		m_matrix = new int*[m_size];
		for (int i = 0; i < m_size; i++) {
			m_matrix[i] = new int[m_size];
		}
	}

	~Matrix() {
		for (int i = 0; i < m_size; i++) {
			delete[] m_matrix[i];
		}
		delete[] m_matrix;
	}

	void fillMatrix() {
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				m_matrix[i][j] = rand() % (m_endRange - m_startRange + 1) + m_startRange;//!
			}
		}
	}

	void printMatrix() {
		for (int i = 1; i < m_size; i++) {
			for (int j = 1; j < m_size; j++) {
				cout << setw(5) << m_matrix[i][j];
			}
		cout << endl;
		}
		cout << endl;
	}

	void printMultAfterMax() {
	}
	
	void isPositiveRow() {
	}

	void getTriangleSum() {
	}

private:
	int m_size;
	// Range is for fillMatrix() method
	int m_startRange;
	int m_endRange;

	int** m_matrix = nullptr;
	const int M_MMS = 100; // M_MAXMATRIXSIZE
};
	
