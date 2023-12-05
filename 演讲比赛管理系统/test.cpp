 #define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"


int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sp;

	while (1)
	{
		sp.Menu();
		cout << "ÇëÑ¡Ôñ²Ù×÷£º" << endl;
		int choice;
		cin >> choice;


		switch (choice)
		{
		case 1:
		{  sp.SpeechStart();
			break;
		}
		case 2:
		{
			sp.Showspeech();
			break;
		}
		case 3:
		{   sp.ClearRecord();
			break;
		}
		case 0:
		{
			sp.ExitSpeech();
			break;
		}
	
		default: 
		{
			system("cls");
			break;
		}
			
		}









	}













}