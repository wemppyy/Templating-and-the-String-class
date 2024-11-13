#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PIBs_in_file() {
	ifstream P, I, B;
	ofstream Result;

	P.open("P.txt");
	I.open("I.txt");
	B.open("B.txt");
	Result.open("Result.txt");

	string result = "";

	while (!P.eof() && !I.eof() && !B.eof()) {
		string p, i, b;
		getline(P, p);
		getline(I, i);
		getline(B, b);

		if (P.eof() && I.eof() && B.eof()) {
			result += p + " " + i + " " + b;
		}
		else {
			result += p + " " + i + " " + b + "\n";
		}
	}

	Result << result;

	P.close();
	I.close();
	B.close();
	Result.close();
}

void Sort_PIBs() {
	ifstream Result;
	ofstream Sorted;

	Result.open("Result.txt");
	Sorted.open("Sorted.txt");

	string pib[100];
	int i = 0;

	while (!Result.eof()) {
		string p;
		getline(Result, p);
		pib[i] = p;
		i++;
	}

	for (int j = 0; j < i - 1; j++) {
		for (int k = j + 1; k < i; k++) {
			if (pib[j] > pib[k]) {
				string temp = pib[j];
				pib[j] = pib[k];
				pib[k] = temp;
			}
		}
	}

	int index = 0;
	for (int j = 0; j < i; j++) {
		Sorted << index << " - " << pib[j] << endl;
		index++;
	}

	Result.close();
	Sorted.close();
}

void create_test_PIBs_files() {
	ofstream P, I, B;

	P.open("P.txt");
	I.open("I.txt");
	B.open("B.txt");

	P << "Petrov\n";
	P << "Ivanov\n";
	P << "Sidorov\n";
	P << "Pavlov\n";
	P << "Kozlov";

	I << "Ivan\n";
	I << "Petr\n";
	I << "Sidor\n";
	I << "Pavel\n";
	I << "Kozel";

	B << "Ivanovich\n";
	B << "Petrovich\n";
	B << "Sidorovich\n";
	B << "Pavlovich\n";
	B << "Kozlovich";

	P.close();
	I.close();
	B.close();

}

int main() {
	int choice;

	do {
		system("cls");
		cout << "Menu\n";
		cout << "1. PIBs in file\n";
		cout << "2. Sort PIBs\n";
		cout << "3. Create test files\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			PIBs_in_file();
			cout << "PIBs in file\n";
			break;
		case 2:
			Sort_PIBs();
			cout << "PIBs sorted\n";
			break;
		case 3:
			create_test_PIBs_files();
			cout << "Test files created\n";
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice\n";
		}
	} while (choice != 4);
	return 0;
}
