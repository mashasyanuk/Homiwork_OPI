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

        for (int i = 0; i < m_size; i++) {
            int max_=0;
            int needed_index=0;

			for (int j = 0; j < m_size; j++) {
                if (m_matrix[i][j]>max_){
                    max_=m_matrix[i][j];
                    needed_index=j;
                }
			}
            int result=Multipultion(i, needed_index);
            cout << "В ряду " << i << "произведение после максимума: " << result << endl;

		}
	}

    int Multipultion(int index_i, int index_j){
        int total=1;
        for(int j=(index_j+1); j<m_size; j++){
            total*=m_matrix[index_i][j];
        }
        return total;
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
	
int InputMenu(){
    cout << endl;
    cout << "1- Для вывода матрицы" << endl;
    cout << "2- Найти поизведение элементов, расположенный после максимального в строке" << endl;
    cout << "3- Поверка на симметричность строк относительно среднего элемента" << endl;
    cout << "4- Вычислить сумму элеметров в нижнем треугольнике" << endl;
    cout << "0- Выход" << endl;
    int menuNumber = 0;
    cin >> menuNumber;
    return menuNumber;
}

void MenuLoop(Matrix& Mat) {
	int menuItem = -1;
	int left = 0, right = 0;
	while (menuItem != 0) {
		menuItem = InputMenu();
		switch(menuItem){
			case 1:
				Mat.printMatrix();
				break;
			case 2:
				Mat.isPositiveRow();
				break;
			case 3:
				Mat.printMultAfterMax();
				break;
			case 4:
				Mat.getTriangleSum();
				break;
			case 0:
				break;
			default:
				cout << "Неправильно выбрана команда, повторите ввод" << endl;
				break;
		}
	}
}

int main() {
	#pragma region init
	srand(unsigned(time(NULL)));
	Matrix Mat(16, -9, 9);
	Mat.fillMatrix();
	#pragma endregion init
   	
	MenuLoop(Mat);

	return 0;
}