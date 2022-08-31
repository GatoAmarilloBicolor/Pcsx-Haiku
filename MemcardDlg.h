
#ifndef MEMCARDDLG_H
#define MEMCARDDLG_H

void OnConf_Mcds();



#include <StringView.h>
#include <Window.h>
#include <MenuBar.h>
#include <Menu.h>
#include <MenuItem.h>
#include <Bitmap.h>
#include  <Alert.h>
#include <Box.h>
#include <PopUpMenu.h>
#include  "ColumnListView.h"
#include <String.h>




struct Attribute;

enum {
	kIcon,
	kTitle,
	kStatus,
	kID,
	kName
};


class ElementListView : public BColumnListView {
public:

	ElementListView(const char *name);

	BPopUpMenu *operationMenu;
	BMenu* priorityMenu;

	BPopUpMenu *ActionMenu();
	virtual void MakeFocus(bool focused = true);
	virtual void SelectionChanged(void);
	virtual void KeyDown(const char *bytes, int32 numBytes);
	virtual	void ExpandOrCollapse(BRow* row, bool expand);
	void FullListDoForEach(bool (*func)(BRow*, void*), void* data);
	void SaveTreeState(BMessage *prefsMessage);
	void LoadTreeState(BMessage *prefsMessage);
	void SavePreset(BMessage *message);
	void LoadPreset(BMessage *message);
};




class  MemcardDlg  : public  BWindow
{
public:
						MemcardDlg(void);
			void		MessageReceived(BMessage *msg1);
//			virtual		~PluginBios();
			
private:


BView * 				DefaultViewb;
		

BBox* 		MemoryCard1Box;

BBox* 		MemoryCard2Box;









};



#endif
