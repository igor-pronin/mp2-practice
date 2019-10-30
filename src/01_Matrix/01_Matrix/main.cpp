#include <iostream>
#include <locale.h>
#include "Matrix.h"
int main()
{
	int choise, size, startIndex, _size, _startIndex, msize, m_size, t_size, t_startIndex;
	setlocale(LC_ALL, "Russian");
	//cout << "Введите 1, если хотите протестировать векторы, введите 2, если хотите протестировать матрицы" << endl;
	//cin >> choise;
	//switch (choise)
	//{
	//case 1:
		/*cout << "Vector testing!" << endl;
		cout << "Введите размер первого вектора" << endl;
		cin >> size;
		cout << "Ввдите стартиндекc вектора" << endl;
		cin >> startIndex;
		TVector<int> A(size, startIndex);
		cout << "Введите координаты вектора" << endl;
		cin >> A;
		cout << "Вектор A:" << endl;
		cout << A << endl;
		cout << "Введите размер второго вектора" << endl;
		cin >> _size;
		cout << "Введите стартиндекс вектора" << endl;
		cin >> _startIndex;
		TVector<int> B(_size, _startIndex);
		cout << "Введите координаты вектора" << endl;
		cin >> B;
		cout << "Вектор B:" << endl;
		cout << B << endl;

		cout << "A==B: " << (A == B) << endl;
		cout << "A!=B: " << (A != B) << endl;
		cout << "A+5: " << A + 5 << endl;
		cout << "A-5: " << A - 5 << endl;
		cout << "A*5: " << A * 5 << endl;
		cout << "A/5: " << A / 5 << endl;
		cout << "A+B: " << A + B << endl;
		cout << "A-B: " << A - B << endl;
		cout << "A*B: " << A * B << endl;
		cout << "Длина вектора A: " << A.Length() << endl;
		cout << "A=B: " << (A = B) << endl;
		cout << "A[0]: " << A[0] << endl;*/
		//break;
	//case 2:
		cout << "Matrix testing!" << endl;
		cout << "Введите размер первой матрицы" << endl;
		cin >> msize;
		TMatrix<int> C(msize);
		cout << "Введите координаты матрицы " << endl;
		cin >> C;
		cout << "Матрица C:" << endl;
		cout << C;
		/*cout << "Введите размер второй матрицы" << endl;
		cin >> m_size;
		TMatrix<int> D(m_size);
		cout << "Введите координаты матрицы" << endl;
		cin >> D;
		cout << "Матрица D:" << endl;
		cout << D;
		cout << "Введите размер вектора для проверки операции умножения матрицы на вектор" << endl;
		cin >> t_size;
		cout << "Ввдите стартиндекс вектора" << endl;
		cin >> t_startIndex;
		TVector<int> E(t_size, t_startIndex);
		cout << "Введите координаты вектора" << endl;
		cin >> E;
		cout << "Вектор E:" << endl;
		cout << E << endl;

		cout << "C==D: " << (C == D) << endl;
		cout << "C!=D: " << (C != D) << endl;
		cout << "C+5: " << C + 5 << endl;
		cout << "C-5: " << C - 5 << endl;
		cout << "C*5: " << C * 5 << endl;
		cout << "C*E: " << C * E << endl;
		cout << "C+D: " << C + D << endl;
		cout << "C-D: " << C - D << endl;
		//cout << "C*D: " << C * D << endl;
		cout << "C=D: " << (C = D) << endl;*/
		//break;
	//default:
		//cout << "Выбранный вариант отсутствует" << endl;
	//}
	system("pause");
}