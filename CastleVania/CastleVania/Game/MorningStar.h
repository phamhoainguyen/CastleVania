#ifndef __MORNING_STAR__
#define __MORNING_STAR__

#include "../FrameWork/Object.h"
class CMorningStar : public CSprite
{
private:
	int m_type;
	int m_characterFrameNumber;
	RECT* m_morningStarSrcRectArray;
public:

	void SetMorningStarType(int type);
	int GetMorningStarType();

	void SetCharacterFrameNumber(int characterFrameNumber);
	int GetCharacterFrameNumber();

	void Draw(int level, int numberFrame, D3DXVECTOR3 position, int direction);

	CMorningStar();
	bool Init(LPWSTR filePath);


	~CMorningStar();
};

#endif //__MORNING_STAR__
