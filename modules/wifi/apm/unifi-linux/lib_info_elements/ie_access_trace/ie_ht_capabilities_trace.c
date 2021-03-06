/* This is an autogenerated file */
/* Tag: noCheckHeader */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2009. All rights reserved. */
/* */
/*   Refer to LICENSE.txt included with this source for details on the */
/*   license terms. */

/* STANDARD INCLUDES *********************************************************/
#include "ie_utils/ie_utils.h"
#include "ie_access_trace/lib_info_element_trace_fields.h"

/* PUBLIC FUNCTION DEFINITIONS ***********************************************/

#ifdef LIB_INFO_ELEMENT_TRACE_ENABLE

CsrUint8* ie_trace_ht_capabilities(CsrUint8 traceLevel, CsrUint8 *pBuf)
{
    CsrUint32 value;

    ie_CsrUint8(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"id:                        0x%.2x", value );
    ie_CsrUint8(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"length:                    0x%.2x", value );
    pBuf = ie_trace_ht_cap(traceLevel, pBuf);
    ie_CsrUint8(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"aMpdu:                     0x%.2x", value );
    CsrLogBuffer(traceLevel, (CsrString*)"", pBuf, 128, (CsrString*)"    supportedMcsSet");
    pBuf += 16;
    ie_le_CsrUint16(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"htExtendedCap:             0x%.4x", value );
    ie_le_CsrUint32(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"txbfCap:                   0x%.8x", value );
    ie_CsrUint8(pBuf, value);         CsrLog(traceLevel, (CsrString*)"", (CsrString*)"aselCap:                   0x%.2x", value );

    return pBuf;
}


#endif /* LIB_INFO_ELEMENT_TRACE_ENABLE */




