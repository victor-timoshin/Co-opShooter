#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "../StdAfx.h"

class Potion : public Item
{
public:
	/// <summary>Конструктор класса.</summary>
	Potion(std::string name, Controller::CharacterController* controller);

	/// <summary>Деструктор класса.</summary>
	virtual ~Potion(void);

private:
};

#endif // POTION_H