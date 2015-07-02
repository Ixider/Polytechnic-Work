#pragma once
#include "TileMap.h"

namespace IsometricGameGrid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::Timer^  GameTimer;
	protected:
	private: System::ComponentModel::IContainer^  components;


	private: 
		TileMap^ tileMap;
		Graphics^ mainCanvas;
		Graphics^ offScreenCanvas;
		Bitmap^ backGroundImage;
		Bitmap^ offScreenBitmap;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->GameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// GameTimer
			// 
			this->GameTimer->Enabled = true;
			this->GameTimer->Tick += gcnew System::EventHandler(this, &Form1::GameTimer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 891);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}


#pragma endregion

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			offScreenBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
			offScreenCanvas = Graphics::FromImage(offScreenBitmap);

			mainCanvas = CreateGraphics();
			tileMap = gcnew TileMap(offScreenCanvas);

		}

		private: System::Void GameTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			
			tileMap->drawMap();
			mainCanvas->DrawImage(offScreenBitmap, 0, 0, ClientRectangle.Width, ClientRectangle.Height);

		}

	};
}

