#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../Math/Inc/BoundingBox.h"
#include "../StdAfx.h"

namespace Collision
{
	class Collidable
	{
		DECL_PROPERTY_INLINE(Math::BoundingBox, BoundingBox, _boundingBox)
		DECL_PROPERTY_INLINE(UInt, GroupId, _groupId) // Уникальный идентификатор группы.
		DECL_PROPERTY_INLINE_BOOLEAN(Collidable, _collidable)

	public:
		/// <summary>Конструктор класса.</summary>
		Collidable(void)
			: _groupId(0)
			, _collidable(false)
		{
		}

		/// <summary>Деструктор класса.</summary>
		~Collidable(void)
		{
		}
	};

	class CollisionSystem
	{
	public:
		/// <summary>Конструктор класса.</summary>
		CollisionSystem(void);

		/// <summary>Деструктор класса.</summary>
		~CollisionSystem(void);

		UInt AddGroup(void);

		Collidable* Add(const Math::BoundingBox& boundingBox, UInt groupId);

		void Remove(Collidable* entity);

		void Update(void);

	protected:
		void TestCollision(Collidable* entity, UInt groupId);

	private:
		std::vector<std::list<Collidable*>> _entities;
	};
}

#endif // COLLISIONSYSTEM_H