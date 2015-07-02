#pragma once
#include "BinaryTree.h"
#include "ExpressionTree.h"

namespace SimpleBinaryTreesLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(235, 420);
			this->listBox1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 439);
			this->Controls->Add(this->listBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
			constructExpressionTree1();
			constructExpressionTree2();

		}

		// Build (2*6) + 3 
		private: void constructExpressionTree1() {
			ExpressionTree^ t1 = gcnew ExpressionTree("*");
			t1->makeLeftChildNode("2");
			t1->makeRightChildNode("6");

			ExpressionTree^ t2 = gcnew ExpressionTree("+");
			t2->addLeftSubTree(t1);
			t2->makeRightChildNode("3");

			t2->postOrder(t2->getRootNode(), listBox1);
			int result = t2->parseExpressionTree(t2->getRootNode());

			String^ postFix = t2->convertToPostFix(t2->getRootNode());
		}

		// Build 2 * (6+3)
		private: void constructExpressionTree2() {
			ExpressionTree^ t1 = gcnew ExpressionTree("+");
			t1->makeLeftChildNode("3");
			t1->makeRightChildNode("6");

			ExpressionTree^ t2 = gcnew ExpressionTree("*");
			t2->addLeftSubTree(t1);
			t2->makeRightChildNode("2");

			t2->postOrder(t2->getRootNode(), listBox1);
			int result = t2->parseExpressionTree(t2->getRootNode());

			String^ postFix = t2->convertToPostFix(t2->getRootNode());

		}

		//Displays the integer binary tree from the slides displaying pre post and in orders.
		private: void displayBinaryTreeContents(){
			BinaryTree<int>^ intTree = ConstructExampleTree();
			listBox1->Items->Add("Example Tree from slides");
			listBox1->Items->Add(" ");

			listBox1->Items->Add("Pre Order");
			intTree->preOrder(intTree->getRootNode(), listBox1);

			listBox1->Items->Add(" ");
			
			listBox1->Items->Add("In Order");
			intTree->inOrder(intTree->getRootNode(), listBox1);

			listBox1->Items->Add(" ");

			listBox1->Items->Add("Post Order");
			intTree->postOrder(intTree->getRootNode(), listBox1);
		}

		private: BinaryTree<int>^ ConstructExampleTree() {
			BinaryTree<int>^ bt1 = gcnew BinaryTree<int>(6);
			bt1->makeLeftChildNode(7);

			BinaryTree<int>^ bt2 = gcnew BinaryTree<int>(5);
			bt2->addLeftSubTree(bt1);

			BinaryTree<int>^ bt3 = gcnew BinaryTree<int>(2);
			bt3->makeLeftChildNode(4);
			bt3->addRightSubTree(bt2);

			BinaryTree<int>^ topTree = gcnew BinaryTree<int>(1);
			topTree->addLeftSubTree(bt3);
			topTree->makeRightChildNode(3);				

			return topTree;
		}

	};
}

