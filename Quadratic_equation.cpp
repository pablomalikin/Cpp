#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Quadratic_equation.h"

using namespace std; 

Equation::Equation(double a, double b, double c) {
	if ( !set_a(a) )
			throw 0;
	set_b(b);
	set_c(c);
	solutions_size = 0;
	solutions = new double[2];		
}

bool Equation::set_a(double a){
	try {
		if ( a == 0 )
			throw 0;
		m_a = a;
	}
	catch (int b) {
		cout << "'a' cann't be " << b << endl;
		return false;
	}
	return true;
}

void Equation::set_b(double b){
	m_b = b;
}

void Equation::set_c(double c){
	m_c = c;
}

const Equation& Equation::operator=(const Equation& other){
	this->m_a = other.m_a;
	this->m_b = other.m_b;
	this->m_c = other.m_c;
	return *this;
}

const Equation Equation::operator+(const Equation &other) const {
	return Equation(this->m_a+other.get_a(),
					this->m_b+other.get_b(),
					this->m_c+other.get_c());
}

const Equation Equation::operator+(double num) {
	return Equation(this->m_a,this->m_b,this->m_c+num);
}

double Equation::Determinate()
{
	return( pow(m_b,2) - 4*m_a*m_c );
}

double const * Equation::get_solutions(){
	double D = Determinate();
	if ( D < 0 ) {
		cout << "We don't have sulution\n";
		solutions_size = 0;
	}
	else 
		if ( D == 0 ) {
			//cout << "We have only 1 solution\n";
			solutions_size = 1;
			solutions[0] = solutions[1] = -1*m_b/(2*m_a);
		}
		else { 
			//cout << "We have 2 solution\n";
			solutions[0] = (-1*m_b + sqrt(D))/(2*m_a);
			solutions[1] = (-1*m_b - sqrt(D))/(2*m_a);
		}
	return solutions;
}

size_t Equation::get_solutions_size(){
	double D = Determinate();
	if ( D < 0 ) solutions_size = 0;
	else 
		if ( D == 0) solutions_size = 1;
		else solutions_size = 2;
	return solutions_size;
}

Equation operator+(double num,const Equation &other) {
	Equation temp = other;
	temp.m_c = num + other.get_c();
	return temp;
}

ostream& operator <<(ostream& out, const Equation& other){
	if (other.m_a != 1 && other.m_a) out << endl << other.m_a << "X^2";
	else 
		if (other.m_a) out << endl << "X^2";
	if (other.m_b) {
		if ( other.m_b > 0 ) out << " + "; 
		else out << " - ";
		if (other.m_b != 1) out << fabs(other.m_b) << "X";
		else 
			if (other.m_b) out << "X";
	}
	if (other.m_c) {
		if ( other.m_c > 0 ) out << " + "; 
		else out << " - ";
		out << fabs(other.m_c);
	}
	out << " = 0" << endl << endl;
	return out;
}
