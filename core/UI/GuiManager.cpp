#include "GuiManager.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../scene/nodes/node.h"

#include "../../libraries/lib/imgui/imgui.h"
#include "../../libraries/lib/imgui/imgui_impl_glfw.h"
#include "../../libraries/lib/imgui/imgui_impl_opengl3.h"

void RenderNodeHierarchy(Node* node) {
	if (!node) return;

	if (ImGui::TreeNode(node->get_name().c_str())) {
		for (Node* child : node->get_children()) {
			RenderNodeHierarchy(child);
		}
		ImGui::TreePop();
	}
}

void GuiManager::RenderDebugUI(Node* rootNode) {
	ImGui::Begin("Scene Hierarchy");

	if (rootNode) {
		RenderNodeHierarchy(rootNode); // Chama a função que desenha a árvore de Nodes
	}

	ImGui::End();
}