/*
��ѡ������ͨPID Kp,Ki,Kd��������ģ��PIDģ��ֵ��

*/


#include <stdio.h>

#define      YES               1
#define      NO                1
#define      back_ratio        0.618     
#define      head_ratio        0.382





int main()
{

	int Change = 0;
	float Range[2] = { 0.0f,0.0f };       //���εķ�Χ
	float Scale[2] = { 0.0f,0.0f };       //��������ֵ
	float Last_scale[2] = { 0.0f,0.0f };       //��һ�ε���������ֵ
	float Head_Result[4] = { 0.0f,0.0f,0.0f,0.0f };      //ȥ��ǰ�벿�ֺ��ֵ
	float Back_Result[4] = { 0.0f,0.0f,0.0f,0.0f };      //ȥ����벿�ֵ�ֵ
	float Long = 0.0f;
	float Scale_head = 0.0f;    //ȥ��ǰ�벿��
	float Scale_back = 0.0f;    //ȥ����벿��

	printf("������Է�Χ\n");
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
			printf("ȥ��ͷ�����ĸ�ֵΪ:%ff,%ff,%ff,%ff\n", Back_Result[0], Back_Result[1], Back_Result[2], Back_Result[3]);
			printf("ȥ��β�����ĸ�ֵΪ:%ff,%ff,%ff,%ff\n", Head_Result[0], Head_Result[1], Head_Result[2], Head_Result[3]);
		}
		else
		{
			printf("ȥ��ͷ�����ĸ�ֵΪ:%ff,%ff,%ff,%ff\n", Back_Result[3], Back_Result[2], Back_Result[1], Back_Result[0]);
			printf("ȥ��β�����ĸ�ֵΪ:%ff,%ff,%ff,%ff\n", Head_Result[3], Head_Result[2], Head_Result[1], Head_Result[0]);
		}

		while (1)
		{
			printf("ѡ����Ҫɾ���Ĳ���(0��ɾ��ͷ�ǲ��֣�1��ɾ��β����2��ɾ��ͷ����β������������������������Ч��)");
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
				printf("����������������룡\n");
			}
		}

	}





}



