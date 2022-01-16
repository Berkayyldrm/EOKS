#pragma once

namespace deneme4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	
	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			serialPort1->Close();
			timer1->Stop();
		}
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	
	
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		String^ mStr;
		String^ speed;
		int hiz;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
		   int i;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM4";
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Location = System::Drawing::Point(414, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 64);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Degerleri gonder";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button2->Location = System::Drawing::Point(669, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 57);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Baslat";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button3->Location = System::Drawing::Point(669, 178);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 58);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Durdur";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ayarlanan Hiz";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Kp";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(87, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Ki";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(87, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Kd";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(87, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Mevcut Hiz";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(188, 225);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"00";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(191, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(191, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(191, 137);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(191, 178);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 269);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1107, 487);
			this->chart1->TabIndex = 13;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1150, 765);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		serialPort1->WriteLine("stop");		//motoru durdur
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		serialPort1->Open();
		timer1->Start();
		mStr = "0";
		i = 300;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		 serialPort1->WriteLine("set_speed" + textBox1->Text);	
		 serialPort1->WriteLine("kp" + textBox2->Text);	
		 serialPort1->WriteLine("ki" + textBox3->Text);	
		 serialPort1->WriteLine("kd" + textBox4->Text);	
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		String^ length;
		length = mStr->Length.ToString();
		if (System::Convert::ToInt32(length) > 5) {
			if (mStr->Substring(0, 5) == "speed") {
				speed  = mStr->Substring(5, System::Convert::ToInt32(length) - 6);
				label6->Text = speed;
				//motor hýzýný grafige bastiriyoruz.

				
				this->chart1->Series["Series1"]->Points->AddXY(i, System::Convert::ToString(speed));
				i++;
				this->chart1->ChartAreas["ChartArea1"]->AxisX->Minimum = i - 300;//x ekseninde kaydirma
				
				
			}
		}

	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
			   mStr = serialPort1->ReadLine();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
					  serialPort1->WriteLine("start");	//motoru baslat
	}
	
};
}
