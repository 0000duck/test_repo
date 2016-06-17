/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file RTPSAsNonReliableSocketWriter.hpp
 *
 */

#ifndef _TEST_PROFILING_RTPSASNONRELIABLESOCKETWRITER_HPP_
#define _TEST_PROFILING_RTPSASNONRELIABLESOCKETWRITER_HPP_

#include "RTPSAsSocketWriter.hpp" 

class RTPSAsNonReliableSocketWriter : public RTPSAsSocketWriter
{
    public:
        void configWriter(WriterAttributes &wattr)
        {
            wattr.endpoint.reliabilityKind = BEST_EFFORT;
        }

        void configRemoteReader(RemoteReaderAttributes &/*rattr*/, GUID_t &/*ĝuid*/)
        {
        }

        std::string getText()
        {
            return "RTPSAsNonReliableSocket";
        }
};

#endif // _TEST_PROFILING_RTPSASNONRELIABLESOCKETWRITER_HPP_

