#include<iostream>

using namespace std;

/*
	��׼��������豸:
	����, ��ʾ��, --> �ڴ�

	========================================================

	# �ڴ���

	���ڴ�������� ������
	���ڴ�Ľ��� �����

	istream ���ʵ�� --> cin
	ostream ��ʵ�� --> cout

	iostrean --> �ȿ�������Ҳ������� --> #include<iostream>

	========================================================

	# ���ļ�ͬ���� ���� ��������
	�ļ���ͬ��׼��������һ��, �г�����������:
	ofstream --> ����ڴ�
	ifstream --> �����ڴ�
	fstream --> ���������

	## ͷ�ļ� --> #include<fstream>

	========================================================

	# ��������Դ�� ����һ���ڴ� -- stl ��Ҫ����һ�����ֵ� ��

	���������ڴ�, ʹ�õ��� �ַ������������

	istringstream --> �ַ���������
	ostringstream --> �ַ��������
	stringstream --> �ַ�����

	����ͷ�ļ� --> #include<sstream>

	*/


void demo1() {

	// # 1. ��ע���������
	// get() �� getline() ���ڵ�����ȡ�ַ�

	int a;
	char c[10];

	// >> ����� ����ȡ �ո�ͻ���
	cin >> a >> c;	// ���� ���� 1 aa cc ��ô��ֻ���� 1 aa

	cout << a << endl;
	cout << c << endl;

	cout << "�������� get ϵ�� ��������" << endl;
}

int demo2() {

	cout << "������ get() �������� -- demo2" << endl;

	char c1, c2;
	cin >> c1;
	cin.get(c2); // ���� k g
	cout << cin.get(); // get ���ڷ���ֵ (���������������)
	cout << c2 << c1;

	return 1;
}

int demo3() {
	cout << "ʹ�� getline() ��һ��" << endl;

	char buffer[20];

	cin.getline(buffer, 20);
	cout << buffer;

	return 0;
}

/*

	ֱ���� cin ����Կո�ͻ���, ����ʹ�� get() �� geiline() ���ȡ�ո�ͻ����ַ�

*/

/*
	����������

	1. rdstate() ���� ���ڶ�ȡ��״̬ ����ֵ��һ������
		���� 0 --> ״̬��ȷ --> good()
		���� 1 --> ϵͳ���� --> bad()
		���� 2 --> ���Ѷ�ȡ���, �����ļ����� --> eof()
		(������ 3
		���� 4 --> �Ƿ����ݶ��� --> fail()

	2.


*/
int demo4() {
	int a;

	cin >> a;

	if (cin.good()) {
		cout << cin.rdstate() << endl;
	}
	if (cin.fail()) {
		cout << "���ݶ���Ƿ�" << endl;
	}

	return 1;
}

// **** ��Ҫ���� cin �� cout ������ 
class stu {
private:
	string name;
	int age;

public:
	stu(string n = "", int a = 0) {
		name = n;
		age = a;
	}
	/*
		������Ԫ���� >> �����

		1. �� �Ŀ��������� ˽�е�, ���Բ������õķ�ʽ���� cin, ���⿽�����캯��
		2. stu ҲҪ���ÿ�������, ���� �β� �� ʵ�� ռ�������ڴ�, ����Ҳ�ü�����

		����ֵ ʹ�� istream& ��Ŀ���� ʹ�� ��������ʵ�������� �Ĺ���.

	*/
	friend istream& operator>> (istream& in, stu& s1) {
		in >> s1.name >> s1.age;
		return in;
	}
	// ����� s1 �����ÿ��Լ� & Ҳ���Բ���
	// ���ಿ�ֺ� >> �����������һ������
	friend ostream& operator<< (ostream& out, stu& s1) {
		out << s1.name << s1.age;
		return out;
	}

};

// ��Ҫ���� ���� cin �� cout
int demo5() {
	// �ȴ���һ�� stu ��, Ϊ��ʵ�ְ���Ч�� �������ﲻʹ�ò���������
	stu s1;

	// ʵ�� ʹ�� cin ��ȡ s1, ʹ�����ͬʱ��ȡ��ͨ���� �� stu ��������
	// ������Ҫ�� cin ���� ��������, ��һ���ֲο� stu �ඨ���е� ���ز��ִ���.
	// ʹ����Ԫ operator>>(cin, s1)
	//cin>>s1; // ʹ�� ��Ԫ
	cin >> s1;


	return 0;
}



int main() {

	//demo1();

	//demo2();

	// demo3();

	demo4();

	return 0;
}
