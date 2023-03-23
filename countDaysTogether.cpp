#include <bits/stdc++.h>

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
{

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int arriveAliceMonth = stoi(arriveAlice.substr(0, 2));
    int arriveAliceDay = stoi(arriveAlice.substr(3, 2));
    int arriveAliceMonthDays = 0;
    for (int i = 0; i < arriveAliceMonth - 1; i++)
    {
        arriveAliceMonthDays += months[i];
    }
    int arriveAliceDate = arriveAliceMonthDays + arriveAliceDay;

    int leaveAliceMonth = stoi(leaveAlice.substr(0, 2));
    int leaveAliceDay = stoi(leaveAlice.substr(3, 2));
    int leaveAliceMonthDays = 0;
    for (int i = 0; i < leaveAliceMonth - 1; i++)
    {
        leaveAliceMonthDays += months[i];
    }
    int leaveAliceDate = leaveAliceMonthDays + leaveAliceDay;

    int arriveBobMonth = stoi(arriveBob.substr(0, 2));
    int arriveBobDay = stoi(arriveBob.substr(3, 2));
    int arriveBobMonthDays = 0;
    for (int i = 0; i < arriveBobMonth - 1; i++)
    {
        arriveBobMonthDays += months[i];
    }
    int arriveBobDate = arriveBobMonthDays + arriveBobDay;

    int leaveBobMonth = stoi(leaveBob.substr(0, 2));
    int leaveBobDay = stoi(leaveBob.substr(3, 2));
    int leaveBobMonthDays = 0;
    for (int i = 0; i < leaveBobMonth - 1; i++)
    {
        leaveBobMonthDays += months[i];
    }
    int leaveBobDate = leaveBobMonthDays + leaveBobDay;

    if (arriveAliceDate > leaveBobDate || arriveBobDate > leaveAliceDate)
    {
        return 0;
    }

    return min(leaveBobDate, leaveAliceDate) - max(arriveAliceDate, arriveBobDate) + 1;
}

int main()
{
    int daysTogether = countDaysTogether("08-11", "09-12", "08-13", "08-29");
    cout << daysTogether << endl;
    return 0;
}