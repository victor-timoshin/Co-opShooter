#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include "StdAfx.h"

class PlayScene : public Scene::ISceneStateBase
{
public:
	static PlayScene playScene;

	virtual void Enter(Scene::ISceneGraphBase* scene);

	virtual void Exit();

	virtual void Pause() {}

	virtual void Resume() {}

	virtual void FrameStarted(OIS::IInputEventBase* event, float timeStep);

	virtual void FrameEnded() {}

	static PlayScene* Instance() {
		return &playScene;
	}

private:
	Scene::ISceneGraphBase* sceneGraph;
	Scene::ICameraBase* camera;

	Core::Math::Vector3 position;
};

#endif // PLAY_SCENE_H