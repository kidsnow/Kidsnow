#pragma once

namespace kidsnow {

class SceneNode;

class Scene {
	enum class RENDERING_MODE
	{
		DEFAULT
	};

public:
	Scene();

private:
	RENDERING_MODE m_renderingMode;
	SceneNode *m_rootNode;
};

}