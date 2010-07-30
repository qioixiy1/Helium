#pragma once

#include "Pipeline/API.h"
#include "Pipeline/Content/Nodes/Instance.h"
#include "Pipeline/Asset/Classes/Entity.h"
#include "Foundation/Automation/Event.h"

namespace Helium
{
    namespace Asset
    {
        class PIPELINE_API EntityInstance : public Content::Instance
        {
        private:
            REFLECT_DECLARE_CLASS( EntityInstance, Instance );
            static void EnumerateClass( Reflect::Compositor< EntityInstance >& comp );

        public:
            EntityInstance( const tstring& assetPath = TXT( "" ) );
            EntityInstance( Helium::TUID id );

            // get the path to the class
            tstring GetEntityPath();

            // helper to find the entity class
            Asset::EntityPtr GetEntity() const;

            //
            // ComponentCollection overrides
            //

            virtual bool ValidatePersistent( const Component::ComponentPtr& attr ) const HELIUM_OVERRIDE;
            virtual const Component::ComponentPtr& GetComponent( i32 typeID ) const HELIUM_OVERRIDE;
            virtual void SetComponent( const Component::ComponentPtr& component, bool validate = true ) HELIUM_OVERRIDE;

        private:
            Helium::Path m_Path;

        public:
            // draw bound in editor
            bool m_ShowPointer;

            // draw bound in editor
            bool m_ShowBounds;

            // show geometry in editor
            bool m_ShowGeometry;
        };

        typedef Helium::SmartPtr< EntityInstance > EntityInstancePtr;
    }
}