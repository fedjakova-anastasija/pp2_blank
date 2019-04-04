#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"

int main(int argc, char *argv[])
{
	CBank* bank = new CBank();
	//CBankClient* client1 = bank->CreateClient();
	//CBankClient* client2 = bank->CreateClient();

	int classInstancesNumber = 2;
	if (argc == 2) {
		int strToInt = atoi(argv[1]);
		classInstancesNumber = strToInt;
	}

	for (int i = 0; i < classInstancesNumber; i++) {
		CBankClient* client = bank->CreateClient();
	}

	// TODO: WaitForMultipleObjects
	while (true)
	{
	}

    return 0;
}