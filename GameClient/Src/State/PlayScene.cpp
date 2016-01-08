#include "../../Inc/State/PlayScene.h"
#include "../../Inc/Item/Potion.h"

#include "../../Inc/Controller/CharacterController.h"

PlayScene  PlayScene::_playScene;
PlayScene* PlayScene::GetInstancePtr(void)
{
	return &_playScene;
}

void PlayScene::Enter(Core::Render::IRenderSystemBase* renderSystem, Scene::ISceneGraphBase* sceneGraph)
{
	_renderSystem = renderSystem;
	_sceneGraph = sceneGraph;

	Scene::ICameraBase* camera = _sceneGraph->CreateCamera("camera");
	camera->LookAt(Math::Vec3F(0.0f, 0.0f, 1.0f));
	camera->Perspective(CAMERA_FOV, SCREEN_WIDTH / SCREEN_HEIGHT, CAMERA_PERSP_NEAR_CLIP, CAMERA_PERSP_FAR_CLIP);
	camera->SetPosition(Math::Vector3F(0.0f, 5.0f, 0.0f));
	camera->Move(Math::Vector3F(0.0f, 0.0f, 0.0f));
	camera->Rotation(0.0f, 0.0f, 0.0f);

	_world = new GameWorld();

	_character = new GameObject("player");
	_character->AddController(new Controller::CharacterController());
	_world->AddCharacter(_character);

	SPAWN_PARAMS lifePotionParams;
	lifePotionParams.position = Math::Vec3F(0.0f, 0.0f, 5.0f);
	Item* lifePotion = new Potion("health_potion_50", _character->GetController<Controller::CharacterController>(0));
	lifePotion->SetDisplayName("Life Potion");
	lifePotion->SetDescription("Instantly restores 60% Life");
	lifePotion->GetSceneNode()->SetPosition(lifePotionParams.position);
	_world->AddGameObject(lifePotion);

	SPAWN_PARAMS manaPotionParams;
	manaPotionParams.position = Math::Vec3F(10.0f, 0.0f, 10.0f);
	Item* manaPotion = new Potion("mana_potion_72", _character->GetController<Controller::CharacterController>(0));
	manaPotion->SetDisplayName("Mana Potion");
	manaPotion->SetDescription("Instantly restores 60% Mana");
	manaPotion->GetSceneNode()->SetPosition(manaPotionParams.position);
	_world->AddGameObject(manaPotion);

	_font = _renderSystem->CreateTTFont("font", "../../../Assets/Fonts/Amble-Light.ttf");
	_font->SetScale(1.2f);
	_font->SetPosition(250.0f, 250.0f);
	_font->SetColor(Math::Color(1.0f, 0.0f, 0.0f, 1.0f));

	_tooltipHeader = _renderSystem->CreateTTFont("tooltip_header", "../../../Assets/Fonts/Amble-LightCondensed.ttf");
	_tooltipHeader->SetScale(1.1f);
	_tooltipHeader->SetPosition(250.0f, 120.0f);
	_tooltipHeader->SetColor(Math::Color(1.0f, 1.0f, 0.0f, 1.0f));

	_tooltipDescription = _renderSystem->CreateTTFont("tooltip_description", "../../../Assets/Fonts/Amble-LightCondensed.ttf");
	_tooltipDescription->SetScale(1.0f);
	_tooltipDescription->SetPosition(250.0f, 150.0f);
	_tooltipDescription->SetColor(Math::Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void PlayScene::Exit(void)
{
	SAFE_DELETE(_world);

	_sceneGraph->Clear();
}

void PlayScene::FrameStarted(OIS::IInputBase* event, float timeStep)
{
	OIS::IKeyboard* keyboard = event->GetKeyboard();

	if (keyboard->HasKeyDown(OIS::KeyCode_Escape))
		PostQuitMessage(0);

	//_sceneGraph->GetActiveCamera()->SetPosition(_world->GetCharacterController(0)->GetEyePosition());

	_character->GetController<Controller::CharacterController>(0)->SetupPlayerInput(event);

	_world->Tick(1.0f / 60.0f);

	_sceneGraph->Update();

	InputMouseMove(event->GetMouse());

	std::string str = std::to_string(_renderSystem->GetNumDisplayObjects());
	_font->SetText(str.c_str());
}

void PlayScene::InputMouseMove(OIS::IMouse* mouse)
{
	float x = mouse->GetCursorPositionAbsolute()._x * 0.1f;
	float y = mouse->GetCursorPositionAbsolute()._y * 0.1f;
	
	SetRotation(x, y);

	mouse->SetCursorSensitivity(1);
	mouse->SetCursorPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void PlayScene::SetRotation(float x, float y)
{
	_sceneGraph->GetActiveCamera()->Rotation(x, y, 0.0f);
}

Core::Render::IRenderSystemBase* PlayScene::GetRenderSystem(void)
{
	return _renderSystem;
}

Scene::ISceneGraphBase* PlayScene::GetSceneGraph(void)
{
	return _sceneGraph;
}