#pragma once
#include "constants.h"
#include "request.h"

//
// Class for work with console representation of modelling.
//
class View
{
public:
	View(unsigned long clients);

	~View()
	{
		SetConsoleCursorPosition(m_console, COORD{ 0, m_bottomY });
	}

	void ShowRequest(const TDATA &request, unsigned long size);
	void ShowLog(const TDATA &request, unsigned long size);

private:
	HANDLE m_console;
	unsigned long m_clients;
	SHORT m_topY;
	SHORT m_topX;
	SHORT m_bottomY;

	void ShowSize(unsigned long size);
	void Paint(const std::vector<std::wstring> &figure, const COORD &coord);
	void PaintServer();
	void PaintLog();
	void PaintQueue();
	void PaintClient(unsigned long id, const COORD &coord);
	void PaintClients();
	void PaintConnects();
	void Write(const std::wstring &msg, const COORD &coord);
	SHORT GetTopY() const;
	SHORT GetTopX() const;
	COORD GetLogShapeCoord() const;
	COORD GetLogFlushCoord() const;
	COORD GetQueueCoord() const;
	COORD GetSizeFlushCoord() const;
	COORD GetClientCoord(unsigned long id) const;
	COORD GetConnectsCoord(unsigned long id) const;

};
