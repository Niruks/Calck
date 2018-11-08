// Kalc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
	int main()
	{
		int cnt = 0, Sum = 0;
		Stack Undo(100), Do(100);
		int op = 0;
		while (op != 5)
		{
			printf("1.Add(+)\n");
			printf("2.Subtract(-)\n");
			printf("3.Undo\n");
			printf("4.Do\n");
			printf("5.Exit\n");
			std::cin >> op;
			switch (op)
			{
			case 1:
				if (Undo.IsStackFull())
				{
					system("cls");
					printf("%d\n StackIsFull\n", Sum);
				}
				else
				{
					printf("Enter the number =");
					std::cin >> cnt;
					Undo.AddElement(cnt);
					Sum = Sum + cnt;
					Do.DeleteAllElements();
					system("cls");
					printf("%d\n", Sum);
				}
				break;
			case 2:
				if (Undo.IsStackFull())
				{
					system("cls");
					printf("%d\n StackIsFull\n", Sum);
				}//c i'm will to diff
				else
				{
					printf("Enter the number =");
					std::cin >> cnt;
					Undo.AddElement(-cnt);
					Sum = Sum - cnt;
					Do.DeleteAllElements();
					system("cls");
					printf("%d\n", Sum);
				}
				break;
			case 3:
				if (Undo.IsStackEmpty())
				{
					system("cls");
					printf("%d\n StackIsEmpty\n", Sum);
				}
				else
				{
					cnt = Undo.DeleteElement();
					Do.AddElement(cnt);
					Sum = Sum - cnt;
					system("cls");
					printf("%d\n", Sum);
				}
				break;
			case 4:
				if (Do.IsStackEmpty())
				{
					system("cls");
					printf("%d\nStackIsEmpty\n", Sum);
				}
				else
				{
					cnt = Do.DeleteElement();
					Undo.AddElement(cnt);
					Sum = Sum + cnt;
					system("cls");
					printf("%d\n", Sum);
				}
				break;
			}
		}
		return 0;
	}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
