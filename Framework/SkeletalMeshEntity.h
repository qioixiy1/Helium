//----------------------------------------------------------------------------------------------------------------------
// SkeletalMeshEntity.h
//
// Copyright (C) 2010 WhiteMoon Dreams, Inc.
// All Rights Reserved
//----------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef LUNAR_FRAMEWORK_SKELETAL_MESH_ENTITY_H
#define LUNAR_FRAMEWORK_SKELETAL_MESH_ENTITY_H

#include "Framework/MeshEntity.h"

#include "Graphics/Animation.h"

#if L_USE_GRANNY_ANIMATION
#include "GrannySkeletalMeshEntityInterface.h"
#endif

namespace Lunar
{
    HELIUM_DECLARE_PTR( Animation );

    /// In-game entity comprising of a skeletal (skinned) mesh.
    class LUNAR_FRAMEWORK_API SkeletalMeshEntity : public MeshEntity
    {
        L_DECLARE_OBJECT( SkeletalMeshEntity, MeshEntity );

#if L_USE_GRANNY_ANIMATION
        friend class Granny::SkeletalMeshEntityData;
#endif

    public:
        /// @name Construction/Destruction
        //@{
        SkeletalMeshEntity();
        virtual ~SkeletalMeshEntity();
        //@}

        /// @name Entity Registration
        //@{
        virtual void Attach();
        virtual void Detach();
        //@}

        /// @name Entity Updating
        //@{
        virtual void SynchronousUpdate( float32_t deltaSeconds );
        //@}

        /// @name Serialization
        //@{
        virtual void Serialize( Serializer& s );
        //@}

        /// @name Data Access
        //@{
        void SetAnimation( Animation* pAnimation );
        inline Animation* GetAnimation() const;

#if L_USE_GRANNY_ANIMATION
        inline const Granny::SkeletalMeshEntityData& GetGrannyData() const;
#endif
        //@}

    protected:
        /// @name Animation Playback Control
        //@{
        void ActivateAssignedAnimation();
        void DeactivateAssignedAnimation();
        //@}

        /// @name Graphics Scene Object Updating
        //@{
        virtual GraphicsSceneObject::UPDATE_FUNC* GetGraphicsSceneObjectUpdateCallback() const;
        //@}

        /// @name Scene Object Synchronization Callback
        //@{
        static void GraphicsSceneObjectUpdate( void* pData, GraphicsScene* pScene, GraphicsSceneObject* pSceneObject );
        //@}

    private:
        /// Active animation.
        AnimationPtr m_spAnimation;

#if L_USE_GRANNY_ANIMATION
        /// Granny-specific data.
        Granny::SkeletalMeshEntityData m_grannyData;
#endif
    };
}

#include "Framework/SkeletalMeshEntity.inl"

#endif  // LUNAR_FRAMEWORK_SKELETAL_MESH_ENTITY_H
