#include "stdafx.h"
#include "ExpressionTree.h"

ExpressionTree::ExpressionTree(String^ rootValue) {
	rootNode = gcnew Node<String^>(rootValue);
}
int ExpressionTree::parseExpressionTree(Node<String^>^ node) 
{
	if(node != nullptr) {
		if(node->Value == "+") {
			return parseExpressionTree(node->Left) + parseExpressionTree(node->Right);
		}
		else if(node->Value == "*") {
			 return parseExpressionTree(node->Left) * parseExpressionTree(node->Right);
		}
		else {
			return Convert::ToInt16(node->Value);
		}
	}
}

String^ ExpressionTree::convertToPostFix(Node<String^>^ node) {

	if(node != nullptr) { 
		if(node->Value == "+" || node->Value == "*") {
			return (convertToPostFix(node->Left) + convertToPostFix(node->Right) + node->Value);
		}
		else {
			return node->Value;
		}
	}
}