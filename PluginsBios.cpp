#include "PluginsBios.h"

#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>
#include <translation/TranslationUtils.h>
#include <String.h>
#include <LayoutBuilder.h>
#include <TranslationUtils.h>
#include <TranslatorFormats.h>

PluginBios::PluginBios(void)
:	BWindow(BRect(100,100,600,600),"Plugins & Bios",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS |B_NOT_RESIZABLE )

{
	
	
	DefaultViewb = new BView(BRect(Bounds()),"DefaultView", B_FOLLOW_ALL, B_WILL_DRAW);
    AddChild(DefaultViewb);
	DefaultViewb->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

//Plugins Box
	BGridLayout* pluginLayout = new BGridLayout(B_USE_DEFAULT_SPACING, B_USE_SMALL_SPACING);
	pluginLayout->SetInsets(B_USE_SMALL_SPACING);

	
	fPluginsBox = new BBox(BRect(0,0,500,590),"Plugins", B_FOLLOW_TOP, B_WILL_DRAW |B_NAVIGABLE_JUMP,B_FANCY_BORDER);
	fPluginsBox->SetLabel("Plugins");
	AddChild(fPluginsBox);

//Graphics Plugins  PopUp Menu 	
	PluginGraphicsMenu=   new BPopUpMenu("Null");

	PluginGraphicsMenu->SetTargetForItems(this);

			
	fGraphicsPfield = new  BMenuField("Graphic Plugin  List", "Graphics :  ",PluginGraphicsMenu);
	fGraphicsPfield->ResizeToPreferred();
	fGraphicsPfield->MoveTo(15,15);
	DefaultViewb->AddChild(fGraphicsPfield);


//Sound Plugins  PopUp Menu 	
	PluginSoundMenu=   new BPopUpMenu("Null");

	PluginSoundMenu->SetTargetForItems(this);

			
	fSoundPfield = new  BMenuField("Sound Plugin  List", "Sound :  ",PluginSoundMenu);
	fSoundPfield->ResizeToPreferred();
	fSoundPfield->MoveTo(15,60);
	DefaultViewb->AddChild(fSoundPfield);

//Controller 1 Plugins  PopUp Menu 	
	PluginController1PMenu=   new BPopUpMenu("Null");

	PluginController1PMenu->SetTargetForItems(this);

			
	fController1Pfield = new  BMenuField("Controller 1 Plugin  List", "Controller 1 :  ",PluginController1PMenu);
	fController1Pfield->ResizeToPreferred();
	fController1Pfield->MoveTo(15,105);
	DefaultViewb->AddChild(fController1Pfield);


//Controler 2 Plugins  PopUp Menu 	
	PluginController2PMenu=   new BPopUpMenu("Null");

	PluginController2PMenu->SetTargetForItems(this);

			
	fController2Pfield = new  BMenuField("Controller 2 Plugin  List", "Controller 2 :  ",PluginController2PMenu);
	fController2Pfield->ResizeToPreferred();
	fController2Pfield->MoveTo(15,150);
	DefaultViewb->AddChild(fController2Pfield);




//Cd Rom Plugins  PopUp Menu 	
	CdRomPluginMenu=   new BPopUpMenu("Null");

	CdRomPluginMenu->SetTargetForItems(this);

			
	fCdRomfield = new  BMenuField("Cd Rom Plugin  List", "CD Rom :  ",CdRomPluginMenu);
	fCdRomfield->ResizeToPreferred();
	fCdRomfield->MoveTo(15,195);
	DefaultViewb->AddChild(fCdRomfield);
	
	
//Link Cable Plugins  PopUp Menu 	
 	LinCablePluginMenu=   new BPopUpMenu("Null");

	LinCablePluginMenu->SetTargetForItems(this);

			
	fLinkCablefield = new  BMenuField("Link Cable Plugin  List", "Link Cable :  ",LinCablePluginMenu);
	fLinkCablefield->ResizeToPreferred();
	fLinkCablefield->MoveTo(15,240);
	DefaultViewb->AddChild(fLinkCablefield);
//Folder to search the plugins

	SearchPluginMenu=   new BPopUpMenu("Null");

	SearchPluginMenu->SetTargetForItems(this);

			
	fSearchInDirfield = new  BMenuField("Search Folder Plugin  List", "Search :  ",SearchPluginMenu);
	fSearchInDirfield->ResizeToPreferred();
	fSearchInDirfield->MoveTo(15,285);
	DefaultViewb->AddChild(fSearchInDirfield);

//Bios Box



	fBiosBox = new BBox(BRect(0,350,500,550),"BIOS", B_FOLLOW_LEFT , B_WILL_DRAW | B_FRAME_EVENTS|B_NAVIGABLE_JUMP,B_FANCY_BORDER);
	fBiosBox->SetLabel("BIOS");
	AddChild(fBiosBox);
	
	//Pop Up Menu for Bios
	
	BiosMenu=   new BPopUpMenu("Null");

	BiosMenu->SetTargetForItems(this);

			
	fBiosfield = new  BMenuField("Bios List", "Bios :  ",BiosMenu);
	fBiosfield->ResizeToPreferred();
	fBiosfield->MoveTo(15,385);
	DefaultViewb->AddChild(fBiosfield);

 
 //Search Folder
 
	SearchPluginMenu=   new BPopUpMenu("Null");

	SearchPluginMenu->SetTargetForItems(this);

			
	fSearchInDirfield = new  BMenuField("Search Folder Plugin  List", "Search :  ",SearchPluginMenu);
	fSearchInDirfield->ResizeToPreferred();
	fSearchInDirfield->MoveTo(15,430);
	DefaultViewb->AddChild(fSearchInDirfield);

	
}


void PluginBios::MessageReceived(BMessage *msg1)
{
	switch (msg1->what)
	{
	
		default:
		{
			BWindow::MessageReceived(msg1);
			break;
		}
		
	}
		
}

//
//virtual		PluginBios::~PluginBios();
//{
//	
//	
//	
//}
//
//bool PluginBios::QuitRequested(void)
//{
//	be_app->PostMessage(B_QUIT_REQUESTED);
//	return true;
//}
//
