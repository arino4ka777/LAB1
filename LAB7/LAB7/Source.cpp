#include "iostream"
#include "clocale"
#include "windows.h"
#include <time.h>
#include <iomanip>

using namespace std;

const int m = 5, n = 3;
//int **mas = new int *[m];

/*void zapolnenie(int **mas)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = rand() % 110 - 50;
		}
	}
}

void vivod(int **mas){
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << mas[i][j] << "\t";
		}
		cout << endl;
	}
}

void maxEl(int max = mas[0][0], int lineMax = 0) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] > max)
			{
				max = mas[i][j];
				lineMax = i;
			}

		}
	}
}

void minEl(int min = mas[0][0], int lineMin = 0) {
	for (int i = 0; i < m; i++)
		{
		for (int j = 0; j < n; j++)
			{
			if (mas[i][j] < min)
				{
					min = mas[i][j];
					lineMin = i;
				}

			}

		}
	}

void zamena(int min, int max, int lineMax, int lineMin) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max > min) {
				int zamena = mas[lineMax][i];
				mas[lineMax][i] = mas[lineMin][i];
				mas[lineMin][i] = zamena;
			}
		}
	}
}

void itog (int **mas)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << mas[i][j] << "\t ";	//вывод конечной матрицы 
		}
		cout << endl;
	}
}*/

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int rows, coloumn;
	cout << "rows = " << endl;
	cin >> rows;
	cout << "coloumn = " << endl;
	cin >> coloumn;
	int lineMin = 0, lineMax = 0;

	int *max, *min;
	//int maxI = 0, minI = 0, maxJ = 0, minJ = 0;
	int *ROWmax =nullptr, *ROWmin = nullptr;
	int **mas = new int *[rows];
	
	for (int i = 0; i < rows; i++)
	{
		mas[i] = new int[coloumn];
	}
	max = &mas[0][0];
	min = &mas[0][0];
	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < rows; i++)
	{
		mas[i] = new int[coloumn];
		for (int j = 0; j < coloumn; j++)
		{
			mas[i][j] = rand() % 110 - 50;
			if (*max < mas[i][j])
			{
				/*maxI = i;
				maxJ = j;*/
				ROWmax = &mas[i][0];
				max = &mas[i][j];
			}
			if (*min > mas[i][j])
			{
				/*minI = i;
				minJ = j;*/
				ROWmin = &mas[i][0];
				min = &mas[i][j];
			}
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}

	cout << *max << '\t' << *min << endl;
	int *ptr = ROWmax;
	ROWmax = ROWmin;
	ROWmin = ROWmax;
	 
	
	cout << endl;
	cout << "Итоговая матрица: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloumn; j++)
		{
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
		delete[] mas[i];
	delete[] mas;
	system("pause");
	return 0;
}



/*int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	int i, j;
	int lineMin = 0, lineMax = 0;
	int max = 0, min = 0;

	int **mas = new int *[m];
	for (int i = 0; i < m; i++)
	{
		mas[i] = new int[n];
		for (int j = 0; j < ; j++)
		{

		}
	}
	cout << "Исходная матрица: " << endl;
	zapolnenie(mas);
	vivod(mas);
	cout << endl;
	
	cout << "Итоговая матрица: " << endl;
	maxEl;
	minEl;
	zamena;
	itog(mas);
	cout << endl;
	delete[] mas;
	system("pause");
	return 0;
}*/
