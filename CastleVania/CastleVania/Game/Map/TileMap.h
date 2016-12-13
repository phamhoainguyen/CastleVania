#ifndef			__TILE_MAP_H__
#define			__TILE_MAP_H__
#include "../../FrameWork/Video/Texture.h"
#include "../../FrameWork/Video/Camera.h"

class CTileMap
{
private:
	CTexture* m_map;
	LPWSTR m_fileImage;
	char* m_fileData;
	int** m_info;
	int m_numberTile;
public:
	CTileMap(LPWSTR fileImage, char* fileData, int numberTile);
	virtual ~CTileMap();
	virtual bool LoadMap();
	virtual void Render(CCamera* camera);
};


#endif			//__TILE_MAP_H__