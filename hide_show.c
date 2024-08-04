#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    HKEY hKey;
    DWORD dwType = REG_DWORD;
    DWORD dwSize = sizeof(DWORD);
    DWORD dwValue;
    DWORD newValue;
    char command[512];

    // ´ò¿ª×¢²á±íÏî
    if (RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_READ | KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        // ¶ÁÈ¡ Hidden µÄÊýÖµÊý¾Ý
        if (RegQueryValueEx(hKey, "Hidden", NULL, &dwType, (LPBYTE)&dwValue, &dwSize) == ERROR_SUCCESS) {
            // ÅÐ¶Ïµ±Ç°Öµ²¢ÉèÖÃÐÂÖµ
            newValue = (dwValue == 1) ? 0 : 1;

            // Ð´ÈëÐÂÖµ
            if (RegSetValueEx(hKey, "Hidden", 0, dwType, (LPBYTE)&newValue, sizeof(DWORD)) == ERROR_SUCCESS) {
                printf("Hidden µÄÊýÖµÊý¾ÝÒÑÐÞ¸ÄÎª£º%d\n", newValue);
            } else {
                printf("ÎÞ·¨Ð´ÈëÐÂÖµ¡£\n");
            }
        } else {
            printf("ÎÞ·¨¶ÁÈ¡ Hidden µÄÊýÖµÊý¾Ý¡£\n");
        }

        // ¹Ø±Õ×¢²á±íÏî
        RegCloseKey(hKey);
    } else {
        printf("ÎÞ·¨´ò¿ª×¢²á±íÏî¡£\n");
    }

    return 0;
}
