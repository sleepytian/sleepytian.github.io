#include<iostream>

using namespace std;

/*
	标准输入输出设备:
	键盘, 显示器, --> 内存

	========================================================

	# 内存流

	进内存的流叫做 输入流
	出内存的叫做 输出流

	istream 类的实例 --> cin
	ostream 类实例 --> cout

	iostrean --> 既可以输入也可以输出 --> #include<iostream>

	========================================================

	# 对文件同样有 出入 两个方向
	文件流同标准输出输出流一样, 有出入两个方向:
	ofstream --> 输出内存
	ifstream --> 输入内存
	fstream --> 输入输出流

	## 头文件 --> #include<fstream>

	========================================================

	# 第三个来源是 另外一个内存 -- stl 主要是这一个部分的 流

	对于其他内存, 使用的是 字符串输入输出流

	istringstream --> 字符串输入流
	ostringstream --> 字符串输出流
	stringstream --> 字符串流

	包含头文件 --> #include<sstream>

	*/


void demo1() {

	// # 1. 标注输入输出流
	// get() 和 getline() 用于单独读取字符

	int a;
	char c[10];

	// >> 运算符 不读取 空格和换行
	cin >> a >> c;	// 假设 输入 1 aa cc 那么会只读入 1 aa

	cout << a << endl;
	cout << c << endl;

	cout << "接下来是 get 系列 函数测试" << endl;
}

int demo2() {

	cout << "下面是 get() 函数测试 -- demo2" << endl;

	char c1, c2;
	cin >> c1;
	cin.get(c2); // 输入 k g
	cout << cin.get(); // get 存在返回值 (不含参数的情况下)
	cout << c2 << c1;

	return 1;
}

int demo3() {
	cout << "使用 getline() 读一行" << endl;

	char buffer[20];

	cin.getline(buffer, 20);
	cout << buffer;

	return 0;
}

/*

	直接用 cin 会忽略空格和换行, 但是使用 get() 和 geiline() 会读取空格和换行字符

*/

/*
	处理流错误

	1. rdstate() 函数 用于读取流状态 返回值是一个整数
		返回 0 --> 状态正确 --> good()
		返回 1 --> 系统错误 --> bad()
		返回 2 --> 流已读取完毕, 到达文件结束 --> eof()
		(不存在 3
		返回 4 --> 非法数据读入 --> fail()

	2.


*/
int demo4() {
	int a;

	cin >> a;

	if (cin.good()) {
		cout << cin.rdstate() << endl;
	}
	if (cin.fail()) {
		cout << "数据读入非法" << endl;
	}

	return 1;
}

// **** 重要案例 cin 和 cout 的重载 
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
		利用友元重载 >> 运算符

		1. 流 的拷贝构造是 私有的, 所以采用引用的方式调用 cin, 避免拷贝构造函数
		2. stu 也要调用拷贝构造, 但是 形参 和 实参 占用两块内存, 所以也得加引用

		返回值 使用 istream& 的目的是 使得 函数可以实现连续读 的功能.

	*/
	friend istream& operator>> (istream& in, stu& s1) {
		in >> s1.name >> s1.age;
		return in;
	}
	// 这里的 s1 的引用可以加 & 也可以不加
	// 其余部分和 >> 运算符重载是一个道理
	friend ostream& operator<< (ostream& out, stu& s1) {
		out << s1.name << s1.age;
		return out;
	}

};

// 重要案例 重载 cin 和 cout
int demo5() {
	// 先创建一个 stu 类, 为了实现案例效果 所以这里不使用参数构造器
	stu s1;

	// 实现 使用 cin 读取 s1, 使其可以同时读取普通数据 和 stu 类型数据
	// 这样需要对 cin 进行 函数重载, 这一部分参考 stu 类定义中的 重载部分代码.
	// 使用友元 operator>>(cin, s1)
	//cin>>s1; // 使用 友元
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
