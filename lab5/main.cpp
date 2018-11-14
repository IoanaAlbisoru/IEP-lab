#include <iostream>

using namespace std;

class Complex {
	private:
		int re, im;
	public:
		Complex() {
			re = im = 0;
		}
		Complex(int real, int imag) {
			re = real;
			im = imag;
		}
		Complex operator+(Complex op);
		Complex operator-(Complex op);
		void show();
};

Complex Complex::operator+(Complex op){
	Complex tmp;
	tmp.re = re + op.re;
	tmp.im = im + op.im;

	return tmp;
}

Complex Complex::operator-(Complex op){
	Complex tmp;
	tmp.re = re - op.re;
	tmp.im = im - op.im;

	return tmp;
}

void Complex::show() {
	cout<< re << " + "<< im << "i\n";
}

int main() {
	Complex a = Complex(2, 3);
	Complex b = Complex(4, 5);
	Complex rez1 = a + b;
	Complex rez2 = a - b;
	rez1.show();
	rez2.show();
	return 0;
}