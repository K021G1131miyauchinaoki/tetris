#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22

char field[FIELD_HEIGHT][FIELD_WIDTH];
char display[FIELD_HEIGHT][FIELD_WIDTH];

enum 
{
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX,

};

enum angle
{
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX,
};

#define MINO_WIDHT 4
#define MINO_HEIGHT 4

int minoType = MINO_TYPE_L, minoAngle = 0;
int minoX = 5, minoY = 0;

char minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDHT] = {
	//MINO_TYPE_I,
	{
		//MINO_ANGLE_0,
		{
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
			0,0,0,0,
		}
	},
	//MINO_TYPE_O,
	{
		//MINO_ANGLE_0,
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		}
	},
	//MINO_TYPE_S,
	{
		//MINO_ANGLE_0,
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,
		}
	},
	//MINO_TYPE_Z,
	{
		//MINO_ANGLE_0,
		{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
		}
	},
	//MINO_TYPE_J,
	{
		//MINO_ANGLE_0,
		{
			0,0,1,0,
			0,0,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,0,0,
			0,1,1,1,
			0,0,0,1,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,1,1,0,
			0,1,0,0,
			0,1,0,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,1,
			0,0,0,0,
		}
	},
	//MINO_TYPE_L,
	{
		//MINO_ANGLE_0,
		{
			0,1,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,0,0,
			0,0,0,1,
			0,1,1,1,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,1,1,0,
			0,0,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,0,0,0,
			0,1,1,1,
			0,1,0,0,
			0,0,0,0,
		}
	},
	//MINO_TYPE_T,
	{
		//MINO_ANGLE_0,
		{
			0,0,0,0,
			1,1,1,0,
			0,1,0,0,
			0,0,0,0,
		},
		//MINO_ANGLE_90,
		{
			0,0,1,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_180,
		{
			0,0,0,0,
			0,1,0,0,
			1,1,1,0,
			0,0,0,0,
		},
		//MINO_ANGLE_270,
		{
			0,1,0,0,
			0,1,1,0,
			0,1,0,0,
			0,0,0,0,
		}
	},
};

bool isHit(int minoX_,int minoY_,int minoType_,int minoAngle_){
	for (size_t i = 0; i < MINO_HEIGHT; i++)
		for (size_t j = 0; j < MINO_WIDHT; j++)
			if (minoShapes[minoType_][minoAngle_][i][j] 
				&& field[minoY_ + i][minoX_ + j])
				return true;
	
	return false;
}

void Draw() {
	//ミノとマップを合体して描画
	memcpy(display, field, sizeof(field));

	for (size_t i = 0; i < MINO_HEIGHT; i++) {
		for (size_t j = 0; j < MINO_WIDHT; j++) {
			display[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
		}
	}
	system("cls");
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			printf(display[i][j] ? " ■" : "　");
		}
		printf("\n");
	}
}

void resetMino() {
	minoX = 5;
	minoY = 0;
	minoType = rand() % MINO_TYPE_MAX;
	minoAngle = rand() % MINO_ANGLE_MAX;
}

void main() {
	memset(field, 0, sizeof(field));
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		//横の両端を1にする
		field[i][0] = field[i][FIELD_WIDTH-1]=1;
	}

	for (size_t i = 0; i < FIELD_WIDTH; i++)
	{
		//一番下を1にする
		field[FIELD_HEIGHT-1][i] = 1;
	}
	
	time_t t = time(NULL);
	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			//case'w':
			case's':
				if (!isHit(
					minoX,
					minoY + 1,
					minoType,
					minoAngle))
				{
					minoY++;
				}
				break;
			case'a':
				if (!isHit(
					minoX-1,
					minoY,
					minoType,
					minoAngle))
				{
					minoX--; 
				}
				break;

			case'd':
				if (!isHit(
					minoX + 1,
					minoY,
					minoType,
					minoAngle))
				{
					minoX++;
				}
				break;
			case 0x20:
				if (!isHit(
					minoX,
					minoY,
					minoType,
					(minoAngle + 1) % angle::MINO_ANGLE_MAX))
				{
					minoAngle = (minoAngle + 1) % angle::MINO_ANGLE_MAX;
				}

			}
			Draw();
		}

		if (t!= time(NULL))
		{
			t = time(NULL);
			if (isHit(
				minoX,
				minoY + 1,
				minoType,
				minoAngle))
			{
				for (size_t i = 0; i < MINO_HEIGHT; i++)
					for (size_t j = 0; j < MINO_WIDHT; j++)
						field[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
				for (size_t i = 0; i < FIELD_HEIGHT-1; i++){
					bool lineFill = true;
					for (size_t j = 1; j < FIELD_WIDTH-1; j++){
						if (!)
						{

						}
					}
				}
				resetMino();
			}
			else{
				minoY++;
			}
			Draw();
			printf("%d\n",minoAngle);
		}
	}
	_getch();

}