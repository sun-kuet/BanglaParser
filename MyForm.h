﻿#pragma once
#include "Markup.h"
#include "addingPosForm.h"
#using <System.Xml.dll>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include<vector>
#include<string>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<hash_map>
#include<ctime>


namespace TextBox {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	using namespace stdext;
	using namespace System::IO;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	map<string, int> noOfSymbol, npdaSymbol;
	vector<string >grammer;
	vector<string> parseTable[200][200], cnfTable[200];
	vector<int>tot_word;
	hash_map<wstring, string> hash;
	hash_map<wstring, bool > bivoktiMap;
	hash_map<wstring, string>::const_iterator it;
	vector<string>splitgrammer[100][100];
	vector<string>FIRST[100], FOLLOW[100];
	vector<string>Nonterminal, terminal;
	int totProduction[100];
	string returnStringFromAddingPosForm;

	bool notFound = false;
	bool ischeckfinished;
	int tot_line;
	//
	/// Timmer class 
	//
	class Timer
	{
	private:
		double begTime;
	public:
		void start()
		{
			begTime = clock();
		}

		double elapsedTime()
		{
			return ((double)clock() - begTime) / (double)CLOCKS_PER_SEC;
		}

		bool isTimeout(double seconds)
		{
			return seconds >= elapsedTime();
		}
	};

	class classForReturnPos
	{
	public:
		classForReturnPos()
		{

		}
		void returnFunction(string str)
		{
			returnStringFromAddingPosForm = str;
		}
	};

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
	private: System::Windows::Forms::TextBox^  mainTextBox;
	private: System::Windows::Forms::TextBox^  lastTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Button^  sendButton;
	private: System::Windows::Forms::Button^  exitButton;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewPOSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addPOSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->mainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewPOSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addPOSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTextBox->Location = System::Drawing::Point(12, 101);
			this->mainTextBox->Multiline = true;
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(255, 220);
			this->mainTextBox->TabIndex = 0;
			// 
			// lastTextBox
			// 
			this->lastTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastTextBox->Location = System::Drawing::Point(397, 101);
			this->lastTextBox->Multiline = true;
			this->lastTextBox->Name = L"lastTextBox";
			this->lastTextBox->ReadOnly = true;
			this->lastTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->lastTextBox->Size = System::Drawing::Size(298, 220);
			this->lastTextBox->TabIndex = 1;
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(273, 129);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(118, 23);
			this->sendButton->TabIndex = 2;
			this->sendButton->Text = L"Predictive Parse";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(299, 333);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(92, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"NPDA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(249, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(175, 39);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem, this->addPOSToolStripMenuItem, this->aboutToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(707, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->viewPOSToolStripMenuItem });
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// viewPOSToolStripMenuItem
			// 
			this->viewPOSToolStripMenuItem->Name = L"viewPOSToolStripMenuItem";
			this->viewPOSToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->viewPOSToolStripMenuItem->Text = L"View POS";
			// 
			// addPOSToolStripMenuItem
			// 
			this->addPOSToolStripMenuItem->Name = L"addPOSToolStripMenuItem";
			this->addPOSToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->addPOSToolStripMenuItem->Text = L"Add POS";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save ";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 368);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->lastTextBox);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		array<String^>^ words;


		array<String^>^ grammerWords = gcnew array<String^>(110);

		array<String^, 2>^ AllgrammerWords = gcnew array<String^, 2>(100, 100);


		array<String^>^ MainInput;




#pragma endregion

		// table for npda


	public:void assignNpdaSymbolValue(string s, int val)
	{
			   if (npdaSymbol.find(s) == npdaSymbol.end())
			   {
				   npdaSymbol[s] = val;
			   }
	}

	public: void makeCnfTable()
	{
				StreamReader^ reader = File::OpenText("npdaGrammer.txt");
				String^ readString;
				int idx = 1;

				while ((readString = reader->ReadLine()) != nullptr)
				{
					string str = marshal_as<std::string>(readString);

					string leftString;

					int productNo = 1;

					int i = 0;
					while (str[i] != '-')
					{
						leftString.push_back(str[i]);
						i++;
					}

					assignNpdaSymbolValue(leftString, idx++);

					for (++i; i < str.size(); i++)
					{
						string first = "", second = "";
						while ((str[i] != ' ' && str[i] != '|') && i < str.size())
						{
							first.push_back(str[i]);
							i++;
						}

						if (str[i] == '|' || i == str.size())
						{

							if (first.size()) assignNpdaSymbolValue(first, idx++);
							cnfTable[npdaSymbol[leftString]].push_back(first);
							continue;
						}

						i++;
						if (i < str.size())
						while (str[i] != '|' && i < str.size())
						{
							second.push_back(str[i]);
							i++;
						}

						if (first.size()) assignNpdaSymbolValue(first, idx++);
						if (second.size()) assignNpdaSymbolValue(second, idx++);

						cnfTable[npdaSymbol[leftString]].push_back(first + " " + second);
					}


				}


	}

	public: bool npdaAlgorithm(int indx, string current)
			{
				if (grammer[indx] == "$" && current.size() == 0)
				{
					ischeckfinished = true;
					return true;
				}

				else if (grammer[indx] != "$" && current.size() == 0)
				{
					return false;
				}

				if (ischeckfinished)
					return true;

				lastTextBox->Text += gcnew String(current.c_str()) + "\r\n";
				string term = "";

				// Calculation of dividing the first symbol
				while (current[0] != ' ' &&  current.size() > 0)
				{
					term.push_back(current[0]);
					current.erase(current.begin());
					if (current[0] == ' ')
					{
						current.erase(current.begin());
						break;
					}
				}


				int neumericVal = npdaSymbol[term];


				if (term[0] >= 'A'&&term[0] <= 'Z')
				{

					for (int i = 0; i < cnfTable[neumericVal].size(); i++)
					{
						bool ret = npdaAlgorithm(indx, cnfTable[neumericVal][i] + " " + current);
						if (ret)
						{
							return true;
						}

					}
					return false;

				}
				else
				{


					if (term == grammer[indx])
					{
						bool ret = npdaAlgorithm(indx + 1, current);
						if (!ret)
						{
							return ret;
						}
					}
					else
					{
						return false;
					}

				}

			}

	public:void calculateFirstOfGrammers()
	{
			   for (int i = 0; i < Nonterminal.size(); i++)
			   {
				   int main_idx = noOfSymbol[Nonterminal[i]];

				   queue<string>q;

				   q.push(Nonterminal[i]);

				   while (!q.empty())
				   {

					   string Non = q.front();
					   q.pop();
					   int idx = noOfSymbol[Non];

					   for (int j = 1; j <= totProduction[idx]; j++)
					   {
						   if (splitgrammer[idx][j][0][0] >= 'A'&&splitgrammer[idx][j][0][0] <= 'Z')
							   q.push(splitgrammer[idx][j][0]);
						   else
							   FIRST[main_idx].push_back(splitgrammer[idx][j][0]);
					   }
				   }

			   }
	}

	public: void calculateFollowOfGrammers()
	{
				for (int i = 0; i < Nonterminal.size(); i++)
				{
					int idx = noOfSymbol[Nonterminal[i]];
					if (Nonterminal[i] == "S")
						FOLLOW[idx].push_back("$");

					for (int k = 1; k <= totProduction[idx]; k++)
					{
						vector<string>v;
						for (int j = 0; j < splitgrammer[idx][k].size(); j++)
						{
							v.push_back(splitgrammer[idx][k][j]);
						}

						if (v.size() == 1)
						{
							string tmp1 = v[0];

							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z'))
							{
								int idx2 = noOfSymbol[tmp1];
								if (FOLLOW[idx2].size() == 0)
								{
									for (int x = 0; x < FOLLOW[idx].size(); x++)
									{
										FOLLOW[idx2].push_back(FOLLOW[idx][x]);
									}
									FOLLOW[idx2].push_back("$");
								}
							}
						}
						else
						{
							string tmp1, tmp2;
							tmp1 = v[0];
							tmp2 = v[1];
							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx1 = noOfSymbol[tmp1];
								int idx2 = noOfSymbol[tmp2];
								if (FOLLOW[idx1].size() == 0)
								for (int x = 0; x < FIRST[idx2].size(); x++)
								{
									FOLLOW[idx1].push_back(FIRST[idx2][x]);
								}
							}

							if ((tmp1[0] >= 'a'&&tmp1[0] <= 'z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx2 = noOfSymbol[tmp2];
								if (FOLLOW[idx2].size() == 0)
								for (int x = 0; x < FOLLOW[idx].size(); x++)
								{
									FOLLOW[idx2].push_back(FOLLOW[idx][x]);
								}
							}

							tmp1 = v[v.size() - 1];
							tmp2 = v[v.size() - 2];

							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx1 = noOfSymbol[tmp1];
								if (FOLLOW[idx1].size() == 0)
									FOLLOW[idx1].push_back("$");
							}
						}
					}
				}
	}

	public: void generateParseTable()
	{
				for (int i = 0; i < Nonterminal.size(); i++)
				{
					int idx = noOfSymbol[Nonterminal[i]];

					for (int j = 1; j <= totProduction[idx]; j++)
					{

						string str = splitgrammer[idx][j][0];

						if (str[0] == '#')
						{
							for (int num = 0; num < FOLLOW[idx].size(); num++)
							{
								int idxTerminal = noOfSymbol[FOLLOW[idx][num]];

								parseTable[idx][idxTerminal].push_back("#");

								if (FOLLOW[idx][num] == "$")
								{
									parseTable[idx][idxTerminal].push_back("#");
								}
							}
						}



						else if (str[0] >= 'A' && str[0] <= 'Z')
						{
							int idxCurrent = noOfSymbol[str];

							for (int num = 0; num < FIRST[idxCurrent].size(); num++)
							{
								int idxTerminal = noOfSymbol[FIRST[idxCurrent][num]];
								for (int k = 0; k < splitgrammer[idx][j].size(); k++)
									parseTable[idx][idxTerminal].push_back(splitgrammer[idx][j][k]);
							}

						}
						else
						{
							int idxTerminal = noOfSymbol[str];

							for (int k = 0; k < splitgrammer[idx][j].size(); k++)
								parseTable[idx][idxTerminal].push_back(splitgrammer[idx][j][k]);
						}
					}

				}
	}

	public: void preprocessingOfParseTable()
	{
				StreamReader^ reader = File::OpenText("ppGrammers.txt");
				String^ readString;
				int idx = 1, idx_term = 1;
				noOfSymbol["$"] = 0;

				while ((readString = reader->ReadLine()) != nullptr)
				{
					string s = marshal_as<std::string>(readString);

					string left = "";
					int i = 0;
					while (s[i] != '-')
					{
						left += s[i];
						i++;
					}

					if (noOfSymbol.find(left) == noOfSymbol.end())
					{
						noOfSymbol[left] = idx++;
						Nonterminal.push_back(left);
					}

					string temp = "";
					int noofProduction = 1;
					for (i = i + 1; s[i]; i++)
					{
						if (s[i] == ' ')
						{
							if (noOfSymbol.find(temp) == noOfSymbol.end())
							{
								if (temp[0] >= 'A'&&temp[0] <= 'Z')
								{
									noOfSymbol[temp] = idx++;
									Nonterminal.push_back(temp);
								}
								else
								{
									noOfSymbol[temp] = idx_term++;
									terminal.push_back(temp);
								}
							}

							splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);
							temp = "";
						}
						else if (s[i] == '|')
						{
							if (noOfSymbol.find(temp) == noOfSymbol.end())
							{
								if (temp[0] >= 'A'&&temp[0] <= 'Z')
								{
									noOfSymbol[temp] = idx++;
									Nonterminal.push_back(temp);
								}
								else
								{
									noOfSymbol[temp] = idx_term++;
									terminal.push_back(temp);
								}
							}
							splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);
							temp = "";
							noofProduction++;
						}
						else
							temp += s[i];
					}
					if (noOfSymbol.find(temp) == noOfSymbol.end())
					{
						if (temp[0] >= 'A'&&temp[0] <= 'Z')
						{
							noOfSymbol[temp] = idx++;
							Nonterminal.push_back(temp);
						}
						else
						{
							noOfSymbol[temp] = idx_term++;
							terminal.push_back(temp);
						}
					}

					splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);

					totProduction[noOfSymbol[left]] = noofProduction;
				}
	}

	public: void genParseTable()
	{
				preprocessingOfParseTable();
				calculateFirstOfGrammers();
				calculateFollowOfGrammers();


				generateParseTable();

	}

			public: void predictiveParsingAlgorithm()
			{
				stack<string> st;


				st.push("S");
				int idx = 0;

				while (!st.empty())
				{
					string temp = st.top();
					st.pop();

					if (temp[0] >= 'a' && temp[0] <= 'z')
					{

						lastTextBox->Text += gcnew String(temp.c_str());
						lastTextBox->Text += gcnew String(grammer[idx].c_str()) + "\r\n";
						if (temp != grammer[idx] || idx >= (int)grammer.size())
						{

							lastTextBox->Text += "  " + "Sentence is not Accepted";
							return;
						}
						else
						{
							idx++;
						}

					}
					else if (temp[0] >= 'A' && temp[0] <= 'Z')
					{
						int nonIdx = noOfSymbol[temp];
						int terIdx = noOfSymbol[grammer[idx]];


						if (parseTable[nonIdx][terIdx].size() == 0)//Empty of the parsing table 
						{
							lastTextBox->Text += "  " + "Sentence is not Accepted";
							return;
						}

						for (int i = parseTable[nonIdx][terIdx].size() - 1; i >= 0; i--)
						{
							if (parseTable[nonIdx][terIdx][i] != "#")
							{
								st.push(parseTable[nonIdx][terIdx][i]);
							}
						}
					}
					else
					{

					}

				}
				lastTextBox->Text += " Sentence is Accepted!";


			}
	public: Void getGrammer()
	{

				grammer.clear();
				for each(String ^ str in grammerWords)
				{
					if (str == nullptr) break;

					std::string stdString = marshal_as<std::string>(str);

					grammer.push_back(stdString);

				}

				grammer.push_back("$");


	}
	public: System::Void xmlWriteFunction()
	{
				XmlDocument^ doc = gcnew XmlDocument;

				doc->Load("temp.xml");

				XmlNode^ root = doc->DocumentElement;

				//Create a new node.
				XmlElement^ elem = doc->CreateElement(L"বাল");
				elem->InnerText = "noun";

				//Add the node to the document.
				root->AppendChild(elem);

				doc->Save("temp.xml");
	}
	public: System::Void xmlReadFunction()  // This function reads data from xml file and save into two txt files
	{


				XmlTextReader ^ xReader = gcnew XmlTextReader("word.xml");
				wstring Index = L"";
				string Key = "";
				int cnt = 0;
				while (xReader->Read())
				{
					switch (xReader->NodeType)
					{
					case XmlNodeType::Element:
					{
												 Index = marshal_as<std::wstring>(xReader->Name);
					}break;
					case XmlNodeType::Text:
					{
											  Key = marshal_as<std::string>(xReader->Value);
					}break;
					case XmlNodeType::EndElement:
					{
													hash[Index] = Key;
					}break;

					default:
						break;
					}

				}

				return;


	}

	public:System::Void splitInputText()
	{

			   Array::Clear(grammerWords, 0, grammerWords->Length);

			   words->Clear;

			   String ^ inputText = mainTextBox->Text;

			   String^ lineEndSymbol = "।";



			   String^ delimStr = ", .:\t\n";

			   array<Char>^ delimiter = delimStr->ToCharArray();



			   words = inputText->Split(delimiter);

			   int i = 0;

			   for each (String ^ str in words)
			   {
				   if (str == " ") continue;
				   /*string temp = marshal_as<std::string>(str);
				   if (temp== "\u0964")
				   {
				   mainTextBox->Text += " break hoise";
				   tot_word.push_back(i);
				   tot_line++, i = 0;
				   continue;
				   //break;
				   }
				   */

				   // XmlNodeList^ elemList = doc->GetElementsByTagName(str);

				   //mainTextBox->Text += str + " ";

				   wstring index = marshal_as<std::wstring>(str);

				   it = hash.find(index);
				   if (it == hash.end())
				   {
					   wstring compString = L"";
					   bool Found = false;

					   for (int i = 0; i < index.size(); i++)
					   {
						   compString += index[i];
						   if (hash.find(compString) != hash.end())
						   {
							   wstring bivoktiString = L"";

							   for (int j = i + 1; j < index.size(); j++)
								   bivoktiString += index[j];

							   if (bivoktiMap.find(bivoktiString) != bivoktiMap.end())
							   {
								   Found = true;
								   break;
							   }
						   }
					   }

					   if (Found)
					   {
						   it = hash.find(compString);
						   lastTextBox->Text += " " + gcnew String((it->second).c_str());
						   grammerWords[i++] = gcnew String((it->second).c_str());
						   continue;
					   }

					   addingPosForm ^ newForm = gcnew addingPosForm(str);
					   newForm->Show();

					   //newForm->Close();

					   lastTextBox->Text += str + " not found :( " + gcnew String( returnStringFromAddingPosForm.c_str() );

					   notFound = true;
					   //return;

				   }
				   else
				   {
					   lastTextBox->Text += " " + gcnew String((it->second).c_str());
					   grammerWords[i++] = gcnew String((it->second).c_str());
				   }


			   }

			   getGrammer();
	}

	private: void readBivokti(){
				 StreamReader^ reader = File::OpenText("bivokti.txt");
				 String^ readString;

				 while ((readString = reader->ReadLine()) != nullptr)
				 {
					 wstring index = marshal_as<std::wstring>(readString);

					 bivoktiMap[index] = true;
				 }

				 return;
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 readBivokti();
				 Timer timer;
				 timer.start();
				 xmlReadFunction();

				 genParseTable();
				 makeCnfTable();
				 double timeElapsed = timer.elapsedTime();

				 lastTextBox->Text = timeElapsed.ToString();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 lastTextBox->Text = "";
				 tot_line = 0;
				 grammer.clear();
				 notFound = false;
				 splitInputText();
				 /*for (int i = 0; i < tot_line; i++)
				  {
				  Array::Clear(grammerWords, 0, grammerWords->Length);
				  for (int j = 0; j < tot_word[i]; j++)
				  {
				  //mainTextBox->Text += " " + AllgrammerWords[i, j];
				  grammerWords[j] = AllgrammerWords[i, j];
				  }
				  getGrammer();
				  predictiveParsingAlgorithm();
				  } */
				 if (!notFound)
				 {
					 lastTextBox->Text = "";

					 predictiveParsingAlgorithm();
				 }

	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 grammer.clear();
				 notFound = false;

				 lastTextBox->Text = "";
				 splitInputText();
				 if (!notFound)
				 {
					 ischeckfinished = false;

					 lastTextBox->Text = "";
					 bool ret = npdaAlgorithm(0, "S");

					 if (ischeckfinished)
					 {
						 lastTextBox->Text += "Sentence is Accepted";
					 }
					 else
						 lastTextBox->Text += "Sentence is not Accepted";
				 }
	}
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void headingLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	};

}