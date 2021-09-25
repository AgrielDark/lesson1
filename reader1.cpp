#include <iostream>
#include <cstdlib>
#include "memory.h"
#include "Offsets.h"

using namespace hazedumper;
using namespace netvars;
using namespace signatures;

PModule Base;
memory mem;

int getHealth()
{
	DWORD localPlayer = mem.Read<DWORD>(Base.dwBase + dwLocalPlayer);
	int health = mem.Read<int>(localPlayer + m_iHealth);
	return health;
}

int main()
{
	while(!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)){}
	Base = mem.GetModule("client.dll");

	while (true)
	{
		std::cout << "Health: " << getHealth() << "\n";
		system("cls");
		Sleep(1);
	}
}