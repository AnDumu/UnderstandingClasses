#include <iostream>
#include <Windows.h>

#pragma warning(disable : 4996)

class cTesting
{
private:
	int Age;
	std::string Name;
public:
	cTesting(int age, std::string name);
	void ShowInfo();
	void SetName(std::string name);
	void SetAge(int age);
};

cTesting::cTesting(int age, std::string name)
{
	this->Age = age;
	this->Name = name;
}

void cTesting::ShowInfo()
{
	std::cout << "'" << this->Name.c_str() << "' tiene " << this->Age << " anios." << std::endl;
}

void cTesting::SetName(std::string name)
{
	this->Name = name;
}

void cTesting::SetAge(int age)
{
	this->Age = age;
}

class cNumber
{
private:
	int MagicNumber;
public:
	cNumber(int number);
	void ShowNumber();
	void SetMagicNumber(int number);
};

cNumber::cNumber(int number)
{
	this->MagicNumber = number;
}

void cNumber::ShowNumber()
{
	std::cout << "Magic Number: " << this->MagicNumber << std::endl;
}

void cNumber::SetMagicNumber(int number)
{
	this->MagicNumber = number;
}

int main()
{
	cTesting test(55, "TuVieja");

	test.ShowInfo();

	//std::cout << std::hex << (LPVOID)&test << std::endl;

	//std::cin.get();

	//test.SetName("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	//test.ShowInfo();

	//std::cin.get();

	//test.SetName("TuTia");
	//test.ShowInfo();

	//std::cin.get();

	DWORD anios = 23;
	char str1[] = "TuHermana";
	byte test2[128] = { 0 };

#ifdef _DEBUG
	#ifdef _WIN64
		*(DWORD*)&test2[0x00] = anios;
		*(DWORD*)&test2[0x04] = 0xCCCCCCCC;
		*(DWORD64*)&test2[0x08] = (DWORD64)&test2[0x38];
		*(DWORD64*)&test2[0x10] = (DWORD64)&test2[0x4C];
		*(DWORD64*)&test2[0x18] = 0;
		*(DWORD64*)&test2[0x20] = strlen(str1);
		*(DWORD64*)&test2[0x28] = strlen(str1) + 0x0F;
		*(DWORD64*)&test2[0x30] = 0xCCCCCCCCCCCCCCCC;

		*(DWORD64*)&test2[0x38] = (DWORD64)&test2[0x08];
		*(DWORD64*)&test2[0x40] = 0;
		*(DWORD*)&test2[0x48] = 0xFDFDFDFD;

		strcpy((char*)&test2[0x4C], str1);
	#else
		*(DWORD*)&test2[0x00] = anios;
		*(DWORD*)&test2[0x04] = (DWORD)&test2[0x24];
		*(DWORD*)&test2[0x08] = (DWORD)&test2[0x30];
		*(DWORD*)&test2[0x0C] = 0;
		*(DWORD*)&test2[0x10] = 0;
		*(DWORD*)&test2[0x14] = 0;
		*(DWORD*)&test2[0x18] = strlen(str1);
		*(DWORD*)&test2[0x1C] = strlen(str1) + 0x0F;
		*(DWORD*)&test2[0x20] = 0xCCCCCCCC;

		*(DWORD*)&test2[0x24] = (DWORD)&test2[0x04];
		*(DWORD*)&test2[0x28] = 0;
		*(DWORD*)&test2[0x2C] = 0xFDFDFDFD;

		strcpy((char*)&test2[0x30], str1);
	#endif
#else
	#ifdef _WIN64
		*(DWORD64*)&test2[0x00] = anios;
		*(DWORD64*)&test2[0x08] = (DWORD64)&test2[0x28];
		*(DWORD64*)&test2[0x10] = 0;
		*(DWORD64*)&test2[0x18] = strlen(str1);
		*(DWORD64*)&test2[0x20] = strlen(str1) + 0x0B;
	
		strcpy((char*)&test2[0x28], str1);
	#else
		*(DWORD*)&test2[0x00] = anios;
		*(DWORD*)&test2[0x04] = (DWORD)&test2[0x1C];
		*(DWORD*)&test2[0x08] = 0;
		*(DWORD*)&test2[0x0C] = 0;
		*(DWORD*)&test2[0x10] = 0;
		*(DWORD*)&test2[0x14] = strlen(str1);
		*(DWORD*)&test2[0x18] = strlen(str1) + 0x0B;

		strcpy((char*)&test2[0x1C], str1);
	#endif
#endif

	((cTesting*)&test2[0])->ShowInfo();

	((cTesting*)&test2[0])->SetName("El KPOP");
	((cTesting*)&test2[0])->SetAge(2023-1990);

	((cTesting*)&test2[0])->ShowInfo();

	((cNumber*)&test2[0])->ShowNumber();

	((cNumber*)&test2[0])->SetMagicNumber(666);
	((cNumber*)&test2[0])->ShowNumber();

	((cTesting*)&test2[0])->ShowInfo();

	std::cin.get();

	return EXIT_SUCCESS;
}