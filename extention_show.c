#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    HKEY hKey;
    DWORD dwType = REG_DWORD;
    DWORD dwSize = sizeof(DWORD);
    DWORD dwValue;
    DWORD newValue;

    // 打开注册表项
    if (RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_READ | KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        // 读取 HideFileExt 的数值数据
        if (RegQueryValueEx(hKey, "HideFileExt", NULL, &dwType, (LPBYTE)&dwValue, &dwSize) == ERROR_SUCCESS) {
            // 判断当前值并设置新值
            newValue = (dwValue == 1) ? 0 : 1;

            // 写入新值
            if (RegSetValueEx(hKey, "HideFileExt", 0, dwType, (LPBYTE)&newValue, sizeof(DWORD)) == ERROR_SUCCESS) {
                printf("HideFileExt 的数值数据已修改为：%d\n", newValue);
            } else {
                printf("无法写入新值。\n");
            }
        } else {
            printf("无法读取 HideFileExt 的数值数据。\n");
        }

        // 关闭注册表项
        RegCloseKey(hKey);
    } else {
        printf("无法打开注册表项。\n");
    }

    return 0;
}
