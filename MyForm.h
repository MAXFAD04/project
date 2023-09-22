#pragma once

namespace FoxHunter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	int fieldSize = 0;
	int foxCount = 0;
	int foundedFox = 0;
	int gameSteps = 0;
	bool simple_level = true;
	bool foxes_coord[14][14];

	void generate_foxes(void) {

		foundedFox = 0;
		gameSteps = 0;

		for (int x = 0; x < 14; x++)
			for (int y = 0; y < 14; y++)
				foxes_coord[x][y] = false;
		if (!fieldSize || !foxCount || foxCount > (fieldSize * fieldSize / 2)) return;

		Random^ rnd = gcnew Random();
		for (int i = 0; i < foxCount; i++) {
			int x = rnd->Next(fieldSize);
			int y = rnd->Next(fieldSize);
			while (foxes_coord[x][y]) {
				x = rnd->Next(fieldSize);
				y = rnd->Next(fieldSize);
			}
			foxes_coord[x][y] = true;
		}		
	}


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::ImageList^ imageList;
	private: System::Windows::Forms::Button^ btnStart3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnStart1;
	private: System::Windows::Forms::Button^ btnStart2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ MainPanel;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ StatusBar;
	private: System::Windows::Forms::CheckBox^ checkDiffLevel;
	private: System::Windows::Forms::CheckBox^ checkSimpleLevel;



	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkDiffLevel = (gcnew System::Windows::Forms::CheckBox());
			this->checkSimpleLevel = (gcnew System::Windows::Forms::CheckBox());
			this->btnStart3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnStart1 = (gcnew System::Windows::Forms::Button());
			this->btnStart2 = (gcnew System::Windows::Forms::Button());
			this->imageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->MainPanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->StatusBar = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Controls->Add(this->checkDiffLevel);
			this->panel1->Controls->Add(this->checkSimpleLevel);
			this->panel1->Controls->Add(this->btnStart3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btnStart1);
			this->panel1->Controls->Add(this->btnStart2);
			this->panel1->Name = L"panel1";
			// 
			// checkDiffLevel
			// 
			resources->ApplyResources(this->checkDiffLevel, L"checkDiffLevel");
			this->checkDiffLevel->ForeColor = System::Drawing::Color::White;
			this->checkDiffLevel->Name = L"checkDiffLevel";
			this->checkDiffLevel->UseVisualStyleBackColor = true;
			this->checkDiffLevel->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkDiffLevel_CheckedChanged);
			// 
			// checkSimpleLevel
			// 
			resources->ApplyResources(this->checkSimpleLevel, L"checkSimpleLevel");
			this->checkSimpleLevel->Checked = true;
			this->checkSimpleLevel->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkSimpleLevel->ForeColor = System::Drawing::Color::White;
			this->checkSimpleLevel->Name = L"checkSimpleLevel";
			this->checkSimpleLevel->UseVisualStyleBackColor = true;
			this->checkSimpleLevel->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkSimpleLevel_CheckedChanged);
			// 
			// btnStart3
			// 
			resources->ApplyResources(this->btnStart3, L"btnStart3");
			this->btnStart3->Name = L"btnStart3";
			this->btnStart3->UseVisualStyleBackColor = true;
			this->btnStart3->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Name = L"label1";
			// 
			// btnStart1
			// 
			resources->ApplyResources(this->btnStart1, L"btnStart1");
			this->btnStart1->Name = L"btnStart1";
			this->btnStart1->UseVisualStyleBackColor = true;
			this->btnStart1->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnStart2
			// 
			resources->ApplyResources(this->btnStart2, L"btnStart2");
			this->btnStart2->Name = L"btnStart2";
			this->btnStart2->UseVisualStyleBackColor = true;
			this->btnStart2->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// imageList
			// 
			this->imageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList.ImageStream")));
			this->imageList->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList->Images->SetKeyName(0, L"foxico");
			this->imageList->Images->SetKeyName(1, L"tree_icon");
			// 
			// tableLayoutPanel1
			// 
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->MainPanel, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// MainPanel
			// 
			resources->ApplyResources(this->MainPanel, L"MainPanel");
			this->MainPanel->Name = L"MainPanel";
			// 
			// panel2
			// 
			resources->ApplyResources(this->panel2, L"panel2");
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Name = L"panel2";
			// 
			// panel3
			// 
			resources->ApplyResources(this->panel3, L"panel3");
			this->panel3->Controls->Add(this->StatusBar);
			this->panel3->Name = L"panel3";
			// 
			// StatusBar
			// 
			resources->ApplyResources(this->StatusBar, L"StatusBar");
			this->StatusBar->ForeColor = System::Drawing::Color::White;
			this->StatusBar->Name = L"StatusBar";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Name = L"label2";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowInTaskbar = false;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		ref class FoxCell : System::Windows::Forms::Button {
		public:
			bool fox = false;
			int x = 0;
			int y = 0;
			bool clicked = false;
			bool foxes = 0;
		};

		// Функция Start - иннициализация новой игры
		private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {

			this->MainPanel->Enabled = true;
			this->checkSimpleLevel->Visible = true;
			this->checkDiffLevel->Visible = true;

			Button^ start_button = safe_cast<Button^>(sender);
			System::String^ name = start_button->Name;
			

			if (fieldSize > 0) this->MainPanel->Controls->Clear();
				
			int buttonSize;			

			if (name == "btnStart2") {
				fieldSize = 10;
				buttonSize = 67;
				foxCount = System::Random().Next(6, 12);
			}
			else if (name == "btnStart3") {
				fieldSize = 14;
				buttonSize = 48;
				foxCount = System::Random().Next(12, 24);
			}
			else {
				fieldSize = 6;
				buttonSize = 112;
				foxCount = System::Random().Next(4, 8);
			}

			generate_foxes();
			this->UpdateStatusBar();

			for (int x = 0; x < fieldSize; x++)
				for (int y = 0; y < fieldSize; y++)
				{
					FoxCell^ cell = gcnew FoxCell();
					cell->Text = "";
					cell->Name = "btnCell" + x + "_" + y;
					cell->Location = Point(x * buttonSize, y * buttonSize);
					cell->Size = System::Drawing::Size(buttonSize, buttonSize);
					cell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					cell->ForeColor = System::Drawing::Color::Aquamarine;
					cell->Parent = this;
					cell->ImageList = this->imageList;
					cell->ImageKey = "tree_icon";
					cell->x = x;
					cell->y = y;
					cell->fox = foxes_coord[x][y];
					/*if (foxes_coord[x][y]) {
						But->ForeColor = System::Drawing::Color::DarkRed;
						But->BackColor = System::Drawing::Color::DarkRed;
						But->ImageKey = "foxico";
					}*/
					cell->Click += gcnew System::EventHandler(this, &MyForm::FoxCell_Click);
					this->MainPanel->Controls->Add(cell);
				}

			this->CenterToScreen();
		}

	    // Функция при нажатии на ячейке
		private: System::Void FoxCell_Click(System::Object^ sender, System::EventArgs^ e) {			
			
			FoxCell^ cell = safe_cast<FoxCell^>(sender);
			if (cell->clicked) return;

			cell->clicked = true;
			gameSteps++;

			int x = cell->x;
			int y = cell->y;
			bool fox = cell->fox;

			if (fox) {
				foundedFox++;
				cell->ForeColor = System::Drawing::Color::DarkRed;
				cell->BackColor = System::Drawing::Color::DarkRed;
				cell->ImageKey = "foxico";
				if (simple_level) {
					foxes_coord[x][y] = false;
					this->CellsUpdate(x, y);
				}
				if (foundedFox == foxCount) {
					this->MainPanel->Enabled = false;
					this->StatusBar->Text = "Игра закончена. Найдено лис: " + foxCount + ". Шагов: " + gameSteps;
					return;
				}
			}
			else {
				cell->ImageKey = "";
				cell->ForeColor = System::Drawing::Color::DarkGreen;
				cell->BackColor = System::Drawing::Color::White;
				this->PelengFoxCountInCells(x, y);
			}
			this->UpdateStatusBar();
			if (this->checkSimpleLevel->Visible) {
				this->checkSimpleLevel->Visible = false;
				this->checkDiffLevel->Visible = false;
			}
		}

	    // Обновить инфостроку
		private: System::Void UpdateStatusBar() {
			this->StatusBar->Text = "Найдено: " + foundedFox + " из " + foxCount + "     Шагов: " + gameSteps;
		}

	    // Переленг лис от клетки с координатами
		private: System::Void PelengFoxCountInCells(int x, int y) {
			FoxCell^ cell = safe_cast<FoxCell^>(this->MainPanel->Controls->Find("btnCell" + x + "_" + y, true)[0]);
			if (!cell->clicked || cell->fox) return;
			int foxes = 0;
			for (int i = 0; i < fieldSize; i++) {
				if (foxes_coord[i][y] && i != x) foxes++;
				if (foxes_coord[x][i] && i != y) foxes++;
				if ((y - x + i) >= 0 && (y - x + i) < fieldSize && foxes_coord[i][y - x + i] && i != x) foxes++;
				if ((y + x - i) >= 0 && (y + x - i) < fieldSize && foxes_coord[i][y + x - i] && i != x) foxes++;				
			}
			cell->Text = foxes.ToString();
			if (!foxes) {
				cell->BackColor = System::Drawing::Color::Gray;
				if (simple_level) this->DisableCells(x, y);
			}
		}

		// Перерасчет количества лис при найденой лисе в открытых ячейках (только для простого уровня)
		private: System::Void CellsUpdate(int x, int y) {
			if (!simple_level) return;
			for (int i = 0; i < fieldSize; i++) {
				if (i!=x) this->PelengFoxCountInCells(i, y);
				if (i!=y) this->PelengFoxCountInCells(x, i);
				if ((y - x + i) >= 0 && (y - x + i) < fieldSize && i != x) this->PelengFoxCountInCells(i, y - x + i);
				if ((y + x - i) >= 0 && (y + x - i) < fieldSize && i != x) this->PelengFoxCountInCells(i, y + x - i);
			}			
		}

		// Закрашивание серым ячеек, где не может быть лис (только для простого уровня)
		private: System::Void DisableCells(int x, int y) {
			if (!simple_level) return;
			for (int i = 0; i < fieldSize; i++) {
				if (i != x) {
					FoxCell^ cell = safe_cast<FoxCell^>(this->MainPanel->Controls->Find("btnCell" + i + "_" + y, true)[0]);
					if (cell->clicked) {
						cell->BackColor = System::Drawing::Color::LightGray;
					}
					else {
						cell->BackColor = System::Drawing::Color::Gray;
					}
				}
				if (i != y) {
					FoxCell^ cell = safe_cast<FoxCell^>(this->MainPanel->Controls->Find("btnCell" + x + "_" + i, true)[0]);
					if (cell->clicked) {
						cell->BackColor = System::Drawing::Color::LightGray;
					}
					else {
						cell->BackColor = System::Drawing::Color::Gray;
					}
				}
				if ((y - x + i) >= 0 && (y - x + i) < fieldSize && i != x) {
					FoxCell^ cell = safe_cast<FoxCell^>(this->MainPanel->Controls->Find("btnCell" + i + "_" + (y - x + i), true)[0]);
					if (cell->clicked) {
						cell->BackColor = System::Drawing::Color::LightGray;
					}
					else {
						cell->BackColor = System::Drawing::Color::Gray;
					}
				}
				if ((y + x - i) >= 0 && (y + x - i) < fieldSize && i != x) {
					FoxCell^ cell = safe_cast<FoxCell^>(this->MainPanel->Controls->Find("btnCell" + i + "_" + (y + x - i), true)[0]);
					if (cell->clicked) {
						cell->BackColor = System::Drawing::Color::LightGray;
					}
					else {
						cell->BackColor = System::Drawing::Color::Gray;
					}
				}
			}
		}

		private: System::Void checkSimpleLevel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (this->checkSimpleLevel->Checked) {
				this->checkDiffLevel->Checked = false;
				simple_level = true;
			}
			else {
				this->checkDiffLevel->Checked = true;
				simple_level = false;
			}
		}

		private: System::Void checkDiffLevel_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (this->checkDiffLevel->Checked) {
				this->checkSimpleLevel->Checked = false;
				simple_level = false;
			}
			else {
				this->checkSimpleLevel->Checked = true;
				simple_level = true;
			}
		}
};

}
