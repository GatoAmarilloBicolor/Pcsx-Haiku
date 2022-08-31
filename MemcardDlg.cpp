#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>
#include <translation/TranslationUtils.h>
#include <String.h>
#include <LayoutBuilder.h>
#include <TranslationUtils.h>
#include <TranslatorFormats.h>
#include <ColumnListView.h>
#include <ColumnTypes.h>

#include  "MemcardDlg.h"
#define B_TRANSLATE(x) x



ElementListView::ElementListView(const char *name)
	: BColumnListView("elementListView", B_FRAME_EVENTS|B_NAVIGABLE, B_FANCY_BORDER, false)
{	

	int32 i = 0;
	AddColumn(new BBitmapColumn(B_TRANSLATE("Icon"), 180, 10, 600, 0), i++);
	AddColumn(new BIntegerColumn(B_TRANSLATE("Title"), 70, 10, 100, B_ALIGN_RIGHT), i++);
	AddColumn(new BIntegerColumn(B_TRANSLATE("Status"), 70, 10, 100, B_ALIGN_RIGHT), i++);
	AddColumn(new BSizeColumn(B_TRANSLATE("ID"), 80, 10, 600), i++);
	AddColumn(new BSizeColumn(B_TRANSLATE("Name"), 90, 10, 600), i++);
	

}








//  Cajas de Memory Card

MemcardDlg::MemcardDlg(void)
:	BWindow(BRect(100,100,900,600),"Memory Cards",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS |B_NOT_RESIZABLE )

{
	
	
	DefaultViewb = new BView(BRect(Bounds()),"DefaultView", B_FOLLOW_ALL, B_WILL_DRAW);
    AddChild(DefaultViewb);
	DefaultViewb->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

//Plugins Box
	BGridLayout* pluginLayout = new BGridLayout(B_USE_DEFAULT_SPACING, B_USE_SMALL_SPACING);
	pluginLayout->SetInsets(B_USE_SMALL_SPACING);

	// Memory Card 1 Box 
	MemoryCard1Box = new BBox(BRect(0,0,400,590),"Memmory Card 1", B_FOLLOW_TOP, B_WILL_DRAW |B_NAVIGABLE_JUMP,B_FANCY_BORDER);
	MemoryCard1Box->SetLabel("Memory Card 1");
	AddChild(MemoryCard1Box);


	
	// Memory Card 2 Box 
	MemoryCard2Box = new BBox(BRect(300,0,600,590),"Memmory Card 2", B_FOLLOW_TOP, B_WILL_DRAW |B_NAVIGABLE_JUMP,B_FANCY_BORDER);
	MemoryCard2Box->SetLabel("Memory Card 2");
	AddChild(MemoryCard2Box);
	
	
	
	


};


void MemcardDlg::MessageReceived(BMessage *msg1)
{
	switch (msg1->what)
	{
	
		default:
		{
			BWindow::MessageReceived(msg1);
			break;
		}
		
	}
		
};
