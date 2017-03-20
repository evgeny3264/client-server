#include "stdafx.h"
#include "controller.h"
#include "client.h"
#include "server.h"


Controller::Controller(unsigned long dwClients)
    : m_dw—lients(dwClients),
    m_view(dwClients),
    m_priorityQueue(m_view),
    m_server(m_priorityQueue)
{
	for (size_t i = 0; i < m_dw—lients; ++i)
		m_clients.push_back(std::make_shared<Client>(m_priorityQueue));
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

void Controller::StopAllThread()
{
	m_thread = std::thread(&Controller::Stop, this);
	m_thread.join();
}

void Controller::Stop()
{	
	for (size_t i = 0; i < m_dw—lients; ++i) {
		m_clients[i]->Stop();
	}
	for (size_t i = 0; i < m_dw—lients; ++i) {
		m_clients[i]->Join();
	}
	m_server.Stop();
	m_server.Join();
	//std::this_thread::sleep_for(std::chrono::milliseconds(Constants::MAX_REQUEST+100));
}