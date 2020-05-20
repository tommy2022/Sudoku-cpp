#include <cassert>  //assert
#include <iostream> //ostream
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <set> 
#include <cmath>
#include <random>
#include <string>
#include "Algorithm.cpp"
#include <time.h>

using namespace std;


class Sudoku {
private:
	string topRow;
	string secondRow;
	int arr[HEIGHT][WIDTH];
	int solution[HEIGHT][WIDTH];
	int original[HEIGHT][WIDTH]; //original problem set.
	bool solvable;
	Solver algorithm;
	string option[3];
	bool checker = false;
	clock_t t;


public:
	Sudoku() : topRow("  |A|B|C||D|E|F||G|H|I||"), secondRow("--|-|-|-||-|-|-||-|-|-||"), arr(), 
		original(), solvable(false),  algorithm() {
		t = clock();
		option[0] = "Random";
		option[1] = "Easy";
		option[2] = "Hard";
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				arr[i][j] = 0;
			}
		}
		get_option();
		cout << "Thanks for playing!";
	}

	void test_func() {
		algorithm.reset(arr);
		algorithm.solve();
		algorithm.reflect_change(arr);
		print_grid();
	}

	//NOT DONE
	void play() {
		string input;
		char col = 'Z';
		int row = 9;
		int num = 0;


		while (!complete()) {

			if (!get_input(col, row, num)) {
				get_option();
				break;
			}
			cout << "Entering " << num << " into Column " << col << ", Row " 
				<< row << ": ";
			input_num(col, row, num);
		}
	}

	//gets input
	//returns true if normal input
	//returns false only if menu was entered
	bool get_input(char& col, int& row, int& num) {

		string input = "";
		string message;
		while (true) {

			cout << "Current sudoku board" << endl;
			print_grid();
			cout << "Enter 'menu' any time to return to main menu" << endl;
			cout << "Enter 'hint' to check for any wrong numbers or help solve one spot" << endl;
			cout << "*You wont be able to get back to the same problem once menu is selected*" << endl;
			while (true) {
				cout << "Enter Column (or 'hint'): ";
				cin >> input;
				cout << endl;
				if (input == "solve") {

				}
				if (input == "menu") { return false; }
				if (input == "hint" ||
					(input.length() == 1 && 
						((input[0] >= 'A' && input[0] <= 'I') || (input[0] >= 'a' && input[0] <= 'i')))){
					break;
				}
				else { cout << "Please enter letter A to I, 'hint' or 'menu'"; }
			}
			if (input == "hint") {
				give_hint();
				continue;
			}
			col = input[0];
			col = toupper(col);

			while (true) {
				cout << "Enter Row: ";
				cin >> input;
				cout << endl;
				if (input == "menu") {
					return false;
				}
				if (input.length() == 1 && input[0] >= '0' && input[0] <= '8') {
					break;
				}
				cout << "Please enter number 0 to 8 or 'menu'";
			}
			row = int(input[0]) - 48;

			while (true) {
				cout << "Enter Number: ";
				cin >> input;
				cout << endl;
				if (input == "menu") {
					return false;
				}
				if (input.length() == 1 && input[0] >= '1' && input[0] <= '9') {
					break;
				}
				cout << "Please enter number 1 to 9";
			}
			num = int(input[0]) - 48;
			return true;
		}
	}

	void give_hint() {
		char input;

		cout << "Do you want to check for errors or help solve a spot?" << endl;
		while (true) {
			cout << "Check for Error: A" << endl;
			cout << "Solve a spot: B" << endl;
			cout << "Return to previous page: C " << endl;
			cout << "Option: ";
			cin >> input;
			cout << endl;
			input = tolower(input);
			if (input == 'a') {
				int index = 0;
				while (detect_error(index)) {}
				return;
			}
			else if (input == 'b') {
				try {
					algorithm.solve_one(arr);
				}
				catch (...) {
					cout << "Unable to solve for next number. At least one number is wrong." << endl;
				}
				return;
			}
			else if (input == 'c') {
				cout << "Returning..." << endl;
				return;
			}
		}
	}

	bool detect_error(int&  index) {
		int row;
		int col;
		char column;
		char keep_checking;
		bool found = true;
		find_diff(index, found);
		if (found) {
			while (true) {
				row = index / 9;
				col = index % 9;
				column = char(col + 65);
				cout << "Column " << column << ", row " << row
					<< " should not be " << arr[row][col] << endl << endl;
				cout << "Do you want to keep checking? y/n: ";
				cin >> keep_checking;

				if (keep_checking == 'y') { return true; }
				if (keep_checking == 'n') { return false; }
				cout << "Please enter y or n" << endl;
			}
		}
		else {
			cout << "All errors found" << endl;
			return false;
		}
	}

	void find_diff(int& index, bool& found) {
		int row;
		int col;
		for (int i = index + 1 ; i < HEIGHT * WIDTH; i++) {
			row = i / 9;
			col = i % 9;
				if (arr[row][col] != 0) {
					if (arr[row][col] != solution[row][col]) {
						index = i;
						return;
					}
				}
			}
		found = false;
		}

	void input_num(char col, int row, int num) {
		int column = int(col) - 65;
		if (original[row][column] != 0) {
			cout << "Oops, this can't be changed" << endl;
			return;
		}

		arr[row][column] = num;

		if (checker == true) {
			if (!check_invariant()) {
				cout << "Oops, you can't put that number there" << endl;
				arr[row][column] = 0;
				return;
			}
		}
	}


	void get_option() {
		print_menu();
		
		char input;
		int num = 5;
		char check;
		while (true) {

			cout << "option: ";
			cin >> input;
			if (input == 'e') {
				while (true) {
					cout << "Option Exit Selected. Are you sure you want to exit?  y/n: ";
					cin >> check;
					cout << endl;
					if (check == 'y') {
						return;
					}
					if (check == 'n') {
						break;
					}
				}
			}
			else if (input == '0' || input == '1' || input == '2') {
				num = int(input) - 48;
				while (true) {
					cout << "Launch option " << input <<", " << option[num] << "?" << "  y/n: ";
					cin >> check;
					cout << endl;
					if (check == 'y' || check == 'n') {
						break;
					}
					cout << "please enter y or n " << endl;
				}
				if (check == 'y') {
					break;
				}
			}
			else {
				cout << "Please enter one of 0, 1, or 2" << endl;
			}
		}
		string auto_check;
		cout << "Do you want the program to check for invalid input?" << endl;
		cout << "This means that the program will not accept input that violates a rule" << endl;
		while (true) {
			cout << "y/n: ";
			cin >> auto_check;
			if (auto_check == "y" || auto_check == "n") { cout << endl;  break; }
			cout << "Please enter 'y' or 'n'" << endl;
		}
		
		if (auto_check == "y") { checker = true; }

		if (num == 0) { random_option(num); }

		else {
			int ver = rand() % 2 + 1;
			int prob = (num - 1) * 2 + ver;
			launch_prob(prob);
			set_original(arr);
		}

		cout << endl << "Starting puzzle " << endl;
		print_grid();
		play();
	}
	
	void random_option(int num) {

		cout << "Creating random problem" << endl;

		cout << "How many number would you like the puzzle to have?" << endl;
		cout << "Enter a number between 25 and 40: ";
		int num_number = 0;
		while (true) {
			cin >> num_number;
			if (num_number >= 25 && num_number <= 40) {
				cout << endl;
				break;
			}
			cout << endl << "Please enter a number between 25 and 40: ";
		}
		int tries = 1;
		//int score = 0;
		while (solvable == false) {
			reset_arr();
			random_gen(0, num_number);
			algorithm.reset(arr);
			try {
				//score = algorithm.solve();
				algorithm.solve();
				solvable = algorithm.complete();
				tries++;
			}
			catch (...) {
				tries++;
			}
		}
		print_grid();
		set_original(arr);
		algorithm.reflect_change(solution);
		print_grid();
		cout << "Solvable random problem generated in ";
		if (tries == 1) {
			cout << "first try!" << endl;
		}
		else {
			cout << tries << " tries!" << endl;
		}
	}

	void set_original(int arr[WIDTH][HEIGHT]) {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				original[i][j] = arr[i][j];
			}
		}
	}

	void random_gen(int num, int thres) {
		if (num == thres) {
			return;
		}
		std::uniform_int_distribution<int> d(0, 215);
		std::random_device rd;
		int col = d(rd) % 9;
		int row = d(rd) % 9;
		int number = d(rd) % 9 + 1;

		if (arr[row][col] != 0) {
			return random_gen(num, thres);
		}
		arr[row][col] = number;
		if (!check_invariant()) {
			arr[row][col] = 0;
			return random_gen(num, thres);
		}
		else {
			return random_gen(num + 1, thres);
		}
	}

	//returns true if no issue
	bool check_invariant() {
		return check_row() && check_column() && check_square();
	}

	void launch_prob (int prob){
		if (prob == 1) {
			p1();
		}
		if (prob == 2) {
			p2();
		}
		if (prob == 3) {
			p3();
		}
		if (prob == 4) {
			p4();
		}
	}

	void print_grid() {
		int counter_in = 0;
		cout << topRow << endl;
		cout << secondRow << endl;

		for (int i = 0; i < 9; i++) {
			cout << i << " |";
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] == 0) {
					cout << " |";
				}
				else {
					cout << arr[i][j] << "|";
				}
				if (counter_in % 3 == 2) {
					cout << "|";
				}
				counter_in++;
			}
			cout << endl;
			cout << "--|-|-|-||-|-|-||-|-|-||" << endl;
		}
	}

private:
	void reset_arr() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				arr[i][j] = 0;
			}
		}
	}

	void print_menu() {
		cout << "---------------------" << endl;
		cout << "       MAIN MENU     " << endl;
		cout << "---------------------" << endl;
		cout << "Which option would you like to play?" << endl;
		cout << "Random: 0" << endl;
		cout << "Easy: 1" << endl;
		cout << "Hard: 2" << endl << endl;
		cout << "Type 'e' to exit" << endl;
	}

	void p1() {
		arr[0][2] = 2;
		arr[0][3] = 3;
		arr[0][5] = 4;
		arr[0][7] = 6;
		arr[0][8] = 8;

		arr[1][0] = 6;
		arr[1][2] = 5;
		arr[1][4] = 9;
		arr[1][6] = 7;
		arr[1][7] = 4;

		arr[2][1] = 3;
		arr[2][2] = 4;
		arr[2][4] = 8;
		arr[2][8] = 5;

		arr[3][0] = 5;
		arr[3][7] = 7;

		arr[4][1] = 6;
		arr[4][2] = 1;
		arr[4][6] = 8;
		arr[4][7] = 5;

		arr[5][0] = 7;
		arr[5][8] = 1;

		arr[6][0] = 8;
		arr[6][4] = 2;
		arr[6][6] = 4;
		arr[6][7] = 3;

		arr[7][1] = 2;
		arr[7][2] = 6;
		arr[7][3] = 8;
		arr[7][6] = 1;
		arr[7][8] = 7;

		arr[8][0] = 8;
		arr[8][1] = 2;
		arr[8][3] = 4;
		arr[8][5] = 8;
		arr[8][6] = 2;

	}
	void p2() {
		arr[0][1] = 3;

		arr[1][0] = 4;
		arr[1][1] = 6;
		arr[1][2] = 7;
		arr[1][6] = 3;
		arr[1][8] = 9;

		arr[2][3] = 3;
		arr[2][5] = 8;
		arr[2][6] = 6;

		arr[3][3] = 6;
		arr[3][4] = 1;
		arr[3][7] = 3;
		arr[3][8] = 4;
		
		arr[4][2] = 3;
		arr[4][4] = 8;
		arr[4][6] = 2;

		arr[5][0] = 9;
		arr[5][1] = 4;
		arr[5][4] = 2;
		arr[5][5] = 3;

		arr[6][2] = 2;
		arr[6][3] = 1;
		arr[6][5] = 7;

		arr[7][0] = 6;
		arr[7][2] = 4;
		arr[7][6] = 1;
		arr[7][7] = 9;
		arr[7][8] = 5;

		arr[8][7] = 6;
	}
	void p3() {
		arr[0][6] = 4;
		arr[0][7] = 8;

		arr[1][0] = 4;
		arr[1][2] = 2;
		arr[1][5] = 1;
		arr[1][8] = 3;

		arr[2][1] = 7;
		arr[2][3] = 9;
		arr[2][8] = 6;

		arr[3][0] = 2;
		arr[3][1] = 3;
		arr[3][2] = 6;
		arr[3][4] = 4;
		arr[3][7] = 5;


		arr[5][1] = 5;
		arr[5][4] = 6;
		arr[5][6] = 7;
		arr[5][7] = 4;
		arr[5][8] = 9;

		arr[6][0] = 9;
		arr[6][5] = 7;
		arr[6][7] = 2;
	
		arr[7][0] = 5;
		arr[7][3] = 3;
		arr[7][6] = 9;
		arr[7][8] = 8;

		arr[8][1] = 2;
		arr[8][2] = 3;
	}
	void p4() {
		arr[0][2] = 1;
		arr[0][3] = 5;
		arr[0][6] = 8;
		arr[0][8] = 2;

		arr[1][0] = 7;
		arr[1][2] = 6;
		arr[1][6] = 3;

		arr[2][4] = 9;
		arr[2][5] = 1;

		arr[3][2] = 2;
		arr[3][3] = 1;
		arr[3][6] = 7;
		arr[3][8] = 5;

		arr[4][3] = 9;
		arr[4][5] = 5;

		arr[5][0] = 9;
		arr[5][2] = 5;
		arr[5][5] = 7;
		arr[5][6] = 2;

		arr[6][3] = 2;
		arr[6][4] = 1;

		arr[7][2] = 7;
		arr[7][6] = 1;
		arr[7][8] = 6;

		arr[8][0] = 2;
		arr[8][2] = 9;
		arr[8][5] = 4;
		arr[8][6] = 5;
	}

	//checking invariant
	bool check_row() {
		int num = 0;
		std::map<int, int> base[9];
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				num = arr[i][j];
				if (num != 0) {
					base[i][num]++;
				}
			}
			if (!(check_map(base[i].begin(), base[i].end()))) {
				return false;
			}
		}
		return true;
	}

	bool check_column() {
		int num = 0;
		std::map<int, int> base[9];
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				num = arr[j][i];
				if (num != 0) {
					base[i][num]++;
				}
			}
			if (!check_map(base[i].begin(), base[i].end())) {
				return false;
			}
		}
		return true;
	}

	bool check_square() {
		for (int big_col = 0; big_col < 3; big_col++) {
			for (int big_row = 0; big_row < 3; big_row++) {
				if (!check_square_small(big_col, big_row)) {
					return false;
				}
			}
		}
		return true;
	}

	bool check_square_small(int col, int row) {
		std::map<int, int> Map;
		int num = 0;
		int col_start = col * 3;
		int row_start = row * 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				num = arr[row_start + i][col_start + j];
				if (num != 0 ) {
					Map[num]++;
				}
			}
		}
		return check_map(Map.begin(), Map.end());
	}

	bool complete() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (arr[i][j] == 0) {
					return false;
				}
			}
		}
		int total;
		for (int i = 0; i < HEIGHT; i++) {
			total = 0;
			for (int j = 0; j < WIDTH; j++) {
				total += int(pow(10, arr[i][j] - 1));
			}
			if (total != 111111111) { return false; }
		}

		for (int j = 0; j < WIDTH; j++) {
			total = 0;
			for (int i = 0; i < HEIGHT; i++) {
				total += int(pow(10, arr[i][j] - 1));
			}
			if (total != 111111111) { return false; }
		}
		return true;
	}

	template <typename iter_type>
	bool check_map(iter_type begin, iter_type end) {
		while (begin != end) {
			if (begin->second >= 2) {
				return false;
			}
			begin++;
		}
		return true;
	}
};

