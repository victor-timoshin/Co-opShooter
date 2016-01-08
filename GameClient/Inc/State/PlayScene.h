#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "../Player.h"
#include "../GameObject.h"
#include "../GameWorld.h"
#include "../StdAfx.h"

class PlayScene : public Scene::ISceneStateBase
{
public:
	static PlayScene* GetInstancePtr(void);

	virtual void Enter(Core::Render::IRenderSystemBase* renderSystem, Scene::ISceneGraphBase* scene);

	virtual void Exit(void);

	virtual void Pause(void) {}

	virtual void Resume(void) {}

	virtual void FrameStarted(OIS::IInputBase* event, float timeStep);

	virtual void FrameEnded(void) {}

	Core::Render::IRenderSystemBase* GetRenderSystem(void);

	Scene::ISceneGraphBase* GetSceneGraph(void);

	GameWorld* GetGameWorld(void) { return _world; }

	GUI::IFontBase* GetTooltipHeader(void) { return _tooltipHeader; }
	GUI::IFontBase* GetTooltipDescription(void) { return _tooltipDescription; }

protected:
	void InputMouseMove(OIS::IMouse* mouse);

	void SetRotation(float x, float y);

private:
	static PlayScene _playScene;

	Core::Render::IRenderSystemBase* _renderSystem;
	Scene::ISceneGraphBase* _sceneGraph;
	Math::Vector3F _cameraPosition;

	GameWorld* _world;
	GameObject* _character;
	Player* _player;

	GUI::IFontBase* _font;
	GUI::IFontBase* _tooltipHeader;
	GUI::IFontBase* _tooltipDescription;
};

#endif // PLAYSCENE_H