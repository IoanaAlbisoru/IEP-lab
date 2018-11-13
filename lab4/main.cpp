#include <iostream>

using namespace std;

class Uncopyable {
	protected:                             // allow construction
		Uncopyable() {}                // and destruction of
		~Uncopyable() {}               // derived objects...
	private:                               //declaring the copy constructor 
		Uncopyable(const Uncopyable&);  //and copy assignment operator private
		Uncopyable& operator=(const Uncopyable&); //to prevent copying
};

class Dog: private Uncopyable{             //inherit Uncopyable to prevent generating
	public:                            //the copy constructor and 
		Dog(const string& name);   //copy assignment operator
    		void bark();
  	private:
    		string name;
};

Dog::Dog(const string& name)
	:name(name){                           //used member initialization list 
  	cout << "Dog's name: " << name << endl;//instead of assignments
}

void Dog::bark(){
	cout << "Woof !" << endl;
}

Dog& myDog(){
	static Dog dog("Bruno"); //define and initialize a local static object
	return dog;              //return a reference to it
}

int main(){

  myDog().bark();

  return 0;
}

