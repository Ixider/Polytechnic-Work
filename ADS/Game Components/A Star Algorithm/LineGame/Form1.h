#pragma once

/*
	AUTHOR:			Sam Glenn
	LastModified:	15/03/14

	TODO:
		Add the user input for making nodes unwalkable
		Add the user input for selecting start and end nodes
 */

#include "constants.h"
#include "SimManager.h"
#include "TileMap.h"
#include "AStar.h"
#include "input.h"

namespace LineGame {

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

		AStar^ aStar;
		TileMap^ tileMap;
		SimManager^ simManager;

		//Inputs from user
		InputManager^ inputManager;

		//Display stuff
		//draws offScreenCanvas to the screen
		Graphics^ mainCanvas;		
		// class's draw on this pointer
		Graphics^ offScreenCanvas;

		Bitmap^ backGroundImage;
		Bitmap^ offScreenBitmap;


	private: System::Windows::Forms::Button^  startPointButton;
	private: System::Windows::Forms::Button^  endPointButton;
	private: System::Windows::Forms::Button^  wallButton;
	private: System::Windows::Forms::Button^  runButton;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Button^  clearButton;

	private: System::Windows::Forms::GroupBox^  groupBox1;

			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->startPointButton = (gcnew System::Windows::Forms::Button());
			this->endPointButton = (gcnew System::Windows::Forms::Button());
			this->wallButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(830, 152);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(142, 23);
			this->runButton->TabIndex = 0;
			this->runButton->Text = L"Start";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &Form1::runButton_Click);
			// 
			// startPointButton
			// 
			this->startPointButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->startPointButton->Location = System::Drawing::Point(20, 32);
			this->startPointButton->Name = L"startPointButton";
			this->startPointButton->Size = System::Drawing::Size(106, 23);
			this->startPointButton->TabIndex = 1;
			this->startPointButton->Text = L"START POINT";
			this->startPointButton->UseVisualStyleBackColor = true;
			this->startPointButton->Click += gcnew System::EventHandler(this, &Form1::startPointButton_Click);
			// 
			// endPointButton
			// 
			this->endPointButton->Location = System::Drawing::Point(20, 61);
			this->endPointButton->Name = L"endPointButton";
			this->endPointButton->Size = System::Drawing::Size(106, 23);
			this->endPointButton->TabIndex = 2;
			this->endPointButton->Text = L"END POINT";
			this->endPointButton->UseVisualStyleBackColor = true;
			this->endPointButton->Click += gcnew System::EventHandler(this, &Form1::startPointButton_Click);
			// 
			// wallButton
			// 
			this->wallButton->Location = System::Drawing::Point(20, 90);
			this->wallButton->Name = L"wallButton";
			this->wallButton->Size = System::Drawing::Size(106, 23);
			this->wallButton->TabIndex = 3;
			this->wallButton->Text = L"WALL";
			this->wallButton->UseVisualStyleBackColor = true;
			this->wallButton->Click += gcnew System::EventHandler(this, &Form1::startPointButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->endPointButton);
			this->groupBox1->Controls->Add(this->wallButton);
			this->groupBox1->Controls->Add(this->startPointButton);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(830, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(142, 134);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Input Modes";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(830, 181);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(142, 23);
			this->clearButton->TabIndex = 5;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 641);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->runButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		{ 
			offScreenBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
			offScreenCanvas = Graphics::FromImage(offScreenBitmap);

			tileMap = gcnew TileMap(offScreenCanvas);
			mainCanvas = CreateGraphics();

			inputManager = gcnew InputManager();
			simManager = gcnew SimManager(CreateGraphics(), offScreenCanvas, inputManager);
		}

		private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			inputManager->takeInput(e->Location.X, e->Location.Y);
			simManager->display();
		}

		private: System::Void startPointButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (sender->Equals(startPointButton))
			{
				inputManager->setMode((int)constants::InputMode::START);
			}
			else if (sender->Equals(endPointButton))
			{
				inputManager->setMode((int)constants::InputMode::END);
			}
			else if (sender->Equals(wallButton))
			{
				inputManager->setMode((int)constants::InputMode::WALL);
			}
		}

		private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			simManager->findPath();
		}

		private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			simManager->display();
			mainCanvas->DrawImage(offScreenBitmap, 0 , 0, ClientRectangle.Width, ClientRectangle.Height);	
		}

	private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
			simManager->reset();
	}
};
}

