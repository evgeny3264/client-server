#include "stdafx.h"
#include "client.h"
#include "priorityqueue.h"

std::atomic<unsigned long> Client::m_id;

void Client::Start()
{
    m_thread = std::thread(&Client::Run, this);
   // m_thread.detach();
}

void Client::Stop()
{
	m_exit = true;	
}
void Client::Join()
{	
	m_thread.join();
}
void Client::Run()
{
    while (!m_exit)
    {
        SendRequest();
		unsigned long dwMilliseconds = m_randomDelay(m_engine);
        std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));
    }
}

void Client::SendRequest()
{
    TDATA tdRequest { };
    tdRequest.cPriority = GetPriority();
    tdRequest.dwClientId = m_dwClientId;
    tdRequest.dwTicks = GetTickCount();
	tdRequest.data = std::vector<char>(5, '1');
	m_priorityQueue.Add(tdRequest);
}
