//������
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

//���Ƶ�ͼ
int map[9][11] = 
{ 
	{0,1,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,0,4,0,0,1,0},
	{0,1,1,0,0,0,3,0,0,1,1},
	{0,1,1,0,0,2,0,0,0,0,1},
	{1,1,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1},
	{1,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0}
};
//���� 0 �����ſհ׵ĵط���
  //1 ������ǽ��
  //2 �������ˣ�
  //3 ���������ӣ�
  //4 ���������ӵ��յ�λ�á�


//�����ͼ�������ֶ�Ӧ��ͼ��
void printMap()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)//����FORѭ�����ͼ����ֵһһ��Ӧ
		{
			switch (map[i][j])
			{
			case 0://0���������
				printf("  "); //�հ׵ĵط�
				break;
			case 1://1���������
				printf("��"); //ǽ 
				break;
			case 2://2���������
				printf("��"); //�� 
				break;
			case 3://3���������
				printf("��"); //���� 
				break;
			case 4://4���������
				printf("��"); //�յ�ط� 
				break;
			case 6://6���������
				printf("");//�˼��յ�λ�� 
				break;
			case 7://7���������
				printf("��");//���Ӽ��յ�λ��
				break;
			}
		}
		printf("\n");//����
	}
}


//������
void pushBox()
{
	int count, caw = 0;//�к��� 
	int i, j, tui;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 11; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)//�����û�к�ǽ���������غ�
			{
				//�����˵�λ��
				count = i;//������Ϊi
				caw = j;//������Ϊj
			}
		}
	}
	//���尴����Ӧ�������ӵĶ���
	char key_down = _getch();


	//������
	switch (key_down)
	{
	case'w':
	case'W':
		if (map[count - 1][caw] == 0 || map[count - 1][caw] == 4)//��������ǿհ׻����յ�
		{
			map[count - 1][caw] += 2;//������Ǹ�����
			map[count][caw] -= 2;//�˶�ǰ���Ǹ��ɿհ�
		}
		else if (map[count - 1][caw] == 3 || map[count - 1][caw] == 7)//�����һ�������ӻ������Ӽ��յ�λ��
		{
			if (map[count - 2][caw] == 0 || map[count - 2][caw] == 4)//�������������Ǹ��ǿհ׻����յ�

			{

				map[count][caw] -= 2;//��������ɿհ�
				map[count - 1][caw] -= 1;//�����Ǹ�����
				map[count - 2][caw] += 3;//����������Ǹ�������
			}
		}
		//�����ǽ���ܶ�
	default:
		break;
}

	//������
	switch (key_down)
	{
	case's':
	case'S':
		if (map[count + 1][caw] == 0 || map[count + 1][caw] == 4)//��������Ǹ��ǿհ׻����յ�
		{
			map[count + 1][caw] += 2;//�����Ǹ�����
			map[count][caw] -= 2;//��������ɿհ�
		}
		else if (map[count + 1][caw] == 3 || map[count + 1][caw] == 7)//��������Ǹ�������
		{
			if (map[count + 2][caw] == 0 || map[count + 2][caw] == 4)//�������������Ǹ��ǿհ�

			{

				map[count][caw] -= 2;//��������ɿհ�
				map[count + 1][caw] -= 1;//�����Ǹ�����
				map[count + 2][caw] += 3;//�����Ǹ�������
			}
		}
		//���ǰ����ǽ���ܶ�
	default:
		break;
	}

	//�������
	switch (key_down)
	{
	case'a':
	case'A':
		if (map[count][caw - 1] == 0 || map[count][caw - 1] == 4)//�������ǿո�
		{
			map[count][caw - 1] += 2;//����Ǹ�����
			map[count][caw] -= 2;//��������ɿհ�
		}
		//�������
		else if (map[count][caw - 1] == 3 || map[count][caw - 1] == 7)//������������
		{
			if (map[count][caw - 2] == 0 || map[count][caw - 2] == 4)//�����ߵ�����ǿհ׻����յ�
			{
				map[count][caw] -= 2;//��������ɿհ�
				map[count][caw - 1] -= 1;//����Ǹ�����
				map[count][caw - 2] += 3;//��ߵ���߱������
			}
		}
		//�����ǽ���ܶ�
	default:
		break;
	}
	//������
	switch(key_down)
	{
	case'd':
	case'D':
		if (map[count][caw + 1] == 0 || map[count][caw + 1] == 4)//����ұ��ǿո�
		{
			map[count][caw + 1] += 2;//�ұ߱����
			map[count][caw] -= 2;//��������ɿհ�
		}
		else if (map[count][caw + 1] == 3 || map[count][caw + 1] == 7)//����ұ��Ǹ�������
		{
			if (map[count][caw + 2] == 0 || map[count][caw + 2] == 4)//����ұߵ��ұ��ǿո�
			{
				map[count][caw] -= 2;//��������ɿհ�
				map[count][caw + 1] -= 1;//�ұ��Ǹ�����
				map[count][caw + 2] += 3;//�ұߵ��ұ߱������
			}
		}
		//�����ǽ�򲻶�
	default:
				break;


	}
}//������


bool gameover()//��Ϸ�����ж�����
{
	int k = 0;//��ʼ��
	int j, i;
	for (i = 0; i < 9; i++)//i��0��9ѭ��
	{
		for (j = 0; j < 11; j++)//j��0��9ѭ��
		{
			if (map[i][j] == 3)//���ҵ�ͼ�ϵĿհ׵��յ�
				k++;//����
		}
	}
	
	//�����ͼ��û�пհ׵��յ�
	if (k == 0)
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");//��Ϸ����
		return true;
	}
}

//��Ϸ����
int main()
{
	while (1)
	{
		printMap();//��ӡ��ͼ

		pushBox();//������
		system("cls");

	}
}
  