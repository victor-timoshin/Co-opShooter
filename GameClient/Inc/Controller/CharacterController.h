#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "MovementController.h"
#include "../StdAfx.h"

class UsableObject;

namespace Controller
{
	class CharacterController : public MovementController
	{
		DECL_PROPERTY_FLOAT(WalkSpeed, _walkSpeed)
		DECL_PROPERTY_FLOAT(RunSpeed, _runSpeed)
		DECL_PROPERTY_FLOAT(JumpSpeed, _jumpSpeed)
		DECL_PROPERTY_BOOLEAN(Running, _isRunning)
		DECL_PROPERTY_FLOAT(AttackSpeed, _attackSpeed)

	public:
		/// <summary>Конструктор класса.</summary>
		CharacterController(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~CharacterController(void);

#pragma region Implementation Controller::IControllerBase

		/// <summary>Метод обновления контроллера.</summary>
		virtual void Update(float deltaTime);

#pragma endregion

	public:
		void SetUsableObject(UsableObject* object);

		void SetupPlayerInput(OIS::IInputBase* input);

		Math::BoundingBox GetBoundingBox(void) const;

		float GetEyeHeight(void) const;

		Math::Vec3F GetEyePosition(void) const;

		//void AddHealth(int increment)
		//{
		//	if (_isDead)
		//		return;
		//	
		//	_model.SetHealth(_model.GetHealth() + increment);
		//}
		//	
		//void LoseHealth(int decrease)
		//{
		//	if (_isDead)
		//		return;
		//	
		//	_model.SetHealth(_model.GetHealth() - decrease);
		//}
		//	
		//void AddEnergy(int increment);
		//	
		//void LoseEnergy(int decrease);
		//	
		//bool IsDead(void)
		//{
		//	return _isDead;
		//}

	protected:
		void InjectKeyUp(const OIS::IKeyboard* keyboard);

		void InjectKeyDown(const OIS::IKeyboard* keyboard);

		void InjectMouseButtonUp(const OIS::IMouse* mouse);

		void InjectMouseButtonDown(const OIS::IMouse* mouse);

		void InjectMouseMove(OIS::IMouse* mouse);

	private:
		Character::CHARACTER_STATE _movementState;
		Character::JUMP_STATE _jumpState;

		UsableObject* _currentUsableObject;
		float _useTargetMaxDist = 512.0f;

		float _capsuleHeight;
		float _capsuleRadius;

		//CharacterModel _model;
		//CharacterView _view;
		//CharacterState _state;
		//bool _isDead;
	};
}

#endif // CHARACTERCONTROLLER_H