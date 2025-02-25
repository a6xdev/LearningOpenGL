#pragma once

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node {
protected:
	string name; // nome do node
	Node* parent; // referencia do parent
	vector<Node*> children; // seus filhos

public:
	Node(const string& name = "Node");
	virtual ~Node();

	void add_child(Node* child);
	void remove_child(Node* child);
	Node* get_parent() const;
	vector<Node*>& get_children();

	virtual void update();
};

#endif // NODE_H