#include <iostream>
#include <time.h>

#pragma once

int xWide = 100; int yWide = 100; int scale = 3;
bool c[100][100]; bool m[100][100];
namespace ConwaysGameofLife {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//deployCells(5000);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;




	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(112, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Alive Cells";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 54);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 185);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(75, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Size of Board";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 508);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Conway\'s Game of Life";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void deployCells(int numAlive)
		{
			int x = 0;
			int y = 0;
			for(int i = 0; i < numAlive; i++)
			{
				do{
					x = rand() % xWide;
					y = rand() % yWide;
				}while(c[x][y]);
				c[x][y] = true;
			}
		}
		void tick(void)
		{
			
			int count = 0;
			for(int i = 0; i < xWide; i++)
			{
				for(int j = 0; j < yWide; j++)
				{
					count = 0;
					if((c[i-1][j])&&(i > 0))//Left
					{
						count++;
					}
					if((c[i][j-1])&&(j > 0))//Down
					{
						count++;
					}
					if((c[i-1][j-1])&&(i > 0)&&(j > 0))
					{
						count++;
					}
					if((c[i+1][j])&&(i < xWide-1))
					{
						count++;
					}
					if((c[i][j+1])&&(j < yWide-1))
					{
						count++;
					}
					if((c[i+1][j+1])&&(i < xWide-1)&&(j < yWide-1))
					{
						count++;
					}
					if((c[i-1][j+1])&&(i > 0)&&(j < yWide-1))
					{
						count++;
					}
					if((c[i+1][j-1])&&(i < xWide-1)&&(j > 0))
					{
						count++;
					}
					/*   1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
						 2. Any live cell with two or three live neighbours lives on to the next generation.
						 3. Any live cell with more than three live neighbours dies, as if by overcrowding.
						 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
					*/
					
					if(c[i][j])
					{
						if(count < 2)
						{
							m[i][j] = false;
						}
						if((count == 2)||(count == 3))
						{
							m[i][j] = true;
						}
						if(count > 3)
						{
							m[i][j] = false;
						}
					}
					else
					{
						if(count == 3)
						{
							m[i][j] = true;
						}
					}
					if((i == 0)||(j == 0)||(i == xWide-1)||(j == yWide-1))
					{
						//c[i][j] = false;
					}
				}
			}
			for(int i = 0; i < xWide; i++)
			{
				for(int j = 0; j < yWide; j++)
				{
					c[i][j] = m[i][j];
				}
			}
		}
		void clearBoard(void)
		{
			for(int i = 0; i < xWide; i++)
			{
				for(int j = 0; j < yWide; j++)
				{
					c[i][j] = false;
					m[i][j] = false;
				}
			}
		}
		void drawBoard(void)
		{
			Graphics^ g = this->pictureBox1->CreateGraphics();
			SolidBrush^ white = gcnew SolidBrush(Color::White);
			SolidBrush^ blue = gcnew SolidBrush(Color::Blue);
			SolidBrush^ black = gcnew SolidBrush(Color::Black);
			//g->Clear(Color::Blue);

			for(int i = 0; i < xWide; i++)
			{
				for(int j = 0; j < yWide; j++)
				{
					if(c[i][j])
					{
						g->FillRectangle(blue, i*scale, j*scale, scale, scale);
					}
					else
					{
						g->FillRectangle(black, i*scale, j*scale, scale, scale);
					}
				}
			}
			delete g;
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
				 drawBoard();
				 tick();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 clearBoard();
				 int numCells = System::Convert::ToInt64(this->textBox1->Text);
				 xWide = System::Convert::ToInt64(this->textBox2->Text);
				 yWide = xWide;
				 scale = 500 / xWide;
				 deployCells(numCells);


				 this->timer1->Start();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->timer1->Stop();
		 }
};
}

