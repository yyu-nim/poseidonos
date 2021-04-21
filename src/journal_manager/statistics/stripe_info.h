/*
 *   BSD LICENSE
 *   Copyright (c) 2021 Samsung Electronics Corporation
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <assert.h>

#include "src/include/address_type.h"
#include "src/include/pos_event_id.h"
#include "src/logger/logger.h"

namespace pos
{
class BlockWriteDoneLog;
class StripeMapUpdatedLog;

class StripeInfo
{
public:
    StripeInfo(void) = delete;
    explicit StripeInfo(StripeId inputVsid);
    StripeInfo(int volumeId, StripeId vsid, StripeId wbLsid, StripeId userLsid, BlkOffset lastOffset, int wbIndex);

    inline int
    GetVolumeId(void)
    {
        return volId;
    }

    inline StripeId
    GetVsid(void)
    {
        return vsid;
    }

    inline StripeId
    GetWbLsid(void)
    {
        return wbLsid;
    }

    inline StripeId
    GetUserLsid(void)
    {
        return userLsid;
    }

    inline BlkOffset
    GetLastOffset(void)
    {
        return lastOffset;
    }

    inline void
    ResetOffset(void)
    {
        lastOffset = UINT64_MAX;
    }

    inline bool
    IsLastOffsetValid(void)
    {
        return (lastOffset != UINT64_MAX);
    }

    inline int
    GetWbIndex(void)
    {
        return wbIndex;
    }

    inline bool
    IsWbIndexValid(void)
    {
        return (wbIndex != INT32_MAX);
    }

protected:
    void _UpdateVolumeId(int inputVolId);
    void _UpdateWbLsid(StripeId inputWbLsid);
    void _UpdateUserLsid(StripeId inputUserLsid);
    void _UpdateLastOffset(BlkOffset curEndOffset);
    void _UpdateWbIndex(int inputIndex);

private:
    void _Reset(void);

    int volId;
    StripeId vsid;
    StripeId wbLsid;
    StripeId userLsid;
    BlkOffset lastOffset;
    int wbIndex;
};

} // namespace pos
