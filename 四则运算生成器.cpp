#include <iostream>
using namespace std;
#include<math.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<map>
#include<string>
#include<string.h>
#include<fstream>
//��Ŀ��
//����ʲô�������
//������������
//�������ڵ�����
//�����ķ�����
int n, ssize, typee, symbolnum, way;//n-��Ŀ�� ssize-��������С typee-�������� symbolnum ������  way�����ʽ 
int symbol[100];//������� 
ofstream fp;
//�û�ѡ�����
void userselection()
{
	int m;
	cout << "��ѡ����Ҫ���ɵ�����             " << endl;
	cout << "��������Ҫ���ɵ���Ŀ����" << endl;
	cin >> n;
	cout << "��������Ҫ����������Ĵ�С��" << endl;
	cin >> ssize;
	cout << "��ѡ����Ҫ������������ͣ�" << endl;
	cout << "1������\n" << "2������" << endl;
	cin >> typee;
	cout << "��ѡ����Ҫ�����ķ�������" << endl;
	cout << "1��1��\n" << "2��2��\n" << "3��3��\n" << "4��4��\n" << endl;
	cin >> symbolnum;
	cout << "��ѡ����Ҫ������������ţ�" << endl;
	cout << "1���ӷ�\n" << "2������\n" << "3���˷�\n" << "4����������������\n" << "5����������������" << endl;
	for (int i = 0; i < symbolnum; i++)
	{
		cin >> m;
		symbol[i] = m;;
	}
	cout << "��ѡ����Ҫ����ķ�ʽ��" << endl;
	cout << "1���ļ�\n" << "2������" << endl;
	cin >> way;
}

//�����������
vector<int> generateNumbers(int minn, int maxn, int numsize)
{
	vector<int> num;
	int number;
	for (int i = 0; i < numsize; i++)
	{
		number = minn + rand() % maxn;
		num.push_back(number);
	}
	return num;
}
//�������һ����
int generatesingle(int minn, int maxn) {
	return minn + rand() % maxn;
}
// շת������������Լ��
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
//�жϷ�������Լ
bool isFractionIrrational(int numerator, int denominator)
{
	if (gcd(numerator, denominator) == 1 && numerator != denominator) {
		return true;
	}
	return false;
}
//�����������
vector<int> generateFraction(int minn, int maxn, int numsize)
{
	vector<int> numfraction;
	int number1, number2;
	int flag = 0;
	while (true)
	{
		number1 = minn + rand() % maxn;
		number2 = minn + rand() % maxn;
		if (number1 != 0 && number2 != 0 && number1 != number2 && isFractionIrrational(number1, number2))
		{
			numfraction.push_back(number1);
			numfraction.push_back(number2);
			flag++;
		}
		if (flag == 2)
		{
			break;
		}
	}
	return numfraction;
}
//�ӷ�����
pair<string, double> addition(int typee, int minn, int maxn, int numsize)
{
	vector<int> num;
	pair<string, double> element;
	string str;
	double res;
	if (typee == 1)
	{
		num = generateNumbers(minn, maxn, numsize);
		str = to_string(num[0]) + " + " + to_string(num[1]);
		res = num[0] + num[1];
		element.first = str;
		element.second = res;
	}
	else if (typee == 2)
	{
		num = generateFraction(minn, maxn, numsize);
		str = to_string(num[0]) + "/" + to_string(num[1]) + " + " + to_string(num[2]) + "/" + to_string(num[3]);
		res = num[0] * 1.0 / num[1] + num[2] * 1.0 / num[3];
		element.first = str;
		element.second = res;
	}
	return element;
}
//��������
pair<string, double> subtraction(int typee, int minn, int maxn, int numsize)
{
	vector<int> num;
	pair<string, double> element;
	string str;
	double res;
	if (typee == 1)
	{
		num = generateNumbers(minn, maxn, numsize);
		if (num[0] < num[1])
		{
			swap(num[0], num[1]);
		}
		str = to_string(num[0]) + " - " + to_string(num[1]);
		res = num[0] - num[1];
		element.first = str;
		element.second = res;
	}
	else if (typee == 2)
	{
		num = generateFraction(minn, maxn, numsize);
		double res1 = num[0] * 1.0 / num[1];
		double res2 = num[2] * 1.0 / num[3];
		if (res1 < res2)
		{
			swap(num[0], num[2]);
			swap(num[1], num[3]);
		}
		str = to_string(num[0]) + "/" + to_string(num[1]) + " - " + to_string(num[2]) + "/" + to_string(num[3]);
		res = num[0] * 1.0 / num[1] - num[2] * 1.0 / num[3];
		element.first = str;
		element.second = res;
	}
	return element;
}
//�˷�����
pair<string, double> multiplication(int typee, int minn, int maxn, int numsize)
{
	vector<int> num;
	pair<string, double> element;
	string str;
	double res;
	if (typee == 1)
	{
		num = generateNumbers(minn, maxn, numsize);
		str = to_string(num[0]) + " * " + to_string(num[1]);
		res = num[0] * num[1];
		element.first = str;
		element.second = res;
	}
	else if (typee == 2)
	{
		num = generateFraction(minn, maxn, numsize);
		str = to_string(num[0]) + "/" + to_string(num[1]) + " * " + to_string(num[2]) + "/" + to_string(num[3]);
		res = (num[0] * 1.0 / num[1]) * (num[2] * 1.0 / num[3]);
		element.first = str;
		element.second = res;
	}
	return element;
}
//�������㣨�����Ƿ������� remain=1-������   remain=0-��������
pair<string, double> division(int typee, int minn, int maxn, int numsize, int remain)
{
	vector<int> num;
	pair<string, double> element;
	string str;
	double res;
	if (typee == 1 && remain == 1)
	{
		while (true) {
			num = generateNumbers(minn, maxn, numsize);
			if (num[1] != 0 && num[0] % num[1] != 0 && num[0] != 0 && num[0] != num[1]) {
				break;
			}
		}
		str = to_string(num[0]) + " / " + to_string(num[1]);
		res = num[0] / num[1];
		element.first = str;
		element.second = res;
	}
	else if (typee == 1 && remain == 0)
	{
		while (true) {
			num = generateNumbers(minn, maxn, numsize);
			if (num[1] != 0 && num[0] % num[1] == 0 && num[0] != 0 && num[0] != num[1]) {
				break;
			}
		}
		str = to_string(num[0]) + " / " + to_string(num[1]);
		res = num[0] / num[1];
		element.first = str;
		element.second = res;
	}
	else if (typee == 2)
	{
		num = generateFraction(minn, maxn, numsize);
		str = to_string(num[0]) + "/" + to_string(num[1]) + "  /  " + to_string(num[2]) + "/" + to_string(num[3]);
		res = (num[0] * 1.0 / num[1]) / (num[2] * 1.0 / num[3]);
		element.first = str;
		element.second = res;
	}
	return element;
}

//��������(����Լӷ����������Ҫ��������˳���ʱ��,cal=1-�ӷ�  cal=0-����)
pair<string, double> bracket(int typee, int minn, int maxn, int numsize, int cal)
{
	vector<int> num;
	pair<string, double> element;
	string str;
	double res;
	if (cal == 1)
	{
		if (typee == 1)
		{
			num = generateNumbers(minn, maxn, numsize);
			str = " ( " + to_string(num[0]) + " + " + to_string(num[1]) + " ) ";
			res = num[0] + num[1];
			element.first = str;
			element.second = res;
		}
		else if (typee == 2) {
			num = generateFraction(minn, maxn, numsize);
			str = " ( " + to_string(num[0]) + "/" + to_string(num[1]) + " + " + to_string(num[2]) + "/" + to_string(num[3]) + " ) ";
			res = num[0] * 1.0 / num[1] + num[2] * 1.0 / num[3];
			element.first = str;
			element.second = res;
		}
	}
	else if (cal == 0)
	{
		if (typee == 1)
		{
			num = generateNumbers(minn, maxn, numsize);
			if (num[0] < num[1])
			{
				swap(num[0], num[1]);
			}
			str = " ( " + to_string(num[0]) + " - " + to_string(num[1]) + " ) ";
			res = num[0] - num[1];
			element.first = str;
			element.second = res;
		}
		else if (typee == 2)
		{
			num = generateFraction(minn, maxn, numsize);
			double res1 = num[0] * 1.0 / num[1];
			double res2 = num[2] * 1.0 / num[3];
			if (res1 < res2)
			{
				swap(num[0], num[2]);
				swap(num[1], num[3]);
			}
			str = " ( " + to_string(num[0]) + "/" + to_string(num[1]) + " - " + to_string(num[2]) + "/" + to_string(num[3]) + " ) ";
			res = num[0] * 1.0 / num[1] - num[2] * 1.0 / num[3];
			element.first = str;
			element.second = res;
		}
	}
	return element;
}
//�����û��������ɶ�Ӧ��ʽ��
void Generativequation(int n, int symbolnum, int* symbol, int typee, int minn, int maxn, int numsize, int way)
{
	pair<string, double> element;
	pair<string, double> element1;
	int num;
	vector<int> num1;
	if (way == 1) {
		fp.open("D:\\adatafile\\My school life\\�������\\�����������.txt", ios::out);
	}
	if (symbolnum == 1)
	{
		if (symbol[0] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				element = addition(typee, minn, maxn, numsize);
				if (way == 1) {
					fp << element.first << " = " << endl;
				}
				else {
					cout << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 2)
		{
			for (int i = 0; i < n; i++)
			{
				element = subtraction(typee, minn, maxn, numsize);
				if (way == 1) {
					fp << element.first << " = " << endl;
				}
				else {
					cout << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = multiplication(typee, minn, maxn, numsize);
				if (way == 1) {
					fp << element.first << " = " << endl;
				}
				else {
					cout << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 4)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 1);
				if (way == 1) {
					fp << element.first << " = " << endl;
				}
				else {
					cout << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 0);
				if (way == 1) {
					fp << element.first << " = " << endl;
				}
				else {
					cout << element.first << " = " << endl;
				}
			}
		}
	}
	else if (symbolnum == 2)
	{
		if (symbol[0] == 1 && symbol[1] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				element = addition(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " + " << num << " = " << endl;
					}
					else {
						cout << element.first << " + " << num << " = " << endl;
					}
				}
				else if(typee==2){
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " + " << num1[0]<<"/"<<num1[1]<< " = " << endl;
					}
					else {
						cout << element.first << " + " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 2)
		{
			for (int i = 0; i < n; i++)
			{
				element = addition(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					while (element.second < num)
					{
						num = generatesingle(minn, maxn);
					}
					if (way == 1) {
						fp << element.first << " - " << num << " = " << endl;
					}
					else {
						cout << element.first << " - " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn,maxn,numsize);
					while (element.second < num1[0]*1.0/num1[1])
					{
						num1 = generateFraction(minn, maxn, numsize);
					}
					if (way == 1) {
						fp << element.first << " - " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " - " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = bracket(typee, minn, maxn, numsize, 1);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " * " << num << " = " << endl;
					}
					else {
						cout << element.first << " * " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " * " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " * " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 4)
		{
			for (int i = 0; i < n; i++)
			{
				if (typee == 1) {
					element = bracket(typee, minn, maxn, numsize, 1);
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num != 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element = bracket(typee, minn, maxn, numsize, 1);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num == 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " / " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " / " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				element = subtraction(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " + " << num << " = " << endl;
					}
					else {
						cout << element.first << " + " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " + " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " + " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 2)
		{
			for (int i = 0; i < n; i++)
			{
				element = subtraction(typee, minn, maxn, numsize);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (int(element.second) > num) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num << " = " << endl;
					}
					else {
						cout << element.first << " - " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					while (true) {
						num1 = generateFraction(minn, maxn, numsize);
						if (element.second > num1[0]*1.0/num1[1]) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " - " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = bracket(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " * " << num << " = " << endl;
					}
					else {
						cout << element.first << " * " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " * " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " * " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 4)
		{
			for (int i = 0; i < n; i++)
			{
				if (typee == 1) {
					element = bracket(typee, minn, maxn, numsize, 0);
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num != 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element = bracket(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num == 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " / " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " / " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 3 && symbol[1] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				element = multiplication(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " + " << num << " = " << endl;
					}
					else {
						cout << element.first << " + " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " + " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " + " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 3 && symbol[1] == 2)
		{
			for (int i = 0; i < n; i++)
			{
				element = multiplication(typee, minn, maxn, numsize);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (int(element.second) > num) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num << " = " << endl;
					}
					else {
						cout << element.first << " - " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					while (true) {
						num1 = generateFraction(minn, maxn, numsize);
						if (element.second >num1[0]*1.0/num1[1]) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " - " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 3 && symbol[1] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = multiplication(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " * " << num << " = " << endl;
					}
					else {
						cout << element.first << " * " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " * " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " * " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 3 && symbol[1] == 4)
		{
			for (int i = 0; i < n; i++)
			{
				if (typee == 1) {
					element = multiplication(typee, minn, maxn, numsize);
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num != 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 3 && symbol[1] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element = multiplication(typee, minn, maxn, numsize);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num == 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " / " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " / " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 5 && symbol[1] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " + " << num << " = " << endl;
					}
					else {
						cout << element.first << " + " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " + " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " + " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 5 && symbol[1] == 2)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (int(element.second) > num) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num << " = " << endl;
					}
					else {
						cout << element.first << " - " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					while (true) {
						num1 = generateFraction(minn, maxn, numsize);
						if (element.second > num1[0]*1.0/num1[1]) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " - " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " - " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 5 && symbol[1] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (way == 1) {
						fp << element.first << " * " << num << " = " << endl;
					}
					else {
						cout << element.first << " * " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " * " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " * " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 5 && symbol[1] == 4)
		{
			for (int i = 0; i < n; i++)
			{
				if (typee == 1) {
					element = division(typee, minn, maxn, numsize, 0);
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num != 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
			}
		}
		else if (symbol[0] == 5 && symbol[1] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element = division(typee, minn, maxn, numsize, 0);
				if (typee == 1) {
					while (true) {
						num = generatesingle(minn, maxn);
						if (num != 0 && int(element.second) % num == 0) {
							break;
						}
					}
					if (way == 1) {
						fp << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element.first << " / " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element.first << " / " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element.first << " / " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
	}
	else if (symbolnum == 3)
	{
		if (symbol[0] == 1 && symbol[1] == 2 && symbol[2] == 3)
		{
			for (int i = 0; i < n; i++)
			{
				element = bracket(typee, minn, maxn, numsize, 1);
				element1 = multiplication(typee, minn, maxn, numsize);
				while (true) {
					element1 = multiplication(typee, minn, maxn, numsize);
					if (int(element.second) > int(element1.second)) {
						break;
					}
				}
				if (way == 1) {
					fp << element.first << " - " << element1.first << " = " << endl;
				}
				else {
					cout << element.first << " - " << element1.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 2 && symbol[2] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element1 = bracket(typee, minn, maxn, numsize, 1);
				while (true) {
					element = division(typee, minn, maxn, numsize, 0);
					if (int(element1.second) > int(element.second)) {
						break;
					}
				}
				if (way == 1) {
					fp << element1.first << " - " << element.first << " = " << endl;
				}
				else {
					cout << element1.first << " - " << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 1 && symbol[1] == 3 && symbol[2] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element1 = bracket(typee, minn, maxn, numsize, 1);
				element = division(typee, minn, maxn, numsize, 0);
				if (way == 1) {
					fp << element1.first << " * " << element.first << " = " << endl;
				}
				else {
					cout << element1.first << " * " << element.first << " = " << endl;
				}
			}
		}
		else if (symbol[0] == 2 && symbol[1] == 3 && symbol[2] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element1 = bracket(typee, minn, maxn, numsize, 0);
				element = division(typee, minn, maxn, numsize, 0);
				if (way == 1) {
					fp << element1.first << " * " << element.first << " = " << endl;
				}
				else {
					cout << element1.first << " * " << element.first << " = " << endl;
				}
			}
		}
	}
	else if (symbolnum == 4)
	{
		if (symbol[0] == 1 && symbol[1] == 2 && symbol[2] == 3 && symbol[3] == 5)
		{
			for (int i = 0; i < n; i++)
			{
				element1 = bracket(typee, minn, maxn, numsize, 1);
				element = multiplication(typee, minn, maxn, numsize);
				if (typee == 1) {
					num = generatesingle(minn, maxn);
					if (num != 0 && int(element.second) % num == 0) {
						break;
					}
					if (way == 1) {
						fp << element1.first << " - " << element.first << " / " << num << " = " << endl;
					}
					else {
						cout << element1.first << " - " << element.first << " / " << num << " = " << endl;
					}
				}
				else if (typee == 2) {
					num1 = generateFraction(minn, maxn, numsize);
					if (way == 1) {
						fp << element1.first << " - " << element.first << " / " << num1[0]<<"/"<<num1[1] << " = " << endl;
					}
					else {
						cout << element1.first << " - " << element.first << " / " << num1[0] << "/" << num1[1] << " = " << endl;
					}
				}
			}
		}
	}
	if (way == 1) {
		cout << "�ɹ�������ļ��У�" << endl;
		fp.close();
	}

}
int main()
{
	srand(time(NULL));
	int a;
	while (true)
	{
		system("cls");
		cout << "                                  ***��ӭ����Сѧ���������Զ����ɳ���***��" << endl;
		cout << endl;
		cout << "��ѡ����Ҫ���еĲ�����" << endl;
		cout << "1��������������\n" << "2���˳�" << endl;
		cin >> a;
		system("cls");
		if (a == 1)
		{
			userselection();
			Generativequation(n, symbolnum, symbol, typee, 0, ssize, 2, way);
		}
		else if (a == 2)
		{
			break;
		}
		system("pause");
	}
	return 0;
}
