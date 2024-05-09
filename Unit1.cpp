//---------------------------------------------------------------------------

#include <vcl.h>
#include <vcl.clipbrd.hpp>    //добавили
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

vector <petshop> animals;
int iMax=0,iCur=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{

    animals.push_back(petshop());

	strcpy(animals[iMax].pet,((AnsiString)EditPet->Text).c_str());
	strcpy(animals[iMax].family, AnsiString(EditFamily->Text).c_str());
	strcpy(animals[iMax].breed, AnsiString(EditBreed->Text).c_str());
	strcpy(animals[iMax].color, AnsiString(EditColor->Text).c_str());

	animals[iMax].age = EditAge->Text.ToIntDef(0);
	animals[iMax].price = EditPrice->Text.ToIntDef(0);

	iCur = iMax;
	iMax++;
	LabelNum->Caption = IntToStr(iMax);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowRecord()
{
	EditPet->Text=animals[iCur].pet;
	EditFamily->Text=animals[iCur].family;
	EditBreed->Text=animals[iCur].breed;
	EditColor->Text=animals[iCur].color;

	EditAge->Text=IntToStr(animals[iCur].age);
	EditPrice->Text=IntToStr(animals[iCur].price);

	LabelNum->Caption=IntToStr(iCur+1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPrevClick(TObject *Sender)
{
	if(iCur<=0) return;
	iCur--;
	ShowRecord();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNextClick(TObject *Sender)
{
	if(iCur>=iMax-1) return;
	iCur++;
	ShowRecord();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	SaveDialog1->Execute();

	FILE *f = fopen(AnsiString(SaveDialog1->FileName).c_str(), "wb");

	if( f )
		fwrite(&animals[0],sizeof(petshop),iMax,f);
	else
		ShowMessage("Файл не был сохранен.");

	fclose( f );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	OpenDialog1->Execute();

	FILE *f = fopen(AnsiString(OpenDialog1->FileName).c_str(), "rb");

	if( f==0 ){
		ShowMessage("Пожалуйста, выберите файл.");
		return;
	}

	for(int i=0;i<animals.max_size();i++){
		petshop s;
		fread(&s,sizeof(petshop),1,f);

		if(feof(f))
			break;

		animals.push_back(s);
	}

	fclose(f);

	iMax=animals.size();
	iCur=0;
	ShowRecord();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ToolBtnBClick(TObject *Sender)
{
	if (ToolBtnB->Down)
		Memo1->Font->Style=Memo1->Font->Style<<fsBold;
	else
		Memo1->Font->Style=Memo1->Font->Style>>fsBold;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnIClick(TObject *Sender)
{
	if (ToolBtnI->Down)
		Memo1->Font->Style=Memo1->Font->Style<<fsItalic;
	else
		Memo1->Font->Style=Memo1->Font->Style>>fsItalic;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnUClick(TObject *Sender)
{
	if (ToolBtnU->Down)
		Memo1->Font->Style=Memo1->Font->Style<<fsUnderline;
	else
		Memo1->Font->Style=Memo1->Font->Style>>fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnClearClick(TObject *Sender)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnCopyClick(TObject *Sender)
{
	Clipboard()->AsText=Memo1->SelText;      //copy
	Memo1->SelText;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnCutClick(TObject *Sender)
{
	Clipboard()->AsText=Memo1->SelText;      //cut
	Memo1->SelText="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolBtnPasteClick(TObject *Sender)
{
	Memo1->SelText=Clipboard()->AsText;
    Memo1->SelText;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N81Click(TObject *Sender)
{
	Memo1->Font->Size=8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N101Click(TObject *Sender)
{
	Memo1->Font->Size=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N121Click(TObject *Sender)
{
	Memo1->Font->Size=12;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N161Click(TObject *Sender)
{
	Memo1->Font->Size=14;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N162Click(TObject *Sender)
{
	Memo1->Font->Size=16;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N181Click(TObject *Sender)
{
	Memo1->Font->Size=18;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N201Click(TObject *Sender)
{
	Memo1->Font->Size=20;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
	//
	StringGrid1->Rows[0]->Add("");
	StringGrid1->Rows[0]->Add("зверь");
	StringGrid1->Rows[0]->Add("отряд");
	StringGrid1->Rows[0]->Add("порода");
	StringGrid1->Rows[0]->Add("масть");
	StringGrid1->Rows[0]->Add("возраст");
	StringGrid1->Rows[0]->Add("цена");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
	for(int i=1;i<StringGrid1->RowCount;i++)
		StringGrid1->Rows[i]->Clear();

	StringGrid1->RowCount=animals.size()+1;

	for(int i=1;i<=animals.size();i++){
		StringGrid1->Cells[0][i]=i;
		StringGrid1->Rows[i]->Add(animals[i-1].pet);
		StringGrid1->Rows[i]->Add(animals[i-1].family);
		StringGrid1->Rows[i]->Add(animals[i-1].breed);
		StringGrid1->Rows[i]->Add(animals[i-1].color);
		StringGrid1->Rows[i]->Add(animals[i-1].age);
		StringGrid1->Rows[i]->Add(animals[i-1].price);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		Memo1->Lines->SaveToFile(SaveDialog1->FileName);   //save
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
		Memo1->Lines->LoadFromFile(OpenDialog1->FileName);   //open
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	try{
		if (iMax>0) {
			animals.erase(animals.begin()+iCur);
			iMax-=1;

			iCur=0;
            ShowRecord();
		} else {
			EditPet->Text = "";
			EditFamily->Text = "";
			EditBreed->Text = "";
			EditColor->Text = "";
			EditAge->Text = "";
			EditPrice->Text = "";

			ShowMessage("Чего нет, удалено быть не может.");
		}
	}

	catch(...){
		ShowMessage("Что-то не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
	try{
		if ((iCur>=0) && (iMax>0)) {
			strcpy(animals[iCur].pet,((AnsiString)EditPet->Text).c_str());
			strcpy(animals[iCur].family, AnsiString(EditFamily->Text).c_str());
			strcpy(animals[iCur].breed, AnsiString(EditBreed->Text).c_str());
			strcpy(animals[iCur].color, AnsiString(EditColor->Text).c_str());
			animals[iCur].age = EditAge->Text.ToIntDef(0);
			animals[iCur].price = EditPrice->Text.ToIntDef(0);
		} else {
			ShowMessage("Ничего нельзя изменить.");
		}
	}

	catch(...){
		ShowMessage("Что-то не так.");
	}
}
//---------------------------------------------------------------------------







void __fastcall TForm1::CBPetChange(TObject *Sender)
{
	try{
		switch(CBPet->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortPetDown); break;
			case 1: sort(animals.begin(),animals.end(),SortPetUp); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBFamilyChange(TObject *Sender)
{
	try{
		switch(CBFamily->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortFamilyDown); break;
			case 1: sort(animals.begin(),animals.end(),SortFamilyUp); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBBreedChange(TObject *Sender)
{
	try{
		switch(CBBreed->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortBreedDown); break;
			case 1: sort(animals.begin(),animals.end(),SortBreedUp); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBColorChange(TObject *Sender)
{
	try{
		switch(CBColor->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortColorDown); break;
			case 1: sort(animals.begin(),animals.end(),SortColorUp); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBAgeChange(TObject *Sender)
{
	try{
		switch(CBAge->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortAgeUp); break;
			case 1: sort(animals.begin(),animals.end(),SortAgeDown); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBPriceChange(TObject *Sender)
{
	try{
		switch(CBPrice->ItemIndex){
			case 0: sort(animals.begin(),animals.end(),SortPriceUp); break;
			case 1: sort(animals.begin(),animals.end(),SortPriceDown); break;
		}

		iCur=0;
		ShowRecord();
	}

	catch(...){
		ShowMessage("А что сортировать-то?");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::EditPetClick(TObject *Sender)
{
	EditPet->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditFamilyClick(TObject *Sender)
{
	EditFamily->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditBreedClick(TObject *Sender)
{
	EditBreed->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditColorClick(TObject *Sender)
{
	EditColor->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditAgeClick(TObject *Sender)
{
	EditAge->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditPriceClick(TObject *Sender)
{
	EditPrice->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnSearchPriceClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		a.price=EditPrice->Text.ToIntDef(0);

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindPrice),a));

		iCur=p-animals.begin();
        ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSearchAgeClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		a.age=EditAge->Text.ToIntDef(0);

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindAge),a));

		iCur=p-animals.begin();
		ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSearchPetClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		strcpy(a.pet,AnsiString(EditPet->Text).c_str());

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindPet),a));

		iCur=p-animals.begin();
		ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSearchFamilyClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		strcpy(a.family,AnsiString(EditFamily->Text).c_str());

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindFamily),a));

		iCur=p-animals.begin();
		ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSearchBreedClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		strcpy(a.breed,AnsiString(EditBreed->Text).c_str());

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindBreed),a));

		iCur=p-animals.begin();
		ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSearchColorClick(TObject *Sender)
{
	try{
		petshop a;
		vector <petshop>::iterator p;

		strcpy(a.color,AnsiString(EditColor->Text).c_str());

		p=find_if(animals.begin(),animals.end(),bind2nd(ptr_fun(FindColor),a));

		iCur=p-animals.begin();
		ShowRecord();

		if (iCur>=iMax) {
		iCur=0;
		ShowRecord();
		ShowMessage("Что-то не так. Попробуйте ввести запрос заново.");
		}
	}

	catch(...){
		ShowMessage("Что-то ну совсем не так.");
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N9Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
