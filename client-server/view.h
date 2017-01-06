#pragma once
#include "constants.h"
#include "request.h"

//
// Class for work with console representation of modelling.
//
class View
{
public:
	View(DWORD clients);

	~View()
	{
		SetConsoleCursorPosition(m_console, COORD{ 0, m_bottomY });
	}

	void ShowRequest(const TDATA &request, DWORD size);
	void ShowLog(const TDATA &request, DWORD size);

private:
	HANDLE m_console;
	DWORD m_clients;
	SHORT m_topY;
	SHORT m_topX;
	SHORT m_bottomY;

	void ShowSize(DWORD size);
	void Paint(const std::vector<std::wstring> &figure, const COORD &coord);
	void PaintServer();
	void PaintLog();
	void PaintQueue();
	void PaintClient(DWORD id, const COORD &coord);
	void PaintClients();
	void PaintConnects();
	void Write(const std::wstring &msg, const COORD &coord);
	SHORT GetTopY() const;
	SHORT GetTopX() const;
	COORD GetLogShapeCoord() const;
	COORD GetLogFlushCoord() const;
	COORD GetQueueCoord() const;
	COORD GetSizeFlushCoord() const;
	COORD GetClientCoord(DWORD id) const;
	COORD GetConnectsCoord(DWORD id) const;

};
