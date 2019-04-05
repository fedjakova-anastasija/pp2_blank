#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include "iostream"
#include "string"

int GetCustomerBalance(CBank* bank)
{
	int totalClientBalance = 0;

	for (CBankClient client : bank->GetClients())
	{
		unsigned clientId = client.GetId();
		int clientBalance = bank->GetClientBalance(clientId);
		std::cout << "Balance of client " << clientId << ": " << clientBalance << std::endl;
		totalClientBalance += clientBalance;
	}

	return totalClientBalance;
}

void ShowStatistics(CBank* bank)
{
	std::cout << "Bank balance: " << bank->GetTotalBalance() << std::endl;
	std::cout << "Customer balance: " << GetCustomerBalance(bank) << std::endl;
}

void ShowUsage() 
{
	std::cout << "Usage: PP2.exe <clients> <primitive>" << std::endl;
	std::cout << "Arguments must be numbers" << std::endl;
}

int main(int argc, char* argv[])
{
	int classInstancesNumber = 2;
	SynchPrimitive primitiveKind = SynchPrimitive::Mutex;

	if (argc == 3)
	{
		int strToIntClient = atoi(argv[1]);
		int strToIntPrimitive = atoi(argv[2]);

		primitiveKind = (SynchPrimitive)strToIntPrimitive;
		classInstancesNumber = strToIntClient;
	}
	else
	{
		ShowUsage();
		return 1;
	}

	CBank* bank = new CBank(primitiveKind);

	for (int i = 0; i < classInstancesNumber; i++)
	{
		CBankClient* client = bank->CreateClient();
	}

	// TODO: WaitForMultipleObjects
	while (true)
	{
		std::string exit;
		std::cin >> exit;
		if (exit == "exit" || exit == "quit")
		{
			break;
		}
	}

	ShowStatistics(bank);

	return 0;
}