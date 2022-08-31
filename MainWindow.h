#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Window.h>
#include <MenuBar.h>
#include <Menu.h>
#include <MenuItem.h>
#include <Bitmap.h>
#include  <Alert.h>

#include "PluginsBios.h"
#include "MemcardDlg.h"

enum
{

    RUN_ISO= 'ri',
    RESET = 'rs',
    GRAPHICS_PLUGIN = 'gp',
    CPU_CFG = 'cc',
    MEM_CARD_DLG = 'mcd',
	
    ABOUT_ALERT_SHOW='ab',
	CONFIG_BIOS_ALERT_SHOW='cas',
	M_SET_COLOR_RED = 'sred',
	PLUGINS_BIOS='pb',
	
	M_SET_COLOR_BLUE = 'sblu',
	M_SET_COLOR_BLACK = 'sblk',
	FILE_LOADED= 'fl',
	TOGGLE_OPTIONS_MSG='tom',
	SLOT_1='s1',
};

class MainWindow : public BWindow
{
public:
						MainWindow(void);
			void		MessageReceived(BMessage *msg);
			bool		QuitRequested(void);
			
private:
			PluginBios	*VentanaPluginsBios;

            BView       *DefaultView;
			
			BMenuBar	*fMenuBar;
			BMenuBar	*dMenuBar;
            
            BMenu       *MainMenu;
			BMenu		*subMenuSaveState;
			BMenu		*subMenuLoadState;
			BMenu		*SubMenuCheat;
            //File
            BMenuItem   *RunCdItem;
            BMenuItem   *RunIsoItem;
            BMenuItem   *RunBiosItem;
            BMenuItem   *RunExeItem;
            BMenuItem   *QuitItem;
            //Emulator
            BMenuItem   *ContinueItem;
            BMenuItem   *ResetItem;
            BMenuItem   *ShutdownItem;
            BMenuItem   *SwitchItem;
            BMenuItem   *SaveStateItem;
            BMenuItem   *LoadStateItem;
            //Configuration
            BMenuItem   *PluginBiosItem;
            BMenuItem   *GraphicsItem;
            BMenuItem   *SoundItem;
            BMenuItem   *CDRomItem;
            BMenuItem   *ControllersItem;
            BMenuItem   *LinkCableItem;
            BMenuItem   *NetPlayItem;
            BMenuItem   *CPUItem;
            BMenuItem   *MemoryCardItem;
            BMenuItem   *CheatItem;
            BMenuItem   *MemoryDumpItem;

            //About
            BMenuItem   *AboutItem;
            
            //images
            BBitmap 			*bmp_h1; // store here first picture
			BBitmap				*logo_pcsx ;//store the pcsx logo
};




#endif
