#include "Simon.h"
#include "../../FrameWork/Video/Camera.h"
#include "../../FrameWork/Time/Timer.h"
#include "../../FrameWork/GlobalVariable/Define.h"
#include "../../FrameWork/Input/Input.h"
CSimon::CSimon() : CObject()
{
	m_simonStatus = 0;
	m_direction = 2;
	m_morningStar = NULL;

	m_isGo = false;
	m_isJump = false;
	m_isStrike = false;
	m_isStand = false;
}
bool CSimon::Init(LPWSTR filePath) 
{ 
	m_numberAnimation = 10;

	if (!CObject::Init(filePath))
		return false;


	m_morningStar = new CMorningStar();
	
	if (!m_morningStar->Init(L"Resources/morningstar.png"))
		return false;
	m_morningStarLevel = MORNING_STAR_LEVEL_1;
	/****************************************************************/
	
	//////////////////////////////////INIT members of class CSimon///////////////////////////
	m_isStand = true;

	/************************************************************************************/

	//////////Sprite Info///////////////
	//m_sprite = new CSprite(&texture);
	this->m_direction = DIRECTION_RIGHT;
	this->SetFrameHeight(66);
	this->SetFrameWidth(60);
	this->SetFramePerRow(8);
	this->SetFramePerCol(3);
	this->SetTotalFrame(24);

	/***********************************/

	///////////////////////Animation Info///////////////////////////


	m_animation[0] = CAnimation(0, 0);
	m_animation[1] = CAnimation(0, 3);
	m_animation[2] = CAnimation(5, 7);
	m_animation[3] = CAnimation(15, 17);
	m_animation[4] = CAnimation(18, 20);
	m_animation[5] = CAnimation(21, 23);
	for (int i = 0; i < 10; i++)
	{
		m_animation[i].SetVelocity(8);
		m_animation[i].SetSrcRect(this);
	}
	
	/**************************************************************/

	m_srcRect = &(m_animation[0].GetSrcRect());

	return true;
}


int CSimon::GetSimonStatus()
{ 
	return m_simonStatus;
}


void CSimon::SetSimonStatus(int status)
{ 
	m_simonStatus = status;
}


void CSimon::Strike()
{
	
	D3DXVECTOR3 position = this->GetPosition();
	m_morningStar->Draw(2, this->GetAnimation(m_currentAnimation).GetCurrentFrame(), position, m_direction);
}


void CSimon::ChangeAnimation()
{ 
	if (CInput::GetInstance()->IsKeyDown(DIK_SPACE))
	{
		if (m_simonStatus == 1)
		{
			m_animation->SetFrameStart(5);
			m_animation->SetFrameEnd(7);
		}
		else if (m_simonStatus == 2)
		{
			m_animation->SetFrameStart(15);
			m_animation->SetFrameEnd(17);
		}

		else if (m_simonStatus == 3)
		{
			m_animation->SetFrameStart(18);
			m_animation->SetFrameEnd(20);
		}

		else if (m_simonStatus == 4)
		{
			m_animation->SetFrameStart(21);
			m_animation->SetFrameEnd(23);
		}
	}
	this->GetAnimation(m_currentAnimation).RunAnimation(this);

}


void CSimon::Move()
{
	if (m_isStand)
		this->StandAnimation();
	//this->ChangeStatus();

	//this->Go();
}


void CSimon::SimonJump()
{

	if (INPUT->GetKeyDown() == DIK_UP)
	{
		this->m_acceleration = -900;
		this->m_velocity.y = 380;
	}

	this->m_currentAnimation = 2;

	CObject::Jump();
}

void CSimon::GoRight()
{
	this->ChangeDirection();

	if (this->m_position.x < 350)	// canh giữa cửa sổ game
		this->m_velocity.x = 100;   // vận tốc của simon

	//Update Camera
	else if (this->m_position.x > 350)
	{
		this->m_velocity.x = 0;
		CCamera::GetInstance()->UpdateCamera(m_deltaTime, D3DXVECTOR2{ 100, 0 });		// vận tốc để cho map di chuyển

	}
	this->m_currentAnimation = 1;
	CObject::Go();
}


void CSimon::GoLeft()
{
	this->ChangeDirection();

	if (this->m_position.x < 350)	// canh giữa cửa sổ game
		this->m_velocity.x = -100;   // vận tốc của simon

	//Update Camera
	else if (this->m_position.x > 350)
	{
		this->m_velocity.x = 0;
		CCamera::GetInstance()->UpdateCamera(m_deltaTime, D3DXVECTOR2{ -100, 0 });		// vận tốc để cho map di chuyển


	}
	this->m_currentAnimation = 1;
	CObject::Go();
}
////////////////////////////////////////////Go FUCNTION///////////////////////////////////////////////////////////////////
void CSimon::Go()
{
	///////////////// GO RIGHT///////////////////
	//if (m_simonStatus == simonStatus::GO)
	//{
	//	if (CInput::GetInstance()->IsKeyDown(DIK_RIGHT))
	//	{
	//		this->GoRight();
	//	}
	//	else if (CInput::GetInstance()->IsKeyDown(DIK_LEFT))
	//	{
	//		this->GoLeft();
	//	}

	//}
	//

	//else if (m_simonStatus == simonStatus::JUMP)
	//{
	//	this->SimonJump();
	//}
	///**************************************/

	///////////////GO LEFT///////////////////
	//
	/////////////////// Stand/////////////////
	//else
	//{
	//	this->StandAnimation();
	//}
	//	
}
/********************************************END Go FUCNTION******************************************/


///////////////////////////////////GoAnimation FUCNTION///////////////////////////////////////////////

void CSimon::GoAnimation()
{

}

/**********************************END GoAnimation FUCNTION***************************************/


///////////////////////////////////StandAnimation FUCNTION//////////////////////////////////
void CSimon::StandAnimation()
{
	this->m_animation[0].SetDirection(this->m_direction);
	m_velocity.x = 0;
	this->m_animation[0].RunAnimationForever(this);
}

/******************************END StandAnimation FUCNTION************************************/


void CSimon::JumpAnimaion()
{

}

void CSimon::ChangeDirection()
{
	if (CInput::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		// thay doi huong di chuyen
		if (m_direction == DIRECTION_RIGHT)
			m_direction = DIRECTION_LEFT;
	}

	else if(CInput::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		// thay doi huong di chuyen
		if (m_direction == DIRECTION_LEFT)
			m_direction = DIRECTION_RIGHT;
	}
}


void CSimon::ChangeStatus()
{
	if (INPUT->IsKeyDown(DIK_RIGHT) || INPUT->IsKeyDown(DIK_LEFT))
		m_simonStatus = simonStatus::GO;

	else if(INPUT->GetKeyDown() == DIK_UP)
		m_simonStatus = simonStatus::JUMP;

	else if (INPUT->GetKeyDown() == DIK_A)
	{
		
	}
	else
		m_simonStatus = simonStatus::STAND;
}

CSimon::~CSimon(){
}