#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

int count = 0;
void startGame(void)
{
	// 初始化数据
	initData();

	// 绘制地图
	drawMap();
	// 输出 提示信息
	printf("请停留在此处操作！！！");
	// 循环控制
	do {
		direction = _getch();// 读取键盘输入
		switch (direction) {
		case 'w':
		case 'W':
			moveUp(); count++;
			break;
		case 'a':
		case 'A':
			moveLeft(); count++;
			break;
		case 's':
		case 'S':
			moveDown(); count++;
			break;
		case 'd':
		case 'D':
			moveRight(); count++;
			break;
		case 'r':
		case 'R':
			restart(); count = 0;
			break;
		case 'n':
		case 'N':
			nextLevel(); count = 0;
			break;
		case 'b':
		case 'B':
			prevLevel(); count = 0;
			break;
		default:
			; // 输入错误的按键执行空语句
		}
		drawMap(); 
		system("cls");
		printf("请停留在此处操作！！！\n");
		printf("目前使用了：%d步   还有%d个箱子\n",count,boxes);// 绘制地图
	} while (boxes);

	// 跳出循环说明游戏结束，进行下一关
	nextLevel();
	count = 0;
}