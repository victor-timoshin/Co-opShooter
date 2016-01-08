#ifndef GAMEWORLD_H
#define GAMEWORLD_H

//#include "Character/CharacterController.h"
#include "GameObject.h"
#include "Item/Item.h"
#include "StdAfx.h"

class GameWorld
{
public:
	/// <summary>Конструктор класса.</summary>
	GameWorld(void);

	/// <summary>Деструктор класса.</summary>
	~GameWorld(void);

	void AddCharacter(GameObject* character);

	GameObject* GetCharacter(UInt ID);

	void AddGameObject(Item* object);

	GameObject* GetGameObject(UInt Id);

	void Tick(float timeStep);

private:
	typedef std::vector<GameObject*> CharacterControllerList;
	CharacterControllerList _characters;

	typedef std::vector<Item*> GameObjectList;
	GameObjectList _objects;
};

#endif // GAMEWORLD_H