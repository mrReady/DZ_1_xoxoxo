#include <iostream>
#define R 9  //количество клеток поля
using namespace std;

void vivod(char* a);	   //вывод
int xod(char* a, int p);  //ход
int end(char* a, int p); //проверка на конец игры
void rules();			//пояснение, кто есть кто

int main()
{
	char a[R];		 //костыль на использование недоцифр с '0'
	int p = 1;
	for (int i = 0; i < R; i++)
		a[i] = i + 1;
	rules();
	while (end(a, p)) { 
		vivod(a);
		p = xod(a, p); //тут я забыл, как передавать по адресу int p
	}
	return 0;
}

void rules() {				//пояснение, кто есть кто
	cout << "Plaer 1 = X" << endl << "Plaer 2 = O" << endl << endl;
}

void vivod(char* a) {	   //вывод
	printf("%c|%c|%c\n%c|%c|%c\n%c|%c|%c\n\n", '0' + a[0], '0' + a[1], '0' + a[2], '0' + a[3], '0' + a[4], '0' + a[5], '0' + a[6], '0' + a[7], '0' + a[8]);
}

int xod(char* a, int p) {		 //ход
	int e = 0;
	while ((e > 9) || (e < 1) || (a[e - 1] == ('X' - '0')) || (a[e - 1] == ('O' - '0'))) { //проверка на ввод и свободное место для хода
		cout << "You turn, player " << p << " : ";
		cin >> e;
		if ((e > 9) || (e < 1) || (a[e - 1] == ('X' - '0')) || (a[e - 1] == ('O' - '0')))
			cout << endl << "Re-enter properly, please" << endl;
	}
	if (p == 1) {
		a[e - 1] = 'X' - '0';
		p++;	//смена игрока
	}
	else {
		a[e - 1] = 'O' - '0';
		p--;	//смена игрока
	}
	return p;
}

int end(char* a, int p) {		//проверка на конец игры
	int cnt = 0;  //господи, прости меня за 280 символов строчкой ниже (проверка выйгрышных вариантов)
	if ((a[0] == a[1] && a[1] == a[2]) || (a[3] == a[4] && a[4] == a[5]) || (a[6] == a[7] && a[7] == a[8]) || (a[0] == a[3] && a[3] == a[6]) || (a[1] == a[4] && a[4] == a[7]) || (a[2] == a[5] && a[5] == a[8]) || (a[0] == a[4] && a[4] == a[8]) || (a[2] == a[4] && a[4] == a[6])) {
		if (p == 1)		//всё наоборот из-за того, что в xod() передаётся ход другому игроку 
			cout << "Winner player 2!" << endl;
		else
			cout << "Winner player 1!" << endl;
		return 0;
	}
	else for (int i = 0; i < R; i++)
		if (a[i] == ('X' - '0') || a[i] == ('O' - '0'))
			cnt++;
	if (cnt == 9) {		//если всё поле занято, то ничья
		cout << "Draw!" << endl;
		return 0;
	}
	return 1;
}