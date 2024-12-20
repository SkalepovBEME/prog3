#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
using namespace std;


int main()
{
	setlocale(0, "");
	cout << "Задание 1.";
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int const N = 10;
	int arr[N][N];
	srand(time(NULL));
	int n = sizeof(arr) / sizeof(*arr);
	int m = sizeof(*arr) / sizeof(**arr);
	int* end = *arr + n * m - 1;
	for (int* p = *arr; p <= end; p++) 
		*p = rand() % (1 + N * N);	
	int shiftX = 0, shiftY = 0;
	int indicator = 1;
	int additionalVariable;
	int L = N;
	int F = 1;
	for (int* p = *arr; p <= end; p++) {
		if (shiftX < L && indicator == 1) {
			shiftX += 1;
			destCoord.X = (shiftX - 1) * m/(N / 5);
			destCoord.Y = shiftY *2+1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			additionalVariable = (shiftX - 1) * m/(N / 5);
		}
		else if (shiftX == L && indicator == 1) {
			shiftY += 1;
			destCoord.X = additionalVariable;
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			L -= 1;
		}
		else if (shiftY < L && indicator == 1) {
			shiftY += 1;
			destCoord.X = additionalVariable;
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
		}
		else if (shiftY == L && indicator == 1) {
			shiftX -= 1;
			destCoord.X = (shiftX - 1) * m/(N/5);
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			additionalVariable = (shiftX - 1) * m / (N / 5);
			indicator *= -1;
		}
		else if (shiftX > F && indicator == -1) {
			shiftX -= 1;
			destCoord.X = (shiftX - 1) * m / (N / 5);
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			additionalVariable = (shiftX - 1) * m / (N / 5);
		}
		else if (shiftY > F && indicator == -1) {
			shiftY -= 1;
			destCoord.X = additionalVariable;
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
		}
		else if (shiftY == F && indicator == -1) {
			shiftX += 1;
			destCoord.X = (shiftX - 1) * m / (N / 5);
			destCoord.Y = shiftY * 2 + 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			additionalVariable = (shiftX - 1) * m / (N / 5);
			indicator *= -1;
			F += 1;
		}
	}
	

	int number = 0;
	shiftX = 0;
	
	for (int* p = *arr; p <= end; p++) {
		if (number % 2 == 0 && shiftX < N) {
			shiftX += 1;
			destCoord.X = number * m/(N/5);
			destCoord.Y = N*2 + shiftX * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
		}
		else if (shiftX == N) {
			number += 1;
			destCoord.X = number * m / (N / 5);
			destCoord.Y = N * 2 + shiftX * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			shiftX -= 1;
		}
		else if (number % 2 != 0 && shiftX > 0) {
			destCoord.X = number * m / (N / 5);
			destCoord.Y = N * 2 + shiftX * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
			shiftX -= 1;
		}
		else if (shiftX == 0) {
			number += 1;
			shiftX += 1;
			destCoord.X = number * m / (N / 5);
			destCoord.Y = N * 2. + shiftX * 2;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *p;
			cout.flush();
			Sleep(20);
		}
 	}
	cout << '\r';
	for (int i = 0; i <= 2*N; i++)
		cout << endl;
	
	
	for (int* p = *arr; p <= end; p++)
		* p = rand() % (1 + N * N);
	while (true) {
		cout << "\n\n"
			<< "1) 1  -> 2 | 2  -> 4 | 4  -> 3 | 3  - > 1\n"
			<< "2) 1 <-> 4 | 2 <-> 3\n"
			<< "3) 1 <-> 3 | 2 <-> 4\n"
			<< "4) 1 <-> 2 | 3 <-> 4\n"
			<< "5) Вывести матрицу\n"
			<< "6) Сортировка (Shaker sort)\n"
			<< "7) Меняет каждый элемент матрицы, взависимости от вашего выбора\n"
			<< "8) Транспонирование матрицы\n"
			<< "0) Выход из программы\n"
			<< "Введите номер функции, которовый вы хотите воспользоваться: ";
		int choice;
		cin >> choice;
		bool swapped = true;
		int start = 0;
		int end = N - 1;
		char choice2;
		int number;
		switch (choice) {
		case 1:
			int arr2[N / 2][N / 2];
			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < N/2; j++)
					arr2[i][j] = arr[i][j];
			}
			for (int i = 0; i < N/2; i++) {
				for (int j = N / 2, j2 = 0; j < N; j++, j2++) {
					swap(*(*arr2 + i * (N/2) + j2), *(*arr + i * N + j));
				}
			}
			for (int i = N / 2, i2 = 0; i < N; i++, i2++) {
				for (int j = N / 2, j2 = 0; j < N; j++, j2++) {
					swap(*(*arr2 + i2 * (N / 2) + j2), *(*arr + i * N + j));
				}
			}
			for (int i = N / 2, i2 = 0; i < N; i++, i2++) {
				for (int j = 0, j2 = 0; j < N/2; j++, j2++) {
					swap(*(*arr2 + i2 * (N / 2) + j2), *(*arr + i * N + j));
				}
			}
			for (int i = 0, i2 = 0; i < N/2; i++, i2++) {
				for (int j = 0, j2 = 0; j < N / 2; j++, j2++) {
					swap(*(*arr2 + i2 * (N / 2) + j2), *(*arr + i * N + j));
				}
			}
			break;
		case 2:
			for (int i = 0, i2 = N/2; i < N / 2; i++, i2++) {
				for (int j = 0, j2 = N/2; j < N / 2; j++, j2++) {
					swap(*(*arr + i2 * N + j2), *(*arr + i * N + j));
				}
			}
			for (int i = 0, i2 = N / 2; i < N / 2; i++, i2++) {
				for (int j = 0, j2 = N / 2; j < N / 2; j++, j2++) {
					swap(*(*arr + i2 * N + j), *(*arr + i * N + j2));
				}
			}
			break;
		case 3:
			for (int i = 0, i2 = N / 2; i < N / 2; i++, i2++) {
				for (int j = 0, j2 = 0; j < N / 2; j++, j2++) {
					swap(*(*arr + i2 * N + j2), *(*arr + i * N + j));
				}
			}
			for (int i = 0, i2 = N / 2; i < N / 2; i++, i2++) {
				for (int j = N/2, j2 = N / 2; j < N; j++, j2++) {
					swap(*(*arr + i2 * N + j2), *(*arr + i * N + j));
				}
			}
			break;
		case 4:
			for (int i = 0, i2 = 0; i < N / 2; i++, i2++) {
				for (int j = 0, j2 = N/2; j < N / 2; j++, j2++) {
					swap(*(*arr + i2 * N + j2), *(*arr + i * N + j));
				}
			}
			for (int i = N/2, i2 = N/2; i < N; i++, i2++) {
				for (int j = 0, j2 = N / 2; j < N / 2; j++, j2++) {
					swap(*(*arr + i2 * N + j2), *(*arr + i * N + j));
				}
			}
			break;
		case 6:
			swapped = true;
			start = 0;
			end = N * N - 1;
			while (swapped) {
				swapped = false;

				for (int i = start; i < end; ++i) {
					if (*(*arr + i) > * (*arr + i + 1)) {
						swap(*(*arr + i), *(*arr + i + 1));
						swapped = true;
					}
				}

				if (!swapped) break;

				--end;
				swapped = false;

				for (int i = end - 1; i >= start; --i) {
					if (*(*arr + i) > * (*arr + i + 1)) {
						swap(*(*arr + i), *(*arr + i + 1));
						swapped = true;
					}
				}

				++start;
			}
			break;
		case 7:
			cout << "\n\n+. К каждому элементу прибавить число\n"
				<< "-. Из каждого элемента вычесть число\n"
				<< "*. Каждый элемент умножить на число\n"
				<< "/. Каждый элемент поделить на число\n"
				<< "Введите символ: ";
			cin >> choice2;
			cout << endl;
			switch (choice2) {
			case '+':
				cout << "Введите число, которое хотите прибавить ко всем элементам: ";
				cin >> number;
				for (int i = 0; i < N * N; i++)
					* (*arr + i) += number;
				break;
			case '-':
				cout << "Введите число, которое хотите вычесть из каждого элемента: ";
				cin >> number;
				for (int i = 0; i < N * N; i++)
					* (*arr + i) -= number;
				break;
			case '*':
				cout << "Введите число, на которое хотите умножить каждый элемент: ";
				cin >> number;
				for (int i = 0; i < N * N; i++)
					* (*arr + i) *= number;
				break;
			case '/':
				cout << "Введите число, на которое хотите поделить каждый элемент: ";
				cin >> number;
				for (int i = 0; i < N * N; i++)
					* (*arr + i) /= number;
				break;
			}
			break;
		case 0:
			return 0;
		case 8:
			system("cls");
			for (int k = 0; k < N; k++) {
				for (int l = k; l < N; l++) {
					swap(*(*arr + N * k + l), *(*arr + N * l + k));
					for (int i = 0; i < N; ++i) {
						for (int j = 0; j < N; ++j) {
							cout << setw(4) << *(*arr + i * N + j);
						}
						cout << endl;
					}
					Sleep(300);
					system("cls");
				}
			}
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cout << setw(4) << *(*arr + i * N + j);
				}
				cout << endl;
			}
			break;
		case 5:
			HANDLE hStdout;
			COORD destCoord;
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			int n = sizeof(arr) / sizeof(*arr);
			int m = sizeof(*arr) / sizeof(**arr);

			int* end = *arr + n * m - 1;
			cout << endl;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cout << setw(4) << *(*arr + i * N + j);
				}
				cout << endl;
			}
			break;
		}
	}
}