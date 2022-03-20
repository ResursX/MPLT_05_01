#pragma once
#include "MPLT_05_01_INT.h"

namespace MPLT_05_01 {
	enum class NodeColor
	{
		BLACK,
		RED
	};

	class TNode {
	public:
		TNode(GameObject*);
		~TNode();

		MPLT_05_01::GameObject* Data;
		TNode* Parent, * Left, * Right;
		NodeColor Color;

		std::string Print();
	private:
		std::string Print(int);
	};

	typedef TNode *PNode;

	class TTree {
	public:
		TTree();
		~TTree();

		PNode Root;

		void Add(GameObject*);
		void Remove(int);
		std::string Print();
	private:
	};

	typedef TTree* PTree;
}