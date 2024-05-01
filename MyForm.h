#pragma once
#include <cmath>
namespace Lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(371, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Потрібно скласти програму, яка зчитує ці дані \r\nта обчислює вказані величини: \r\n1"
				L"2. Середнє арифметичне чисел, кратних 3.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Читати дані з файлу\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(295, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Обчислити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(423, 461);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(283, 519);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(158, 48);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Записати у файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(26, 461);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(361, 21);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Середнє арифметичне чисел, кратних 3:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(30, 203);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(423, 227);
			this->textBox1->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 583);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Cambria", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = "numbers.txt";
		if (File::Exists(fname)) {
			StreamReader^ reader = File::OpenText(fname);
			textBox1->Clear();
			String^ fileContent = reader->ReadToEnd();
			array<String^>^ numbers = fileContent->Split(' ');
			for (int i = 0; i < numbers->Length; i++) {
				textBox1->AppendText(numbers[i] + Environment::NewLine);
			}
			reader->Close();
		}

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	double sum = 0;
	float ser;
	int k = 0;
	for (int i = 0; i < textBox1->Lines->Length; i++)
	{
		int number;
		if (int::TryParse(textBox1->Lines[i], number))
		{
			if (number % 3 == 0)
			{
				sum += number;
				k += 1;

			}
		}
	}
	ser = sum / k;
	label2->Text = Convert::ToString(ser);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ fileName = "output.txt";
	StreamWriter^ writer = File::CreateText(fileName);
	double sum = 0;
	float ser;
	int k = 0;
	for
		(int i = 0; i < textBox1->Lines->Length; i++) {
		int number;
		if (int::TryParse(textBox1->Lines[i], number)) {
			if (number % 3 == 0) {
				sum += number;
				k += 1;
				writer->WriteLine(number);
			}
		}
	}
	ser = sum / k;
	writer->WriteLine("Average value: " + Convert::ToString(ser));
	writer->Close();
	MessageBox::Show("Середнє арифметичне чисел, кратних 3 було записано у файл " + fileName);
}
};
}
