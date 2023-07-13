#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"
void drawMap(void)
{
	// 开始批量绘图
	BeginBatchDraw();

	// 输出背景图片
	putimage(0, 0, &BkImg);

	// 输出地图（左侧的主游戏界面）
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			putimage(BLOCK * (j + 2), BLOCK * (i + 2), mapPicLoad(map[i][j]));
		}
	}

	// 输出说明信息
	putimage(1179, 0, &Explain);

	// 输出批量绘图内容
	FlushBatchDraw();

	// 结束批量绘图
	EndBatchDraw();
}

IMAGE* mapPicLoad(int id)
{
	switch (id) {
	case BLANK:
		return &Blank;
		break;
	case WALL:
		return &Wall;
		break;
	case HUMAN:
		return &Human;
		break;
	case BOX:
		return &Box;
		break;
	case DEST:
		return &Dest;
		break;
	case DONE:
		return &Box_D;
		break;
	default:
		return NULL;
	}
}