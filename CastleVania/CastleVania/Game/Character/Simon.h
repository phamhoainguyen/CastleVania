#ifndef			__SIMON_H__
#define			__SIMON_H__

#include "../../FrameWork/DynamicObject/Object.h"
#include "../../FrameWork/Input/Input.h"
#include "../../FrameWork/Video/Texture.h"
#include "../../FrameWork/Video/Animation.h"
#include "MorningStar.h"
class CSimon : public CObject
{
protected:

	
	bool m_isJump;
	bool m_isGo;
	bool m_isStrike;
	bool m_isStand;
	CMorningStar* m_morningStar;

	int m_simonStatus;
	int m_morningStarLevel;
public:

	CSimon();
	bool Init(LPWSTR filePath);
	void Move();
	void Go();
	void GoRight();
	void GoLeft();
	int GetSimonStatus();
	void ChangeAnimation();
	void SetSimonStatus(int status);
	void GoAnimation();
	void StandAnimation();
	void JumpAnimaion();
	void ChangeDirection();
	void SimonJump(); 
	void Strike();
	void ChangeStatus();
	

	//void GoBack();
	~CSimon();
};
#endif			//__SIMON_H__