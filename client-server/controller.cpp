#include "stdafx.h"
#include "controller.h"
#include "client.h"
#include "server.h"

Controller::Controller(DWORD dwClients)
    : m_dw—lients(dwClients),
    m_view(dwClients),
    m_priorityQueue(m_view),
    m_server(m_priorityQueue)
{
    for (size_t i = 0; i < m_dw—lients; ++i)
        m_clients.push_back(std::auto_ptr<Client>(new Client(m_priorityQueue)));
}

void Controller::Start()
{
	m_thread = std::thread(&Controller::Run, this);
    m_thread.detach();
}

void Controller::Run()
{
    m_server.Start();
    for (size_t i = 0; i < m_dw—lients; ++i)
        m_clients[i]->Start();
}
