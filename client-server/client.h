#pragma once

#include "stdafx.h"
#include "constants.h"
#include "request.h"
#include "lock.h"
#include "priorityqueue.h"


class Client
{
public:
    Client(PriorityQueue &priorityQueue)
        : m_dwClientId(++m_id),
		m_exit(false),
        m_thread(),
        m_priorityQueue(priorityQueue),
        m_engine(static_cast<unsigned long>(std::time(nullptr)) + m_dwClientId),
        m_randomDelay(Constants::MIN_REQUEST, Constants::MAX_REQUEST),
        m_randomPriority(Constants::MIN_REQUEST_PRIORITY, Constants::MAX_REQUEST_PRIORITY)
    {
    }

    // Start client thread.
    void Start();
	// Stop client thread
	void Stop();
    unsigned long GetId()
    {
        return m_dwClientId;
    }
     
private:
	unsigned long m_dwClientId;
	std::atomic<bool> m_exit;
	static std::atomic<unsigned long> m_id;

    PriorityQueue &m_priorityQueue;

    std::thread m_thread;
    //std::mutex m_mutex;
    // Random number engine.
    std::default_random_engine m_engine;
    // Random number generator for delay.
	std::uniform_int_distribution<unsigned long> m_randomDelay;
    // Random number generator for priority.
	std::uniform_int_distribution<unsigned long> m_randomPriority;
    // Send requests infinity times.
    void Run();
    // Send request to PriorityQueue.
    void SendRequest();

    // Generate request priority.
    BYTE GetPriority()
    {
        return static_cast<BYTE>(m_randomPriority(m_engine));
    }   
    // Generate request data.
   void GetData(char * data) const
    {
		for (int i = 0; i < 10; ++i)
		{
			*data++ = '1'; // random data
		}
    }
};
