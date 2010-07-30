#pragma once

#include "API.h"

#include <maya/MPxTransform.h>

namespace Helium
{
    //
    // This coallates EntityNode objects for scene tidyness,
    //  and makes wrangling instances in the code easier
    //

    class MAYA_API EntityGroupNode : public MPxTransform 
    {
    public:
        static const char* s_TypeName;
        static const MTypeId s_TypeID;  

        static void * Creator()
        {
            return new EntityGroupNode();  
        }

        static MStatus Initialize()
        {
            return MS::kSuccess;
        }
    };

}