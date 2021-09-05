#pragma once
#include "Creditos.h"
#include"Instrucciones.h"
#include"PrimerNivel.h"
#include "SegundoNivel.h"
namespace TRABAJOFINALPROGRA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MiMenu
	/// </summary>

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnNivel1;
	protected:


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::NumericUpDown^ nudTiempo;
	private: System::Windows::Forms::NumericUpDown^ nudHabitantes;


	private: System::Windows::Forms::NumericUpDown^ nudAliados;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->nudTiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudHabitantes = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudHabitantes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAliados))->BeginInit();
			this->SuspendLayout();
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnNivel1->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel1->ForeColor = System::Drawing::Color::Red;
			this->btnNivel1->Location = System::Drawing::Point(421, 235);
			this->btnNivel1->Margin = System::Windows::Forms::Padding(2);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(193, 57);
			this->btnNivel1->TabIndex = 0;
			this->btnNivel1->Text = L"SALUD ";
			this->btnNivel1->UseVisualStyleBackColor = false;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnNivel1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::Color::YellowGreen;
			this->btnNivel2->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel2->ForeColor = System::Drawing::Color::Red;
			this->btnNivel2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnNivel2->Location = System::Drawing::Point(407, 331);
			this->btnNivel2->Margin = System::Windows::Forms::Padding(2);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(244, 57);
			this->btnNivel2->TabIndex = 1;
			this->btnNivel2->Text = L"AMBIENTE";
			this->btnNivel2->UseVisualStyleBackColor = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnNivel2_Click);
			// 
			// nudTiempo
			// 
			this->nudTiempo->BackColor = System::Drawing::Color::MediumBlue;
			this->nudTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudTiempo->Location = System::Drawing::Point(146, 251);
			this->nudTiempo->Margin = System::Windows::Forms::Padding(2);
			this->nudTiempo->Name = L"nudTiempo";
			this->nudTiempo->Size = System::Drawing::Size(154, 30);
			this->nudTiempo->TabIndex = 3;
			this->nudTiempo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nudTiempo->ValueChanged += gcnew System::EventHandler(this, &MenuPrincipal::nudTiempo_ValueChanged);
			// 
			// nudHabitantes
			// 
			this->nudHabitantes->BackColor = System::Drawing::Color::MediumBlue;
			this->nudHabitantes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudHabitantes->Location = System::Drawing::Point(184, 347);
			this->nudHabitantes->Margin = System::Windows::Forms::Padding(2);
			this->nudHabitantes->Name = L"nudHabitantes";
			this->nudHabitantes->Size = System::Drawing::Size(154, 30);
			this->nudHabitantes->TabIndex = 4;
			this->nudHabitantes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// nudAliados
			// 
			this->nudAliados->BackColor = System::Drawing::Color::MediumBlue;
			this->nudAliados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudAliados->Location = System::Drawing::Point(240, 304);
			this->nudAliados->Margin = System::Windows::Forms::Padding(2);
			this->nudAliados->Name = L"nudAliados";
			this->nudAliados->Size = System::Drawing::Size(154, 30);
			this->nudAliados->TabIndex = 6;
			this->nudAliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Coral;
			this->label2->Location = System::Drawing::Point(20, 251);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 29);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Tiempo:";
			this->label2->Click += gcnew System::EventHandler(this, &MenuPrincipal::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(20, 347);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 29);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Habitante(s):";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Coral;
			this->label5->Location = System::Drawing::Point(20, 304);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(210, 29);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Aliados y Agentes:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(9, 2);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 37);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Instrucciones";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Red;
			this->button2->Location = System::Drawing::Point(499, 10);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 37);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Creditos";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MenuPrincipal::button2_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(674, 432);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nudAliados);
			this->Controls->Add(this->nudHabitantes);
			this->Controls->Add(this->nudTiempo);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->btnNivel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MenuPrincipal";
			this->Text = L"MiMenu";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudHabitantes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAliados))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		PrimerNivel<int>^ nivel1 = gcnew PrimerNivel<int>((int)nudTiempo->Value, (int)nudAliados->Value, (int)nudAliados->Value, (int)nudHabitantes->Value);
		this->Visible = false;
		nivel1->ShowDialog();
		this->Visible = true;
		delete nivel1;
	}

	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		SegundoNivel<int>^ nivel2 = gcnew SegundoNivel<int>((int)nudTiempo->Value, (int)nudAliados->Value, (int)nudAliados->Value, (int)nudHabitantes->Value);
		nivel2->ShowDialog();
		delete nivel2;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Instrucciones^ instuc = gcnew Instrucciones();
		instuc->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ credi = gcnew Creditos();
		credi->ShowDialog();
	}
	private: System::Void nudTiempo_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
