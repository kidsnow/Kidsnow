#pragma once

#include <vector>

namespace kidsnow {

class Mesh;

class SceneNode {

typedef std::vector<SceneNode*> Children;

public:
	SceneNode();
	
public:
	inline void setMesh(Mesh *mesh) { m_mesh = mesh; }

private:
	SceneNode *m_parent, *m_child;
	Mesh *m_mesh;
	Children m_children;
};

}