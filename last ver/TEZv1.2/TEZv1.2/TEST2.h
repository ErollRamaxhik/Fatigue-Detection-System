#include "FullscreenForm.h"

namespace TEZv12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TEST2
	/// </summary>
	public ref class TEST2 : public System::Windows::Forms::Form
	{
	public:
		TEST2(void)
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
		~TEST2()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// TEST2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"TEST2";
			this->Text = L"TEST2";
			this->Load += gcnew System::EventHandler(this, &TEST2::TEST2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TEST2_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		TEZv12::FullscreenForm^ ff = gcnew FullscreenForm;
		ff->ShowDialog();
	}
	};
}
