#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Quadratic_equation.h"

using namespace std;

int main(void)  try {
	cout << "******* Eq1 *******\n";
	Equation Eq1(10,20,30);
	cout << Eq1;
	cout << Eq1.get_solutions_size() << endl;
	Eq1 = -20 + Eq1;
	cout << Eq1;
	cout << Eq1.get_solutions_size() << endl;
	cout << Eq1.get_solutions()[0] << endl;
	
	//cout << Equation(1,5,3) + Equation(2,6,4);
	Equation Eq2 = Equation(1,3,-4);
	cout << "\n******* Eq2 *******\n";
	cout << Eq2;
	cout << Eq2.get_solutions_size() << endl;
	cout << Eq2.get_solutions()[0] << endl;
	cout << Eq2.get_solutions()[1] << endl;	
	/////////////////////////////////////////
	//Equation Eq = Eq1; 
	//cout << "\n******* Eq *******\n";
	//cout << Eq;
	//cout << "\n****** Eq1+40 ******\n";
	//cout << Eq1+40;

	cout << "******* Eq3 *******\n";
	Equation Eq3 = {-3,1,7};
	cout << Eq3;
	//Eq.set_a(0);Eq.set_b(0);Eq.set_c(0);
	cout << endl;
	cout << "******* Eq3+Eq2 *******\n";
	Equation Eq4 = Eq3 + Eq2;
	cout << Eq4;
	cout << "******* Eq4+7 ******\n";
	Equation Eq5 = Eq4 + 7;
	cout << Eq5;
	try {
		Equation Eq6(0,1,2);
	}
	catch(int err) {
		cerr << "C'tor Error, it's not Quadratic equation ==> a = " << err << endl << endl;	
	}
	
	Equation Eq6(-3,1,7);
	cout << "******* Eq6 *******\n";
	cout << Eq6;
	Equation Eq7(0,1,2);
	Equation Eq8(7,4,-5);
	cout << "******* Eq8 *******\n";
	cout << Eq8;
	return 0;
}
catch(int err) {
		//cerr << "Exception: " << e.what() << endl;
		cerr << "\nError a value a = " << err<< endl;
		return -1;
}
