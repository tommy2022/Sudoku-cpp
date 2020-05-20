#include "Grid.cpp"
#include "unit_test_framework.h"
using namespace std;

int main() {
	Grid grid;
	grid.input_num('A', 0, 2);
	if (grid.check_invariant()) {
		cout << "initial check complete" << endl << endl;
	}
	grid.input_num('D', 0, 2);
	if (!grid.check_invariant()) {
		cout << "row check complete" << endl << endl;
	}
	grid.input_num('D', 0, 0);
	grid.input_num('C', 1, 2);
	if (!grid.check_invariant()) {
		cout << "square check complete" << endl << endl;
	}
	grid.input_num('C', 1, 0);
	if (!grid.check_invariant()) {
		cout << "square check complete" << endl << endl;
	}

}