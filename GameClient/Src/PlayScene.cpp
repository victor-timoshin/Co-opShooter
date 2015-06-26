#include "../Inc/PlayScene.h"

PlayScene PlayScene::playScene;

void PlayScene::Enter(Scene::ISceneGraphBase* scene)
{
	sceneGraph = scene;

	Scene::ISceneComponentBase* component = sceneGraph->CreateBox("boxComponent");
	Scene::ISceneNodeBase* sceneNode = sceneGraph->GetRootSceneNode()->CreateChild("boxSceneNode");

	sceneNode->Attach(component);
}

void PlayScene::Exit()
{
	sceneGraph->Clear();
}