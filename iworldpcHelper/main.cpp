#include<iostream>
#include<Windows.h>

int main() {
	HWND hGameWnd = FindWindow(L"RenderWindow_ClassName", L"√‘ƒ„ ¿ΩÁ");
	if (hGameWnd == NULL) {
		printf("Find handle. error code:%d\n", GetLastError());
		return 0;
	}
	DWORD dPID = 0;
	GetWindowThreadProcessId(hGameWnd, &dPID);

	if (dPID == 0) {
		printf("Get PID. error code: %d\n", GetLastError());
		return 0;
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
	DWORD dBaseAddress = 0x00905A4D;
	DWORD dReader = 0;
	DWORD dSize = 0;
	//HMODULE hBase = GetModuleHandle(L"iworldpc.exe");
	//if (hBase == NULL) {
	//	printf("%d\n", GetLastError());
	//}
	if (NULL == ReadProcessMemory(
		hProcess,
		//(LPVOID)(dBaseAddress+0x00971D7C+0x8C),
		(LPVOID)(0x00E68000),
		&dReader,
		sizeof(DWORD),
		&dSize
	)) {
		printf("Read memory. error code: %d\n", GetLastError());
		return 0;
	}
	std::cout << dReader << "\n";
	//return 0;
	/*loop start*/
	DWORD dReader0 = dReader;
	DWORD dReader1 = 0;
	ReadProcessMemory(
		hProcess,
		(LPVOID)(dReader0),
		&dReader1,
		sizeof(DWORD),
		&dSize
	);
	std::cout << dReader1 << "\n";
	/*loop end*/
	return 0;
	/*loop start*/
	dReader0 = dReader1;
	dReader1 = 0;
	ReadProcessMemory(
		hProcess,
		(LPVOID)(dReader0 + 0x8),
		&dReader1,
		sizeof(DWORD),
		&dSize
	);
	std::cout << dReader1 << "\n";
	/*loop end*/
	/*loop start*/
	dReader0 = dReader1;
	dReader1 = 0;
	ReadProcessMemory(
		hProcess,
		(LPVOID)(dReader0 + 0xC),
		&dReader1,
		sizeof(DWORD),
		&dSize
	);
	std::cout << dReader1 << "\n";
	/*loop end*/
	/*loop start*/
	dReader0 = dReader1;
	dReader1 = 0;
	ReadProcessMemory(
		hProcess,
		(LPVOID)(dReader0 + 0x4),
		&dReader1,
		sizeof(DWORD),
		&dSize
	);
	std::cout << dReader1 << "\n";
	/*loop end*/
	return 0;
	/*945804461=1*/
	int n = 945804461;
	WriteProcessMemory(
		hProcess,
		(LPVOID)(dReader0 + 0x4),
		&n,
		sizeof(DWORD),
		&dSize
	);
	
	return 0;
}