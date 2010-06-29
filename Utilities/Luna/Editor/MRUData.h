#pragma once

#include "Luna/API.h"
#include "Application/UI/MRU.h"
#include "Foundation/Reflect/Element.h"
#include "Foundation/Reflect/ArraySerializer.h"

namespace Luna
{
  /////////////////////////////////////////////////////////////////////////////
  // 
  // 
  class LUNA_EDITOR_API MRUData : public Reflect::Element
  {
  private:
    std::vector< tstring > m_Paths;
    //TODO: std::vector< tstring > m_Icons;

    // RTTI
  public:
    REFLECT_DECLARE_CLASS( MRUData, Reflect::Element );
    static void EnumerateClass( Reflect::Compositor<MRUData>& comp );

  public:
    static void InitializeType();
    static void CleanupType();

    MRUData();
    virtual ~MRUData();

    const std::vector< tstring >& GetPaths() const;
    void SetPaths( const std::vector< tstring >& paths );
  };
  typedef Nocturnal::SmartPtr< MRUData > MRUDataPtr;
}