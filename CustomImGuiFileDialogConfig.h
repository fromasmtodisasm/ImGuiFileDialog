#pragma once

// uncomment and modify defines under for customize ImGuiFileDialog

//#define USE_IMGUI_TABLES

// widget
// button widget use for compose path
//#define IMGUI_PATH_BUTTON ImGui::Button
// standar button
//#define IMGUI_BUTTON ImGui::Button

// locales string
//#define createDirButtonString "+"
//#define okButtonString " OK"
//#define cancelButtonString " Cancel"
//#define resetButtonString "R"
//#define drivesButtonString "Drives"
//#define searchString "Search"
//#define dirEntryString "[DIR] "
//#define linkEntryString "[LINK] "
//#define fileEntryString "[FILE] "
//#define fileNameString "File Name : "
//#define buttonResetSearchString "Reset search"
//#define buttonDriveString "Drives"
//#define buttonResetPathString "Reset to current directory"
//#define buttonCreateDirString "Create Directory"

/*
Comment theses line if you not want to have customization, like icon font here
*/

#include <CustomFont.h>

#define createDirButtonString ICON_IGFD_ADD
#define okButtonString ICON_IGFD_OK " OK"
#define cancelButtonString ICON_IGFD_CANCEL " Cancel"
#define resetButtonString ICON_IGFD_RESET
#define drivesButtonString ICON_IGFD_DRIVES
#define searchString ICON_IGFD_SEARCH
#define dirEntryString ICON_IGFD_FOLDER
#define linkEntryString ICON_IGFD_LINK
#define fileEntryString ICON_IGFD_FILE

#define USE_BOOKMARK
//#define bookmarkPaneWith 150.0f
//#define IMGUI_TOGGLE_BUTTON ToggleButton
#define bookmarksButtonString ICON_IGFD_BOOKMARK
//#define bookmarksButtonHelpString "bookmark"
#define addBookmarkButtonString ICON_IGFD_ADD
#define removeBookmarkButtonString ICON_IGFD_REMOVE



