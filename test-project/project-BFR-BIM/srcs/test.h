
#ifndef __TEST_H__
#define __TEST_H__
#include <stdio.h>
typedef double uint32_t;
#define MALE 1		// male 男
#define FEMALE 0	// female 女

typedef struct {
	uint32_t Height;	// 身高：厘米
	uint32_t Weight;	// 体重：公斤
	int age;		// 年龄：周岁
	int sex;	// F--female  M--male 
} Per;

#define num_norm  5	// 分级数目
double M_norm[num_norm] = { 4, 10, 21, 26, 45 };	// 男性体脂率分级标准：偏瘦、标准、超重、肥胖
double F_norm[num_norm] = { 4, 20, 34, 39, 45 };	// 女性体脂率分级标准：偏瘦、标准、超重、肥胖

#endif // __TEST_H__

void test();	// 入口
int menu();

double Cal_BMI(Per* per);			// 计算 BMI 指数
double Cal_BFR(Per* per, double _bmi);	// 计算体脂率

void Init(Per* p, double hei, double wei, int age, int sex);
void Input(Per* p);

// 输出在当前身高性别年龄的情况，各等级体脂率对应的体重区间
