#include "../../Inc/Collision/CollisionSystem.h"

namespace Collision
{
	/// <summary>Конструктор класса.</summary>
	CollisionSystem::CollisionSystem(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	CollisionSystem::~CollisionSystem(void)
	{
		for (UInt i = 0; i < _entities.size(); ++i)
		{
			for (auto iter = _entities[i].begin(); iter != _entities[i].end(); ++iter)
				delete (*iter);
		}
	}

	UInt CollisionSystem::AddGroup(void)
	{
		_entities.push_back(std::list<Collidable*>());
		return _entities.size() - 1;
	}

	Collidable* CollisionSystem::Add(const Math::BoundingBox& boundingBox, UInt groupId)
	{
		if (groupId >= _entities.size())
			return nullptr;

		Collidable* entity = new Collidable();
		entity->SetGroupId(groupId);
		entity->SetBoundingBox(boundingBox);

		_entities[groupId].push_back(entity);
		return entity;
	}

	void CollisionSystem::Remove(Collidable* entity)
	{
		_entities[entity->GetGroupId()].remove(entity);
		delete entity;
	}

	void CollisionSystem::Update(void)
	{
		for (UInt i = 0; i < _entities.size(); ++i)
		{
			auto iter = _entities[i].begin();
			while (iter != _entities[i].end())
			{
				if ((*iter)->HasCollidable())
					TestCollision((*iter), i);

				++iter;
			}
		}
	}

	void CollisionSystem::TestCollision(Collidable* entity, UInt groupId)
	{
		for (UInt i = 0; i < _entities.size(); ++i)
		{
			if (i != groupId)
			{
				auto iter = _entities[i].begin();
				while (iter != _entities[i].end())
				{
					if ((*iter)->HasCollidable())
					{
						if(entity->GetBoundingBox().IsIntersect((*iter)->GetBoundingBox()))
						{
						}
					}

					++iter;
				}
			}
		}
	}
}