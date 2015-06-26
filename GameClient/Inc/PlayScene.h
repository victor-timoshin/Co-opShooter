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

	virtual void FrameStarted(float timeStep) {}

	virtual void FrameEnded() {}

	static PlayScene* Instance() {
		return &playScene;
	}

private:
	Scene::ISceneGraphBase* sceneGraph;
	
	Gapi::IShaderBase* shader;
	Gapi::IBufferBase* vertexBuffer;
	Gapi::IBufferBase* indexBuffer;
};

#endif // PLAY_SCENE_H