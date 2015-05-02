#pragma once

#include "sha256.h"
#include <iostream>

#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/SecureStreamSocket.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>
#include <Poco/Crypto/CipherKey.h>
#include <Poco/AutoPtr.h>

#include <msclr\marshal_cppstd.h>

namespace Project2 {

	using namespace std;
	using namespace Poco::Net;
	using namespace Poco::Crypto;
	using namespace Poco;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SendForm
	/// </summary>
	public ref class SendForm : public System::Windows::Forms::Form
	{
	public:
		SendForm(void)
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
		~SendForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label8;




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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(15, 127);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(501, 314);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(103, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(413, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(103, 39);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(413, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(103, 65);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(413, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(103, 91);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(413, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Your Email: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Your Password: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Send to: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Subject: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 451);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Encryption: ";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(103, 476);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(413, 20);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 479);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Key: ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 509);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(389, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Please enter a key of over 16 characters. The key will be hashed to a 256 bit key."
				L"\'";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 546);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Go back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SendForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(316, 546);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Send Email";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SendForm::button2_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(100, 451);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(185, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Advanced Encryption Standard (AES)";
			// 
			// SendForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 588);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"SendForm";
			this->Text = L"SendForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->textBox5->Text->Length > 16){
				 string host = "smtp.gmail.com";
				 Poco::UInt16 port = 465;
				 string user = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
				 string password = msclr::interop::marshal_as<std::string>(this->textBox2->Text);
				 string to = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
				 string from = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
				 string subject = msclr::interop::marshal_as<std::string>(this->textBox4->Text);
				 subject = MailMessage::encodeWord(subject, "UTF-8");
				 string content = msclr::interop::marshal_as<std::string>(this->richTextBox1->Text);

				 string key = msclr::interop::marshal_as<std::string>(this->textBox5->Text);
				 string salt = "im100%salty";

				 Hashing::SHA256 sha256;
				 string hashedKey = sha256(key + salt);

				 CipherFactory& factory = CipherFactory::defaultFactory();
				 Cipher* pCipher = factory.createCipher(CipherKey("aes-256-cbc", hashedKey));
				 string encryptedContent = pCipher->encryptString(content, Cipher::ENC_BASE64);
				 //string decryptedContent = pCipher->decryptString(encryptedContent, Cipher::ENC_BASE64);
				 //string finalContent = encryptedContent + "\n" + decryptedContent;

				 string introduction = "Hello,\n\n" + from + " has sent you an encrypted message. Here it is: \n\n";
				 string ending = "\n\nUse the program with the key and salt that you should probably know to decrypt the message. Thanks for using our program!";
				 string finalMessage = introduction + encryptedContent + ending;

				 MailMessage message;
				 message.setSender(from);
				 message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, to));
				 message.setSubject(subject);
				 message.setContentType("text/plain; charset=UTF-8");
				 message.setContent(finalMessage, MailMessage::ENCODING_8BIT);

				 try {
					 initializeSSL();
					 SharedPtr<InvalidCertificateHandler> ptrHandler = new AcceptCertificateHandler(false);
					 Context::Ptr ptrContext = new Context(Context::CLIENT_USE, "", "", "", Context::VERIFY_RELAXED, 9, true, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
					 SSLManager::instance().initializeClient(0, ptrHandler, ptrContext);

					 SocketAddress sa(host, port);
					 SecureStreamSocket socket(sa);
					 SMTPClientSession session(socket);

					 try {
						 session.login(SMTPClientSession::AUTH_LOGIN, user, password);
						 session.sendMessage(message);
						 String^ m = "Message successfully sent";
						 System::Windows::Forms::MessageBox::Show(m, "Woot!",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 session.close();
						 uninitializeSSL();
						 this->textBox1->Text = "";
						 this->textBox2->Text = "";
						 this->textBox3->Text = "";
						 this->textBox4->Text = "";
						 this->textBox5->Text = "";
						 this->label7->ForeColor = System::Drawing::Color::Black;
						 this->label7->Text = "Please enter a key of over 16 characters. The key will be hashed to a 256 bit key.";
						 this->richTextBox1->Text = "";
					 }
					 catch (SMTPException &e) {
						 String^ m = gcnew String(e.displayText().c_str());
						 System::Windows::Forms::MessageBox::Show(m, "Something went wrong!",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
				 }
				 catch (NetException &e) {
					 String^ m = gcnew String(e.displayText().c_str());
					 System::Windows::Forms::MessageBox::Show(m, "Something went wrong!",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 }
			 }
			 else{
				 this->label7->ForeColor = System::Drawing::Color::Red;
				 this->label7->Text = "Please enter a key of over 16 characters.";
			 }
}
};
}
