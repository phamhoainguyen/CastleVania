//#include "Collision.h"
//#include <limits>
//#include <algorithm>
//Box Collision::GetBound(CObject object)
//{
//	Box box;
//
//	box.posX = object.GetPosition().x;
//	box.posY = object.GetPosition().y;
//
//	box.width =(float)object.GetFrameWidth();
//	box.height = (float)object.GetFrameHeight();
//
//	box.velocityX = (float)object.GetVelocity().x;
//	box.velocityY = (float)object.GetVelocity().y;
//	
//	return box;
//}
//
//
//Box GetBound(CSprite sprite)
//{
//	Box box;
//
//	box.posX = sprite.GetPosition().x;
//	box.posY = sprite.GetPosition().y;
//
//	box.width = (float)sprite.GetFrameWidth();
//	box.height = (float)sprite.GetFrameHeight();
//
//	box.velocityX = 0.0f;
//	box.velocityY = 0.0f;
//
//	return box;
//}
//
//float Collision::SweptAABB(CObject object1, CObject object2, float& normalx, float& normaly)
//{
//	Box b1 = GetBound(object1);
//	Box b2 = GetBound(object2);
//
//	float xInvEntry, yInvEntry;  // K/c du de xay ra va cham
//	float xInvExit, yInvExit;		// K/c du de het va cham
//
//	//////////////// Tim khoang cach giua hai vat the o canh gan va canh xa/////////////////////
//	if (b1.velocityX > 0.0f)
//	{
//		xInvEntry = b2.posX - (b1.posX + b1.width);
//		xInvExit = (b2.posX + b2.width) - b1.posX;
//	}
//
//	else
//	{
//		xInvEntry = (b2.posX + b2.width) - b1.posX;
//		xInvExit = b2.posX - (b1.posX + b1.width);
//	}
//
//	if (b1.velocityY > 0.0f)
//	{
//		yInvEntry = b2.posY - (b1.posY + b1.height);
//		yInvExit = (b2.posY + b2.height) - b1.posY;
//	}
//	else
//	{
//		yInvEntry = (b2.posY + b2.height) - b1.posY;
//		yInvExit = b2.posY - (b1.posY + b1.height);
//	}
//	
//	/***************************************************************************************/
//
//
//	//////////////////Du doan thoi gian xay ra va cham///////////////////////
//	float xEntry, yEntry;
//	float xExit, yExit;
//
//	if (b1.velocityX == 0.0f)
//	{
//		xEntry = -std::numeric_limits<float>::infinity();
//		xExit = std::numeric_limits<float>::infinity();
//	}
//
//	else
//	{
//		xEntry = xInvEntry / b1.velocityX; // X/d khoang thoi gian xay ra va cham
//		xExit = xInvExit / b1.velocityX;	// x/k khoang thoi gian het va cham
//	}
//
//	if (b1.velocityY == 0.0f)
//	{
//		yEntry = -std::numeric_limits<float>::infinity();
//		yExit = std::numeric_limits<float>::infinity();
//	}
//
//	else
//	{
//		yEntry = yInvEntry / b1.velocityY; //x/d khoang thoi gian xay ra va cham
//		yExit = yInvExit / b1.velocityY;	// x/k khoang thoi gian het va cham
//	}
//	/***************************************************************************/
//
//	///////////////////////////////Tim chinh xac thoi gian bat dau xay ra va cham//////////////////
//	float entryTime = max(xEntry, yEntry);
//	float exitTime = max(xExit, yExit);
//	/*********************************************************************************************/
//	
//
//	////////////////////////////Neu khong va cham/////////////////////////////////////
//	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
//	{
//		normalx = 0.0f;
//		normaly = 0.0f;
//		return 1.0f;
//	}
//	/***********************************************************************************/
//
//	/////////////////////////Neu va cham/////////////////////////
//	else
//	{
//		if (xEntry > yEntry)
//		{
//			if (xInvEntry < 0.0f)
//			{
//				normalx = 1.0f;
//				normaly = 0.0f;
//			}
//			else
//			{
//				normalx = -1.0f;
//				normaly = 0.0f;
//			}
//		}
//		else
//		{
//			if (yInvEntry < 0.0f)
//			{
//				normalx = 0.0f;
//				normaly = 1.0f;
//			}
//			else
//			{
//				normalx = 0.0f;
//				normaly = -1.0f;
//			}
//		}
//		return entryTime;
//	}
//	/***************************************************/
//}
//
