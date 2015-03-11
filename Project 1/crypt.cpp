#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

//a <-> 0, b <-> 1, ... , y <-> 24, z <-> 25, ' ' <-> 26
unsigned int letter_to_value(char a){
	if (a == ' '){
		return 26;
	}
	return (a - 'a');
}

char value_to_letter(int a){
	if (a == 26){
		return ' ';
	}
	return (char(a + 'a'));
}

vector<unsigned int> string_to_vector(string a){
	vector<unsigned int> temp;
	for (unsigned int i = 0; i < a.length(); i++){
		temp.push_back(letter_to_value(a[i]));
	}

	return temp;
}

string vector_to_string(vector<unsigned int> a){
	string temp = "";
	temp.resize(a.size());
	for (unsigned int i = 0; i < a.size(); i++){
		temp[i] = value_to_letter(a[i]);
	}

	return temp;
}

bool test1helper(string a, string b, unsigned int t){
	set<unsigned int> temp;
	for (int i = 0; i < a.length(); i++){
		temp.insert(abs(a[i] - b[i]));
	}
	if (temp.size() <= t){
		return true;
	}
	return false;
}

bool test1(string dict1[], unsigned int dict1Length, string cipherText, unsigned int t){
	for (int i = 0; i < dict1Length; i++){
		if (test1helper(dict1[i], cipherText, t)){
			cout << "The plaintext is: " << endl << dict1[i] << endl;
			return true;
		}
	}
	return false;
}

int main(){
	//vector<unsigned int> aaa = string_to_vector("abcdefghijklmnopqrstuvwxyz ");
	//string bbb = vector_to_string(aaa);

	const int L = 100;
	const int u = 200;
	const int v = 100;
	int t = 0;

	string dict1[u];
	string dict2[v];

	ifstream file;
	file.open("Dictionary1.txt");
	for (int i = 0; i < u; i++){
		getline(file, dict1[i]);
	}
	file.close();

	file.open("Dictionary2.txt");
	for (int i = 0; i < v; i++){
		getline(file, dict2[i]);
	}
	file.close();

	/*
	cout << "Yo give me t:"<<endl;
	cin >> t;
	cin.ignore();

	string input = "";
	cout << "Give me the ciphertext:"<<endl;
	getline(cin,input);
	*/

	string input = "aiahei cad be aied id chahacjehifidg hebebadce acheii a iej ef affbicajied decaidi je iaffehj daja g";
	cout << "The ciphertext is:" << endl << input << endl;
	test1(dict1, u, input, 10);

	

}