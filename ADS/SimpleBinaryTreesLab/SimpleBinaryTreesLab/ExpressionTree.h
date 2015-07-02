#pragma once
#include "BinaryTree.h"

using namespace System;


ref class ExpressionTree : BinaryTree<String^> {
	private:
	public:
		ExpressionTree(String^ rootValue);
		int parseExpressionTree(Node<String^>^ node);
		String^ convertToPostFix(Node<String^>^ node);
};