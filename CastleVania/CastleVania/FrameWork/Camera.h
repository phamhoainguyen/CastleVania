#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <DirectXMath.h>
#include "Sprite.h"
#include "Singleton.h"


class CCamera : public Singleton<CCamera>
{
	friend Singleton<CCamera>;
private: 
	CCamera();
public:
	D3DXVECTOR2 m_viewport;		//Thiết lập tọa độ của camera	
	int m_maxSize, m_minSize;

	~CCamera();
	D3DXVECTOR3 CenterSprite(int x, int y);	//Tìm tọa độ center của sprite
	void UpdateCamera(float dt, D3DXVECTOR2 velocity);
	void UpdateCamera(int &w, int &h);
	void SetSizeMap(int _max, int _min);
	D3DXVECTOR2 Transform(int x, int y);	//Hàm transform, chuyển tọa độ viewport về tọa độ world
};

#endif /* __CAMERA_H__ */
