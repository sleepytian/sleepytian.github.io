#include <iostream>
#include <fstream>

using namespace std;

class Stu {
	char name[20];
	int age;
	double score;
	
	public:
		
	// 构造函数 
	Stu (char n[]="", int a=0, double s = 0) {
		strcpy(name,n);
		age = a;
		score = s; 
	}
	
	void show() {
		cout << name << " " << age << " " << score << endl; 
	}
};

void demo1() {
	Stu[3] = {
		Stu("name1",1,2),
		Stu("name2",3,4),
		Stu("name3",5,6)
	}
	
	// 以二进制方式写入文件, 标明使用 binary 方式写入 
	ofstream out ("test.txt", ios::binary);
	for (int i = 0; i < 3; i++) {
		out.write((char * )s[i], sizeof(Stu));
	}
	
	
}


int main () {
	
	demo1();
	
	return 0;
} 
