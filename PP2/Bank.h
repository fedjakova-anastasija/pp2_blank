#pragma once
#include "BankClient.h"
#include <iostream>
#include <map>
#include <mutex>
#include <vector>

enum SynchPrimitive
{
	Mutex = 0,
	CriticalSection = 1
};

class CBank
{
public:
	CBank(SynchPrimitive primitiveKind);
	~CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	int GetTotalBalance();
	std::vector<CBankClient> GetClients();
	void SetTotalBalance(int value);
	int GetClientBalance(int client);

private:
	CRITICAL_SECTION m_balanceUpdate;
	SynchPrimitive m_primitiveKind;
	std::mutex m_mutex;

	std::vector<CBankClient> m_clients;
	int m_totalBalance;
	std::map<int, int> m_clientBalance;

	void SomeLongOperations();
};