/* 项目名称：体脂率计算器
 * 项目负责人：keybug
 * 项目简介：这是一个小demo 用来计算一个人的体脂率(BFR)
 * 输入：身高、体重、性别
 * 输出：对应数据的体脂率 (0~100%) 
 * */

// |      | 男  性 | 女  性 | 
// | 偏瘦 |  5~10% |  5~20% |
// | 标准 | 11~21% | 21~34% |
// | 超重 | 22~26% | 35~39% | 
// | 肥胖 | 27~45% | 40~45% |

#include <stdio.h>

// double calculate();	// 计算
// double cal_BMI();	// BMI = 体重/身高的平方
// double cal_BFR();	// BFR = 1.2 * BMI + 0.23 * 年龄 - 5.4 - 10.8 * 性别(男为1，女为0)
// int menu();

double cal_BFR(double _bmi, int age, int sex)
{
	double _bfr = 0.0;
	return _bfr = 1.2 * _bmi + 0.23 * age - 5.4 - 10.8 * sex;
}
double cal_BMI(double _bmi, int* _age)
{
	double height = 0.0;
	double weight = 0.0;
	do{
		printf("\n\n############################");
		printf("\n $ 输入身高 (厘米) :>_ "); scanf("%lf", &height);
		printf("\n $ 输入体重 (斤) :>_ "); scanf("%lf", &weight);
		printf("\n $ 输入年龄 (岁) :>_ "); scanf("%d", _age);
		printf("\n#############################");
		printf("确认输入： 身高：%.2f  体重：%.2f  年龄：%d  (输入 <r> 重新输入，否则继续)\n", height, weight, *_age);
	}while('r' == getchar());
	height /= 100.0;
	weight /= 2.0;
	return _bmi = weight / (height * height);
}

int menu()
{
	int input = 0;
	printf("\n");
	printf("#################################\n");
	printf("    1. 男性体脂率\n");
	printf("    2. 女性体脂率\n");
	printf("    0. 退出计算器\n");
	printf("#################################\n\n");
	printf(" $ 请输入 :>_ ");
	scanf("%d", &input);
	return input;
}

int main()
{
	double bmi = 0.0;
	double bfr = 0.0;
	int age = 0;
	int i = 0;
	while(i = menu())
	{
		bmi = cal_BMI(bmi, &age);
		if (i == 1)
		{
			bfr = cal_BFR(bmi, age, 1);
			break;
		}
		else if (i == 2)
		{
			bfr = cal_BFR(bmi, age, 0);
			break;
		}
		else{
			printf("error : input error....\n");
		}
	}
	printf("\n\n >>>>> 体脂率 (BFR) :>_ %.2f%% %d %lf", bfr, age, bmi);
	return 0;
}

