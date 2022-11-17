//точка, прямая, круг
//point, line, circle
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>

using namespace std;

class point {

public:
	int X = 0,
		Y = 0;

	point() {}
	~point() {}

};

class line : protected point {
	int start_x,
		start_y,
		end_x,
		end_y;
	double distance;

public:
	line() : start_x(X), start_y(Y), end_x(X), end_y(Y), distance(0.0) {}


	void Set_start_x(int start_x) {
		this->start_x = start_x;
	}
	void Set_start_y(int start_y) {
		this->start_y = start_y;
	}
	void Get_start_x() {
		cout << this->start_x;
	}
	void Get_start_y() {
		cout << this->start_y;
	}
	void Set_end_x(int end_x) {
		this->end_x = end_x;
	}
	void Set_end_y(int end_y) {
		this->end_y = end_y;
	}
	void Get_end_x() {
		cout << this->end_x;
	}
	void Get_end_y() {
		cout << this->end_y;
	}
	void Set_distance(double dis) {
		distance = dis;
	}
	void Get_distance() {
		distance = pow(pow(end_x - start_x, 2) + pow(end_y - start_y, 2), 0.5);
	}

	int GetRandomNumber(int min, int max)
	{
		srand(time(NULL));

		int num = min + rand() % (max - min + 1);

		return num;
	}
	void Set_characters() {
		int n(0);
		cout << setw(20) << "Coordinate start X: " << setw(9);
		cin >> n;	Set_start_x(n);
		cout << setw(20) << "Coordinate start Y: " << setw(9);
		cin >> n;	Set_start_y(n);
		cout << setw(20) << "Coordinate end X: " << setw(9);
		cin >> n;	Set_end_x(n);
		cout << setw(20) << "Coordinate end Y: " << setw(9);
		cin >> n;	Set_end_y(n);
	}
	void Set_random_characters() {
		this->start_x = GetRandomNumber(-10, 10);
		this->start_y = GetRandomNumber(-10, 10);
		this->end_x = GetRandomNumber(-10, 10);
		this->end_y = GetRandomNumber(-10, 10);
	}
	void print() {
		cout << setw(20) << "Coordinate start X: " << setw(9) << this->start_x << endl
			<< setw(20) << "Coordinate start Y: " << setw(9) << this->start_y << endl
			<< setw(20) << "Coordinate end X: " << setw(9) << this->end_x << endl
			<< setw(20) << "Coordinate end Y: " << setw(9) << this->end_y << endl
			<< setw(20) << "Distance line: " << setw(9) << distance << endl << endl;
	}

};
class circle : protected point {
	int center_x,
		center_y,
		radius;

public:
	circle() : center_x(X), center_y(Y), radius(0) {}

	void Set_X(int X) {
		this->X = X;
	}
	void Set_Y(int Y) {
		this->Y = Y;
	}
	void Get_X() {
		cout << this->X;
	}
	void Get_Y() {
		cout << this->Y;
	}
	void Set_radius(int rad) {
		radius = rad;
	}
	void Set_radius() {
		cout << radius;
	}
	void Set_random_characters() {
		center_x = (rand() % -10) + rand() % 10;
		center_y = (rand() % -10) + rand() % 10;
		radius = (rand() % -10) + rand() % 10;
	}
	int pth(int x, int y) {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	void print() {
		cout << "coordinate X: " << setw(6) << center_x << endl
			<< "coordinate Y: " << setw(6) << center_y << endl
			<< "coordinate radius: " << setw(6) << radius << endl << endl;

		const int width = radius;
		const int length = radius * 1.5;
		for (int y = width; y >= -width; y -= 2) {
			for (int x = -length; x <= length; x++) {

				if ((int)pth(x, y) == radius) cout << "*";
				else cout << " ";

			}
			cout << "\n";
		}
	}
};

int main() {
	srand((unsigned)time(NULL));

	line vector;
	circle bag;

	/*vector.print();
	vector.Set_characters();
	vector.Get_distance();
	vector.print();*/
	bag.print();
	bag.Set_random_characters();
	bag.print();

	return 0;
}