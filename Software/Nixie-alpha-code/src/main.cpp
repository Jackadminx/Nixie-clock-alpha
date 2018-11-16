#include <Arduino.h>
#include <DS3232RTC.h>

int A, B, C, D, data_min, data_hour = 0, E, F;

int datapin = 5;
int latchpin = 6;
int clockpin = 7;

int POWs(int i, int j)
{
    int result = 1;
    if (j == 0)
        return result;
    for (int k = 0; k < j; k++)
    {
        result *= i;
    }
    return result;
}

void randowss(int z)
{
    for (int xx = 0; xx < z; xx++)
    {
        delay(50);
        A = random(10);
        B = random(10);
        C = random(10);
        D = random(10);
        data_min = C * POWs(2, 4) + D;
        data_hour = A * POWs(2, 4) + B;
        digitalWrite(latchpin, LOW);
        shiftOut(datapin, clockpin, LSBFIRST, data_min);
        shiftOut(datapin, clockpin, LSBFIRST, data_hour);
        digitalWrite(latchpin, HIGH);
    }
}
//随机数字显示

void printalll(int zz)
{
    for (int xx = 0; xx < 10; xx++)
    {
        data_min = xx * POWs(2, 4) + xx;
        data_hour = xx * POWs(2, 4) + xx;
        digitalWrite(latchpin, LOW);
        shiftOut(datapin, clockpin, LSBFIRST, data_min);  //B
        shiftOut(datapin, clockpin, LSBFIRST, data_hour); //A
        digitalWrite(latchpin, HIGH);
        delay(zz);
    }
}
//顺序数字显示0-9

void setup()
{
    pinMode(10, OUTPUT);
    //LED二极管，冒号

    Serial.begin(9600);
    setSyncProvider(RTC.get); // the function to get the time from the RTC
    if (timeStatus() != timeSet)
        Serial.println("Unable to sync with the RTC");
    else
        Serial.println("RTC has set the system time");

    pinMode(clockpin, OUTPUT); //Data
    pinMode(datapin, OUTPUT);  //stcp
    pinMode(latchpin, OUTPUT); //shcp

    printalll(200); //顺序显示数字间隔200ms
    randowss(20);   //随机显示数字，20次，间隔50ms
}

void loop()
{

    if ((E == 0 && F == 0) || (E == 0 && F == 1) || (E == 0 && F == 2)) //每分钟进行一次随机显示
    {
        randowss(30);
    }
    if (D == 0 && E == 0 && C == 0) //每10分钟进行一次顺序显示
    {
        printalll(1000);
    }

    //串口打印时间
    Serial.print(hour());
    Serial.print(":");
    if (minute() < 10) // 小于10加0
        Serial.print('0');
    Serial.print(minute());
    Serial.print(":");
    if (second() < 10) // 小于10加0
        Serial.print('0');
    Serial.println(second());

    A = hour() / 10;
    B = hour() % 10;
    C = minute() / 10;
    D = minute() % 10;
    E = second() / 10;
    F = second() % 10;

    data_min = C * POWs(2, 4) + D;
    data_hour = A * POWs(2, 4) + B;

    Serial.print(A);
    Serial.print(" ");
    Serial.print(B);
    Serial.print(" ");
    Serial.print(C);
    Serial.print(" ");
    Serial.println(D);

    Serial.print(data_hour);
    Serial.print(" ");
    Serial.println(data_min);

    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, LSBFIRST, data_min);  //min
    shiftOut(datapin, clockpin, LSBFIRST, data_hour); //hour
    digitalWrite(latchpin, HIGH);

    digitalWrite(10, 0); //点亮冒号LED
    delay(1000);
    digitalWrite(10, 1); //熄灭冒号LED
    delay(1000);
}
