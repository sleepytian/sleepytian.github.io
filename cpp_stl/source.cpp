#include <iostream>
#include <fstream>

using namespace std;

class stu {
	string name;
	int age;
	double score;
	
	public:
		
	stu() {}
	
	stu(string name, int age, double score) {
		this->age = age;
		this->name = name;
		this->score = score; 
	}
		
	void show() {
		
	}
	
	void write(ofstream &fout) {
		cout << name << age << score;
	}
	
	read(ifstream &fin) {
		cin >> name >> age >> score; 
	}
};

void demo1() {
	stu s1("name1",1,1);
	stu s2("name",2,3);
	
	stu s;
	
	// д���ļ�
	ofstream fout("test.txt");
	s1.write(fout);
	s2.write(fout);
	fout.close();
	
	// ���ļ� 
	ifstream fin("test.txt");
	while (s.read(fin) && !( fin.eof() ) ) {
	s.show();
	}
}	


// �������ļ� 
void demo2() {
	
}

int main () {
	
	//demo1();
	
	return 0;
}
