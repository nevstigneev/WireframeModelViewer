#pragma once

#include "Dispatcher.h"
#include "PBViewport.h"

namespace oop04 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Dispatcher *disp;
	bool is_scene_loaded = false;
	bool is_initialized = false;
	bool is_mouse_left_clicked = false;
	bool is_mouse_right_clicked = false;
	int mouse_position_x;
	int mouse_position_y;

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  Image;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpenFile;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		//Dispatcher disp;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Image = (gcnew System::Windows::Forms::PictureBox());
			this->dlgOpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Image))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->openToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// Image
			// 
			this->Image->BackColor = System::Drawing::SystemColors::Window;
			this->Image->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Image->Location = System::Drawing::Point(0, 24);
			this->Image->Name = L"Image";
			this->Image->Size = System::Drawing::Size(684, 474);
			this->Image->TabIndex = 1;
			this->Image->TabStop = false;
			this->Image->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Image_Paint);
			this->Image->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Image_MouseDown);
			this->Image->MouseEnter += gcnew System::EventHandler(this, &Form1::Image_MouseEnter);
			this->Image->MouseLeave += gcnew System::EventHandler(this, &Form1::Image_MouseLeave);
			this->Image->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Image_MouseMove);
			this->Image->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Image_MouseUp);
			this->Image->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Image_MouseWheel);
			this->Image->Resize += gcnew System::EventHandler(this, &Form1::Image_Resize);
			// 
			// dlgOpenFile
			// 
			this->dlgOpenFile->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 498);
			this->Controls->Add(this->Image);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"WireframeModelViewer";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Image))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close();
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 dlgOpenFile = gcnew System::Windows::Forms::OpenFileDialog();
				 dlgOpenFile->ShowDialog();
				 String^ str = dlgOpenFile->FileName;
				 IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
				 char* path = (char*)ptr.ToPointer();
				 disp->ClearScene();
				 if (disp->LoadScene(path))
				 {
					 is_scene_loaded = true;
					 disp->TranslateCamera(0, 0, -3, 0);
					 Image->Invalidate();
				 }
				 else
				 {
					MessageBox::Show("Error. Invalid model.");
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 disp = Dispatcher::Instance();
			 }
	private: System::Void Image_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			 {
				 if (!is_scene_loaded)
				 {
				 	return;
				 }
			     disp->RenderScene(PictureBoxViewport(e->Graphics, Image->Size.Width, Image->Size.Height), 0);
		     }
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			 {
				 delete disp;
			 }
	private: System::Void Image_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				if (e->Button == ::System::Windows::Forms::MouseButtons::Left) 
				{
					 is_mouse_left_clicked = false;
				} 
				else if (e->Button == ::System::Windows::Forms::MouseButtons::Right) 
				{
					 is_mouse_right_clicked = false;
				}
			 }
	private: System::Void Image_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				if (!is_scene_loaded)
				{
					 return;
			    }
				mouse_position_x = e->X;
				mouse_position_y = e->Y;
				if (e->Button == ::System::Windows::Forms::MouseButtons::Left)
				{
				    is_mouse_left_clicked = true;
				}
				else if (e->Button == ::System::Windows::Forms::MouseButtons::Right)
				{
				    is_mouse_right_clicked = true;
				}
			 }
	private: System::Void Image_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			 {
				if (!is_scene_loaded)
				{
					 return;
				}
				if (is_mouse_right_clicked)
				{
					 int offset_x = e->X - mouse_position_x;
					 int offset_y = e->Y - mouse_position_y;
					 const double factor = 100.0;
					 double dx = offset_x / factor;
					 double dy = -offset_y / factor;
					 double dz = 0.0;
					 disp->TranslateCamera(dx, dy, dz, 0);
					 Image->Invalidate();
				}
				else if (is_mouse_left_clicked)
				{
					 int offset_x = e->X - mouse_position_x;
					 int offset_y = e->Y - mouse_position_y;
					 double axis_x = -offset_y;
					 double axis_y = -offset_x;
					 double axis_z = 0.0;
					 double angle = (1.0 * Math::PI) / 180.0;
					 disp->RotateModel(axis_x, axis_y, axis_z, angle, 0);
					 Image->Invalidate();
				}
				mouse_position_x = e->X;
				mouse_position_y = e->Y;
			 }
	private: System::Void Image_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
			 {
				if (!is_scene_loaded)
				{
					 return;
				}
				is_mouse_left_clicked = false;
				is_mouse_right_clicked = false;
			 }
			 System::Void Image_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
			 {
			 	 const double factor = 1.1;
			 	 if (e->Delta > 0)
			 	 {
			 		 disp->ScaleModel(factor, 0);
			 		 Image->Invalidate();
			 	 }
			 	 else if (e->Delta < 0)
			 	 {
			 		 disp->ScaleModel(1.0 / factor, 0);
			 		 Image->Invalidate();
			 	 }
			 }
	private: System::Void Image_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
			 {
				if (!is_scene_loaded)
				{
					 return;
				}
				Image->Focus();
				mouse_position_x = 0;
				mouse_position_y = 0;
			 }
private: System::Void Image_Resize(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Image->Invalidate();
		 }
};
}