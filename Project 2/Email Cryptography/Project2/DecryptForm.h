#pragma once
#include "sha256.h"
#include <iostream> // for std::cout only, not needed for hashing library

#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>
#include <Poco/Crypto/CipherKey.h>
#include <Poco/Exception.h>

#include <msclr\marshal_cppstd.h>

namespace Project2 {

	using namespace Poco;
	using namespace Poco::Crypto;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DecryptForm
	/// </summary>
	public ref class DecryptForm : public System::Windows::Forms::Form
	{
	public:
		DecryptForm(void)
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
		~DecryptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Encryption: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(100, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(185, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Advanced Encryption Standard (AES)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Key: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(100, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(413, 20);
			this->textBox1->TabIndex = 3;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(15, 70);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(498, 455);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 548);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Go back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DecryptForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(313, 548);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Decrypt Message";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DecryptForm::button2_Click);
			// 
			// DecryptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 583);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"DecryptForm";
			this->Text = L"DecryptForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 Hashing::SHA256 sha256;
				 std::string key = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
				 std::string salt = "im100%salty";
				 std::string hashedKey = sha256(key + salt);
				 std::string content = msclr::interop::marshal_as<std::string>(this->richTextBox1->Text);

				 CipherFactory& factory = CipherFactory::defaultFactory();
				 Cipher* pCipher = factory.createCipher(CipherKey("aes-256-cbc", hashedKey));
				 std::string decryptedContent = pCipher->decryptString(content, Cipher::ENC_BASE64);

				 String^ finalContent = gcnew String(decryptedContent.c_str());

				 this->richTextBox1->Text = finalContent;
			 }
			 catch(RuntimeException e){
				 System::Windows::Forms::MessageBox::Show("Wrong key maybe?", "Something went wrong!",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
}
};
}
