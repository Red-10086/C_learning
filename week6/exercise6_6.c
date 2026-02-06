#include <stdio.h>
#include <windows.h>

void alert(int n);//n次响铃函数

int main(void)
{

    /* Include one of these in a function */
    // MessageBeep(MB_OK);/* play Windows default beep */
    // MessageBeep(MB_ICONINFORMATION); /* play asterisk sound */
    // MessageBeep(MB_ICONQUESTION);    /* play question sound */
    // MessageBeep(MB_ICONWARNING);     /* play warning sound */
    int num = 0;
    printf("请输入响铃几声：");
    scanf("%d", &num);
    alert(num);

    return 0;
}

void alert(int n)
{
    for(int i = 0; i < n; i++)
    {
        MessageBeep(MB_OK);  // 响铃一次
        Sleep(500);          // 暂停500毫秒（0.5秒）
        // 如果需要1秒间隔，改为 Sleep(1000);
    }
}