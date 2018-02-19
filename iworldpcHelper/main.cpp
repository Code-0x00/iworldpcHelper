#include<iostream>
#include<Windows.h>

int main() {
	//HMODULE hBase = GetModuleHandle(NULL);
	DWORD offset[5] = { 0x8C,0x50,0x8,0xC,0x4 };
	DWORD readAddr[6];
	HWND hGameWnd = FindWindow(L"GBOXAPP", L"ÀËÂþ×¯Ô° 2.01");
	if (hGameWnd == NULL) {
		printf("Find handle. error code:%d\n", GetLastError());
		return 0;
	}
	else {
		printf("handle:%d\n", hGameWnd);
	}
	DWORD dPID = 0;
	GetWindowThreadProcessId(hGameWnd, &dPID);
	if (dPID == 0) {
		printf("Get PID. error code: %d\n", GetLastError());
		return 0;
	}
	else {
		printf("pid:%d\n", dPID);
	}
	HANDLE hProcess = OpenProcess(
		PROCESS_ALL_ACCESS,
		FALSE,
		dPID
	);
	if (hProcess == NULL) {
		printf("Open Process. error code:%d\n", GetLastError());
		return 0;
	}
	else {
		printf("hprocess:%d\n", hProcess);
	}
	DWORD dBaseAddress = 0x29007BE0;
	DWORD dReader = 0;
	DWORD dSize = 0;

	if (NULL == ReadProcessMemory(
		hProcess,
		(LPVOID)(dBaseAddress),
		&readAddr[0],
		sizeof(DWORD),
		&dSize
	)) {
		printf("Read memory. error code: %d\n", GetLastError());
		return 0;
	}
	readAddr[0] = 0x29007BE0;
	std::cout << readAddr[0] << "\n";

	for (int i = 0; i < 5; i++) {
		DWORD dBaseAddress = 0x29007BE0;
		DWORD dReader = 0;
		DWORD dSize = 0;

		if (NULL == ReadProcessMemory(
			hProcess,
			(LPVOID)(readAddr[i]+offset[i]),
			&readAddr[i+1],
			sizeof(DWORD),
			&dSize
		)) {
			printf("Read memory. error code: %d\n", GetLastError());
			return 0;
		}
		std::cout << readAddr[i+1] << "\n";
	}

	return 0;
	/*945804461=1*/
	int n = 945804461;
	WriteProcessMemory(
		hProcess,
		(LPVOID)(readAddr[4]),
		&n,
		sizeof(DWORD),
		&dSize
	);
	return 0;
}