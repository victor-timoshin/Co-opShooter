#ifndef USABLEOBJECT_H
#define USABLEOBJECT_H

#include "../../Inc/Controller/CharacterController.h"
#include "../StdAfx.h"

#include "../GameObject.h"

class UsableObject : public GameObject
{
public:
	/// <summary>Конструктор класса.</summary>
	UsableObject(std::string name, Controller::CharacterController* controller);

	/// <summary>Деструктор класса.</summary>
	virtual ~UsableObject(void);

	virtual void Use(void);

	virtual void Unuse(void);

	virtual bool CanUse(void);

	virtual bool HasUsing(void);

	//virtual void OnUsed(CharacterController* controller);
	//virtual void OnPickedUp();
	//virtual void OnPlaced();

private:
	Controller::CharacterController* _characterController;
	bool _isUsing;
};

#endif // USABLEOBJECT_H