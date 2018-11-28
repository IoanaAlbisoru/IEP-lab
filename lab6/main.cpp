#include <iostream>
#include <cstdlib> 

using namespace std;

class Bitmap {
	public:
		Bitmap(){};
		Bitmap(const Bitmap& b){};
};

class Widget {
	public:
		Widget& operator=(const Widget& rhs) 
		{ 
			//return *this; // return the left-hand object - ITEM 10

			Bitmap *pOrig = pb; // remember original pb
			pb = new Bitmap(*rhs.pb); // point pb to a copy of rhs’s bitmap
			delete pOrig; // delete the original pb
			return *this;
		}

		Widget& operator+=(const Widget& rhs) // the convention applies to
		{ 
			return *this;
		}
		Widget& operator-=(int rhs) // it applies even if the
		{ // operator’s parameter type ... // is unconventional
			return *this;
		}

	private:
		Bitmap *pb;
};


class Widget2 : public Widget {
	public:
		Widget2(const Widget2& rhs);
		Widget2(int p) {
			priority = p;
		}
		Widget2& operator=(const Widget2& rhs);
	private:
		int priority;
};

Widget2::Widget2(const Widget2& rhs): Widget(rhs), priority(rhs.priority){
	cout << "Widget2 copy constructor" << endl;
}

Widget2& Widget2::operator=(const Widget2& rhs){
	cout << "Widget2 copy assignment operator" << endl;
	Widget::operator=(rhs); // assign base class parts
	priority = rhs.priority;
	return *this;
}


int main(){
	Bitmap bm; //= new Bitmap();
	Widget w;// = new Widget(bm);
	Widget2 w2(3);// = new Widget2(2);
	Widget2 w3 = w2;
	return 0;
}