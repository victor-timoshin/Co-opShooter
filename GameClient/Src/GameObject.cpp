#include "../Inc/GameObject.h"
#include "../Inc/State/PlayScene.h"

/// <summary>Конструктор класса.</summary>
GameObject::GameObject(std::string name)
{
	Scene::ISceneGraphBase* scene = PlayScene::GetInstancePtr()->GetSceneGraph();
	Core::Render::IRenderSystemBase* render = PlayScene::GetInstancePtr()->GetRenderSystem();

	_component = scene->CreateBox(std::string(name + "_component").c_str());
	_node = scene->GetRootSceneNode()->CreateChild(std::string(name + "_node").c_str());
	_node->Attach(_component);
	_node->SetPosition(0.0f, 0.0f, 0.0f);
	_node->SetRotation(Math::Vec3F(0.0f, 0.0f, 0.0f), 0.0f, Scene::TransformSpace::TRANSFORM_WORLD);
	_node->SetScale(1.0f, 1.0f, 1.0f);

	Core::Render::IMaterialBase* material = render->GetMaterialManager()->GetMaterialByName(std::string(name + "_material").c_str());
	render->SetRenderableComponent(_component, material);
}

/// <summary>Деструктор класса.</summary>
GameObject::~GameObject(void)
{
}

void GameObject::AddController(Controller::IControllerBase* controller)
{
	// Привязываем текущий класс к контроллеру.
	controller->Attach(this);

	// Добавляем в коллекцию.
	_controllers.push_back(controller);
}

Scene::ISceneNodeBase* GameObject::GetSceneNode(void) const
{
	return _node;
}

Scene::ISceneComponentBase* GameObject::GetSceneComponent(void) const
{
	return _component;
}

void GameObject::Tick(float deltaTime)
{
	for (auto& controller : _controllers)
		controller->Update(deltaTime);
}