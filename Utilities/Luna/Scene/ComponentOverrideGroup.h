#pragma once

#include "ComponentGroup.h"
#include "Foundation/Automation/Property.h"
#include "Application/Inspect/Widgets/Group.h"

namespace Luna
{
  /////////////////////////////////////////////////////////////////////////////
  // Template class for making a UI group that contains a checkbox and a panel
  // displaying all members of a specific attribute type.  The checkbox is 
  // meant to enable and disable the sub-panel.
  // 
  template < class TAttrib, class TContainer >
  class ComponentOverrideGroup : public Inspect::Group
  {
  public:
    typedef bool ( TContainer::*Getter )() const;
    typedef void ( TContainer::*Setter )( bool );

  protected:
    typedef ComponentOverrideGroup< TAttrib, TContainer > ThisGroup;

  protected:
    Enumerator* m_Enumerator;
    OS_SelectableDumbPtr m_Selection;
    tstring m_LabelText;
    ComponentGroup< TAttrib >* m_ComponentPanel;
    Inspect::CheckBox* m_CheckBox;
    Getter m_Get;
    Setter m_Set;
    

  public:
    ///////////////////////////////////////////////////////////////////////////
    // Constructor
    // 
    ComponentOverrideGroup( const tstring& checkBoxLabel, Enumerator* enumerator, const OS_SelectableDumbPtr& selection, Getter get, Setter set )
      : m_Selection( selection )
      , m_LabelText( checkBoxLabel )
      , m_ComponentPanel( NULL )
      , m_CheckBox( NULL )
      , m_Get( get )
      , m_Set( set )
    {
      m_Interpreter = m_Enumerator = enumerator;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Destructor
    // 
    virtual ~ComponentOverrideGroup()
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    // Creates the control for the first time.
    // 
    virtual void Create() NOC_OVERRIDE
    {
      m_Enumerator->PushContainer();
      {
        m_Enumerator->AddLabel( m_LabelText );

        m_CheckBox = m_Enumerator->AddCheckBox< TContainer, bool >( m_Selection, m_Get, m_Set );
        m_CheckBox->AddBoundDataChangedListener( Inspect::ChangedSignature::Delegate( this, &ThisGroup::OnOverrideCheckBox ) );
      }
      m_Enumerator->Pop();

      Refresh( false );

      __super::Create();
    }

    ///////////////////////////////////////////////////////////////////////////
    // Callback for when the checkbox is clicked.  Refreshes the contained panel
    // in case it needs to change its enable/expansion state.
    // 
    void OnOverrideCheckBox( const Inspect::ChangeArgs& args )
    {
      Refresh( true );
    }

    ///////////////////////////////////////////////////////////////////////////
    // Enables or disables the inner panel as appropriate.
    // 
    void Refresh(bool layout)
    {
      Freeze();

      if ( m_CheckBox->GetChecked() && !m_ComponentPanel )
      {
        m_ComponentPanel = new ComponentGroup< TAttrib >( m_Interpreter, m_Selection );

        m_Enumerator->Push( m_ComponentPanel );
        {
          m_ComponentPanel->SetCanvas( m_Enumerator->GetContainer()->GetCanvas() );
          m_ComponentPanel->Create();
        }
        m_Enumerator->Pop();
      }
      else if ( !m_CheckBox->GetChecked() && m_ComponentPanel )
      {
        m_ComponentPanel->GetParent()->RemoveControl( m_ComponentPanel );
        m_ComponentPanel = NULL;
      }

      if ( m_ComponentPanel )
      {
        m_ComponentPanel->Refresh();
      }

      if ( layout )
      {
        GetCanvas()->Layout();
      }

      Thaw();
    }
  };
}