#include "../../Inc/Controller/MovementController.h"
#include "../../Inc/GameObject.h"

namespace Controller
{
	DEF_PROPERTY(MovementController, Math::Vec3F, MovementDirection, _movementDirection)
	DEF_PROPERTY_FLOAT(MovementController, NormalSpeed, _normalSpeed)
	DEF_PROPERTY_FLOAT(MovementController, MinSpeed, _minSpeed)
	DEF_PROPERTY_FLOAT(MovementController, MaxSpeed, _maxSpeed)

	/// <summary>Конструктор класса.</summary>
	MovementController::MovementController(void)
		: _object(nullptr)
		, _isActivated(true)
		, _movementDirection(VEC3F_ZERO)
		, _lastMovementDirection(VEC3F_ZERO)
		, _isMoving(false)
		, _normalSpeed(1.0f)
		, _minSpeed(0.8f)
		, _maxSpeed(1.2f)
	{
	}

	/// <summary>Деструктор класса.</summary>
	MovementController::~MovementController(void)
	{
	}

#pragma region Implementation Controller::IControllerBase

	/// <summary>Привязывает к этому контроллеру игровой объект.</summary>
	void MovementController::Attach(GameObject* object)
	{
		_object = object;
	}

	/// <summary>Отвязывает от этого контроллера игровой объект.</summary>
	void MovementController::Detach(void)
	{
		_object = nullptr;
	}

	bool MovementController::HasObjectAttached(void) const
	{
		return (_object != nullptr);
	}

	void MovementController::SetActive(bool state)
	{
		_isActivated = state;
	}

	bool MovementController::HasActivated(void) const
	{
		return _isActivated;
	}

	/// <summary>Метод обновления контроллера.</summary>
	void MovementController::Update(float deltaTime)
	{
		if (HasObjectAttached() AND HasActivated())
			_object->GetSceneNode()->SetTranslate(_movementDirection * _normalSpeed);
	}

#pragma endregion

	void MovementController::SetMoving(bool state)
	{
		_isMoving = state;
	}

	bool MovementController::HasMoving(void) const
	{
		return _isMoving;
	}
}