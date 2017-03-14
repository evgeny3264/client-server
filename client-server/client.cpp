#include "stdafx.h"
#include "client.h"
#include "priorityqueue.h"

std::atomic<unsigned long> Client::m_id;

void Client::Start()
{
    m_thread = std::thread(&Client::Run, this);
    m_thread.detach();
}

void Client::Stop()
{
	m_exit = true;
}
void Client::Run()
{
    while (true)
    {
        SendRequest();
		unsigned long dwMilliseconds = m_randomDelay(m_engine);
        std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));
		if (m_exit)
		{			
			break;
		}
    }
}

void Client::SendRequest()
{
    TDATA tdRequest { };
    tdRequest.cPriority = GetPriority();
    tdRequest.dwClientId = m_dwClientId;
    tdRequest.dwTicks = GetTickCount();
	GetData(tdRequest.data);
	m_priorityQueue.Add(tdRequest);
}
