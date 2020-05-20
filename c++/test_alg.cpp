#include "unit_test_framework.h"
#include "Grid.cpp"
#include <time.h>
using namespace std;

/*TEST(delete_from_row) {
	clock_t t;
	t = clock();
	Grid grid;
	grid.input_num('A', 0, 1);
	grid.input_num('B', 0, 2);
	grid.input_num('C', 0, 3);
	grid.input_num('D', 0, 4);
	grid.input_num('E', 0, 5);
	grid.input_num('F', 0, 6);
	grid.input_num('G', 0, 7);
	grid.input_num('H', 0, 8);


	grid.test_func();
	grid.print_grid();
	cout << (float)t/CLOCKS_PER_SEC << endl;
}

TEST(cross_solution) {
	cout << endl << endl << "test 2" << endl << "option e" << endl;
	clock_t t;
	t = clock();
	Grid grid;
	grid.input_num('E', 0, 7);
	grid.input_num('I', 1, 7);
	grid.input_num('A', 3, 7);
	grid.input_num('B', 8, 7);

	grid.test_func();

	cout << (float)t / CLOCKS_PER_SEC << endl;
}


TEST(test_p1) {
	cout << endl << endl << "option 1" << endl;
	clock_t t;
	t = clock();
	Grid grid;
	grid.test_func();
	cout << (float)t / CLOCKS_PER_SEC << endl;

}
*/

TEST(random) {
	cout << endl << endl << "option01" << endl;
	clock_t t;
	t = clock();
	Sudoku test;
	cout << t << endl;
	cout << (float)t / CLOCKS_PER_SEC << endl;
}


TEST_MAIN()