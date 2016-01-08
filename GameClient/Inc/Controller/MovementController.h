#ifndef MOVEMENTCONTROLLER_H
#define MOVEMENTCONTROLLER_H

#include "ControllerBase.h"
#include "../Character/CharacterState.h"
#include "../StdAfx.h"

namespace Controller
{
	class MovementController : public IControllerBase
	{
		DECL_PROPERTY(Math::Vec3F, MovementDirection, _movementDirection) // Направление движения.
		DECL_PROPERTY_FLOAT(NormalSpeed, _normalSpeed) // Скорость движения.
		DECL_PROPERTY_FLOAT(MinSpeed, _minSpeed) // Минимальная скорость движения.
		DECL_PROPERTY_FLOAT(MaxSpeed, _maxSpeed) // Максимальноя скорость движения.
			
	public:
		/// <summary>Конструктор класса.</summary>
		MovementController(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~MovementController(void);

#pragma region Implementation Controller::IControllerBase

		/// <summary>Привязывает к этому контроллеру игровой объект.</summary>
		virtual void Attach(GameObject* object);

		/// <summary>Отвязывает от этого контроллера игровой объект.</summary>
		virtual void Detach(void);

		/// <summary>Метод обновления контроллера.</summary>
		virtual void Update(float deltaTime);

		virtual bool HasObjectAttached(void) const;

		virtual void SetActive(bool state);

		virtual bool HasActivated(void) const;

#pragma endregion

	protected:
		virtual void SetMoving(bool state);

		virtual bool HasMoving(void) const;

	protected:
		GameObject* _object;
		bool _isActivated;

		Math::Vec3F _lastMovementDirection;
		bool _isMoving;
	};
}

#endif // MOVEMENTCONTROLLER_H