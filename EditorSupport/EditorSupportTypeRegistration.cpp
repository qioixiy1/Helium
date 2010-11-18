//----------------------------------------------------------------------------------------------------------------------
// EditorSupportTypeRegistration.cpp
//
// Copyright (C) 2010 WhiteMoon Dreams, Inc.
// All Rights Reserved
//----------------------------------------------------------------------------------------------------------------------

// !!! AUTOGENERATED FILE - DO NOT EDIT !!!

#include "EditorSupportPch.h"
#include "Platform/Assert.h"
#include "Engine/Package.h"

#include "EditorSupport/ShaderVariantResourceHandler.h"
#include "EditorSupport/Texture2dResourceHandler.h"
#include "EditorSupport/ShaderResourceHandler.h"
#include "EditorSupport/MaterialResourceHandler.h"
#include "EditorSupport/MeshResourceHandler.h"
#include "EditorSupport/AnimationResourceHandler.h"

static Lunar::StrongPtr< Lunar::Package > spEditorSupportTypePackage;

LUNAR_EDITOR_SUPPORT_API Lunar::Package* GetEditorSupportTypePackage()
{
    Lunar::Package* pPackage = spEditorSupportTypePackage;
    if( !pPackage )
    {
        Lunar::Object* pTypesPackageObject = Lunar::Object::FindChildOf( NULL, Lunar::Name( TXT( "Types" ) ) );
        HELIUM_ASSERT( pTypesPackageObject );
        HELIUM_ASSERT( pTypesPackageObject->IsPackage() );

        pPackage = Lunar::Object::Create< Lunar::Package >( Lunar::Name( TXT( "EditorSupport" ) ), pTypesPackageObject );
        HELIUM_ASSERT( pPackage );
        spEditorSupportTypePackage = pPackage;
    }

    return pPackage;
}

LUNAR_EDITOR_SUPPORT_API void ReleaseEditorSupportTypePackage()
{
    spEditorSupportTypePackage = NULL;
}

LUNAR_EDITOR_SUPPORT_API void RegisterEditorSupportTypes()
{
    HELIUM_VERIFY( GetEditorSupportTypePackage() );

    HELIUM_VERIFY( Lunar::AnimationResourceHandler::InitStaticType() );
    HELIUM_VERIFY( Lunar::MaterialResourceHandler::InitStaticType() );
    HELIUM_VERIFY( Lunar::MeshResourceHandler::InitStaticType() );
    HELIUM_VERIFY( Lunar::ShaderResourceHandler::InitStaticType() );
    HELIUM_VERIFY( Lunar::ShaderVariantResourceHandler::InitStaticType() );
    HELIUM_VERIFY( Lunar::Texture2dResourceHandler::InitStaticType() );
}

LUNAR_EDITOR_SUPPORT_API void UnregisterEditorSupportTypes()
{
    Lunar::AnimationResourceHandler::ReleaseStaticType();
    Lunar::MaterialResourceHandler::ReleaseStaticType();
    Lunar::MeshResourceHandler::ReleaseStaticType();
    Lunar::ShaderResourceHandler::ReleaseStaticType();
    Lunar::ShaderVariantResourceHandler::ReleaseStaticType();
    Lunar::Texture2dResourceHandler::ReleaseStaticType();

    ReleaseEditorSupportTypePackage();
}
