#define _CRT_SECURE_NO_WARNINGS

#include "TileMap.h"
#include <stdio.h>

CTileMap::CTileMap(LPWSTR fileImage, char* fileData, int numberTile)
{
	m_map = NULL;
	m_fileImage = fileImage;
	m_fileData = fileData;
	m_info = NULL;
	m_numberTile = numberTile;

}

CTileMap::~CTileMap()
{
	delete m_map;
	for (int i = 0; i < m_numberTile; i++)
	{
		delete m_info[i];
	}

	delete m_info;
}

bool CTileMap::LoadMap()
{
	//////////////////////////Load image/////////////////////////
	m_map = new CTexture(m_fileImage);
	if (!m_map->Load(D3DCOLOR_XRGB(0, 0, 0)))
		return false;


	m_info = new int*[m_numberTile];
	for (int i = 0; i < m_numberTile; i++)
	{
		m_info[i] = new int[8];
	}

	if (m_info == NULL)
		return false;
	/***********************************************************/

	/////////////////Open File///////////////////////
	FILE *myFile;
	myFile = fopen(m_fileData, "r");

	if (myFile == NULL)
	{
		return false;
	}
	/***********************************************************/
	
	for (int i = 0; i < m_numberTile; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			fscanf(myFile, "%d,", &m_info[i][j]);
		}
	}

	fclose(myFile);

	return true;

}

void CTileMap::Render(CCamera* camera)
{
	D3DXVECTOR3 position(0, 0, 0);
	RECT srcRect;
	for (int i = 0; i < m_numberTile; i++)
	{
		position.x = camera->Transform(m_info[i][2], m_info[i][3]).x;
		position.y = camera->Transform(m_info[i][2], m_info[i][3]).y;

		position.z = 0;

		srcRect.left = (float)m_info[i][4];
		srcRect.top = (float)m_info[i][5];
		srcRect.right = srcRect.left + m_info[i][6];
		srcRect.bottom = srcRect.top + m_info[i][7];



		e_spriteHandler->Draw(
			m_map->GetImage(),
			&srcRect,
			NULL,
			&position,
			D3DCOLOR_XRGB(255, 255, 255)
			//0xFFFFFFFF //color
			);
	}
}