#ifndef PLUGINSBIOS_H
#define PLUGINSBIOS_H

#include <StringView.h>
#include <Window.h>
#include <MenuBar.h>
#include <Menu.h>
#include <MenuItem.h>
#include <Bitmap.h>
#include  <Alert.h>
#include <Box.h>
#include <PopUpMenu.h>


//enum
//{
//	
//	
//	
//	
//}

class  PluginBios  : public  BWindow
{
public:
						PluginBios(void);
			void		MessageReceived(BMessage *msg1);
//			virtual		~PluginBios();
			
private:
		BView * 				DefaultViewb;
		

		BBox*					fPluginsBox;
		
//Graphics

	
		BMenu*	 			PluginGraphicsMenu;
		BMenuField*		fGraphicsPfield;

		BButton*			GraphicPluginButton;
		BButton*			AboutGraphicButtonPlugin;
		
//Sound
		
		
		BMenu*				PluginSoundMenu;
		BMenuField*		fSoundPfield;
		BButton*			SoundPluginButton;
		BButton*			AboutSoundButtonPlugin;


//Controllers
		BMenu*				PluginController1PMenu;
		BMenuField*		fController1Pfield;
		BButton*			Controller1PPluginButton;
		BButton*			AboutController1PButtonPlugin;
//2
		BMenu*				PluginController2PMenu;
		BMenuField*		fController2Pfield;
		BButton*			Controller2PPluginButton;
		BButton*			AboutController2PButtonPlugin;
		
		
//Cd Rom		
		BMenu*				CdRomPluginMenu;
		BMenuField*		fCdRomfield;
		BButton*			CdRomButton;
		BButton*			AboutCdRomButtonPlugin;
		
//Link Cable		
    	BMenu*				LinCablePluginMenu;
		BMenuField*		fLinkCablefield;
		BButton*			LinkCableButton;
		BButton*			AboutLinkCableButtonPlugin;		
		
				
//Search Dir		
		
		BMenu*				SearchPluginMenu;
		BMenuField*		fSearchInDirfield;		
		
//Bios		
		BBox*			fBiosBox;


		BMenu*				BiosMenu;
		BMenuField*		fBiosfield;
		BButton*			BiosButton;
		BButton*			AboutBiosButton;
		
		
//Search Bios DirField
		BStringView* 	SearchText;	
						
		BMenuField*		fSearchBiosDirfield;		
		BButton*			SearchButton;
		BButton*			AboutSearchButton	;	


};

#endif
