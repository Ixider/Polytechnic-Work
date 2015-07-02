#pragma once
#include "Manager.h"

namespace Fractals {

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
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Graphics^ gfx;
		Bitmap^ osBmp;
		Graphics^ mainCanvas;
		Bitmap^ bmp;

		Manager^ manager;

	private: System::Windows::Forms::Panel^  display;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button5;





			

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->display = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// display
			// 
			this->display->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->display->Location = System::Drawing::Point(12, 12);
			this->display->Name = L"display";
			this->display->Size = System::Drawing::Size(805, 805);
			this->display->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(823, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Sierpinski Triangle";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(823, 79);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Sierpinski Carpet";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(823, 109);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Snowflake";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(823, 139);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(137, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Tree";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(823, 168);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(137, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Circles";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(824, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(136, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(823, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Depth";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 840);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->display);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 bmp = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
				 gfx = Graphics::FromImage(bmp);
				 mainCanvas = display->CreateGraphics();
				 
				 manager = gcnew Manager(gfx);
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 int mode = -1;
				 if(sender == button1) {
					 mode = FTYPE::TRIANGLE;
				 } if (sender == button2) {
					 mode = FTYPE::CARPET;
				 } if (sender == button3) {
					 mode = FTYPE::SNOWFLAKE;
				 } if (sender == button4) {
					 mode = FTYPE::TREE;
				 } if (sender == button5) {
					 mode = FTYPE::CIRCLE;
				 }

				manager->Input(mode, textBox1->Text);
				mainCanvas->DrawImage(bmp, 0 , 0, ClientRectangle.Width, ClientRectangle.Height);
			 }

};
}

