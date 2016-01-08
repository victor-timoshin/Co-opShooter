#include "../Inc/GameWorld.h"
#include "../Inc/State/PlayScene.h"
#include "../Inc/Item/Potion.h"
#include "../Inc/Controller/MovementController.h"
//#include "../Inc/Controller/PlayerCharacterController.h"

/// <summary>Конструктор класса.</summary>
GameWorld::GameWorld(void)
{
}

/// <summary>Деструктор класса.</summary>
GameWorld::~GameWorld(void)
{
	_objects.clear();
	_characters.clear();
}

void GameWorld::AddCharacter(GameObject* character)
{
	_characters.push_back(character);
}

GameObject* GameWorld::GetCharacter(UInt ID)
{
	return _characters[ID];
}

void GameWorld::AddGameObject(Item* object)
{
	_objects.push_back(object);
}

GameObject* GameWorld::GetGameObject(UInt Id)
{
	return _objects[Id];
}

void GameWorld::Tick(float timeStep)
{
	for (GameObjectList::iterator iter = _objects.begin(); iter != _objects.end(); ++iter)
	{
		Item* object = *iter;

		if (object->CanUse())
		{
			_characters[0]->GetController<Controller::CharacterController>(0)->SetUsableObject(object);

			PlayScene::GetInstancePtr()->GetTooltipHeader()->SetText(static_cast<Potion*>(object)->GetDisplayName());
			PlayScene::GetInstancePtr()->GetTooltipDescription()->SetText(static_cast<Potion*>(object)->GetDescription());
		}
		else
		{
			_characters[0]->GetController<Controller::CharacterController>(0)->SetUsableObject(nullptr);
		}

		object->Tick(timeStep);
	}

	_characters[0]->Tick(timeStep);
}