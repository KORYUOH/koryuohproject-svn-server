#pragma once

namespace HMMGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  COPY_CLIP;
	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  MACRO_IFN;
	private: System::Windows::Forms::Label^  label3;
	protected: 

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->COPY_CLIP = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MACRO_IFN = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// COPY_CLIP
			// 
			this->COPY_CLIP->Location = System::Drawing::Point(22, 68);
			this->COPY_CLIP->Name = L"COPY_CLIP";
			this->COPY_CLIP->Size = System::Drawing::Size(75, 23);
			this->COPY_CLIP->TabIndex = 0;
			this->COPY_CLIP->Text = L"#ifndef";
			this->COPY_CLIP->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(103, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"二重インクルード防止マクロを、";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(103, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"クリップボードへコピーします。";
			// 
			// MACRO_IFN
			// 
			this->MACRO_IFN->Location = System::Drawing::Point(22, 43);
			this->MACRO_IFN->Name = L"MACRO_IFN";
			this->MACRO_IFN->Size = System::Drawing::Size(258, 19);
			this->MACRO_IFN->TabIndex = 3;
			this->MACRO_IFN->Text = L"_*_H_";
			this->MACRO_IFN->TextChanged += gcnew System::EventHandler(this, &Form1::MACRO_IFN_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"マクロの名前を入力します";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 122);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->MACRO_IFN);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->COPY_CLIP);
			this->Name = L"Form1";
			this->Text = L"二重定義防止マクロ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void MACRO_IFN_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

