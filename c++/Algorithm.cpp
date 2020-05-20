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
	map<int, map<int, int>> squ_number;

public:
	Solver() :sudoku(), squ_number() {
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				sudoku[i][j].second = false;
				for (int k = 1; k < 10; k++) {
					sudoku[i][j].first.push_back(k);
				}
			}
		}
	}

	void reset_number() {
		//reset squ_number. 
		//Done every round of solving.
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 1; j < 10; j++) {
				squ_number[i][j] = 0;
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
		int first_layer = 0;
		int second_layer = 0;
		do{
			//first check method
			do {
				update();
				first_layer++;
			} while (check_unique());
			
			reset_number();
			count_up();

			second_layer++;

		} while (find_solution());

		return 1;
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

	void count_up() {
		int index;
		for (int row_sec = 0; row_sec < 3; row_sec++) {
			for (int col_sec = 0; col_sec < 3; col_sec++) {
				index = row_sec * 3 + col_sec;
				for (int i = row_sec * 3; i < row_sec * 3 + 3; i++) {
					for (int j = col_sec * 3; j < col_sec * 3 + 3; j++) {
						if (sudoku[i][j].second == false) {
							for (std::vector<int>::iterator it = sudoku[i][j].first.begin();
								it != sudoku[i][j].first.end(); it++) {
								squ_number[index][*it]++;
							}
						}
					}
				}
			}
		}
	}

	bool find_solution() {
		bool rtn = false;
		map<int, int>::iterator it;
		for (int i = 0; i < WIDTH; i++) {
			it = squ_number[i].begin();
			while (it != squ_number[i].end()) {
				if (it->second == 1) {
					find_num(i, it->first);
					rtn = true;
				}
				it++;
			}
		}
		return rtn;
	}

	void find_num(int num, int elem) {
		std::vector<int>::iterator iter;
			int row = num / 3;
		int col = num % 3;
		for (int i = row * 3; i < row * 3 + 3; i++) {
			for (int j = col * 3; j < col * 3 + 3; j++) {
				iter = std::find(sudoku[i][j].first.begin(),
					sudoku[i][j].first.end(), elem);
				if (iter != sudoku[i][j].first.end()) {
					//element found in cell
					sudoku[i][j].first.clear();
					sudoku[i][j].first.push_back(elem);
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
		int row;
		int col;
		reset(arr);
		update();
		int num = solve_one_helper(row, col);
		arr[row][col] = num;
		char column = char(col + 65);
		cout << "Updated column " << column << ", row " << row
			<< " to " << num << endl;
		return;
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

	int solve_one_helper(int& row, int& col) {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (sudoku[i][j].second == false && sudoku[i][j].first.size() == 1) {
					row = i;
					col = j;
					return sudoku[i][j].first[0];
				}
			}
		}
		reset_number();
		count_up();

		map<int, int>::iterator it;
		for (int i = 0; i < WIDTH; i++) {
			it = squ_number[i].begin();
			while (it != squ_number[i].end()) {
				if (it->second == 1) {
					find_num_one(i, it->first, row, col);
					return it->first;
				}
				it++;
			}
		}

		throw std::logic_error("");
	}


	void find_num_one(int num, int elem, int& row_in, int& col_in) {
		std::vector<int>::iterator iter;
		int row = num / 3;
		int col = num % 3;
		for (int i = row * 3; i < row * 3 + 3; i++) {
			for (int j = col * 3; j < col * 3 + 3; j++) {
				iter = std::find(sudoku[i][j].first.begin(),
					sudoku[i][j].first.end(), elem);
				if (iter != sudoku[i][j].first.end()) {
					//element found in cell
					row_in = i;
					col_in = j;
					return;
				}
			}
		}
		throw std::logic_error("");
		assert(false);
	}

	bool check_solve(int arr[HEIGHT][WIDTH]) {
		return true;
	}
};
	