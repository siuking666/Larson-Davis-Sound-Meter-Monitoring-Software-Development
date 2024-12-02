#pragma once

void RegisterHandlers(ConnServerConnection* pConn);

const char* ToModelName(int meterType);

void ParseTextEntry(const char* pNext, const char* buffer, MenuEntry& choice);

void ProcessInput(MenuEntry choice, ConnServerConnection* pConn, const char* buffer);

int GetId(const char* pBuffer);

void DisplayMeterList(rapidjson::Document* doc, const char* pHeaderText, const char* pMemberName);

void PrintHelp();
