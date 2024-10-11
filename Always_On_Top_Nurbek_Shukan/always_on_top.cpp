#include <iostream>
#include <windows.h>

int main() {
    HWND notepadWindow = FindWindow(NULL, L"name.txt - Notepad");
    if (!notepadWindow) {
        std::cerr << "Error: Unable to find Notepad window with name.txt open.\n";
        return 1;
    }

    SetWindowPos(notepadWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    std::cout << "Notepad window is now always on top.\n";

    while (IsWindow(notepadWindow)) {
        if (IsIconic(notepadWindow)) {
            ShowWindow(notepadWindow, SW_RESTORE); // Restore if minimized
        }
        SetWindowPos(notepadWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        Sleep(1000);
    }

    return 0;
}