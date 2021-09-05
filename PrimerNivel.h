#pragma once
#include <ctime>
#include "JuegoPrimerNivel.h"
namespace TRABAJOFINALPROGRA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Nivel1
	/// </summary>
	template <class Tipo>
	public ref class PrimerNivel : public System::Windows::Forms::Form
	{
	public:
		PrimerNivel(int tiempo, int aliados, int agentes, int habitantes)
		{
			InitializeComponent();
			srand(time(NULL));
			this->tiempo = tiempo;
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			control = new Controladora1<int>(aliados, agentes, habitantes);
			bmpLider = gcnew Bitmap("Lider.png");
			bmpAgente = gcnew Bitmap("AGENTE.png");
			bmpAliado = gcnew Bitmap("ALIADO SALUD.png");
			bmpHabitante = gcnew Bitmap("HABITANTE SALUD.png");
			bmpMapa = gcnew Bitmap("EscenarioSalud.png");
			bmpObstaculo = gcnew Bitmap("cosas (2).png");	
			bmpPollo = gcnew Bitmap("POLLOS.png");
			buscarMedicina = false;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PrimerNivel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		bool buscarMedicina;
		int tiempo;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpLider;
		Bitmap^ bmpAgente;
		Bitmap^ bmpHabitante;
		Bitmap^ bmpAliado;
		Bitmap^ bmpObstaculo;
		Bitmap^ bmpMapa;
		Controladora1<int>* control;
		Bitmap^ bmpPollo;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblTiempo;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Timer^ timer2;

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
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->lblTiempo = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->lblPuntos = (gcnew System::Windows::Forms::Label());
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &PrimerNivel::timer1_Tick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(12, 28);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(98, 26);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Tiempo: ";
			   // 
			   // lblTiempo
			   // 
			   this->lblTiempo->AutoSize = true;
			   this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblTiempo->Location = System::Drawing::Point(105, 28);
			   this->lblTiempo->Name = L"lblTiempo";
			   this->lblTiempo->Size = System::Drawing::Size(0, 26);
			   this->lblTiempo->TabIndex = 1;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(503, 28);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(98, 26);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Puntos: ";
			   // 
			   // lblPuntos
			   // 
			   this->lblPuntos->AutoSize = true;
			   this->lblPuntos->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPuntos->Location = System::Drawing::Point(601, 28);
			   this->lblPuntos->Name = L"lblPuntos";
			   this->lblPuntos->Size = System::Drawing::Size(0, 26);
			   this->lblPuntos->TabIndex = 3;
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Interval = 1000;
			   this->timer2->Tick += gcnew System::EventHandler(this, &PrimerNivel::timer2_Tick);
			   // 
			   // Nivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(982, 653);
			   this->Controls->Add(this->lblPuntos);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->lblTiempo);
			   this->Controls->Add(this->label1);
			   this->Name = L"PrimerNivel";
			   this->Text = L"PrimerNivel";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PrimerNivel::PrimerNivel_KeyDown);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion	

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		control->dibujarTodo(buffer->Graphics, bmpMapa, bmpLider, bmpAgente, bmpAliado, bmpHabitante, bmpObstaculo, bmpPollo);
		control->moverTodo(buffer->Graphics);
		control->Colision();
		if (buscarMedicina == false) {
			control->moverAliados(buffer->Graphics);
		}
		if (buscarMedicina == true) {
			control->moverBuscar(buffer->Graphics);
		}

		lblPuntos->Text = (" " + control->getPuntos());
		lblTiempo->Text = (" " + tiempo);
		if (tiempo == 0) {
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		else if (control->getAge() == 0 && control->getAli() == 0 && control->getObs() != 0) {
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		else if (control->getAge() == 0 && control->getAli() == 0 && control->getObs() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("GANASTE");
			this->Close();
		}
		else {
			buffer->Render(g);
		}

		

	}
	private: System::Void PrimerNivel_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		control->Tecla(e->KeyData);
		switch (e->KeyData)
		{
		case Keys::M: {
			buscarMedicina = true;
			control->setMedi(true);
			control->agregarPollo();
			break;
		}
		default:
			break;
		}
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		tiempo--;
	}
	};
}
