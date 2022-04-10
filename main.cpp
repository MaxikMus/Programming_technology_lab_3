#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cmath>
#include "aprog.h"
#include "gprog.h"

template <typename T>
T getData();

void aProg();
void gProg();

//template <typename T1>
AP* memory(AP* arr, int* count) {
	AP* temp = nullptr;
	(*count)++;
	temp = new AP[*count];
	for (int i = 0; i < *count - 1; i++) {
		(temp + i)->setInit((arr + i)->getInit());
		(temp + i)->setDiff((arr + i)->getDiff());
	}
	delete[] arr;
	return temp;
}

//template <typename T1>
GP* memory(GP* arr, int* count) {
	GP* temp = nullptr;
	(*count)++;
	temp = new GP[*count];
	for (int i = 0; i < *count - 1; i++) {
		(temp + i)->setInit((arr + i)->getInit());
		(temp + i)->setRatio((arr + i)->getRatio());
	}
	delete[] arr;
	return temp;
}

//template <typename T2>
AP* realloc(AP* arr, int* count, int num) {
	AP* temp = nullptr;
	(*count)--;
	temp = new AP[*count];
	for (int i = 0, j = 0; i < *count + 1; i++, j++) {
		if (i == num - 1) {
			j--;
			continue;
		}
		(temp + j)->setInit((arr + i)->getInit());
		(temp + j)->setDiff((arr + i)->getDiff());
	}
	delete[] arr;
	return temp;
}

//template <typename T2>
GP* realloc(GP* arr, int* count, int num) {
	GP* temp = nullptr;
	(*count)--;
	temp = new GP[*count];
	for (int i = 0, j = 0; i < *count + 1; i++, j++) {
		if (i == num - 1) {
			j--;
			continue;
		}
		(temp + j)->setInit((arr + i)->getInit());
		(temp + j)->setRatio((arr + i)->getRatio());
	}
	delete[] arr;
	return temp;
}

int main() {
	short choice;
	do {
		system("cls");
		std::cout << "Select progression:\n" << "1. Arithmetic Progression\n" << "2. Geometric Progression\n" << "3. Exit" << std::endl;
		std::cout << "Your choice: ";
		choice = getData<short>();

		switch (choice)
		{
		case 1:
			aProg();
			break;
		case 2:
			gProg();	
			break;
		case 3:
			return 1;
			break;
		default:

			break;
		}
	} while (true);
	


	return 0;
}

void gProg() {
	int choice;
	bool exit = false;
	double temp_num;
	int count = 0;
	std::fstream file;
	GP* p = nullptr;

	do {
		system("cls");
		std::cout << "-------------------\n" << "Geometric Progression\n" << "-------------------\n";
		std::cout << "Select action:\n" << "1. Show progressions\n" << "2. Redact\n" << "3. Add new progression\n" <<
			"4. Delete progression\n" << "5. Save data\n" << "6. Load data\n" << "7. Exit" << std::endl;
		std::cout << "Your choice: ";
		choice = getData<int>();
		switch (choice)
		{
			// show
		case 1:
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common ratio:" << (p + i)->getRatio() << "\n|The sum of the progression: " << (p + i)->sumProg(10);
			}
			std::cout << "\n--------------------------------\n\n";
			system("pause");
			break;

			// redact
		case 2:
			std::cout << "Select progression: " << std::endl;
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common ratio: " << (p + i)->getRatio();
			}
			std::cout << "\n--------------------------------\n\n";
			std::cout << "Your choice: ";
			choice = getData<int>();

			system("cls");

			std::cout << "Now:\n" << "Initial term: " << (p + choice - 1)->getInit() <<
				"\nCommon ratio: " << (p + choice - 1)->getRatio() << std::endl;

			std::cout << "\nWill:\n" << "Initial term: ";
			temp_num = getData<double>();
			(p + choice - 1)->setInit(temp_num);
			std::cout << "Common ratio: ";
			temp_num = getData<double>();
			(p + choice - 1)->setRatio(temp_num);


			break;

			// add new prog
		case 3:
			p = memory(p, &count);
			std::cout << "Enter initial term: ";
			temp_num = getData<double>();
			(p + count - 1)->setInit(temp_num);

			std::cout << "Enter common ratio: ";
			temp_num = getData<double>();
			(p + count - 1)->setRatio(temp_num);
			break;

			// delete prog
		case 4:
			if (count == 0) {
				std::cout << "There are no progressions";
				break;
			}
			std::cout << "Select progression to delete " << std::endl;
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common difference: " << (p + i)->getRatio();
			}
			std::cout << "\n--------------------------------\n\n";
			std::cout << "Your choice: ";
			choice = getData<int>();

			p = realloc(p, &count, choice);

			system("cls");

			break;

			// load data
		case 6:
		{
			char ch[10];
			if (count > 0) {
				std::cout << "There are progressons in list" << std::endl;
				system("pause");
				break;
			}

			file.open("gprog.txt", std::ios::in);
			if (file.eof()) {
				std::cout << "File is empty" << std::endl;
				system("pause");
				break;
			}

			file.getline(ch, 10);
			count = atoi(ch);
			if (!count) {
				std::cout << "File is empty" << std::endl;
				system("pause");
				break;
			}
			p = new GP[count];

			for (int i = 0; i < count; i++) {
				file.getline(ch, 10);
				(p + i)->setInit(atof(ch));
				file.getline(ch, 10);
				(p + i)->setRatio(atof(ch));
			}

			file.close();
			break;

		}
			// exit
		case 7:
			exit = true;
			std::cout << "Do you wanna save data?\n" << "1. Yes\n" << "2. No" << std::endl;
			choice = getData<int>();
			if (choice == 2) {
				break;
			}

			// save data
		case 5:

			if (count == 0) {
				std::cout << "There are no progressions" << std::endl;
				system("pause");
				break;
			}

			file.open("gprog.txt", std::ios_base::out | std::ios_base::trunc);

			if (!file.is_open()) {
				std::cout << "File doesn't exist" << std::endl;
				system("pause");
				break;
			}

			file << p->getCount() << "\n";
			for (int i = 0; i < count; i++) {
				file << (p + i)->getInit() << "\n";
				file << (p + i)->getRatio() << "\n";
			}

			file.close();
			break;

		default:
			break;
		}
	} while (!exit);


	delete[] p;
}


void aProg() {
	int choice;
	bool exit = false;
	double temp_num;
	int count = 0;
	std::fstream file;
	AP* p = nullptr;

	do {
		system("cls");
		std::cout << "-------------------\n" << "Arithmetic Progression\n" << "-------------------\n";
		std::cout << "Select action:\n" << "1. Show progressions\n" << "2. Redact\n" <<	"3. Add new progression\n" << 
			"4. Delete progression\n" << "5. Save data\n" << "6. Load data\n" << "7. Exit" << std::endl;
		std::cout << "Your choice: ";
		choice = getData<int>();
		switch (choice)
		{
			// show
		case 1:
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common difference:" << (p + i)->getDiff() << "\n|The sum of the progression: " << (p+i)->sumProg(5);
			}
			std::cout << "\n--------------------------------\n\n";
			system("pause");
			break;

			// redact
		case 2:
			std::cout << "Select progression: " << std::endl;
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common difference: " << (p + i)->getDiff();
			}
			std::cout << "\n--------------------------------\n\n";
			std::cout << "Your choice: ";
			choice = getData<int>();

			system("cls");
			
			std::cout << "Now:\n" << "Initial term: " << (p + choice - 1)->getInit() <<
				"\nCommon difference: " << (p + choice - 1)->getDiff() << std::endl;

			std::cout << "\nWill:\n" << "Initial term: ";
			temp_num = getData<double>();
			(p + choice - 1)->setInit(temp_num);
			std::cout << "Common difference: ";
			temp_num = getData<double>();
			(p + choice - 1)->setDiff(temp_num);

 
			break;

			// add new prog
		case 3:
			p = memory(p, &count);
			std::cout << "Enter initial term: ";
			temp_num = getData<double>();
			(p + count - 1)->setInit(temp_num);

			std::cout << "Enter common difference: ";
			temp_num = getData<double>();
			(p + count - 1)->setDiff(temp_num);
			break;

			// delete prog
		case 4:
			if (count == 0) {
				std::cout << "There are no progressions";
				break;
			}
			std::cout << "Select progression to delete " << std::endl;
			for (int i = 0; i < count; i++) {
				std::cout << "\n\n" << i + 1 << "-------------------------------\n" << "|Initial term: " << (p + i)->getInit() <<
					"\n|Common difference: " << (p + i)->getDiff();
			}
			std::cout << "\n--------------------------------\n\n";
			std::cout << "Your choice: ";
			choice = getData<int>();

			p = realloc(p, &count, choice);

			system("cls");

			break;

			// load data
		case 6:
		{
			char ch[10];
			if (count > 0) {
				std::cout << "There are progressons in list" << std::endl;
				system("pause");
				break;
			}

			file.open("aprog.txt", std::ios::in);
			if (file.eof()) {
				std::cout << "File is empty" << std::endl;
				system("pause");
				break;
			}

			file.getline(ch, 10);
			count = atoi(ch);
			if (!count) {
				std::cout << "File is empty" << std::endl;
				system("pause");
				break;
			}
			p = new AP[count];

			for (int i = 0; i < count; i++) {
				file.getline(ch, 10);
				(p + i)->setInit(atof(ch));
				file.getline(ch, 10);
				(p + i)->setDiff(atof(ch));
			}

			file.close();
			break;

		}
		case 7:
			exit = true;
			std::cout << "Do you wanna save data?\n" << "1. Yes\n" << "2. No" << std::endl;
			choice = getData<int>();
			if (choice == 2) {
				break;
			}

			// save data
		case 5:

			if (count == 0) {
				std::cout << "There are no progressions" << std::endl;
				system("pause");
				break;
			}

			file.open("aprog.txt", std::ios_base::out | std::ios_base::trunc);

			if (!file.is_open()) {
				std::cout << "File doesn't exist" << std::endl;
				system("pause");
				break;
			}

			file << p->getCount() << "\n";
			for (int i = 0; i < count; i++) {
				file << (p + i)->getInit() << "\n";
				file << (p + i)->getDiff() << "\n";
			}

			file.close();
			break;

		default:
			break;
		}
	} while (!exit);
	

	delete[] p;
}


#undef max
template <typename T>
T getData() {
	T temp;
	std::cin >> temp;
	while (std::cin.fail() || std::cin.get() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.sync();
		std::cout << "Enter again: ";
		std::cin >> temp;
	}
	return temp;
}