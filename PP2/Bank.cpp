#include "Bank.h"
#include <vector>

CBank::CBank()
{
	m_clients = std::vector<CBankClient>();
	m_totalBalance = 0;
}


CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	CBankClient* client = new CBankClient(this, clientId);
	m_clients.push_back(*client);
	return client;
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	int totalBalance = GetTotalBalance();
	unsigned clientId = client.GetId();
	std::cout << "Client " << clientId << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();

	totalBalance += value;
	m_clientBalance[clientId] += value;

	std::cout
		<< "Client " << clientId << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);
}


int CBank::GetTotalBalance()
{
	return m_totalBalance;
}

std::vector<CBankClient> CBank::GetClients() {
	return m_clients;
}

int CBank::GetClientBalance(int client)
{
	return m_clientBalance[client];
}

void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	// TODO
}