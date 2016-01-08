#include "../../Inc/Controller/CharacterController.h"
#include "../../Inc/Item/UsableObject.h"
#include "../../Inc/GameObject.h"

namespace Controller
{
	DEF_PROPERTY_FLOAT(CharacterController, WalkSpeed, _walkSpeed)
	DEF_PROPERTY_FLOAT(CharacterController, RunSpeed, _runSpeed)
	DEF_PROPERTY_FLOAT(CharacterController, JumpSpeed, _jumpSpeed)
	DEF_PROPERTY_BOOLEAN(CharacterController, Running, _isRunning)
	DEF_PROPERTY_FLOAT(CharacterController, AttackSpeed, _attackSpeed)

	/// <summary>Конструктор класса.</summary>
	CharacterController::CharacterController(void)
		: _walkSpeed(1.0f)
		, _runSpeed(1.7f)
		, _jumpSpeed(2.0f)
		, _isRunning(false)
		, _currentUsableObject(nullptr)
	{
	}

	/// <summary>Деструктор класса.</summary>
	CharacterController::~CharacterController(void)
	{
	}

#pragma region Implementation Controller::IControllerBase

	/// <summary>Метод обновления контроллера.</summary>
	void CharacterController::Update(float deltaTime)
	{
		MovementController::Update(deltaTime);
	}

#pragma endregion

	void CharacterController::SetUsableObject(UsableObject* object)
	{
		_currentUsableObject = object;
	}

	Math::BoundingBox CharacterController::GetBoundingBox(void) const
	{
		return _object->GetSceneComponent()->GetAttributePacket().aabb;
	}

	float CharacterController::GetEyeHeight(void) const
	{
		return 1.0f;
	}
	
	Math::Vec3F CharacterController::GetEyePosition(void) const
	{
		Math::Vec3F eyePosition = _object->GetSceneNode()->GetPosition();
		eyePosition._y += GetEyeHeight() - (_object->GetSceneNode()->GetScale().GetY() / 2.f);
		return eyePosition;
	}

	void CharacterController::SetupPlayerInput(OIS::IInputBase* input)
	{
		InjectKeyUp(input->GetKeyboard());
		InjectKeyDown(input->GetKeyboard());
		InjectMouseButtonUp(input->GetMouse());
		InjectMouseButtonDown(input->GetMouse());
		InjectMouseMove(input->GetMouse());
	}

	void CharacterController::InjectKeyDown(const OIS::IKeyboard* keyboard)
	{
		if (HasObjectAttached() AND HasActivated())
		{
			if (keyboard->HasKeyDown(OIS::KeyCode_E) AND _currentUsableObject != nullptr)
			{
				if (_currentUsableObject->HasUsing())
					_currentUsableObject->Unuse();
				else
					_currentUsableObject->Use();
			}

			Math::Vec3F movement = VEC3F_ZERO;
			Math::Vec3F rotation = VEC3F_ZERO;

			if (keyboard->HasKeyDown(OIS::KeyCode_W) OR keyboard->HasKeyDownStr("up"))
			{
				_movementState = (HasRunning()) ? Character::CHARACTER_STATE::RunForward : Character::CHARACTER_STATE::WalkForward;

				movement = VEC3F_FORWARD;
				SetNormalSpeed(((HasRunning()) ? GetRunSpeed() : GetWalkSpeed()) * 0.02f);
				SetMoving(true);
			}

			if (keyboard->HasKeyDown(OIS::KeyCode_S) OR keyboard->HasKeyDownStr("down"))
			{
				_movementState = (HasRunning()) ? Character::CHARACTER_STATE::RunBack : Character::CHARACTER_STATE::WalkBack;

				movement = VEC3F_BACK;
				SetNormalSpeed(((HasRunning()) ? GetRunSpeed() : GetWalkSpeed()) * 0.02f);
				SetMoving(true);
			}

			if (keyboard->HasKeyDown(OIS::KeyCode_D) OR keyboard->HasKeyDownStr("right"))
			{
				_movementState = (HasRunning()) ? Character::CHARACTER_STATE::RunRight : Character::CHARACTER_STATE::WalkRight;

				movement = VEC3F_RIGHT;
				SetNormalSpeed(((HasRunning()) ? GetRunSpeed() : GetWalkSpeed()) * 0.015f);
				SetMoving(true);
			}

			if (keyboard->HasKeyDown(OIS::KeyCode_A) OR keyboard->HasKeyDownStr("left"))
			{
				_movementState = (HasRunning()) ? Character::CHARACTER_STATE::RunLeft : Character::CHARACTER_STATE::WalkLeft;

				movement = VEC3F_LEFT;
				SetNormalSpeed(((HasRunning()) ? GetRunSpeed() : GetWalkSpeed()) * 0.015f);
				SetMoving(true);
			}

			SetMovementDirection(movement);
		}
	}

	void CharacterController::InjectKeyUp(const OIS::IKeyboard* keyboard)
	{
		if (HasObjectAttached() AND HasActivated())
		{
			SetMovementDirection(VEC3F_ZERO);
			SetMoving(false);
		}
	}

	void CharacterController::InjectMouseButtonUp(const OIS::IMouse* mouse)
	{
	}

	void CharacterController::InjectMouseButtonDown(const OIS::IMouse* mouse)
	{
		if (mouse->HasMouseLeftButtonDown())
		{
			//GameObject* object = new GameObject("health_potion_50");
		}
	}

	void CharacterController::InjectMouseMove(OIS::IMouse* mouse)
	{
		if (HasObjectAttached() AND HasActivated())
		{
			float x = mouse->GetCursorPositionAbsolute()._x * 0.1f;
			float y = mouse->GetCursorPositionAbsolute()._y * 0.1f;

			//_object->GetSceneNode()->SetRotation(Math::Vec3F(x, y, 0.0f), 1.0f, Scene::TransformSpace::TRANSFORM_WORLD);
		}
	}
}