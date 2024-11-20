#include <iostream>
#include "Ex.h"
using namespace std;

#define RUN_EX 5

int main()
{
#if RUN_EX == 1
	Ex_1();
#elif RUN_EX == 2
	Ex_2();
#elif RUN_EX == 3
	Ex_3();
#elif RUN_EX == 4
	Ex_4();
#elif RUN_EX == 5
	Ex_5();
#else 
	cout << "Invalid RUN_EX";
#endif
}
