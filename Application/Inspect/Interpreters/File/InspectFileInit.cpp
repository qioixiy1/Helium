#include "InspectFileInit.h"

#include "Foundation/InitializerStack.h"
#include "Application/Inspect/Controls/Container.h"
#include "Application/Inspect/InspectInit.h"
#include "Application/Inspect/Interpreters/Reflect/InspectReflectInit.h"
#include "Application/Inspect/Interpreters/Reflect/ReflectInterpreter.h"

#include "FileDialogButton.h"
#include "FileBrowserButton.h"

#include "FileInterpreter.h"
#include "FileContainerInterpreter.h"

using namespace Helium;
using namespace Helium::Inspect;

#pragma TODO( "Why is RegisterClass defined?" )
#undef RegisterClass

static i32 g_InitCount = 0;
static Helium::InitializerStack g_RegisteredTypes;

void InspectFile::Initialize()
{
  if ( ++g_InitCount == 1 )
  {
    Inspect::Initialize();

    g_RegisteredTypes.Push( Reflect::RegisterClass<FileDialogButton>( TXT( "InspectFileDialogButton" ) ) );
    g_RegisteredTypes.Push( Reflect::RegisterClass<FileBrowserButton>( TXT( "InspectFileBrowserButton" ) ) );

    ReflectFieldInterpreterFactory::Register<FileContainerInterpreter>( Reflect::GetType<Reflect::StringArraySerializer>(), Reflect::FieldFlags::FilePath );
    ReflectFieldInterpreterFactory::Register<FileInterpreter>( Reflect::GetType<Reflect::StringSerializer>(), Reflect::FieldFlags::FilePath );
  }
}

void InspectFile::Cleanup()
{
  if ( --g_InitCount == 0 )
  {
    g_RegisteredTypes.Cleanup();
    Inspect::Cleanup();
  }
}
