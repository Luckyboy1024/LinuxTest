
#include "test.h"
#include <stdlib.h>
#include <math.h>

int menu()
{
	int input = 0;
	printf("\n#############################");
	printf("\n  1.input\t  0.exit\t");
	printf("\n#############################");
	printf("\n$ Enter your choose :>_ ");
	scanf("%d", &input);
	return input;
}

double Cal_BMI(Per* per)
{
	double bmi = 0.0;
	bmi =  per->Weight / ((per->Height) * (per->Height));
	return bmi;
}

double Cal_BFR(Per* per, double _bmi)
{
	double bfr = 0.0;
	bfr = 1.2 * _bmi + 0.23 * per->age - 5.4 - 10.8 * per->sex;
	return bfr;
}

void Init(Per* p, double hei, double wei,  int age, int sex)
{
	p->Height = hei;
	p->Weight = wei;
	p->age = age;
	p->sex = sex;
}

void Input(Per* p)
{
	do {
		printf("height (公分) :>_ "); scanf("%lf", &p->Height); p->Height /= 100;
		printf("weight (公斤) :>_ "); scanf("%lf", &p->Weight);
		printf("age    (周岁) :>_ "); scanf("%d", &p->age);
		printf("sex(男=1,女=0):>_ "); scanf("%d", &p->sex);
		printf("\n 确认输入 :> ");
		printf("\n\t| 身高\t| 体重\t| 年龄\t| 性别\t|");
		printf("\n\t| %.2lf\t| %.1lf\t|   %d\t| ", p->Height, p->Weight, p->age);
		if (1 == p->sex) printf("male\t|");
		else if (0 == p->sex) printf("female\t|");
		printf("\n >>>>>>>>>>>>> 回车继续; 键入<r> 重新输入 <<<<<<<<<<<<<< \n");
		while(!getchar());
	} while('r' == getchar());
}

double Wei_BFR(Per* p, double _bfr) //通过指定体脂率，逆推出对应体重
{
	double _wei = 0.0;
	_wei = (_bfr + 10.8 * p->sex + 5.4 - 0.23 * p->age) / 1.2 * (p->Height * p->Height);
	return _wei;
}

void Output(Per* p, double bfr)
{
	printf("\n$ 体脂率：%.2lf", bfr);
	printf("\n根据已输入数据(身高、年龄、性别)，系统可判断 >>\n不同等级的体脂率所对应体重如下 >> ");
	printf("\n###########################################");
	printf("\n# 分级\t # \t对应体重区间");
	double* norm = NULL;
	char* n[] = { "偏瘦", "标准", "超重", "肥胖" };
	if (0 == p->sex)
	{
		norm = F_norm;
	}
	else if (1 == p->sex)
	{
		norm = M_norm;
	}
	double tmp = Wei_BFR(p, norm[0]);
	int i = 1;
	for(; i < num_norm; i++)
	{
		double wei = Wei_BFR(p, norm[i]);
		printf("\n# %s\t#\t%3.2lf ~ %3.2lf", n[i-1], tmp, wei);
		tmp = wei;
	}
	printf("\n###########################################\n");
}

void test()
{
	while(menu()){
		Per* per = NULL;
		double _bfr = 0.0;
		double _bmi = 0.0;
		per = (Per*)malloc(sizeof(Per));
		Init(per, 1.80, 70, 20, MALE);
		Input(per);
		_bmi = Cal_BMI(per);
		_bfr = Cal_BFR(per, _bmi);
		Output(per, _bfr);
		// printf("%.2lf  %.2lf\n", _bmi, _bfr);
	}	
}

