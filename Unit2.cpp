//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
	Label1->Caption="Добро пожаловать в приложение Зоомагазин!";

	Label2->Caption="Здесь Вы можете создать свою базу        ";
	Label3->Caption="данных. Для этого введите информацию     ";
	Label4->Caption="о животном в соответствующее поле и      ";
	Label5->Caption="нажмите кнопку Добавить в разделе        ";
	Label6->Caption="Редактирование. Используйте кнопки       ";
	Label7->Caption="Удалить и Изменить для удаления и        ";
	Label8->Caption="изменения записей в таблице.             ";
	Label12->Caption="Также Вы можете загрузить существующую  ";
	Label13->Caption="базу через Открыть в разделе Файл.      ";

	Label9->Caption="Не забывайте нажать кнопку Показать,     ";
	Label10->Caption="чтобы посмотреть вашу таблицу.          ";
	Label11->Caption="Хорошего дня и удачных проектов!        ";
}
//---------------------------------------------------------------------------
