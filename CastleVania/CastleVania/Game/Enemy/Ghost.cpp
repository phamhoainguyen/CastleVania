#include "Ghost.h"

CGhost::CGhost() : CObject()
{
	m_life = 0;
}
void CGhost::SetLife(bool life)
{
	m_life = life;
}
bool CGhost::GetLife()
{
	return m_life;
}
void CGhost::IsDead()
{

}
CGhost::~CGhost()
{
	CObject::~CObject();
}