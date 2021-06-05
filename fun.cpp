//推箱子
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

//绘制地图
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
//其中 0 代表着空白的地方；
  //1 代表着墙；
  //2 代表着人；
  //3 代表着箱子；
  //4 代表着箱子的终点位置。


//定义地图中与数字对应的图像
void printMap()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)//两个FOR循环与地图的数值一一对应
		{
			switch (map[i][j])
			{
			case 0://0所代表的是
				printf("  "); //空白的地方
				break;
			case 1://1所代表的是
				printf("■"); //墙 
				break;
			case 2://2所代表的是
				printf("人"); //人 
				break;
			case 3://3所代表的是
				printf("☆"); //箱子 
				break;
			case 4://4所代表的是
				printf("◎"); //终点地方 
				break;
			case 6://6所代表的是
				printf("");//人加终点位置 
				break;
			case 7://7所代表的是
				printf("★");//箱子加终点位置
				break;
			}
		}
		printf("\n");//换行
	}
}


//推箱子
void pushBox()
{
	int count, caw = 0;//行和列 
	int i, j, tui;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 11; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)//如果人没有和墙或者箱子重合
			{
				//定义人的位置
				count = i;//行坐标为i
				caw = j;//列坐标为j
			}
		}
	}
	//定义按键对应的推箱子的动作
	char key_down = _getch();


	//向上走
	switch (key_down)
	{
	case'w':
	case'W':
		if (map[count - 1][caw] == 0 || map[count - 1][caw] == 4)//如果向上是空白或者终点
		{
			map[count - 1][caw] += 2;//上面的那格变成人
			map[count][caw] -= 2;//运动前的那格变成空白
		}
		else if (map[count - 1][caw] == 3 || map[count - 1][caw] == 7)//如果下一格是箱子或者箱子加终点位置
		{
			if (map[count - 2][caw] == 0 || map[count - 2][caw] == 4)//如果上面的上面那格是空白或者终点

			{

				map[count][caw] -= 2;//现在这格变成空白
				map[count - 1][caw] -= 1;//上面那格变成人
				map[count - 2][caw] += 3;//上面的上面那格变成箱子
			}
		}
		//如果是墙则不能动
	default:
		break;
}

	//向下走
	switch (key_down)
	{
	case's':
	case'S':
		if (map[count + 1][caw] == 0 || map[count + 1][caw] == 4)//如果下面那格是空白或者终点
		{
			map[count + 1][caw] += 2;//下面那格变成人
			map[count][caw] -= 2;//现在这格变成空白
		}
		else if (map[count + 1][caw] == 3 || map[count + 1][caw] == 7)//如果下面那格是箱子
		{
			if (map[count + 2][caw] == 0 || map[count + 2][caw] == 4)//如果下面的下面那格是空白

			{

				map[count][caw] -= 2;//现在这格变成空白
				map[count + 1][caw] -= 1;//下面那格变成人
				map[count + 2][caw] += 3;//下面那格变成箱子
			}
		}
		//如果前面是墙则不能动
	default:
		break;
	}

	//向左边走
	switch (key_down)
	{
	case'a':
	case'A':
		if (map[count][caw - 1] == 0 || map[count][caw - 1] == 4)//如果左边是空格
		{
			map[count][caw - 1] += 2;//左边那格变成人
			map[count][caw] -= 2;//现在这格变成空白
		}
		//其他情况
		else if (map[count][caw - 1] == 3 || map[count][caw - 1] == 7)//如果左边有箱子
		{
			if (map[count][caw - 2] == 0 || map[count][caw - 2] == 4)//如果左边的左边是空白或者终点
			{
				map[count][caw] -= 2;//现在这格变成空白
				map[count][caw - 1] -= 1;//左边那格变成人
				map[count][caw - 2] += 3;//左边的左边变成箱子
			}
		}
		//如果是墙则不能动
	default:
		break;
	}
	//向右走
	switch(key_down)
	{
	case'd':
	case'D':
		if (map[count][caw + 1] == 0 || map[count][caw + 1] == 4)//如果右边是空格
		{
			map[count][caw + 1] += 2;//右边变成人
			map[count][caw] -= 2;//现在这格变成空白
		}
		else if (map[count][caw + 1] == 3 || map[count][caw + 1] == 7)//如果右边那格有箱子
		{
			if (map[count][caw + 2] == 0 || map[count][caw + 2] == 4)//如果右边的右边是空格
			{
				map[count][caw] -= 2;//现在这格变成空白
				map[count][caw + 1] -= 1;//右边那格变成人
				map[count][caw + 2] += 3;//右边的右边变成箱子
			}
		}
		//如果是墙则不动
	default:
				break;


	}
}//推箱子


bool gameover()//游戏结束判断条件
{
	int k = 0;//初始化
	int j, i;
	for (i = 0; i < 9; i++)//i从0到9循环
	{
		for (j = 0; j < 11; j++)//j从0到9循环
		{
			if (map[i][j] == 3)//查找地图上的空白的终点
				k++;//计数
		}
	}
	
	//如果地图上没有空白的终点
	if (k == 0)
	{
		printf("恭喜你，你赢了！\n");//游戏结束
		return true;
	}
}

//游戏结束
int main()
{
	while (1)
	{
		printMap();//打印地图

		pushBox();//推箱子
		system("cls");

	}
}
  