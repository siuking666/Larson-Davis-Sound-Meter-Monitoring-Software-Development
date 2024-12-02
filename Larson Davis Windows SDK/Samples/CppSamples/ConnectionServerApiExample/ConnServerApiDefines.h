#pragma once

enum class MenuEntry
{
   Invalid  = -1,
   Shutdown =  0,
   Resend   =  1,
   Add      =  2,
   Exclude  =  3,
   Include  =  4,
   Scan     =  5,
   Forget   =  6,
   Hide     =  7,
   Unhide   =  8,
   Refresh  =  9,
   Close    =  10
};

// No arguments
#define CMD_RESEND_ITEMS "resend"
// Host, Port, Secure
#define CMD_ADD_HOST "addHost"
// No Arguments
#define CMD_SHUTDOWN "shutdown"
// No Arguments
#define CMD_REFRESH_METERS "refreshMeters"
// Meter Id
#define CMD_EXCLUDE "exclude"
// Meter Id
#define CMD_INCLUDE "include"
// No Arguments
#define CMD_PING "ping"
// No Arguments
#define CMD_PONG "pong"
// No Arguments
#define CMD_QUERY_UDP "queryudp"
// Meter Id
#define CMD_PING_DEVICE "pingDevice"
// Meter Id, Target Id (Meter to move after), Project Id
#define CMD_MOVE_ITEM "move"
// Meter Id
#define CMD_HIDE_ITEM "hide"
// Meter Id
#define CMD_UNHIDE_ITEM "unhide"
// Meter Id
#define CMD_FORGET_ITEM "forgetItem"
// Meter Id, New Nickname
#define CMD_NICKNAME_ITEM "nicknameItem"
// Meter Id, Host, Port, Secure
#define CMD_CHANGE_TCP_SETTINGS "changeTcpSettings"

// Occurs when the server finds a meter
#define RSP_METERS_ADDED "added"
// Occurs when the server looses a meter
#define RSP_METERS_REMOVED "removed"
// Occurs on initial connect from a client or when told to send it
#define RSP_FULL_METER_REPORT "full"
// Occurs when the server resovles an endpoint (host and port) to a meter
#define RSP_ENDPOINT_RESOVLED "resolved"
// Occurs when the server reaches a resolved meter through a new unresolved endpoint
#define RSP_DUPLICATE_FOUND "duplicate_found"
// Occurs when the server finds a new meter on a resolved endpoint or via UDP/USB/BLE
#define RSP_DISCOVERED "discovered"
// Occurs when the command has resulted in an error
#define RSP_ERROR_RESPONSE "error"
// Occurs when a USB device has been found in DFU mode (LD Spartan 730).
#define RSP_DFU_METER_FOUND "dfu"
// Occurs in response to a ping
#define RSP_PING_RESULT "pingResult"
// Occurs when an LxT or 831A is connected and needed firmware uploading
#define RSP_METER_IN_BOOT_LOADER "meterInBootLoader"