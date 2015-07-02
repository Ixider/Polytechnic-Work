#include "stdafx.h"
#include "BinarySearchTree.h"

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	Stores all strings encodes and decodes strings
	and text files in a Huffman Tree datastructure

	Exposes:
		void   Add(int, string)
		string decodeString(string)
		string generateCodes()

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

// Public functions
/*
	 !! Deprecated function from binarySearchTree !!

	PRE: RootNode must be null ptr
*/
void BinarySearchTree::Add(int i, String^ s) {
	insertItem(rootNode, i, s);
}
/*
	POST: Root node is not nullptr
*/


/*
	PRE:
*/
void BinarySearchTree::insertItem(Node<int>^ %node, int value, String^ symbol) {
	// Leaf Condition
	if(node == nullptr) {
		node = gcnew Node<int>(value, symbol);
		return;
	}
	// Tree Navigation
	if(value > node->Value) {
		return insertItem(node->Left, value, symbol);
	}
	return insertItem(node->Right, value, symbol);		
}
/*
	POST:
*/

/*
	PRE:
*/
String^ BinarySearchTree::decodeString(String^ str) {
	// Node used for tree navigation
	Node<int>^ node = rootNode;
	
	// Returned value
	String^ tempString = "";

	for(int i = 0; i < str->Length; i++) {
		// Tree traversal 
		if (str[i] == '0') {
			node = node->Right;
		}
		else if(str[i] == '1') {
			node = node->Left;
		}	
		// Character recored, and found within the tree
		if(node->Symbol->Length == 1) {
			tempString += node->Symbol;
			// Sets the traversal node back to the root for next bit sequence 
			node = rootNode;
		}
	}

	return tempString;
}
/*
	POST: decoded string is returned
*/

/*
	Wrapper function for recursive encoding of binary tree
	PRE: 
*/
void BinarySearchTree::generateCodes() {
	CodeStore = gcnew Dictionary<String^, String^>();
	encodedString = "";
	encodeTree(rootNode, "");
}
/*
	POST:
*/

//Private functions
/*
	Encodes tree into into bit representations, stores them in CodeStores
	
	PRE: IsEmpty() Must be called and return false
*/
void BinarySearchTree::encodeTree(Node<int>^ node, String^ code) {
	// Item not found case
	if(node->Symbol->Length == 1) {
		CodeStore->Add(node->Symbol, code);
		encodedString += code;
		// Breaks the current path
		return;
	}
	// Navagates tree and records the path through the tree
	encodeTree(node->Left, code += "1");
	code = code->Substring(0, code->Length - 1);

	encodeTree(node->Right, code += "0"); 	
	code = code->Substring(0, code->Length - 1);
}
/*
	POST: Bit representation and symbol have been stored in CodeStores property in string format 
*/