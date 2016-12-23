#include "Action.h"

CAction::CAction()
{

}

CAction::~CAction()
{

}

void CAction::Go(CObject* object)
{
	object->SetPosition(object->GetPosition().x + (object->GetVelocity().x  * object->GetDeltaTime()), object->GetPosition().y);
}
void CAction::Jump(CObject* object)
{
	float y = object->GetVelocity().y + object->GetAcceleration() * object->GetDeltaTime();
	D3DXVECTOR2 velocity = { object->GetVelocity().x, y };
	object->SetVelocity(velocity);
	object->SetPosition(object->GetVelocity().x, object->GetPosition().y - (object->GetVelocity().y * object->GetDeltaTime()));

	if (object->GetVelocity().y < 0)
	{
		float y = object->GetVelocity().y + (object->GetAcceleration() * object->GetDeltaTime() * 2);
		D3DXVECTOR2 velocity = { object->GetVelocity().x, y };
		object->SetVelocity(velocity);
		object->SetPosition(object->GetVelocity().x, object->GetPosition().y - (object->GetVelocity().y * object->GetDeltaTime()));
	}
}