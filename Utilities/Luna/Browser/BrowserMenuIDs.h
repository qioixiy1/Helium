#pragma once

#include "Platform/Types.h"
#include "Platform/Assert.h"
#include "Foundation/Reflect/Enumeration.h"
#include <sstream>

namespace Luna
{
  namespace BrowserMenu
  {
    ///////////////////////////////////////////////////////////////////////////
    enum MenuIDs
    {
      START = wxID_HIGHEST, // Do not use: must be first

      FoldersPanel,
      CollectionsPanel,
      HelpPanel,
      
      ViewSmall,
      ViewMedium,
      ViewLarge,
      ViewDetails,

      AdvancedSearch,
      AdvancedSearchGo,
      AdvancedSearchCancel,

      CopyPathWindows,
      CopyPathClean,

      Sync,
      CheckOut,
      History,

      Open,
      Preview,

      Refresh,

      New,
      NewFolder,
      Cut,
      Copy,
      Paste,
      Rename,
      Delete,
      Properties,

      SelectAll,

      Sort,
      SortByName,
      SortByType,

      ShowInFolders,
      ShowInPerforce,
      ShowInWindowsExplorer,

      ShowCollection,

      NewCollectionFromSelection,
      NewDepedencyCollectionFromSelection,
      NewUsageCollectionFromSelection,

      NewCollection,
      NewDependencyCollection,
      NewUsageCollection,

      OpenCollection,
      CloseCollection,

      RenameCollection,
      DeleteCollection,

      ImportCollection,
      ImportIntoCollection,
      SaveCollection,

      AddToCollection,
      RemoveFromCollection,

      Preferences,

      COUNT_PLUS_START // Do not use: must be last
    };
    static const u32 s_Count = COUNT_PLUS_START - START;

    ///////////////////////////////////////////////////////////////////////////
    static const tstring s_Labels[s_Count] = 
    {
      TXT( "INVALID" ), // placeholder for START

      TXT( "Folders" ),
      TXT( "Collections" ),
      TXT( "Help" ),

      TXT( "Small" ),
      TXT( "Medium" ),
      TXT( "Large" ),
      TXT( "Details" ),

      TXT( "Advanced Search" ),
      TXT( "Go" ),
      TXT( "Cancel" ),

      TXT( "Path (Windows Format)" ),
      TXT( "Path (Clean Format)" ),

      TXT( "Sync" ),
      TXT( "Check Out" ),
      TXT( "Revision History" ),

      TXT( "Open" ),
      TXT( "Preview" ),

      TXT( "Refresh" ),

      TXT( "New" ),
      TXT( "New Folder" ),
      TXT( "Cut" ),
      TXT( "Copy" ),
      TXT( "Paste" ),
      TXT( "Rename" ),
      TXT( "Delete" ),
      TXT( "Properties" ),

      TXT( "Select All\tCtrl+A" ),

      TXT( "Sort" ),
      TXT( "Name" ),
      TXT( "Type" ),

      TXT( "Folders" ),
      TXT( "Show in Revision Control" ),
      TXT( "Windows Explorer" ), 

      TXT( "Show" ),

      TXT( "Static Collection" ),
      TXT( "Dependency Collection" ),
      TXT( "Usage Collection" ),

      TXT( "Static Collection" ),
      TXT( "Asset Dependencies Collection" ),
      TXT( "Asset Usage Collection" ),

      TXT( "Open" ),
      TXT( "Close" ),

      TXT( "Rename" ),
      TXT( "Delete" ),

      TXT( "Import..." ),
      TXT( "Import into..." ),
      TXT( "Export..." ),

      TXT( "Add Selected Assets" ),
      TXT( "Remove Selected Assets" ),

      TXT( "Customize Preferences..." ),
    };
    
    inline const tstring& Label( i32 id )
    {
      NOC_ASSERT( id > START );
      NOC_ASSERT( id < COUNT_PLUS_START );
      return s_Labels[id-START];
    }
  };
  typedef BrowserMenu::MenuIDs BrowserMenuID;

  ///////////////////////////////////////////////////////////////////////////
  namespace ThumbnailSizes
  {
    enum ThumbnailSize
    {
      Small = 64,
      Medium = 128,
      Large = 256
    };
    inline tstring Label( ThumbnailSize size )
    {
      tstringstream str;
      str << TXT( "(" ) << size << TXT( "x" ) << size << TXT( ")" );
      return str.str();
    }
  }
  typedef ThumbnailSizes::ThumbnailSize ThumbnailSize;

  ///////////////////////////////////////////////////////////////////////////
  namespace ViewOptionIDs
  {
    enum ViewOptionID
    {
      Small = BrowserMenu::ViewSmall,
      Medium = BrowserMenu::ViewMedium,
      Large = BrowserMenu::ViewLarge,
      Custom = -1,
    };

    static void ViewOptionIDEnumerateEnumeration( Reflect::Enumeration* info )
    {
      info->AddElement(Small, TXT( "Small" ) );
      info->AddElement(Medium, TXT( "Medium" ) );
      info->AddElement(Large, TXT( "Large" ) );
      info->AddElement(Custom, TXT( "Custom" ) );
    }
  }
  typedef ViewOptionIDs::ViewOptionID ViewOptionID;
}
