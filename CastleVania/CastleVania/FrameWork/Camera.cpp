#include "Camera.h"
#include "Global.h"
#include "Camera.h"

CCamera::CCamera()
{
	m_viewport.x = 1;
	m_viewport.y = (float)e_screenHeight;
}

CCamera::~CCamera()
{

}

void CCamera::SetSizeMap(int _max, int _min)
{
	m_maxSize = _max;
	m_minSize = _min;
}
D3DXVECTOR2 CCamera::Transform(int x, int y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -m_viewport.x;
	matrix._42 = m_viewport.y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}

D3DXVECTOR3 CCamera::CenterSprite(int x, int y)
{
	D3DXVECTOR3 pCenter = D3DXVECTOR3(x / 2, y / 2, 0);
	return pCenter;
}

void CCamera::UpdateCamera(float dt, D3DXVECTOR2 velocity)
{
	
	m_viewport.x += dt * velocity.x;
	//Tự viết dự vào hướng dẫn của GV LT
}

void CCamera::UpdateCamera(int &w, int &h)
{
	//Tự viết dự vào hướng dẫn của GV LT
}






