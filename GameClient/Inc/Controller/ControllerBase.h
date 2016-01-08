#ifndef CONTROLLERBASE_H
#define CONTROLLERBASE_H

#include "../StdAfx.h"

class GameObject;

namespace Controller
{
	class IControllerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IControllerBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IControllerBase(void) {}

		virtual void Attach(GameObject* object) = 0;

		virtual void Detach(void) = 0;

		virtual bool HasObjectAttached(void) const = 0;

		virtual void SetActive(bool state) = 0;

		virtual bool HasActivated(void) const = 0;

		virtual void Update(float deltaTime) = 0;
	};
}

#endif // CONTROLLERBASE_H