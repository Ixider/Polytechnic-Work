#pragma once
#include "Manager.h"

namespace HuffmanEncoding {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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

	private:
		Manager^ manager;
		Graphics^ canvas;

	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  decodeInput;



	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  decodedDisplay;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  eSize;

	private: System::Windows::Forms::Label^  oSize;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->eSize = (gcnew System::Windows::Forms::Label());
			this->oSize = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->decodeInput = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->decodedDisplay = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Read File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 29);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(53, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(11, 55);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(53, 20);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(11, 81);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(53, 20);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 107);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(53, 20);
			this->textBox5->TabIndex = 5;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(11, 133);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(53, 20);
			this->textBox6->TabIndex = 6;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(12, 159);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(53, 20);
			this->textBox7->TabIndex = 7;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(12, 185);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(53, 20);
			this->textBox8->TabIndex = 8;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(12, 211);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(53, 20);
			this->textBox9->TabIndex = 9;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(70, 29);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(51, 20);
			this->textBox10->TabIndex = 17;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(71, 55);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(51, 20);
			this->textBox11->TabIndex = 16;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(70, 81);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(51, 20);
			this->textBox12->TabIndex = 15;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(70, 107);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(51, 20);
			this->textBox13->TabIndex = 14;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(70, 133);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(51, 20);
			this->textBox14->TabIndex = 13;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(70, 159);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(51, 20);
			this->textBox15->TabIndex = 12;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(71, 185);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(51, 20);
			this->textBox16->TabIndex = 11;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(70, 211);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(51, 20);
			this->textBox17->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Symbol";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(68, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Frequency";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 238);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Submit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox17);
			this->panel1->Controls->Add(this->textBox10);
			this->panel1->Controls->Add(this->textBox15);
			this->panel1->Controls->Add(this->textBox12);
			this->panel1->Controls->Add(this->textBox11);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->textBox13);
			this->panel1->Controls->Add(this->textBox8);
			this->panel1->Controls->Add(this->textBox14);
			this->panel1->Controls->Add(this->textBox9);
			this->panel1->Controls->Add(this->textBox16);
			this->panel1->Location = System::Drawing::Point(16, 41);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(133, 276);
			this->panel1->TabIndex = 21;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(3, 16);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(125, 212);
			this->listBox1->TabIndex = 22;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->decodeInput);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Location = System::Drawing::Point(16, 324);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(133, 441);
			this->panel2->TabIndex = 23;
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->eSize);
			this->panel5->Controls->Add(this->oSize);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Location = System::Drawing::Point(3, 234);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(125, 111);
			this->panel5->TabIndex = 0;
			// 
			// eSize
			// 
			this->eSize->AutoSize = true;
			this->eSize->Font = (gcnew System::Drawing::Font(L"Moire", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eSize->Location = System::Drawing::Point(25, 68);
			this->eSize->Name = L"eSize";
			this->eSize->Size = System::Drawing::Size(36, 18);
			this->eSize->TabIndex = 3;
			this->eSize->Text = L"       ";
			// 
			// oSize
			// 
			this->oSize->AutoSize = true;
			this->oSize->Font = (gcnew System::Drawing::Font(L"Moire", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->oSize->Location = System::Drawing::Point(25, 27);
			this->oSize->Name = L"oSize";
			this->oSize->Size = System::Drawing::Size(40, 18);
			this->oSize->TabIndex = 2;
			this->oSize->Text = L"        ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Encoded Bit Size";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Ascii Bit Size";
			// 
			// decodeInput
			// 
			this->decodeInput->Location = System::Drawing::Point(3, 387);
			this->decodeInput->Name = L"decodeInput";
			this->decodeInput->Size = System::Drawing::Size(125, 20);
			this->decodeInput->TabIndex = 25;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->decodedDisplay);
			this->panel3->Location = System::Drawing::Point(3, 351);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(125, 30);
			this->panel3->TabIndex = 24;
			// 
			// decodedDisplay
			// 
			this->decodedDisplay->AutoSize = true;
			this->decodedDisplay->Location = System::Drawing::Point(8, 9);
			this->decodedDisplay->Name = L"decodedDisplay";
			this->decodedDisplay->Size = System::Drawing::Size(0, 13);
			this->decodedDisplay->TabIndex = 24;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 413);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 23);
			this->button3->TabIndex = 23;
			this->button3->Text = L"decode";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Codes";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Location = System::Drawing::Point(155, 12);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1000, 750);
			this->panel4->TabIndex = 24;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1162, 770);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}


#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 canvas = panel4->CreateGraphics();
				 manager = gcnew Manager(listBox1, decodedDisplay, oSize, eSize, canvas);
				 openFileDialog1->Filter = "Text file (*.txt)|*.txt";
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					 Stream^ stream;
					 if ((stream = openFileDialog1->OpenFile()) != nullptr) {
						 StreamReader^ reader = gcnew StreamReader(stream);
						 String^ str = reader->ReadToEnd();				
						 manager->takeInput(str);
						 reader->Close();
						 stream->Close();
					}
				 }
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<String^>^ inputs = { 
											textBox2->Text,
											textBox3->Text,
											textBox4->Text,
											textBox5->Text,
											textBox6->Text,
											textBox7->Text,
											textBox8->Text,
											textBox9->Text,

											textBox10->Text,
											textBox11->Text,
											textBox12->Text,
											textBox13->Text,
											textBox14->Text,
											textBox15->Text,
											textBox16->Text,
											textBox17->Text
										  };
				
				 manager->takeInput(inputs);
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 manager->decodeString(decodeInput->Text);
		 }
};
}

