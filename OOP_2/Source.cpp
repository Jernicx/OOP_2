#include <iostream>
#include <conio.h>

using namespace std;

class Earth {
public:
	int x, y;
	Earth()
	{
		cout <<" Earth() "<< endl;
		x = 0;
		y = 0;

	}
	Earth(int x, int y) {
		cout << "Earth(int x, int y)" << endl;
		this->x = x;
		this->y = y;
	}
	Earth(const Earth& p) {
		cout << "Earth(const Earth & p)" << endl;
		x = p.x;
		y = p.y;
	}
	virtual ~Earth() {
		cout << x<<"  "<<y << endl;
		cout << "~Earth()" << endl;
	}
	 virtual void move(int dx, int dy) {
		x = x + dx;
		y = y + dy;
	}
	void reset();
	virtual void print() {
		cout << "Привет" << endl;
	}
	
};
void Earth::reset() {
	x = 0;
	y = 0;
}
class Albedo : public Earth {
protected:
	int Mech;
public:
	Albedo():Earth()
	{
		cout << "Albedo() " << endl;
		Mech = 0;

	}
	Albedo(int x, int y, int Mech): Earth(x,y) {
		cout << "Albedo(int x, int y, int Mech)" << endl;
		this->Mech = Mech;
	}
	Albedo(const Albedo &p) {
		cout << "Albedo(const Earth& p)" << endl;
		Mech = p.Mech;
		x = p.x;
		y = p.y;
	}
	void move_back(int dx, int dy, int dmech) {
		x = x - dx;
		y = y - dy;
		Mech = Mech - dmech;
	}
	
	void print() {
		cout << "пока" << endl;
	}
	~Albedo() {
		cout << x << "  " << y<< "  "<<Mech << endl;
		cout << "~Albedo()" << endl;
	}
	void  creating_mechanism(int new_mechanism) {
		Mech = new_mechanism;
	}
	
};
class DED {  
protected:
	Earth* p1;
	Earth* p2;
public:
	DED() 
	{
		cout << "DED() " << endl;
		p1 = new Earth;
		p2 = new Earth;

	}
	DED(int x, int y, int x2, int y2) {
		cout << "DED(int x, int y, int x2, int y2)" << endl;
		p1 = new Earth(x, y);
		p2 = new Earth(x2, y2);
	}
	DED(const DED* pm) {
		cout << "DED(const DED& p)" << endl;
		p1 = new Earth(*(pm->p1));
		p2 = new Earth(*(pm->p2));
	}

	~DED() {
		delete p1;
		delete p2;
		cout << "~DED()" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "RUS");
	{
		cout << "Создание статических объектов" << endl;
		Earth P;
		Earth p2(10, 20);
		Earth p3(p2);
	}
	printf("\n\n\n\n");
	{
		cout << "Создание динамических объектов" << endl;
		Earth *p= new Earth;
		Earth *P2= new Earth(10, 20);
		Earth *p3=new Earth(*P2);
		delete p;
		delete P2;
		delete p3;
	}
	printf("\n\n\n\n");
	{
		cout << "Методы определения и после определения" << endl;
		Earth *p=new Earth(1,2);
		Earth *p2= new Earth(10, 10);
		p->reset();
		p2->move(10,10);
		delete p;
		delete p2;


	}
	printf("\n\n\n\n");
	{
		cout << "Создание и использование методов потомка" << endl;
		Albedo *p = new Albedo(10, 20, 30);
		p->move_back(10,20,30);
		delete p;
	}
	printf("\n\n\n\n");
	{
		cout << "Помещение объектов переменных различных типов и переопределение объектов" << endl;
		Earth* p = new Albedo(1, 5, 7);
		(*(p)).move(10,20);
		p->print();

		delete p;

	}
	printf("\n\n\n\n");
	{
		cout << "Композиция" << endl;
		DED* p = new DED;
		DED* p2 = new DED(p);
		delete p;
		delete p2;
	}
	
	return 0;
}