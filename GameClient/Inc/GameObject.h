#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Controller/ControllerBase.h"
#include "StdAfx.h"

typedef struct SpawnParams
{
	Math::Vec3F position;
	Math::Quaternion rotation;
	Math::Vec3F scale;
	UInt flags;
} SPAWN_PARAMS;

class GameObject
{
public:
	/// <summary>Конструктор класса.</summary>
	GameObject(std::string name);

	/// <summary>Деструктор класса.</summary>
	virtual ~GameObject(void);

	virtual void AddController(Controller::IControllerBase* controller);

	template<class T>
	T* GetController(UInt index) {
		return static_cast<T*>(_controllers[index]);
	}

	virtual Scene::ISceneNodeBase* GetSceneNode(void) const;

	virtual Scene::ISceneComponentBase* GetSceneComponent(void) const;

	virtual void Init(void) {}
	virtual void Tick(float deltaTime);

	virtual void OnSpawn(UInt flag) {}
	virtual void OnDestroy(UInt flag) {}
	virtual void OnPick(/*Player* player*/) {}
	virtual void OnBodyCollision(/*CollisionBody& self, CollisionBody& other*/) {}

private:
	Scene::ISceneComponentBase* _component;
	Scene::ISceneNodeBase* _node;

	std::vector<Controller::IControllerBase*> _controllers;
};

#endif // GAMEOBJECT_H