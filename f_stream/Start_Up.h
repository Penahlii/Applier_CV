#pragma once

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void menu_print(char** arr, int a,int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (i == a)
			SetConsoleTextAttribute(console, 10);
		else
			SetConsoleTextAttribute(console, 7);

		cout << arr[i] << endl;
	}
}

class StartUp
{
public:

	static void start()
	{
		Company Step_Academy;

		/*Step_Academy.read_to_file("All_CVs.txt");*/

		char** mymenu = new char* [5];

		mymenu[0] = new char[] {"  Show ALL CVs"};
		mymenu[1] = new char[] {"  Hire Up"};
		mymenu[2] = new char[] {"  Write To File"};
		mymenu[3] = new char[] {"  Read From File"};
		mymenu[4] = new char[] {"  Exit"};

		int input;
		int a = 0, b = 0;
		while (true)
		{
			system("cls");

			mymenu[a][b] = '>';


			menu_print(mymenu, a,5);
			input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (int(input) == 72)
				{
					if (a == 0)
					{
						mymenu[a][b] = ' ';
						a = 4;
					}
					else
					{
						a--;
						mymenu[a + 1][b] = ' ';
					}

				}
				else if (int(input) == 80)
				{

					if (a == 4)
					{
						mymenu[a][b] = ' ';
						a = 0;
					}
					else
					{
						a++;
						mymenu[a - 1][b] = ' ';
					}
				}

				if (a == -1 && int(input) == 72)
				{
					a = 0;
					mymenu[a][b] = ' ';
					a = 4;
				}
				if (a == 5 && int(input) == 80)
				{
					a = 4;
					mymenu[a][b] = ' ';
					a = 0;
				}
			}
			else if (input == 87)
			{
				if (a == 0)
				{
					mymenu[a][b] = ' ';
					a = 4;
				}
				else
				{
					a--;
					mymenu[a + 1][b] = ' ';
				}
			}
			else if (input == 83)
			{
				if (a == 4)
				{
					mymenu[a][b] = ' ';
					a = 0;
				}
				else
				{
					a++;
					mymenu[a - 1][b] = ' ';
				}
			}
			else if (input == '\r')
			{
				if (a == 0)
				{
					system("cls");
					Step_Academy.show_all_cv();
					Sleep(5000);
				}
				else if (a == 1)
				{
					system("cls");
					string name, speciality, text;
					ushort age;
					cout << "Enter Name: ";
					cin >> name;
					cout << "Enter Age: ";
					cin >> age;
					cout << "Enter Speciality: ";
					cin >> speciality;
					cout << "Enter Text: ";
					cin >> text;

					try
					{
						system("cls");
						Applier* new_cv = new Applier(name, age, speciality, text);
						Step_Academy.hire_up(new_cv);
						cout << "CV was Hire Up Succesfully";
						Sleep(3000);
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(4000);
					}

				}
				else if (a == 2)
				{
					system("cls");
					try
					{
						Step_Academy.write_to_file("All_CVs.txt");
						cout << "All Read Succesfully";
						Sleep(3000);
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(4000);
					}
				}
				else if (a == 3)
				{
					system("cls");
					try
					{
						Step_Academy.read_to_file("All_CVs.txt");
						cout << "All Writed Succesfully";
						Sleep(3000);
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(4000);
					}
				}
				else if (a == 4)
				{
					system("cls");
					SetConsoleTextAttribute(console, 7);
					cout << "Good-Bye";
					break;
				}
			}
		}
	}
};