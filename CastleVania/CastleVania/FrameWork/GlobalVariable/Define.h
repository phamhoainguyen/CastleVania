#ifndef				__DEFINE_H__
#define				__DEFINE_H__
#include <d3d9.h>
#include <d3dx9.h>
#include "../Input/Input.h"

#define GAME_SCREEN_RESOLUTION_640_480_24   0
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_768_24  2

#define GAME_SCREEN_RESOLUTION_640_480_32   10
#define GAME_SCREEN_RESOLUTION_800_600_32   11
#define GAME_SCREEN_RESOLUTION_1024_768_32  12

#define	FULL_SCREEN							true
#define NO_FULL_SCREEN						false

#define BACKBUFFER_FORMAT_D3DFMT_X8R8G8B8	D3DFMT_X8R8G8B8					

#define WINDOW_NAME							L"Castle Vania"

#define KEYBOARD_BUFFER_SIZE				1024

#define NUMBER_SIMON_STATE_3				3
#define SIMON_NUMBER_FRAME_STATE1_3			3

#define SCREEN_WIDTH_800					800
#define SCREEN_HEIGHT_600					600

#define CENTER_1							1

#define FRAME_PER_SECOND					60

#define DIRECTION_LEFT						1
#define DIRECTION_RIGHT						2

#define MORNING_STAR_LEVEL_1				0
#define MORNING_STAR_LEVEL_2				1
#define MORNING_STAR_LEVEL_3				2
enum morningStar
{
	LEVEL_1_FRAME_1	= 0,
	LEVEL_1_FRAME_2,
	LEVEL_1_FRAME_3,

	LEVEL_2_FRAME_1,
	LEVEL_2_FRAME_2,
	LEVEL_2_FRAME_3,

	LEVEL_3_FRAME_1,
	LEVEL_3_FRAME_2,
	LEVEL_3_FRAME_3
};

#define INPUT CInput::GetInstance()


enum simonStatus
{
	STAND = 0,
	GO,
	JUMP,
	DEAD
};


#endif		// __DEFINE_H__