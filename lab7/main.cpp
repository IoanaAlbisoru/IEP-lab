#include <iostream>
#include <cstdlib> 
#include <memory>

using namespace std;

class Bitmap {
	public:
		int a;
		Bitmap(int a){
			this->a = a;
		};
		Bitmap(const Bitmap& b){};

		int getAtribute(){
			return a;
		}
};

int main(){
	//auto_ptr int example
	std::auto_ptr<int> p1 (new int);
	*p1.get()=10;
	std::auto_ptr<int> p2 (p1);
	std::cout << "p2 points to " << *p2 << '\n';

	//auto_ptr object example
	std::auto_ptr<Bitmap> bitmap1 (new Bitmap(5));
	std::auto_ptr<Bitmap> bitmap2 (bitmap1);
	std::cout << "bitmap2 points to " << bitmap2->getAtribute() << '\n';

	//shared_ptr object example
	std::shared_ptr<Bitmap> bitmap3 (new Bitmap(7));
	std::shared_ptr<Bitmap> bitmap4 (bitmap3);
	std::cout << "bitmap4 points to " << bitmap4->getAtribute() << '\n';

	return 0;
}