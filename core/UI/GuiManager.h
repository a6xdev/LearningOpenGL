#pragma once
#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include "../scene/nodes/node.h"

class GuiManager {
public:
	void RenderDebugUI(Node* rootNode);
};

#endif // GUI_MANAGER_H