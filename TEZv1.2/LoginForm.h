#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\opencv_modules.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <sql.h>
#include <sys\timeb.h>
#include "MainForm.h"
//#include "FullscreenForm.h"
#include "RegistrationForm.h"
namespace TEZv12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace cv;
	using namespace std;
	using namespace cv::face;


	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		//Veritabaný ile kod arasýnda baglantý 
		SqlConnection^ connection = gcnew SqlConnection();
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  automaticRB;
	protected:
	private: System::Windows::Forms::RadioButton^  manualRB;
	private: System::Windows::Forms::Button^  autoBTN;

	private: System::Windows::Forms::TextBox^  usernameTB;
	private: System::Windows::Forms::TextBox^  passTB;
	private: System::Windows::Forms::TableLayoutPanel^  manualPanel;
	private: System::Windows::Forms::Button^  manualBTN;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::LinkLabel^  newuserLL;

	private: System::ComponentModel::IContainer^  components;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->automaticRB = (gcnew System::Windows::Forms::RadioButton());
			this->manualRB = (gcnew System::Windows::Forms::RadioButton());
			this->autoBTN = (gcnew System::Windows::Forms::Button());
			this->usernameTB = (gcnew System::Windows::Forms::TextBox());
			this->passTB = (gcnew System::Windows::Forms::TextBox());
			this->manualPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->manualBTN = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->newuserLL = (gcnew System::Windows::Forms::LinkLabel());
			this->manualPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// automaticRB
			// 
			this->automaticRB->AutoSize = true;
			this->automaticRB->Checked = true;
			this->automaticRB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->automaticRB->Location = System::Drawing::Point(12, 152);
			this->automaticRB->Name = L"automaticRB";
			this->automaticRB->Size = System::Drawing::Size(89, 20);
			this->automaticRB->TabIndex = 0;
			this->automaticRB->TabStop = true;
			this->automaticRB->Text = L"Auto Login";
			this->automaticRB->UseVisualStyleBackColor = true;
			this->automaticRB->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::automaticRB_CheckedChanged);
			// 
			// manualRB
			// 
			this->manualRB->AutoSize = true;
			this->manualRB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->manualRB->Location = System::Drawing::Point(12, 239);
			this->manualRB->Name = L"manualRB";
			this->manualRB->Size = System::Drawing::Size(106, 20);
			this->manualRB->TabIndex = 1;
			this->manualRB->Text = L"Manual Login";
			this->manualRB->UseVisualStyleBackColor = true;
			this->manualRB->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::manualRB_CheckedChanged);
			// 
			// autoBTN
			// 
			this->autoBTN->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->autoBTN->Location = System::Drawing::Point(12, 179);
			this->autoBTN->Name = L"autoBTN";
			this->autoBTN->Size = System::Drawing::Size(89, 29);
			this->autoBTN->TabIndex = 2;
			this->autoBTN->Text = L"Log In";
			this->autoBTN->UseVisualStyleBackColor = true;
			this->autoBTN->Click += gcnew System::EventHandler(this, &LoginForm::autoBTN_Click);
			// 
			// usernameTB
			// 
			this->usernameTB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->usernameTB->Location = System::Drawing::Point(131, 5);
			this->usernameTB->MaxLength = 16;
			this->usernameTB->Name = L"usernameTB";
			this->usernameTB->Size = System::Drawing::Size(122, 20);
			this->usernameTB->TabIndex = 3;
			// 
			// passTB
			// 
			this->passTB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->passTB->Location = System::Drawing::Point(131, 35);
			this->passTB->MaxLength = 16;
			this->passTB->Name = L"passTB";
			this->passTB->Size = System::Drawing::Size(122, 20);
			this->passTB->TabIndex = 4;
			this->passTB->UseSystemPasswordChar = true;
			// 
			// manualPanel
			// 
			this->manualPanel->ColumnCount = 2;
			this->manualPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->manualPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->manualPanel->Controls->Add(this->manualBTN, 1, 2);
			this->manualPanel->Controls->Add(this->label2, 0, 1);
			this->manualPanel->Controls->Add(this->passTB, 1, 1);
			this->manualPanel->Controls->Add(this->label1, 0, 0);
			this->manualPanel->Controls->Add(this->usernameTB, 1, 0);
			this->manualPanel->Enabled = false;
			this->manualPanel->Location = System::Drawing::Point(12, 265);
			this->manualPanel->Name = L"manualPanel";
			this->manualPanel->RowCount = 3;
			this->manualPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->manualPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->manualPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->manualPanel->Size = System::Drawing::Size(256, 100);
			this->manualPanel->TabIndex = 5;
			// 
			// manualBTN
			// 
			this->manualBTN->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->manualBTN->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->manualBTN->Location = System::Drawing::Point(164, 65);
			this->manualBTN->Name = L"manualBTN";
			this->manualBTN->Size = System::Drawing::Size(89, 29);
			this->manualBTN->TabIndex = 6;
			this->manualBTN->Text = L"Log In";
			this->manualBTN->UseVisualStyleBackColor = true;
			this->manualBTN->Click += gcnew System::EventHandler(this, &LoginForm::manualBTN_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(51, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Password :";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(48, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Username :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->ForeColor = System::Drawing::Color::Gray;
			this->label3->Location = System::Drawing::Point(36, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(228, 42);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Log in Page ";
			// 
			// newuserLL
			// 
			this->newuserLL->AutoSize = true;
			this->newuserLL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->newuserLL->Location = System::Drawing::Point(181, 379);
			this->newuserLL->Name = L"newuserLL";
			this->newuserLL->Size = System::Drawing::Size(87, 20);
			this->newuserLL->TabIndex = 7;
			this->newuserLL->TabStop = true;
			this->newuserLL->Text = L"New User\?";
			this->newuserLL->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel1_LinkClicked);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(277, 409);
			this->Controls->Add(this->newuserLL);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->manualPanel);
			this->Controls->Add(this->autoBTN);
			this->Controls->Add(this->manualRB);
			this->Controls->Add(this->automaticRB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->manualPanel->ResumeLayout(false);
			this->manualPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void automaticRB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		autoBTN->Enabled = true;
		manualPanel->Enabled = false;
	}
private: System::Void manualRB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
	autoBTN->Enabled = false;
	manualPanel->Enabled = true;
}
private: System::Void autoBTN_Click(System::Object^  sender, System::EventArgs^  e) 
{
	/*
	cv::Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();

	model->load("C:\\Users\\Rabia\\Desktop\\rabia\\Tez\\yaml\\LBPHface.yml");


	VideoCapture capVideo;
	string faceCascadeName = "haarcascade_frontalface_alt.xml";
	CascadeClassifier faceCascade;
	capVideo.open(0);

	if (!capVideo.isOpened())
		return;
	faceCascade.load(faceCascadeName);

	//double start, dur;

	Mat grayFrame;
	Mat actualFrame;
	namedWindow("Actual Frame", 1);
	vector<Rect> face;
	
	while (true)
	{
		capVideo >> actualFrame;
		//process(actualFrame);
		flip(actualFrame, actualFrame, 1);
		cvtColor(actualFrame, grayFrame, CV_BGR2GRAY);
		equalizeHist(grayFrame, grayFrame);

		//detection face
		faceCascade.detectMultiScale( grayFrame,face, 1.25, 1, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(60, 60));
		if(face.size()>0)
		{
			//draw rectangle for detected face
			rectangle(actualFrame, face[0], CV_RGB(0, 255, 0), 1, 8, 0);
			imshow("Actual Frame", actualFrame);
			
			Mat faceROI = grayFrame(face[0]);

			//recognizing what faces detected
			int label = -1; 
			double confidence = 0;
			model->predict(faceROI, label, confidence);

			
			if (confidence > 50)	//Prediction is greater than %50 go to MainForm (System will open)
			{
				TEZv12::MainForm^ mf = gcnew MainForm;
				mf->ShowDialog();
				this->Close();
			}
			else    //Prediction is smaller than % 50, not open system and show message to user
			{
				MessageBox::Show("Registration not found!, You cannot use the system.", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

		if (waitKey(10) == 27) break;

		actualFrame.release();
		grayFrame.release();
		
	}*/
}
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	TEZv12::RegistrationForm^ rf = gcnew RegistrationForm;
	rf->ShowDialog();
}
	private: System::Void manualBTN_Click(System::Object^  sender, System::EventArgs^  e)
	{
		

		//Textbox bos olmamasi sagliyor if kontrol
		if ((usernameTB->Text == "") || (passTB->Text == ""))
		{
			MessageBox::Show("Lutfen Kullanici Adi ve sifrenizi giriniz!!!");
		}
		else
		{			
			connection->ConnectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Rabia\\Documents\\profile.mdf;Integrated Security=True;Connect Timeout=30";
			
			if (connection->State == ConnectionState::Closed)
				connection->Open();

			SqlCommand^ cmd = gcnew SqlCommand("SELECT COUNT (*) FROM PROFILE WHERE username=@ID and Password=@Sifre", connection);
			//Kullaýcýdan alýnan verilerle veritabanýndaki verileri karsilastirma
			
			dataAdapter->SelectCommand = cmd;
			//SQL injection engelemek icin kullanilan kod
			dataAdapter->SelectCommand->Parameters->AddWithValue("@ID", usernameTB->Text);
			dataAdapter->SelectCommand->Parameters->AddWithValue("@Sifre", passTB->Text);

			//Veri tablosu olusturma
			DataTable^ table = gcnew DataTable();
			if (dataAdapter->Fill(table) > 0)
			{
				dataAdapter->Fill(table);
			}
			else
			{
				MessageBox::Show("Kullanýcý sistemde tanýmlý deðil.");
			}

			if (table->Rows->Count>0)
			{				
				MainForm^ mf = gcnew MainForm();				
				mf->ShowDialog();
				this->Close();
			}
			else
			{
				MessageBox::Show("Kullanici Adinizi ya da Sifrenizi hatali girdiniz");
			}
		}
		connection->Close();
	}
};
}
