#include "Precompile.h"
#include "ContainerItemNode.h"
#include "ContainerNode.h"

using namespace Luna;

// Definition
LUNA_DEFINE_TYPE( Luna::ContainerItemNode );

///////////////////////////////////////////////////////////////////////////////
// 
// 
void ContainerItemNode::InitializeType()
{
  Reflect::RegisterClass<Luna::ContainerItemNode>( TXT( "Luna::ContainerItemNode" ) );
}

///////////////////////////////////////////////////////////////////////////////
// 
// 
void ContainerItemNode::CleanupType()
{
  Reflect::UnregisterClass<Luna::ContainerItemNode>();
}

///////////////////////////////////////////////////////////////////////////////
// 
// 
ContainerItemNode::ContainerItemNode( Luna::AssetManager* assetManager, Luna::ContainerNode* container, const tstring& name )
: Luna::AssetNode( assetManager )
, m_Container( container )
{
  SetName( name );
}

///////////////////////////////////////////////////////////////////////////////
// 
// 
ContainerItemNode::~ContainerItemNode()
{
}
