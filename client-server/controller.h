#pragma once

#include "stdafx.h"
#include "client.h"
#include "server.h"
#include "priorityqueue.h"

//
// Modeling interaction between server and clients.
//
class Controller
{
public:
	explicit Controller(unsigned long dwClients);

    // Start server and clients.
    void Start();
	void StopAllThread();
    unsigned long GetClients()
    {
        return m_dw—lients;
    }

    void SetClient(unsigned long dwClients)
    {
        m_dw—lients = dwClients;
    }

	Controller& operator=(const Controller &) = delete;
private:
    void Run();
	void Stop();
    std::thread m_thread;

    unsigned long m_dw—lients;
    View m_view;
    PriorityQueue m_priorityQueue;
    Server m_server;
    std::vector<std::shared_ptr<Client>> m_clients;
};
