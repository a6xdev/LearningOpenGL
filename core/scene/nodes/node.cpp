#include "node.h"

#include "../../../libraries/lib/imgui/imgui.h"

#include <algorithm>
#include <iostream>

using namespace std;

Node::Node(const string& name) : name(name), parent(nullptr) {}

Node::~Node() { // ~ um destrutor, ou seja, quando o node for apagado, vai deletar todos os filhos.
	for (Node* child : children) {
		delete child;
	}
	children.clear();
}

void Node::add_child(Node* child) { // quando adiciona algum filho, este node vai receber o papel de pai.
	if (child && child->parent == nullptr) {
		children.push_back(child);
		child->parent = this;
	}
}

void Node::remove_child(Node* child) {
	if (!child) cout << "Child not found";

	auto it = find(children.begin(), children.end(), child);
	if (it != children.end()) {
		child->parent = nullptr;
		children.erase(it);
	}
}

Node* Node::get_parent() const {
	return parent;
}

vector<Node*>& Node::get_children() {
	return children;
}

void Node::update() {
	for (Node* child : children) { // se child receber o valor de children, retorna o update()
		child->update();
	}
}

const string& Node::get_name() const {
	return name;
}

void Node::set_name(const string& new_name) {
	name = new_name;
}