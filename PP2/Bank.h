#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "BankClient.h"

class CBank
{
public:
	CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	int GetTotalBalance();	
	std::vector<CBankClient>GetClients();
	void SetTotalBalance(int value);
	int GetClientBalance(int client);

private:
	std::vector<CBankClient> m_clients;
	int m_totalBalance;
	std::map<int, int> m_clientBalance;

	void SomeLongOperations();
};