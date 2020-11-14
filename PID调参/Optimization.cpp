/*
优选法调普通PID Kp,Ki,Kd参数，调模糊PID模糊值域

*/


#include <stdio.h>

#define      YES               1
#define      NO                1
#define      back_ratio        0.618     
#define      head_ratio        0.382





int main()
{

	int Change = 0;
	float Range[2] = { 0.0f,0.0f };       //调参的范围
	float Scale[2] = { 0.0f,0.0f };       //两个比例值
	float Last_scale[2] = { 0.0f,0.0f };       //上一次的两个比例值
	float Head_Result[4] = { 0.0f,0.0f,0.0f,0.0f };      //去掉前半部分后的值
	float Back_Result[4] = { 0.0f,0.0f,0.0f,0.0f };      //去掉后半部分的值
	float Long = 0.0f;
	float Scale_head = 0.0f;    //去掉前半部分
	float Scale_back = 0.0f;    //去掉后半部分

	printf("输入调试范围\n");
	printf("range[0] = ");
	scanf_s("%f", &Range[0]);
	printf("range[1] = ");
	scanf_s("%f", &Range[1]);
	printf("\n");
	while (1)
	{
		Long = Range[1] - Range[0];
		Scale[0] = Range[0] + Long * head_ratio;
		Scale[1] = Range[0] + Long * back_ratio;
		printf("Scale[0] = %ff,Scale[1] = %ff\n", Scale[0], Scale[1]);

		Last_scale[0] = Scale[0];
		Last_scale[1] = Scale[1];
		Scale_head = (Range[1] - Scale[0]) / 3;
		Scale_back = (Scale[1] - Range[0]) / 3;
		Head_Result[0] = Range[0];
		Back_Result[0] = Scale[0];
		for (int i = 1; i < 4; i++)
		{
			Head_Result[i] = Head_Result[i - 1] + Scale_head;
			Back_Result[i] = Back_Result[i - 1] + Scale_back;
		}
		if (Range[0] > 0)
		{
			printf("去掉头部的四个值为:%ff,%ff,%ff,%ff\n", Back_Result[0], Back_Result[1], Back_Result[2], Back_Result[3]);
			printf("去掉尾部的四个值为:%ff,%ff,%ff,%ff\n", Head_Result[0], Head_Result[1], Head_Result[2], Head_Result[3]);
		}
		else
		{
			printf("去掉头部的四个值为:%ff,%ff,%ff,%ff\n", Back_Result[3], Back_Result[2], Back_Result[1], Back_Result[0]);
			printf("去掉尾部的四个值为:%ff,%ff,%ff,%ff\n", Head_Result[3], Head_Result[2], Head_Result[1], Head_Result[0]);
		}

		while (1)
		{
			printf("选择需要删除的部分(0：删除头那部分，1：删除尾部，2：删除头部和尾部，其他的输入其他数字无效！)");
			scanf_s("%d", &Change);
			if(Change == 0)
			{
			    Range[1] = Scale[1];
				break;
			}
			if (Change == 1)
			{
				Range[0] = Scale[0];
				break;
			}
			if (Change == 2)
			{
				Range[1] = Scale[1];
				Range[0] = Scale[0];
				break;
			}
			else
			{
				printf("输入错误，请重新输入！\n");
			}
		}

	}





}



