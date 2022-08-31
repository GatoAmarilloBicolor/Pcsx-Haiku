#include "MainWindow.h"
#include "PluginsBios.h"
#include "MemcardDlg.h"

#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>
#include <translation/TranslationUtils.h>
#include <String.h>



bool file_loaded=false;


MainWindow::MainWindow(void)

//Create a new window
    :	BWindow(BRect(100,100,519,336),"PCSXR-Haiku",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS |B_NOT_RESIZABLE )
{


    bmp_h1 = BTranslationUtils::GetBitmapFile("pcsxr.png");
	logo_pcsx =BTranslationUtils::GetBitmapFile("pixmaps//pcsxr-icon.png");
	
	
    DefaultView = new BView(BRect(Bounds()),"DefaultView", B_FOLLOW_ALL, B_WILL_DRAW);
    AddChild(DefaultView);


    if (bmp_h1)
{
         DefaultView->SetViewBitmap(bmp_h1,B_FOLLOW_ALL,0);
}
            else
{
    DefaultView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}
    BRect r(Bounds());
	r.bottom = 20;


    //Menu Bar
    fMenuBar = new BMenuBar(r,  "MainMenuBar", B_FOLLOW_LEFT_RIGHT | B_FOLLOW_TOP, B_ITEMS_IN_ROW, true );
    DefaultView->AddChild(fMenuBar);

    //FILE
	BMenu *menu = new BMenu("File");
    //ITems for File
	menu->AddItem(new BMenuItem("Run CD",new BMessage(M_SET_COLOR_RED),'o'));
	menu->AddItem(new BMenuItem("Run ISO",new BMessage(RUN_ISO),'i'));
	menu->AddItem(new BMenuItem("Run Bios",new BMessage(M_SET_COLOR_BLUE),'b'));
	menu->AddItem(new BMenuItem("Run EXE",new BMessage(M_SET_COLOR_BLACK),'e'));
	menu->AddSeparatorItem();
	menu->AddItem(new BMenuItem("Quit",new BMessage(B_QUIT_REQUESTED),'q'));
//	menu->SetTarget(be_app);
	fMenuBar->AddItem(menu);
	

    //Emulator
	menu = new BMenu("Emulator");
    //Items for  Emulator
 
	menu->AddItem(new BMenuItem("Continue",new BMessage(M_SET_COLOR_RED),'c'));
	menu->AddItem(new BMenuItem("Reset",new BMessage(RESET),'r'));
	menu->AddItem(new BMenuItem("Shutdown",new BMessage(M_SET_COLOR_BLUE),'s'));
	menu->AddSeparatorItem();
	menu->AddItem(new BMenuItem("Switch Iso",new BMessage(M_SET_COLOR_BLACK),'w'));
	menu->AddSeparatorItem();


	
//Submenus de slots
	subMenuSaveState = new BMenu("Save State");
	menu->AddItem(subMenuSaveState);
		subMenuSaveState->AddItem(new BMenuItem("Slot 1", new BMessage(SLOT_1),'1' ));
		subMenuSaveState->AddItem(new BMenuItem("Slot 2", new BMessage(SLOT_1),'2'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 3", new BMessage(SLOT_1),'3'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 4", new BMessage(SLOT_1),'4'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 5", new BMessage(SLOT_1),'5'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 6", new BMessage(SLOT_1),'6'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 7", new BMessage(SLOT_1),'7'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 8", new BMessage(SLOT_1),'8'));
		subMenuSaveState->AddItem(new BMenuItem("Slot 9", new BMessage(SLOT_1),'9'));
		subMenuSaveState->AddItem(new BMenuItem("Other", new BMessage(SLOT_1),'0'));
	subMenuLoadState= new BMenu("Load State");
	menu->AddItem(subMenuLoadState);
		subMenuLoadState->AddItem(new BMenuItem("Slot 1", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 2", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 3", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 4", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 5", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 6", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 7", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 8", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Slot 9", new BMessage(SLOT_1)));
		subMenuLoadState->AddItem(new BMenuItem("Other", new BMessage(SLOT_1)));

	fMenuBar->AddItem(menu);





    //Configuration
	menu = new BMenu("Configuration");

    //Items for  Configuration
	menu->AddItem(new BMenuItem("Plugins & Bios",new BMessage(PLUGINS_BIOS),'p'));
	menu->AddItem(new BMenuItem("Graphics",new BMessage(GRAPHICS_PLUGIN),'g'));
	menu->AddItem(new BMenuItem("Sound",new BMessage(M_SET_COLOR_BLUE),'s'));
	menu->AddItem(new BMenuItem("CD Rom & Iso",new BMessage(M_SET_COLOR_BLACK)));
	menu->AddItem(new BMenuItem("Controller",new BMessage(M_SET_COLOR_BLACK)));
	menu->AddItem(new BMenuItem("Link Cable",new BMessage(M_SET_COLOR_BLACK)));
	menu->AddSeparatorItem();
	menu->AddItem(new BMenuItem("Netplay",new BMessage(M_SET_COLOR_RED)));
	menu->AddSeparatorItem();
	menu->AddItem(new BMenuItem("CPU",new BMessage(CPU_CFG)));
	menu->AddItem(new BMenuItem("Memory Cards",new BMessage(MEM_CARD_DLG),'m'));
	menu->AddSeparatorItem();

		SubMenuCheat= new BMenu("Cheats");
	menu->AddItem(SubMenuCheat);
		SubMenuCheat->AddItem(new BMenuItem("Browse", new BMessage(SLOT_1)));
		SubMenuCheat->AddItem(new BMenuItem("Search", new BMessage(SLOT_1)));
		
	menu->AddItem(new BMenuItem("Memory Dump",new BMessage(M_SET_COLOR_BLACK),'E'));
	fMenuBar->AddItem(menu);
	
	
    //Help
    MainMenu = new BMenu("Help", B_ITEMS_IN_COLUMN);
    fMenuBar->AddItem(MainMenu);
    //Help Items
    AboutItem = new BMenuItem("About", new BMessage(ABOUT_ALERT_SHOW));
    MainMenu->AddItem(AboutItem);

//Disable the MenuItems until the Iso is loaded
	ContinueItem= fMenuBar->FindItem("Continue");
	ResetItem=fMenuBar->FindItem("Reset");	
	ShutdownItem=fMenuBar->FindItem("Shutdown");	
	SwitchItem=fMenuBar->FindItem("Switch Iso");
	MemoryDumpItem=fMenuBar->FindItem("Memory Dump");

		if (file_loaded==false)
{			 
			    ContinueItem->SetEnabled(false);
				ResetItem->SetEnabled(false);
				ShutdownItem->SetEnabled(false);
				SwitchItem->SetEnabled(false);
				MemoryDumpItem->SetEnabled(false);
}
     		else
{           
				ContinueItem->SetEnabled(true);
				ResetItem->SetEnabled(true);
				ShutdownItem->SetEnabled(false);
				ResetItem->SetEnabled(false);
				SwitchItem->SetEnabled(false);
				MemoryDumpItem->SetEnabled(false);
 }

	

 //Barra Inferior
//    dMenuBar = new BMenuBar(200,  "StatusBar", B_FOLLOW_LEFT_RIGHT | B_FOLLOW_TOP, B_ITEMS_IN_ROW, true );
//    DefaultView->AddChild(dMenuBar);


}


void MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{


//
//case HELLO_BTN_CLICKED:
//       {
////	     BAlert(const char* title,
////       const char* text,
////       const char* button0Label,
////       const char* button1Label = NULL,
////       const char* button2Label = NULL,
////       button_width widthStyle = B_WIDTH_AS_USUAL,
////       alert_type type = B_INFO_ALERT);
//           BString hello;
//           hello.Append("Hello");
//           hello.Append(InputBox->Text());
//           if (hello.CountChars() ==6)
//           {
//           BAlert *Alert = new BAlert("Hello World Alert", "Hello World", "Haiku es una Chimba", NULL, NULL, B_WIDTH_AS_USUAL, B_INFO_ALERT);
//           Alert->Go();
//           }
//
//           else
//           {
//                BAlert *Alert = new BAlert("Hello World Alert", "Hello World", "Haiku es una Chimba", NULL, NULL, B_WIDTH_AS_USUAL, B_INFO_ALERT);
//                Alert->Go();
//           }
//       }

	case PLUGINS_BIOS:
	{
		
		PluginBios *pluginbi = new PluginBios();
		pluginbi->Show();
		break;
	}
	

	case MEM_CARD_DLG:
	{
	MemcardDlg* memcardcfg = new MemcardDlg();
	memcardcfg->Show(); 
	
	break;	
	}

	
//
//	case CONFIG_BIOS_ALERT_SHOW:
//	{  
//	
//	 BAlert *Alert = new BAlert("Config Plugins & Bios", " Configurator Plugins & Bios    Hello World example aplication\n\nVersion 1.0\n\tLicencia MIT", "OK!", NULL, NULL, B_WIDTH_AS_USUAL, B_INFO_ALERT);
//      Alert->Go();
//      
//	}
	
		case ABOUT_ALERT_SHOW:
    {
    	  	
    	BAlert *Alert = new BAlert("About Alert", "Hello , Welcome to PCSXR for Haiku\n\nVersion 1.0\n\tLicencia MIT\nPorted by CozmoKat", "OK!", NULL, NULL, B_WIDTH_AS_USUAL, B_INFO_ALERT);
        Alert->Go();
		break;
    }

	
	


		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
		
		
		
		
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
