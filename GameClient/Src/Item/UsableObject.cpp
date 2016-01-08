#include "../../Inc/Item/UsableObject.h"

/// <summary>Конструктор класса.</summary>
UsableObject::UsableObject(std::string name, Controller::CharacterController* controller) : GameObject(name)
	, _characterController(controller)
{
}

/// <summary>Деструктор класса.</summary>
UsableObject::~UsableObject(void)
{
}

void UsableObject::Use(void)
{
	_isUsing = true;
}

void UsableObject::Unuse(void)
{
	_isUsing = false;
}

bool UsableObject::CanUse(void)
{
	const Math::BoundingBox& boundingBox = GetSceneComponent()->GetAttributePacket().aabb;
	return boundingBox.IsIntersect(_characterController->GetBoundingBox());
}

bool UsableObject::HasUsing(void)
{
	return _isUsing;
}