#include "LinkedList.h"
#include "Game.h"


class c1 {
	int i1 = 1;
};
class c2 :public c1{
	int i2 = 2;
};



int main() {
	LinkedList <c1*> list;
	list.insert(new c2);
	cout << list[0];
}