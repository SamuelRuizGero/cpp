#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;

class Students
{
private:
	struct Student
	{
		string name;
		double gpa;
		bool used;
	};

	Student *s;
	int capacity;

public:
	Students(int);
	~Students();
	void clear();
	int insert(int, string, double);
	int remove(int);
	bool find(string) const;
	bool isEmpty() const;
	bool isFull() const;
	void print() const;
};

Students::Students(int c) {
	capacity = c;
	s = new Student[c];
	for (int i = 0; i < capacity; i++) {
		s[i].used = false;
	}
}
Students::~Students() {
	delete[] s;
}
void Students::clear() {
	for (int i = 0; i < capacity; i++) {
		s[i].used = false;
	}
}
int Students::insert(int i, string name, double gpa) {
	if (i < 0 || i >= capacity) {
		return -1;
	}	else {
		s[i].name = name;
		s[i].gpa = gpa;
		s[i].used = true;
		return 0;
	}
}
int Students::remove(int i) {
	if (i> 0 && i < capacity) {
		s[i].used = false;
		return 0;
	} else {
		return -1;
	}
}
bool Students::find(string name) const {
	
	for (int i = 0; i < capacity; i++) {
	
		if (name == s[i].name) {

			s[i].used = true;
			return true;
		}
	}
	return false;
};
bool Students::isEmpty() const {
	for (int i = 0; i < capacity; i++) {
		if (s[i].used == true) {
			return false;
		}
	}
	return true;
};
bool Students::isFull() const {
	for (int i = 0; i < capacity; i++) {
		if (s[i].used == false) {
			return false;
		}
	}
	return true;
};
void Students::print() const {
	for (int i = 0; i < capacity; i++) {
		if(s[i].used == true){
			cout << "Name: " << s[i].name << " GPA:" << s[i].gpa << endl;
		}
	}
};
#endif