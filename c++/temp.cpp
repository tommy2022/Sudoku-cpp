#include <cassert>  //assert
#include <iostream> //ostream
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <set> 
#include <cmath>
#include <vector>
#include <list>

using namespace std;
const int HEIGHT = 9;
const int WIDTH = 9;



class Solver {
private:
	pair<vector<int>, bool> sudoku[HEIGHT][WIDTH];

public:
	Solver() :sudoku() {
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				sudoku[i][j].second = false;
				for (int k = 1; k < 10; k++) {
					sudoku[i][j].first.push_back(k);
				}
			}
		}
	}

	void reset(const int arr[HEIGHT][WIDTH]) {
		//set array in grid into sudoku
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				sudoku[i][j].second = false;
				sudoku[i][j].first.clear();
			}
		}

		int num = 0;
		for (int row = 0; row < HEIGHT; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (arr[row][col] != 0) {
					sudoku[row][col].second = true;
					sudoku[row][col].first.push_back(arr[row][col]);
				}
			}
		}

		for (int row = 0; row < HEIGHT; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (sudoku[row][col].second == false) {
					for (int j = 1; j < 10; j++) {
						sudoku[row][col].first.push_back(j);
					}
				}
			}
		}
	}

	int solve() {
		int cur_count = 0;
		int inner_times = 0;
		int outer_times = 0;
		int num = 0;
		do {
			//first check method
			do {
				for (int i = 0; i < HEIGHT; i++) {
					for (int j = 0; j < WIDTH; j++) {

						if (sudoku[i][j].second == true) {
							num = sudoku[i][j].first[0];
							delete_from_row(i, j, num);
							delete_from_col(i, j, num);
							delete_from_square(i, j, num);

						}
					}
				}
				inner_times++;
			} while (check_unique());

			outer_times++;
		} while (count_up());

		return outer_times;
	}

	void update() {
		int num;
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (sudoku[i][j].second == true) {
					num = sudoku[i][j].first[0];
					delete_from_row(i, j, num);
					delete_from_col(i, j, num);
					delete_from_square(i, j, num);
				}
			}
		}
	}

	bool complete() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (sudoku[i][j].second == false) {
					return false;
				}
			}
		}
		int total;
		for (int i = 0; i < HEIGHT; i++) {
			total = 0;
			for (int j = 0; j < WIDTH; j++) {
				total += int(pow(10, sudoku[i][j].first[0] - 1));
			}
			if (total != 111111111) { return false; }
		}

		for (int j = 0; j < WIDTH; j++) {
			total = 0;
			for (int i = 0; i < HEIGHT; i++) {
				total += int(pow(10, sudoku[i][j].first[0] - 1));
			}
			if (total != 111111111) { return false; }
		}


		for (int row_sec = 0; row_sec < 3; row_sec++) {
			for (int col_sec = 0; col_sec < 3; col_sec++) {
				total = 0;
				for (int i = row_sec * 3; i < row_sec * 3 + 3; i++) {
					for (int j = col_sec * 3; j < col_sec * 3 + 3; j++) {
						total += int(pow(10, sudoku[i][j].first[0] - 1));
					}
				}
				if (total != 111111111) { return false; }
			}
		}

		return true;
	}

	bool count_up() {
		bool rtn = false;
		int index;
		int count;
		std::vector<int>::iterator it;
		for (int row_sec = 0; row_sec < 3; row_sec++) {
			for (int col_sec = 0; col_sec < 3; col_sec++) {
				index = row_sec * 3 + col_sec;
				for (int number = 1; number < 10; number++) {
					count = 0;
					for (int i = row_sec * 3; i < row_sec * 3 + 3; i++) {
						for (int j = col_sec * 3; j < col_sec * 3 + 3; j++) {
							if (sudoku[i][j].second == false) {
								it = std::find(sudoku[i][j].first.begin(),
									sudoku[i][j].first.end(), number);
								if (it != sudoku[i][j].first.end()) {
									count++;
								}
							}
						}
					}
					if (count == 1) {
						rtn = true;
						find_num(row_sec, col_sec, number);
					}
				}
			}
		}
		return rtn;
	}


	/*bool find_solution(int square[WIDTH]) {

		int count = 0;
		for (int i = 0; i < WIDTH; i++) {
			for (int number = 1; number < 10; number++) {
				count = squ_number[i] % 10;
				squ_number[i] /= 10;
				if (count == 1) {
					find_num(i, number);
					rtn = true;
				}
			}
		}
		return rtn;
	}
	*/

	void find_num(int row_sec, int col_sec, int num) {
		std::vector<int>::iterator iter;

		for (int i = row_sec * 3; i < row_sec * 3 + 3; i++) {
			for (int j = col_sec * 3; j < col_sec * 3 + 3; j++) {
				iter = std::find(sudoku[i][j].first.begin(),
					sudoku[i][j].first.end(), num);
				if (iter != sudoku[i][j].first.end()) {
					//element found in cell
					sudoku[i][j].first.clear();
					sudoku[i][j].first.push_back(num);
					sudoku[i][j].second = true;
					return;
				}
			}
		}
		throw std::logic_error("");
		assert(false);
	}


	void print_arr() {

		for (int i = 0; i < 9; i++) {
			cout << i << " |";
			for (int j = 0; j < 9; j++) {
				if (sudoku[i][j].second == false) {
					cout << " |";
				}
				else {
					cout << sudoku[i][j].first[0] << "|";
				}


			}
			cout << endl;
			cout << "--|-|-|-|-|-|-|-|-|-|" << endl;


		}
	}

	void delete_from_row(int row, int col, int num) {
		std::vector<int>::iterator iter;

		for (int j = 0; j < WIDTH; j++) {
			if (j != col) {
				iter = std::find(sudoku[row][j].first.begin(), sudoku[row][j].first.end(), num);
				if (iter != sudoku[row][j].first.end()) {
					if (sudoku[row][j].second == false) {
						sudoku[row][j].first.erase(iter);
					}
				}
			}
		}
	}

	void delete_from_col(int row, int col, int num) {
		std::vector<int>::iterator iter;

		for (int j = 0; j < HEIGHT; j++) {
			if (j != row) {
				iter = std::find(sudoku[j][col].first.begin(), sudoku[j][col].first.end(), num);
				if (iter != sudoku[j][col].first.end()) {
					if (sudoku[j][col].second == false) {
						sudoku[j][col].first.erase(iter);
					}
				}
			}
		}
	}

	void delete_from_square(int row, int col, int num) {
		std::vector<int>::iterator iter;

		int row_section = row / 3;
		row_section = row_section * 3;
		int col_section = col / 3;
		col_section = col_section * 3;
		for (int i = row_section; i < row_section + 3; i++) {
			for (int j = col_section; j < col_section + 3; j++) {
				if (!(i == row && j == col)) {
					iter = std::find(sudoku[i][j].first.begin(), sudoku[i][j].first.end(), num);
					if (iter != sudoku[i][j].first.end()) {
						if (sudoku[i][j].second == false) {
							sudoku[i][j].first.erase(iter);
						}
					}
				}
			}
		}
	}



	void print_cell(int row, int col) {
		cout << "row: " << row << endl;
		cout << "col: " << col << endl;
		cout << "bool: " << sudoku[row][col].second << endl;
		std::vector<int>::iterator iter = sudoku[row][col].first.begin();
		cout << "data: ";
		while (iter != sudoku[row][col].first.end()) {
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}

	void reflect_change(int arr[HEIGHT][WIDTH]) {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (sudoku[i][j].second == true) {
					arr[i][j] = sudoku[i][j].first[0];
				}
			}
		}
	}

	void solve_one(int arr[HEIGHT][WIDTH]) {
		reflect_change(arr);
	}

	bool check_unique() {
		bool rtn = false;
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (sudoku[i][j].first.size() == 0) { throw std::logic_error(""); }

				if (sudoku[i][j].second == false && sudoku[i][j].first.size() == 1) {
					sudoku[i][j].second = true;
					rtn = true;
				}
			}
		}
		return rtn;
	}
	bool check_solve(int arr[HEIGHT][WIDTH]) {
		return true;
	}
};
