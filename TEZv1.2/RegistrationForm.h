#pragma once
#include <Windows.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2\video\video.hpp>
#using <System.Data.dll>
#include <sql.h>
#include "FullscreenForm.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\face.hpp>
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
	/// <summary>
	/// Summary for RegistrationForm
	/// </summary>
    public ref class RegistrationForm : public System::Windows::Forms::Form
    {
    public:
        RegistrationForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
		SqlConnection^ connection = gcnew SqlConnection();
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RegistrationForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^  signupBtn;
    protected:

    private: System::Windows::Forms::GroupBox^  uiGB;
    private: System::Windows::Forms::Label^  label7;
    private: System::Windows::Forms::RadioButton^  femaleRB;
    private: System::Windows::Forms::RadioButton^  maleRB;
    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::TextBox^  passwordSecTB;
    private: System::Windows::Forms::TextBox^  passwordTB;
    private: System::Windows::Forms::TextBox^  emailTB;

    private: System::Windows::Forms::TextBox^  surnameTB;
    private: System::Windows::Forms::TextBox^  nameTB;
    private: System::Windows::Forms::GroupBox^  picGB;



    private: System::Windows::Forms::PictureBox^  profilePB;

    private: System::Windows::Forms::Button^  profileBtn;



    private: System::Windows::Forms::Label^  label8;
    private: System::Windows::Forms::TextBox^  usernameTB;

    private: System::Windows::Forms::ComboBox^  ageCB;
    private: System::Windows::Forms::Label^  label9;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RegistrationForm::typeid));
			this->signupBtn = (gcnew System::Windows::Forms::Button());
			this->uiGB = (gcnew System::Windows::Forms::GroupBox());
			this->ageCB = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->usernameTB = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->femaleRB = (gcnew System::Windows::Forms::RadioButton());
			this->maleRB = (gcnew System::Windows::Forms::RadioButton());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->passwordSecTB = (gcnew System::Windows::Forms::TextBox());
			this->passwordTB = (gcnew System::Windows::Forms::TextBox());
			this->emailTB = (gcnew System::Windows::Forms::TextBox());
			this->surnameTB = (gcnew System::Windows::Forms::TextBox());
			this->nameTB = (gcnew System::Windows::Forms::TextBox());
			this->picGB = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->profilePB = (gcnew System::Windows::Forms::PictureBox());
			this->profileBtn = (gcnew System::Windows::Forms::Button());
			this->uiGB->SuspendLayout();
			this->picGB->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePB))->BeginInit();
			this->SuspendLayout();
			// 
			// signupBtn
			// 
			this->signupBtn->BackColor = System::Drawing::Color::Transparent;
			this->signupBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signupBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->signupBtn->ForeColor = System::Drawing::Color::Red;
			this->signupBtn->Location = System::Drawing::Point(664, 357);
			this->signupBtn->Name = L"signupBtn";
			this->signupBtn->Size = System::Drawing::Size(115, 47);
			this->signupBtn->TabIndex = 12;
			this->signupBtn->Text = L"Sign Up";
			this->signupBtn->UseVisualStyleBackColor = false;
			this->signupBtn->Click += gcnew System::EventHandler(this, &RegistrationForm::signupBtn_Click);
			// 
			// uiGB
			// 
			this->uiGB->BackColor = System::Drawing::Color::Transparent;
			this->uiGB->Controls->Add(this->ageCB);
			this->uiGB->Controls->Add(this->label8);
			this->uiGB->Controls->Add(this->usernameTB);
			this->uiGB->Controls->Add(this->label7);
			this->uiGB->Controls->Add(this->femaleRB);
			this->uiGB->Controls->Add(this->maleRB);
			this->uiGB->Controls->Add(this->label6);
			this->uiGB->Controls->Add(this->label5);
			this->uiGB->Controls->Add(this->label4);
			this->uiGB->Controls->Add(this->label3);
			this->uiGB->Controls->Add(this->label2);
			this->uiGB->Controls->Add(this->label1);
			this->uiGB->Controls->Add(this->passwordSecTB);
			this->uiGB->Controls->Add(this->passwordTB);
			this->uiGB->Controls->Add(this->emailTB);
			this->uiGB->Controls->Add(this->surnameTB);
			this->uiGB->Controls->Add(this->nameTB);
			this->uiGB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->uiGB->Location = System::Drawing::Point(43, 43);
			this->uiGB->Name = L"uiGB";
			this->uiGB->Size = System::Drawing::Size(320, 267);
			this->uiGB->TabIndex = 19;
			this->uiGB->TabStop = false;
			this->uiGB->Text = L"User Information";
			// 
			// ageCB
			// 
			this->ageCB->FormattingEnabled = true;
			this->ageCB->Location = System::Drawing::Point(154, 81);
			this->ageCB->MaxLength = 2;
			this->ageCB->Name = L"ageCB";
			this->ageCB->Size = System::Drawing::Size(130, 24);
			this->ageCB->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(49, 190);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 16);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Username :";
			// 
			// usernameTB
			// 
			this->usernameTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->usernameTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->usernameTB->Location = System::Drawing::Point(154, 187);
			this->usernameTB->MaxLength = 11;
			this->usernameTB->Name = L"usernameTB";
			this->usernameTB->Size = System::Drawing::Size(130, 22);
			this->usernameTB->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(89, 219);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 16);
			this->label7->TabIndex = 27;
			this->label7->Text = L"Sex :";
			// 
			// femaleRB
			// 
			this->femaleRB->AutoSize = true;
			this->femaleRB->BackColor = System::Drawing::Color::Transparent;
			this->femaleRB->Checked = true;
			this->femaleRB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->femaleRB->ForeColor = System::Drawing::Color::Black;
			this->femaleRB->Location = System::Drawing::Point(208, 218);
			this->femaleRB->Name = L"femaleRB";
			this->femaleRB->Size = System::Drawing::Size(59, 17);
			this->femaleRB->TabIndex = 8;
			this->femaleRB->TabStop = true;
			this->femaleRB->Text = L"Female";
			this->femaleRB->UseVisualStyleBackColor = false;
			// 
			// maleRB
			// 
			this->maleRB->AutoSize = true;
			this->maleRB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->maleRB->ForeColor = System::Drawing::Color::Red;
			this->maleRB->Location = System::Drawing::Point(154, 219);
			this->maleRB->Name = L"maleRB";
			this->maleRB->Size = System::Drawing::Size(48, 17);
			this->maleRB->TabIndex = 7;
			this->maleRB->Text = L"Male";
			this->maleRB->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(11, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 16);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Password Check :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(52, 138);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Password :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(74, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 16);
			this->label4->TabIndex = 22;
			this->label4->Text = L"E-mail :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(87, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 16);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Age :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(58, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 16);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Surname :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(75, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Name :";
			// 
			// passwordSecTB
			// 
			this->passwordSecTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->passwordSecTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->passwordSecTB->Location = System::Drawing::Point(154, 162);
			this->passwordSecTB->MaxLength = 16;
			this->passwordSecTB->Name = L"passwordSecTB";
			this->passwordSecTB->Size = System::Drawing::Size(130, 22);
			this->passwordSecTB->TabIndex = 5;
			this->passwordSecTB->UseSystemPasswordChar = true;
			// 
			// passwordTB
			// 
			this->passwordTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->passwordTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->passwordTB->Location = System::Drawing::Point(154, 135);
			this->passwordTB->MaxLength = 16;
			this->passwordTB->Name = L"passwordTB";
			this->passwordTB->Size = System::Drawing::Size(130, 22);
			this->passwordTB->TabIndex = 4;
			this->passwordTB->UseSystemPasswordChar = true;
			// 
			// emailTB
			// 
			this->emailTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->emailTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->emailTB->Location = System::Drawing::Point(154, 108);
			this->emailTB->MaxLength = 50;
			this->emailTB->Name = L"emailTB";
			this->emailTB->Size = System::Drawing::Size(130, 22);
			this->emailTB->TabIndex = 3;
			// 
			// surnameTB
			// 
			this->surnameTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->surnameTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->surnameTB->Location = System::Drawing::Point(154, 54);
			this->surnameTB->MaxLength = 20;
			this->surnameTB->Name = L"surnameTB";
			this->surnameTB->Size = System::Drawing::Size(130, 22);
			this->surnameTB->TabIndex = 1;
			// 
			// nameTB
			// 
			this->nameTB->BackColor = System::Drawing::SystemColors::Window;
			this->nameTB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nameTB->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->nameTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->nameTB->ForeColor = System::Drawing::Color::Black;
			this->nameTB->Location = System::Drawing::Point(154, 27);
			this->nameTB->MaxLength = 20;
			this->nameTB->Name = L"nameTB";
			this->nameTB->Size = System::Drawing::Size(130, 22);
			this->nameTB->TabIndex = 0;
			this->nameTB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RegistrationForm::nameTB_KeyPress);
			// 
			// picGB
			// 
			this->picGB->BackColor = System::Drawing::Color::Transparent;
			this->picGB->Controls->Add(this->label9);
			this->picGB->Controls->Add(this->profilePB);
			this->picGB->Controls->Add(this->profileBtn);
			this->picGB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->picGB->ForeColor = System::Drawing::Color::Red;
			this->picGB->Location = System::Drawing::Point(523, 43);
			this->picGB->Name = L"picGB";
			this->picGB->Size = System::Drawing::Size(321, 181);
			this->picGB->TabIndex = 20;
			this->picGB->TabStop = false;
			this->picGB->Text = L"Picture Information";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(6, 27);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(310, 16);
			this->label9->TabIndex = 25;
			this->label9->Text = L"*Take photo for face Recognition using this button!!!";
			// 
			// profilePB
			// 
			this->profilePB->Location = System::Drawing::Point(128, 46);
			this->profilePB->Name = L"profilePB";
			this->profilePB->Size = System::Drawing::Size(75, 64);
			this->profilePB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->profilePB->TabIndex = 22;
			this->profilePB->TabStop = false;
			// 
			// profileBtn
			// 
			this->profileBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->profileBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->profileBtn->ForeColor = System::Drawing::Color::Red;
			this->profileBtn->Location = System::Drawing::Point(128, 126);
			this->profileBtn->Name = L"profileBtn";
			this->profileBtn->Size = System::Drawing::Size(75, 23);
			this->profileBtn->TabIndex = 10;
			this->profileBtn->Text = L"Profile";
			this->profileBtn->UseVisualStyleBackColor = true;
			this->profileBtn->Click += gcnew System::EventHandler(this, &RegistrationForm::profileBtn_Click);
			// 
			// RegistrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(862, 442);
			this->Controls->Add(this->picGB);
			this->Controls->Add(this->uiGB);
			this->Controls->Add(this->signupBtn);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"RegistrationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegistrationForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegistrationForm::RegistrationForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &RegistrationForm::RegistrationForm_Load);
			this->uiGB->ResumeLayout(false);
			this->uiGB->PerformLayout();
			this->picGB->ResumeLayout(false);
			this->picGB->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePB))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
    private: System::Void signupBtn_Click(System::Object^  sender, System::EventArgs^  e)
    {
        if (nameTB->Text == "" || surnameTB->Text == "" || emailTB->Text == "" ||
            passwordTB->Text == "" || passwordSecTB->Text == "" || usernameTB->Text == "")
        {
            MessageBox::Show("Please Insert necessary information", "Information", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        else
        {
            if (passwordTB->Text == passwordSecTB->Text)
            {
                connection->ConnectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Rabia\\Documents\\profile.mdf;Integrated Security=True;Connect Timeout=30";
                if (connection->State == ConnectionState::Closed)
                    connection->Open();
                //string mySelect = "INSERT INTO PROFILE(username, Name, Surname, Age, Email, Password, Sex, LeftImage, ProfileImage, RightImage) VALUES(@un,@n,@sn,@age,@mail,@pas,@sex,@leftimg,@prof,@rigimg)";
                SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO PROFILE(username, Name, Surname, Age, Email, Password, Sex) VALUES(@un,@n,@sn,@age,@mail,@pass,@sex)", connection);

                cmd->Parameters->AddWithValue("@un", usernameTB->Text);
                cmd->Parameters->AddWithValue("@n", nameTB->Text);
                cmd->Parameters->AddWithValue("@sn", surnameTB->Text);
                cmd->Parameters->AddWithValue("@age", ageCB->Text);
                cmd->Parameters->AddWithValue("@mail", emailTB->Text);
                cmd->Parameters->AddWithValue("@pass", passwordTB->Text);
                if (maleRB->Checked)
                    cmd->Parameters->AddWithValue("@sex", "M");
                else
                    cmd->Parameters->AddWithValue("@sex", "F");
                try
                {
                    cmd->ExecuteNonQuery();
                    if (connection->State == ConnectionState::Open)
                        connection->Close();
                    MessageBox::Show("Profile created", "Sucessful", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                catch (EventHandler^)
                {
                    MessageBox::Show("There is something wrong with Database", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            else
                MessageBox::Show("Please insert the same password in the password security field", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    private: System::Void RegistrationForm_Load(System::Object^  sender, System::EventArgs^  e)
    {
        for (int i = 0; i < 48; i++)
        {
            ageCB->Items->Add(i + 18);
        }
        ageCB->SelectedIndex = 0;
    }
    private: System::Void nameTB_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
    {
        if (!Char::IsLetter(e->KeyChar) && !Char::IsControl(e->KeyChar))
            e->Handled = true;
    }
    private: System::Void RegistrationForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
    {

    }
    private: System::Void profileBtn_Click(System::Object^  sender, System::EventArgs^  e)
    {
        Mat selectedImage;
        vector<int> labels;

       // Mat image;
        
        //imshow("profile", selectedImage);
        int num_components = 10;
        double treshold = 10.0;
        System::String ^ name = usernameTB->Text;
        /* std::string name2 = msclr::interop::marshal_as<std::string>(name);

        // this is for face recognizer to train computer for recognizing faces
       // cv::Ptr<cv::face::FaceRecognizer> model = face::createEigenFaceRecognizer(num_components,treshold);
        
       // double current_treshold = model->getThreshold();
        //model->setThreshold(0.0);
        selectedImage = imread("profile" + name2 + ".png", CV_LOAD_IMAGE_GRAYSCALE);
        //int predict = model->predict(selectedImage);

       // label10->Text = predict.ToString();
        //imshow("profile", selectedImage);
        readPicture(outputFolder, selectedImage, labels, ';');*/
       
        TEZv12::FullscreenForm^ fsf = gcnew FullscreenForm;
        fsf->setName(name);
        fsf->ShowDialog();
        
    }
    private: System::Void leftProfileBtn_Click(System::Object^  sender, System::EventArgs^  e)
    {
        useButtons(1);
    }

    private: System::Void rightProfileBtn_Click(System::Object^  sender, System::EventArgs^  e)
    {
        useButtons(3);
    }

             void useButtons(int button)
             {
                 
                 /* switch (button)
                  {
                  case 1:
                      DrawCVImage(leftPB, selectedImage);
                      break;
                  case 2:
                      DrawCVImage(profilePB, selectedImage);
                      break;
                  case 3:
                      DrawCVImage(rightPB, selectedImage);
                      break;
                  }*/
              }
             /*
              void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
              {
                  System::Drawing::Graphics^ graphics = control->CreateGraphics();
                  System::IntPtr ptr(colorImage.ptr());
                  System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
                  System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
                  graphics->DrawImage(b, rect);
                  delete graphics;
              }
              public:void funData(Mat frame)
              {
                  Mat crop = frame;
              }
              */
             static void readPicture(const string& filename, Mat& images, vector<int>& labels, char separator)
             {
                 std::ifstream file(filename.c_str(), ifstream::in);
                   /*  if (!file)
                     {
                         //string errorMessage = "No valid input file was given please check the given file name";
                         //CV_Error(CV_StsBadArg, errorMessage);
                     }*/
                 string line, path, classLabel;
                 while (getline(file, line))
                 {
                     stringstream liness(line);
                     getline(liness, path, separator);
                     getline(liness, classLabel);

                     if (!path.empty() && !classLabel.empty())
                     {                     
                         images.push_back(imread(path, 0));
                         labels.push_back(atoi(classLabel.c_str()));
                     }
                 }
                 imshow("profile", images);
             }
             };
}