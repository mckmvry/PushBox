#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

int count = 0;
void startGame(void)
{
	// ��ʼ������
	initData();

	// ���Ƶ�ͼ
	drawMap();
	// ��� ��ʾ��Ϣ
	printf("��ͣ���ڴ˴�����������");
	// ѭ������
	do {
		direction = _getch();// ��ȡ��������
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
			; // �������İ���ִ�п����
		}
		drawMap(); 
		system("cls");
		printf("��ͣ���ڴ˴�����������\n");
		printf("Ŀǰʹ���ˣ�%d��   ����%d������\n",count,boxes);// ���Ƶ�ͼ
	} while (boxes);

	// ����ѭ��˵����Ϸ������������һ��
	nextLevel();
	count = 0;
}