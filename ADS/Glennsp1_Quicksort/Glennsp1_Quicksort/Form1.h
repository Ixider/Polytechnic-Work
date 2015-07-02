#pragma once

#include "Manager.h"

namespace Glennsp1_Quicksort {

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
	private: System::Windows::Forms::ListBox^  sortedLB;
	protected: 
	private: System::Windows::Forms::ListBox^  unsortedLB;
	private: System::Windows::Forms::Button^  pop;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  button1;

		// User defined
		Manager^ manager;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sortedLB = (gcnew System::Windows::Forms::ListBox());
			this->unsortedLB = (gcnew System::Windows::Forms::ListBox());
			this->pop = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sortedLB
			// 
			this->sortedLB->FormattingEnabled = true;
			this->sortedLB->Location = System::Drawing::Point(138, 54);
			this->sortedLB->Name = L"sortedLB";
			this->sortedLB->Size = System::Drawing::Size(120, 446);
			this->sortedLB->TabIndex = 0;
			// 
			// unsortedLB
			// 
			this->unsortedLB->FormattingEnabled = true;
			this->unsortedLB->Location = System::Drawing::Point(12, 54);
			this->unsortedLB->Name = L"unsortedLB";
			this->unsortedLB->Size = System::Drawing::Size(120, 446);
			this->unsortedLB->TabIndex = 1;
			// 
			// pop
			// 
			this->pop->Location = System::Drawing::Point(12, 25);
			this->pop->Name = L"pop";
			this->pop->Size = System::Drawing::Size(120, 23);
			this->pop->TabIndex = 2;
			this->pop->Text = L"Run";
			this->pop->UseVisualStyleBackColor = true;
			this->pop->Click += gcnew System::EventHandler(this, &Form1::pop_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(139, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"How it works";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(269, 509);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pop);
			this->Controls->Add(this->unsortedLB);
			this->Controls->Add(this->sortedLB);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pop_Click(System::Object^  sender, System::EventArgs^  e) {
				 manager->run();
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 manager = gcnew Manager(unsortedLB, sortedLB);
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 String^ desc = "Quicksort works by repeatedly dividing a collection of numbers into smaller pieces or partitions, to divide a partition " +
				 "you first pick a value near the middle called  a piviot, then finding and moving smaller values to the left of the piviot and greater values to the right.";
			 MessageBox::Show(desc, "How?", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		 }
};
}

