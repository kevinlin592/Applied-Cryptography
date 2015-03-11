#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

const int L = 100;
const int u = 200;
const int v = 100;
const int ALPHABET = 27;

//a <-> 0, b <-> 1, ... , y <-> 24, z <-> 25, ' ' <-> 26
int letter_to_value(char a){
	if (a == ' '){
		return 26;
	}
	return (a - 'a');
}

vector<int> string_to_vector(const string &a){
	vector<int> temp;
	for (size_t i = 0; i < a.length(); i++){
		temp.push_back(letter_to_value(a[i]));
	}

	return temp;
}

bool test1helper(const string &a, const string &b, int t){
	set<int> temp;
	int val1 = 0;
	int val2 = 0;
	for (size_t i = 0; i < a.length(); i++){
		val1 = letter_to_value(a[i]);
		val2 = letter_to_value(b[i]);
		if (val1 - val2 < 0){
			temp.insert(val1 - val2 + ALPHABET);
		}
		else {
			temp.insert(val1 - val2);
		}
	}
	return (temp.size() <= t);
}

//	This function examines the ciphertext using the first dictionary
bool test1(string dict1[], int dict1Length, const string &cipherText, int t){
	for (size_t i = 0; i < dict1Length; i++){
		if (test1helper(dict1[i], cipherText, t)){
			cout << "The decrypted plaintext is: " << endl << dict1[i] << endl;
			return true;
		}
	}
	return false;
}

bool test2helper(set<int> &duplicates, const string &a, const string &b, int t, int pos){
	int val1 = 0;
	int val2 = 0;
	for (size_t i = pos; i < a.length(); i++){
		val1 = letter_to_value(a[i]);
		val2 = letter_to_value(b[i]);
		if (val1 - val2 < 0){
			duplicates.insert(val1 - val2 + ALPHABET);
		}
		else {
			duplicates.insert(val1 - val2);
		}
	}
	return (duplicates.size() <= t);
}

bool test2(set<int> duplicates, const string &guess, string dict2[], int dict2Length, const string &cipherText, int t){
	if (guess.length() == L){
		cout << "The decrypted plaintext is: " << endl << guess << endl;
		return true;
	}
	else {
		int length = guess.length();
		set<int> duplicatesCopy;
		string guessCopy;
		for (size_t i = 0; i < dict2Length; i++){
			duplicatesCopy = duplicates;
			guessCopy = guess;

			guessCopy.append(dict2[i]);
			guessCopy.append(" ");
			if (guessCopy.length() > L){
				guessCopy.resize(L);
			}

			if (test2helper(duplicatesCopy, guessCopy, cipherText, t, length)){
				if (test2(duplicatesCopy, guessCopy, dict2, dict2Length, cipherText, t)){
					return true;
				}
			}

		}
	}
	return false;
}

//	This function examines the ciphertext using the second dictionary
bool test2(string dict2[], int dict2Length, const string &cipherText, int t){
	set<int> duplicates;
	string guess = "";
	return test2(duplicates, guess, dict2, dict2Length, cipherText, t);
}

int main(){
	int t = 0;

	string dict1[u];
	string dict2[v];

	/*	We open the first and second dictionary
	 *	and store the rows of each into arrays
	 */
	ifstream file;
	file.open("Dictionary1.txt");
	if (!file.is_open()){
		cout << "Dictionary1.txt is missing from root directory!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < u; i++){
		getline(file, dict1[i]);
	}
	file.close();

	file.open("Dictionary2.txt");
	if (!file.is_open()){
		cout << "Dictionary2.txt is missing from root directory!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < v; i++){
		getline(file, dict2[i]);
	}
	file.close();

	//	Get user input for keyspace size and ciphertext
	cout << "What is t?" << endl;
	cin >> t;
	cin.ignore();

	string input = "";
	cout << endl << "Give me the ciphertext:" << endl;
	getline(cin, input);
	cout << endl;

	if (input.length() != L){
		cout << "Ciphertext length is not " << L << " characters!" << endl;
		system("pause");
		return 0;
	}

	//	Checks plaintext using Dictionary1.txt then Dictionary2.txt
	if (!test1(dict1, u, input, t)){
		if (!test2(dict2, v, input, t)){
			cout << "A decrypted plaintext was unable to be determined." << endl;
		}
	}

	cout << endl;
	system("pause");

}