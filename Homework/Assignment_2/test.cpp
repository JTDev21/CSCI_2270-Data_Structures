#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct wordRecord {
    std::string word;
    int count;
};

void sortArray(wordRecord distinctWords[], int length)
{
    for(int i = 0; i < length; i++)
    {
        if(!(distinctWords[i].count > distinctWords[i+1].count) && i+1 != length)
        {
            for(int j = 0; j <= i; j++)
            {
                if(distinctWords[i+1].count >= distinctWords[j].count)
                {
                    wordRecord temp = distinctWords[i+1];
                    for(int k = i+1; k > j; k--)
                    {
                        distinctWords[k] = distinctWords[k-1];
                    }
                    distinctWords[j] = temp;
                    j = i+1;
                }
            }
        }
    }
}


// void swap(wordRecord *x, wordRecord *y)
// {
//     wordRecord temp = *x;
//     *x = *y;
//     *y = temp;
// }

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    std::cout << std::endl;
    float previous_occurrenceProb = -1;
    int start = 0;
    int end = 0;
    for(int i = N; i < N+10; i++)
    {
        float current_occurrenceProb = static_cast<float>(distinctWords[i].count) / totalNumWords;
        if(previous_occurrenceProb == current_occurrenceProb && ((distinctWords[i].word)[0] < (distinctWords[i+1].word)[0]))
        {
            start = i-1;
            for(int j = i; j < N+10; j++)
            {
                current_occurrenceProb = static_cast<float>(distinctWords[j].count) / totalNumWords;
                if(current_occurrenceProb == previous_occurrenceProb)
                {
                    end = j;
                }
            }
            // std::cout << "start: " << start << " | end:" << end << std::endl;
            for(int j = start; j <= end; j++)
            {
                for(int k = j+1; k <= end; k++)
                {
                    if((distinctWords[j].word)[0] > (distinctWords[k].word)[0])
                    {
                        // std::cout << distinctWords[j].word << " > " << distinctWords[k].word << std::endl;
                        wordRecord temp = distinctWords[j];
                        distinctWords[j] = distinctWords[k];
                        distinctWords[k] = temp;
                    }
                }
            }
        }
        previous_occurrenceProb = current_occurrenceProb;
    }

    for(int i = N; i < N+10; i++)
    {
        float occurrenceProb = static_cast<float>(distinctWords[i].count) / totalNumWords;
        // std::cout << std::setprecision(5) << std::fixed << occurrenceProb << " - " << distinctWords[i].word << std::endl;
        std::cout << "[" << i << "] "  << distinctWords[i].word << " - " << distinctWords[i].count << std::endl;
    }
}

int main()
{
    wordRecord distinctWords[26];

    string stringArray[26]={"lima","charlie","delta","bravo","echo","juliet","foxtrot","tango","whiskey","golf","yankee","alpha","mike","india","oscar","zulu","quebec","xray","sierra","hotel","uniform","victor","november","romeo","kilo","papa"};
    int countArray[26]={1,3,3,3,25,4,24,5,23,6,22,8,21,8,3,9,19,10,18,11,17,12,16,13,15,14};
    for(int i = 0; i < 26; i++)
    {
        distinctWords[i].word = stringArray[i];
        distinctWords[i].count = countArray[i];
    }

    sortArray(distinctWords, 26);
    printTenFromN(distinctWords, 16, 26);

    // std::cout << std::endl;
    // for(int i = 0; i < 26; i++)
    // {
    //     if(i == 16)
    //     {
    //         cout << "-----" << endl;
    //     }
    //     cout << distinctWords[i].word << " - " << distinctWords[i].count << endl;
    // }
    return 0;
}


