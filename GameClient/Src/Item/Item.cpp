#include "../../Inc/Item/Item.h"

/// <summary>Конструктор класса.</summary>
Item::Item(std::string name, Controller::CharacterController* controller) : UsableObject(name, controller)
{
	_displayName = "Unnamed";
	_useDescription = "Missing";
	_usePrompt = "Press [] to use";
	_pickupPrompt = "Press [] to pick up";
}

/// <summary>Деструктор класса.</summary>
Item::~Item(void)
{
}

void Item::SetDisplayName(std::string displayName)
{
	_displayName = displayName;
}

std::string Item::GetDisplayName(void) const
{
	return _displayName;
}

void Item::SetDescription(std::string description)
{
	_useDescription = description;
}

std::string Item::GetDescription(void) const
{
	return _useDescription;
}

void Item::SetUsePrompt(std::string usePrompt)
{
	_usePrompt = usePrompt;
}

std::string Item::GetUsePrompt(void) const
{
	return _usePrompt;
}

void Item::SetPickupPrompt(std::string pickupPrompt)
{
	_pickupPrompt = pickupPrompt;
}

std::string Item::GetPickupPrompt(void) const
{
	return _pickupPrompt;
}