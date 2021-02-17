#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

string convert(string s, int numRows)
{
	if(1 == numRows) return s;
	string p = NULL;
	int len = strlen(s);
	p = (string)malloc(len);
	int group = 2*numRows-2;	// 组内元素个数
	int gnum = len/group;		// 组的个数
	int t = len%group;
	if(0 < t) gnum++;
	int i = 0;
	for(i = 0; i < gnum; i++)
		p[i] = s[i*group];
	t--;
	for(int hang = 2; hang < numRows; hang++)
	{
		for(int a = 0; a < gnum-1; a++)
		{
			p[i] = s[group*a+hang-1];
			p[i+1] = s[group*a+group-hang+1];
			i+=2;
		}	
		if(t>0 && t + hang < numRows + 2)
		{
				p[i] = s[group*gnum-group+hang-1];
				p[i+1] = s[group*gnum-hang+1];
				i+=2;
				t--;
			}
			else{
				p[i] = s[group*gnum-group+hang-1];
				t--;
			}
		
	}

	return p;
}

void test()
{
	string s = "LEETCODEISHIRING";
	printf("in :>_ LEETCODEISHIRING\n");
	printf("out:>_ %s\n", convert(s, 3));
}

int main()
{
	test();
	return 0; 
}

	
