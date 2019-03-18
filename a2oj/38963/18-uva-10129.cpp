#include <iostream>
#include <string>

#define ASCII_A 97
#define ALPHABET_SIZE 26

using namespace std;

int main() {
	int t, n, i, first_letter, last_letter, odds,
		letter_counts[ALPHABET_SIZE];
	string name;

	cin >> t;
	while (t--) {
		cin >> n;

		for (i = 0; i < ALPHABET_SIZE; i++)
			letter_counts[i] = 0;
		
		for (i = 0; i < n; i++) {
			cin >> name;
			letter_counts[name[0] - ASCII_A]++;
			letter_counts[name[name.length() - 1] - ASCII_A]++;
		}

		odds = 0;
		for (i = 0; i < ALPHABET_SIZE; i++)
			if (letter_counts[i] % 2 == 1)
				odds++;

		if (odds > 2) {
			cout << "The door cannot be opened.\n";
		} else {
			cout << "Ordering is possible.\n";
		}
	}	


	return 0;
}