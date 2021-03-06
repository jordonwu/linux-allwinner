/* This is an autogenerated file */
/* Tag: noCheckHeader */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2009. All rights reserved. */
/* */
/*   Refer to LICENSE.txt included with this source for details on the */
/*   license terms. */

#ifndef __BT_SAP_REMOTE_OUTPUT_INTERFACE_GEN_H__
#define __BT_SAP_REMOTE_OUTPUT_INTERFACE_GEN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "abstractions/osa.h"
#ifdef IPC_IP
#include "ipc/ipc.h"
extern ipcConnection* get_bt_ipc_connection(void* context);
#else
#ifdef IPC_CHARDEVICE
#include "ipc/ipc.h"
extern ipcConnection* get_bt_ipc_connection(void* context);
#endif
#endif

#ifdef REMOTE_BT_SAP
extern CsrBool remote_bt_signal_receive(FsmContext* context, CsrUint8* buffer, CsrUint16 size);
#else
#define remote_bt_signal_receive(context, buffer, size) FALSE
#endif

#ifdef __cplusplus
}
#endif

#endif /* __BT_SAP_REMOTE_OUTPUT_INTERFACE_GEN_H__ */
