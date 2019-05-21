#ifndef QUADRATIC_EGUATION_H
#define QUADRATIC_EGUATION_H
#include <iostream>

using namespace std; 

/**************** Declarations ***************/

class Equation
{
	public:
		// C'tor
		Equation(double a, double b, double c);	
		// Copy C'tor
		Equation(const Equation & other) :
			m_a(other.m_a),m_b(other.m_b),m_c(other.m_c) {}
		
		~Equation() { delete[] solutions; }//{cout<<"D'tor : " << this << endl;}

		//methods
		bool set_a(double);
		void set_b(double);
		void set_c(double);
		
		double get_a() const { return m_a; };
		double get_b() const { return m_b; };
		double get_c() const { return m_c; };
		
		size_t get_solutions_size();
		double const * get_solutions();	
		
		double Determinate(); 
		const Equation& operator=(const Equation &);
		const Equation operator+(const Equation &) const;
		const Equation operator+(double);
		
		friend Equation operator+(double,const Equation &);	
		friend ostream& operator <<(ostream& , const Equation &);

		private:
			//members
			double m_a,m_b,m_c;
			double *solutions;
			size_t solutions_size;

};

#endif // QUADRATIC_EGUATION_H
