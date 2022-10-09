/**
 * Complex class using Fraction2.cpp
 * @author Jatin Pandya
 * @since 4/4/2018
 */

#include <iostream>
using namespace std;

// complex number class definition
class Complex {

public:
  // constant for 0
  static const double ZERO = 0;

  Complex() {
    a = ZERO;
    b = ZERO;
  }
  
  //setting both a and b
  void set (double one, double two) {
    a = one;
    b = two;
  }
  //Setting a
  void setReal(double num){
    a = num;
  }
  //Setting B
  void setImaginary(double imag){
    //re-use code!
    set(a, imag);
  }
  // returning real and imaginary numbers
  double getReal() const{
    return a;
  } 
  double getImaginary() const{
    return b;
  }
  // printing complex numbers
  void print() const{      
    cout << a << " + " << b << "i" << endl;
  }

private:
  double a;
  double b;
};

int main (void) {
  // variables
  Complex c1;
  Complex c2;
  Complex c3;

  // constructor tester
  cout << "Testing Constructor" << endl;
  cout << "Complex number c1 is : ";
  c1.print();
  cout << "Complex number c2 is : ";
  c2.print();
  cout << "Complex number c3 is : ";
  c3.print();

  // set tester
  cout << "Testing set() function" << endl;
  c2.set(3,6);
  c3.set(-9,2);

  cout << "Complex number c2 is now : ";
  c2.print();
  cout << "Complex number c3 is now : ";
  c3.print();

  // get tester
  cout << "Testing get() functions" << endl;

  cout << "Complex number c1's real part is " << c1.getReal() << endl;
  cout << "Complex number c1's imaginary part is " << c1.getImaginary() << endl;
  cout << "Complex number c2's real part is " << c2.getReal() << endl;
  cout << "Complex number c2's imaginary part is " << c2.getImaginary() << endl;
  cout << "Complex number c3's real part is " << c3.getReal() << endl;
  cout << "Complex number c3's imaginary part is " << c3.getImaginary() << endl;
  return 0;
}
