//----------------------------------------------------------------------------------------------------------------------
// DynamicMemoryStream.h
//
// Copyright (C) 2010 WhiteMoon Dreams, Inc.
// All Rights Reserved
//----------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef LUNAR_CORE_DYNAMIC_MEMORY_STREAM_H
#define LUNAR_CORE_DYNAMIC_MEMORY_STREAM_H

#include "Core/Stream.h"

#include "Core/DynArray.h"

namespace Lunar
{
    /// Stream for reading from and writing to a dynamic memory buffer (backed using a DynArray of bytes).
    class LUNAR_CORE_API DynamicMemoryStream : public Stream
    {
    public:
        /// @name Construction/Destruction
        //@{
        explicit DynamicMemoryStream( DynArray< uint8_t >* pBuffer = NULL );
        virtual ~DynamicMemoryStream();
        //@}

        /// @name Stream Assignment
        //@{
        virtual void Open( DynArray< uint8_t >* pBuffer );
        //@}

        /// @name Stream Interface
        //@{
        virtual void Close();
        virtual bool IsOpen() const;

        virtual size_t Read( void* pBuffer, size_t size, size_t count );
        virtual size_t Write( const void* pBuffer, size_t size, size_t count );

        virtual void Flush();

        virtual int64_t Seek( int64_t offset, ESeekOrigin origin );
        virtual int64_t Tell() const;
        virtual int64_t GetSize() const;
        //@}

        /// @name Stream Capabilities
        //@{
        virtual bool CanRead() const;
        virtual bool CanWrite() const;
        virtual bool CanSeek() const;
        //@}

        /// @name Data Access
        //@{
        inline DynArray< uint8_t >* GetBuffer() const;
        //@}

    private:
        /// Memory buffer.
        DynArray< uint8_t >* m_pBuffer;
        /// Current buffer read/write offset.
        size_t m_offset;
    };
}

#include "Core/DynamicMemoryStream.inl"

#endif  // LUNAR_CORE_DYNAMIC_MEMORY_STREAM_H