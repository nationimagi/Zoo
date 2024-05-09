//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct petshop{
	char pet[40];
	char family[40];
	char breed[40];
	char color[10];
	int age;
	int price;

};

bool SortPriceUp(const petshop& a, const petshop& b){
	return a.price<b.price;
}      //for sort by price <

bool SortPriceDown(const petshop& a, const petshop& b){
	return a.price>b.price;
}      //for sort by price >

bool FindPrice(petshop a, petshop b){
	return a.price==b.price;
}      //for search by price


bool SortPetUp(const petshop& a, const petshop& b){
	return strcmp(a.pet,b.pet)>0;
}      //for sort by pet <

bool SortPetDown(const petshop& a, const petshop& b){
	return strcmp(a.pet,b.pet)<0;
}      //for sort by pet >

bool FindPet(petshop a, petshop b){
	return strcmp(a.pet,b.pet)==0;
}      // for search by pet


bool SortFamilyUp(const petshop& a, const petshop& b){
	return strcmp(a.family,b.family)>0;
}      //for sort by family <

bool SortFamilyDown(const petshop& a, const petshop& b){
	return strcmp(a.family,b.family)<0;
}      //for sort by family >

bool FindFamily(petshop a, petshop b){
	return strcmp(a.family,b.family)==0;
}      // for search by family


bool SortBreedUp(const petshop& a, const petshop& b){
	return strcmp(a.breed,b.breed)>0;
}      //for sort by breed <

bool SortBreedDown(const petshop& a, const petshop& b){
	return strcmp(a.breed,b.breed)<0;
}      //for sort by breed >

bool FindBreed(petshop a, petshop b){
	return strcmp(a.breed,b.breed)==0;
}      // for search by breed


bool SortColorUp(const petshop& a, const petshop& b){
	return strcmp(a.color,b.color)>0;
}      //for sort by color <

bool SortColorDown(const petshop& a, const petshop& b){
	return strcmp(a.color,b.color)<0;
}      //for sort by color >

bool FindColor(petshop a, petshop b){
	return strcmp(a.color,b.color)==0;
}      // for search by color


bool SortAgeUp(const petshop& a, const petshop& b){
	return a.age<b.age;
}      //for sort by age <

bool SortAgeDown(const petshop& a, const petshop& b){
	return a.age>b.age;
}      //for sort by age >

bool FindAge(petshop a, petshop b){
	return a.age==b.age;
}      //for search by age


extern vector <petshop> animals;
extern int iMax, iCur;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *EditPet;
	TEdit *EditFamily;
	TEdit *EditBreed;
	TEdit *EditColor;
	TEdit *EditAge;
	TEdit *EditPrice;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TPopupMenu *PopupMenu1;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolBtnCopy;
	TToolButton *ToolBtnCut;
	TToolButton *ToolBtnPaste;
	TToolButton *ToolButton4;
	TToolButton *ToolBtnB;
	TToolButton *ToolBtnI;
	TToolButton *ToolBtnU;
	TToolButton *ToolButton8;
	TToolButton *ToolBtnSize;
	TMenuItem *N81;
	TMenuItem *N101;
	TMenuItem *N121;
	TMenuItem *N161;
	TLabel *LabelNum;
	TButton *ButtonPrev;
	TButton *ButtonNext;
	TLabel *Label7;
	TMemo *Memo1;
	TToolButton *ToolBtnClear;
	TMenuItem *N162;
	TMenuItem *N181;
	TMenuItem *N201;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton1;
	TLabel *Label8;
	TButton *BtnSearchPrice;
	TComboBox *CBPet;
	TComboBox *CBFamily;
	TComboBox *CBBreed;
	TComboBox *CBColor;
	TComboBox *CBAge;
	TComboBox *CBPrice;
	TButton *BtnSearchAge;
	TButton *BtnSearchColor;
	TButton *BtnSearchBreed;
	TButton *BtnSearchFamily;
	TButton *BtnSearchPet;
	TMenuItem *N9;
	void __fastcall N5Click(TObject *Sender);
	void __fastcall ButtonPrevClick(TObject *Sender);
	void __fastcall ButtonNextClick(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ToolBtnBClick(TObject *Sender);
	void __fastcall ToolBtnIClick(TObject *Sender);
	void __fastcall ToolBtnUClick(TObject *Sender);
	void __fastcall ToolBtnClearClick(TObject *Sender);
	void __fastcall ToolBtnCopyClick(TObject *Sender);
	void __fastcall ToolBtnCutClick(TObject *Sender);
	void __fastcall ToolBtnPasteClick(TObject *Sender);
	void __fastcall N81Click(TObject *Sender);
	void __fastcall N101Click(TObject *Sender);
	void __fastcall N121Click(TObject *Sender);
	void __fastcall N161Click(TObject *Sender);
	void __fastcall N162Click(TObject *Sender);
	void __fastcall N181Click(TObject *Sender);
	void __fastcall N201Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall CBPetChange(TObject *Sender);
	void __fastcall CBFamilyChange(TObject *Sender);
	void __fastcall CBBreedChange(TObject *Sender);
	void __fastcall CBColorChange(TObject *Sender);
	void __fastcall CBAgeChange(TObject *Sender);
	void __fastcall CBPriceChange(TObject *Sender);
	void __fastcall EditPetClick(TObject *Sender);
	void __fastcall EditFamilyClick(TObject *Sender);
	void __fastcall EditBreedClick(TObject *Sender);
	void __fastcall EditColorClick(TObject *Sender);
	void __fastcall EditAgeClick(TObject *Sender);
	void __fastcall EditPriceClick(TObject *Sender);
	void __fastcall BtnSearchPriceClick(TObject *Sender);
	void __fastcall BtnSearchAgeClick(TObject *Sender);
	void __fastcall BtnSearchPetClick(TObject *Sender);
	void __fastcall BtnSearchFamilyClick(TObject *Sender);
	void __fastcall BtnSearchBreedClick(TObject *Sender);
	void __fastcall BtnSearchColorClick(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

void __fastcall ShowRecord(); //добавили

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
