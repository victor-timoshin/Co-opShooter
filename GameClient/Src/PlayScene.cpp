#include "../Inc/PlayScene.h"

#define CAMERA_FOV 90.0f
#define CAMERA_ZNEAR 1.0f
#define CAMERA_ZFAR 100000.0f

PlayScene PlayScene::playScene;

void PlayScene::Enter(Scene::ISceneGraphBase* scene)
{
	sceneGraph = scene;

	camera = sceneGraph->CreateCamera("camera");
	camera->LookAt();
	camera->Perspective(CAMERA_FOV, 800.0f / 600.0f, CAMERA_ZNEAR, CAMERA_ZFAR);
	camera->SetPosition(Core::Math::Vector3(0.0f, 0.0f, 0.0f));
	
	camera->Move(Core::Math::Vector3(0.0f, 2.0f, 10.0f));
	camera->Rotation(0.0f, 0.0f, 0.0f);

	Scene::ISceneComponentBase* component = sceneGraph->CreateBox("boxComponent");
	Scene::ISceneNodeBase* sceneNode = sceneGraph->GetRootSceneNode()->CreateChild("boxSceneNode");

	sceneNode->Attach(component);

	sceneNode->SetPosition(0.0f, 0.0f, 0.0f);
	sceneNode->SetRotation(Core::Math::Vector3(0.0f, 0.0f, 0.0f), 0.0f, Scene::TransformSpace::TRANSFORM_WORLD);
	sceneNode->SetScale(1.0f, 1.0f, 1.0f);
}

void PlayScene::Exit()
{
	sceneGraph->Clear();
}

void PlayScene::FrameStarted(OIS::IInputEventBase* event, float timeStep)
{
	if (event->KeyDown(OIS::KEY_ESCAPE)) PostQuitMessage(0);

	position._x = event->KeyDown(OIS::KEY_D) ? 0.1f : 0.0f + event->KeyDown(OIS::KEY_A) ? -0.1f : 0.0f;
	position._y = 0.0f;
	position._z = event->KeyDown(OIS::KEY_S) ? 0.1f : 0.0f + event->KeyDown(OIS::KEY_W) ? -0.1f : 0.0f;

	camera->Move(position);
}