#include "Simon.h"
#include "../FrameWork/Camera.h"
#include "../FrameWork/Timer.h"
#include "../FrameWork/Define.h"
#include "../FrameWork/Input.h"
CSimon::CSimon() : CDynamicObject()
{
	m_simonStatus = 0;
	m_direction = 2;
	m_morningStar = NULL;

	m_isGo = false;
	m_isJump = false;
	m_isStrike = false;
	m_isStand = false;
	m_isStriking = false;
}
bool CSimon::Init(LPWSTR filePath)
{
	m_numberAnimation = 10;

	if (!CDynamicObject::Init(filePath))
		return false;

	m_morningStar = new CMorningStar();

	if (!m_morningStar->Init(L"Resources/morningstar.png"))
		return false;
	m_morningStarLevel = MORNING_STAR_LEVEL_1;
	/****************************************************************/

	//////////////////////////////////INIT members of class CSimon///////////////////////////
	m_isStand = true;
	m_isGo = false;
	m_isStrike = false;
	m_isStriking = false;
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
		m_animation[2].SetDirection(m_direction);
		m_isStriking = m_animation[2].RunAnimation(this);
		//this->m_currentAnimation = 2;
		m_morningStar->Draw(0, this->m_animation[2].GetCurrentFrame(), position, m_direction);
}

void CSimon::ChangeAnimation()
{

}

bool temp;
void CSimon::Move()
{

	this->ChangeStatus();
	///////////////////////////////////////////////////////
	if (m_isStriking == true)
	{
		m_animation[2].ResetAnimation();
		m_isStriking = false;
		m_isStrike = false;
		m_isStand = true;
	}
	////////////////////////////////////////////////////////
	if (m_isStand)
	{
		this->StandAnimation();
	}

	else if (m_isGo && !m_isStrike)
	{
		this->Go();
	}
	//////////////////////////////////////////
	else if (m_isStrike)
	{
		this->Strike();
	}
	//////////////////////////////////////////
}


void CSimon::SimonJump()
{

	if (INPUT->GetKeyDown() == DIK_UP)
	{
		this->m_acceleration = -900;
		this->m_velocity.y = 380;
	}

	this->m_currentAnimation = 2;

	CDynamicObject::Jump();
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
	CDynamicObject::Go();
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
	CDynamicObject::Go();
}
////////////////////////////////////////////Go FUCNTION///////////////////////////////////////////////////////////////////
void CSimon::Go()
{
	///////////////// GO RIGHT///////////////////
	if (CInput::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		this->GoRight();
	}
	else if (CInput::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		this->GoLeft();
	}


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
	//m_currentAnimation = 0;
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

	else if (CInput::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		// thay doi huong di chuyen
		if (m_direction == DIRECTION_LEFT)
			m_direction = DIRECTION_RIGHT;
	}
}


void CSimon::ChangeStatus()
{

		if ((INPUT->IsKeyDown(DIK_RIGHT) || INPUT->IsKeyDown(DIK_LEFT)) && m_isStrike == false)
		{
			m_isGo = true;
			m_isStand = false;
			return;
		}

		else if (INPUT->GetKeyDown() == DIK_X && m_isStrike == false)
		{
			m_isGo = false;
			m_isStand = false;
			m_isStrike = true;
			return;
		}
		
		else
		{
			if (m_isStrike == false)
			{
				m_isGo = false;
				m_isStand = true;
				return;
			}
		}
}

CSimon::~CSimon(){
	if (m_morningStar)
		delete m_morningStar;
}