#include "node.h"

#include <algorithm>
#include <iostream>

using namespace std;

Node::Node(const string& name) : name(name), parent(nullptr) {}

Node::~Node() { // ~ é um destrutor, ou seja, quando o node for apagado, vai deletar todos os filhos.
	for (Node* child : children) {
		delete child;
	}
	children.clear();
}

void Node::add_child(Node* child) { // quando adiciona algum filho, este node vai receber o papel de pai.
	if (child && child->parent == nullptr) {
		child->parent = this;
		children.push_back(child);
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