#pragma once

#include "..\Library\BaseSequence.h"
#include "..\Library\BST.h"
#include "..\Library\Hash.h"
#include "..\Lab2Find\Program.h"

namespace Lab2GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Program* p;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	public:
		MyForm(void)
		{
			InitializeComponent();
			p = new Program();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bAdd;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbKey;
	private: System::Windows::Forms::TextBox^  tbValue;
	private: System::Windows::Forms::RichTextBox^  rtbBST;
	private: System::Windows::Forms::RichTextBox^  rtbBT;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  bFind;
	private: System::Windows::Forms::TextBox^  tbKeyFind;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbValueFind;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbCount;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Button^  bTest;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbKey = (gcnew System::Windows::Forms::TextBox());
			this->tbValue = (gcnew System::Windows::Forms::TextBox());
			this->rtbBST = (gcnew System::Windows::Forms::RichTextBox());
			this->rtbBT = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bFind = (gcnew System::Windows::Forms::Button());
			this->tbKeyFind = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbValueFind = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbCount = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->bTest = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(224, 22);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(75, 23);
			this->bAdd->TabIndex = 0;
			this->bAdd->Text = L"Добавить";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Click += gcnew System::EventHandler(this, &MyForm::bAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ключ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(114, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Значение";
			// 
			// tbKey
			// 
			this->tbKey->Location = System::Drawing::Point(12, 25);
			this->tbKey->Name = L"tbKey";
			this->tbKey->Size = System::Drawing::Size(100, 20);
			this->tbKey->TabIndex = 3;
			// 
			// tbValue
			// 
			this->tbValue->Location = System::Drawing::Point(118, 25);
			this->tbValue->Name = L"tbValue";
			this->tbValue->Size = System::Drawing::Size(100, 20);
			this->tbValue->TabIndex = 4;
			// 
			// rtbBST
			// 
			this->rtbBST->Location = System::Drawing::Point(12, 76);
			this->rtbBST->Name = L"rtbBST";
			this->rtbBST->Size = System::Drawing::Size(177, 385);
			this->rtbBST->TabIndex = 5;
			this->rtbBST->Text = L"";
			// 
			// rtbBT
			// 
			this->rtbBT->Location = System::Drawing::Point(195, 76);
			this->rtbBT->Name = L"rtbBT";
			this->rtbBT->Size = System::Drawing::Size(135, 385);
			this->rtbBT->TabIndex = 6;
			this->rtbBT->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Двоичное дерево поиска";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(195, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Хеш-таблица";
			// 
			// bFind
			// 
			this->bFind->Location = System::Drawing::Point(442, 25);
			this->bFind->Name = L"bFind";
			this->bFind->Size = System::Drawing::Size(75, 23);
			this->bFind->TabIndex = 11;
			this->bFind->Text = L"Искать";
			this->bFind->UseVisualStyleBackColor = true;
			this->bFind->Click += gcnew System::EventHandler(this, &MyForm::bFind_Click);
			// 
			// tbKeyFind
			// 
			this->tbKeyFind->Location = System::Drawing::Point(336, 26);
			this->tbKeyFind->Name = L"tbKeyFind";
			this->tbKeyFind->Size = System::Drawing::Size(100, 20);
			this->tbKeyFind->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(333, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Ключ";
			// 
			// tbValueFind
			// 
			this->tbValueFind->Location = System::Drawing::Point(523, 28);
			this->tbValueFind->Name = L"tbValueFind";
			this->tbValueFind->Size = System::Drawing::Size(100, 20);
			this->tbValueFind->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(523, 12);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Значение";
			// 
			// tbCount
			// 
			this->tbCount->Location = System::Drawing::Point(658, 28);
			this->tbCount->Name = L"tbCount";
			this->tbCount->Size = System::Drawing::Size(100, 20);
			this->tbCount->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(655, 12);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Количество";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(764, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Сгенерировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(336, 493);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 20;
			// 
			// bTest
			// 
			this->bTest->Location = System::Drawing::Point(928, 26);
			this->bTest->Name = L"bTest";
			this->bTest->Size = System::Drawing::Size(75, 23);
			this->bTest->TabIndex = 22;
			this->bTest->Text = L"Тест it!";
			this->bTest->UseVisualStyleBackColor = true;
			this->bTest->Click += gcnew System::EventHandler(this, &MyForm::bTest_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(503, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(691, 500);
			this->panel1->TabIndex = 23;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(979, 579);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Кол-во";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(491, 60);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(39, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"время";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1233, 615);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->bTest);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tbCount);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbValueFind);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbKeyFind);
			this->Controls->Add(this->bFind);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->rtbBT);
			this->Controls->Add(this->rtbBST);
			this->Controls->Add(this->tbValue);
			this->Controls->Add(this->tbKey);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bAdd);
			this->Name = L"MyForm";
			this->Text = L"Лаба 2";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			System::String^ str = tbValue->Text;
			std::string myString = "";
			for (int i = 0; i < str->Length; i++)
				myString += (char)str[i];

			const char * stt = myString.c_str();
			p->addPair(Convert::ToInt32(tbKey->Text), stt);
		}
		catch (InvalidCastException^)
		{
			MessageBox::Show("Некорректное значение в полях");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString());
		}
		catch (const std::exception& se)
		{
			MessageBox::Show(gcnew String(se.what()));
		}
		catch (...)
		{
			MessageBox::Show("Неизвестная ошибка");
		}
		Invalidate();
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		try {
			rtbBST->Text = gcnew String(p->toString(0).c_str());
			rtbBT->Text = gcnew String(p->toString(1).c_str());
			
			List<Pen^>^ pens = gcnew List<Pen^>();
			pens->Add(gcnew Pen(Color::Red));
			pens->Add(gcnew Pen(Color::Black));
			List<String^>^ strings = gcnew List<String^>();
			strings->Add("Двоичное дерево поиска");
			strings->Add("Хеш-таблица");
			Graphics^ g = Graphics::FromHwnd(panel1->Handle);
			for (int i = 0; i < p->totalCount(); ++i)
			{
				int x = 0; int y = 0;
				g->DrawArc(pens[i], 0, 500, 2, 2, 0, 360);
				for(int j = 0; j < 4; ++j)
				{
					int yn = p->getTest(j, i) / 1000;
					g->DrawLine(pens[i], x, 500 - y, x + 100, 500 - yn);
					x += 100;
					y = yn;
					g->DrawArc(pens[i], x, 500 - y, 2, 2, 0, 360);
				}
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
				g->DrawString(strings[i], drawFont, drawBrush, x, 500 - y);
			}
			int num = 1;
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
			SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
			g->DrawString("0", drawFont, drawBrush, 0, 500 - 20);
			for (int i = 1; i < 5; ++i)
			{
				num *= 20;
				g->DrawString(Convert::ToString(num), drawFont, drawBrush, i * 100, 500 - 20);
				
			}
			g->DrawLine(gcnew Pen(Color::Black), 0, 500 - 1, 500 - 1, 500 - 1);
			g->DrawLine(gcnew Pen(Color::Black), 0, 500 - 1, 0, 0);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString());
		}
		catch (const std::exception& se)
		{
			MessageBox::Show(gcnew String(se.what()));
		}
		catch (...)
		{
			MessageBox::Show("Неизвестная ошибка");
		}

	}
	private: System::Void bFind_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			tbValueFind->Text = gcnew String(p->findValue(Convert::ToInt32(tbKeyFind->Text)).c_str());
		}

		catch (InvalidCastException^)
		{
			MessageBox::Show("Некорректное значение в полях");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString());
		}
		catch (const std::exception& se)
		{
			MessageBox::Show(gcnew String(se.what()));
		}
		catch (...)
		{
			MessageBox::Show("Неизвестная ошибка");
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			int count = Convert::ToInt32(tbCount->Text);
			p->generate(count);
		}
		catch (InvalidCastException^)
		{
			MessageBox::Show("Некорректное значение в полях");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString());
		}
		catch (const std::exception& se)
		{
			MessageBox::Show(gcnew String(se.what()));
		}
		catch (...)
		{
			MessageBox::Show("Неизвестная ошибка");
		}
	}
private: System::Void bTest_Click(System::Object^  sender, System::EventArgs^  e) {
	p->test();
}
};
}
