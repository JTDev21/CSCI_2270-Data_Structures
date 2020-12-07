#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct wordRecord {
    std::string word;
    int count;
};

void getIgnoreWords(const char *ignoreWordFileName, std::string ignoreWords[50])
{
    std::ifstream instream;
    instream.open(ignoreWordFileName);

    if(instream.is_open())
    {
        std::string word;
        int i = 0;
        while(instream >> word)
        {
            ignoreWords[i] = word;
            i++;
        }
        instream.close();
    }
    else
    {
        std::cout << "Failed to open" << ignoreWordFileName << std::endl;
    }
}

bool isIgnoreWord(std::string word, std::string ignoreWords[50])
{
    for(int i = 0; i < 50; i++)
    {
        if(word == ignoreWords[i])
        {
            return true;
        }
    }
    return false;
}

int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    int totalWords = 0;
    for(int i = 0; i < length; i++)
    {
        totalWords += distinctWords[i].count;
    }
    return totalWords;
}

void sortArray(wordRecord distinctWords[], int length)
{
    // I believe this is a crude version of the insertion sort algorithm
    // Iterate through the distinctWords array
    for(int i = 0; i < length; i++)
    {
        // If the count from i is less than the count of i+1, then we know its not in order from greatest to least
        // The i+1 != length makes sure we don't have a segmentation fault error
        if(distinctWords[i].count < distinctWords[i+1].count && i+1 != length)
        {
            // We need to find a value where the count from (i+1) is greater than the count value from j
            for(int j = 0; j <= i; j++)
            {
                if(distinctWords[i+1].count > distinctWords[j].count)
                {
                    // Here's where the insertion happens, but before that we must make room for the value of i+1
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

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    float previous_occurrenceProb = -1;
    int start = 0;
    int end = 0;
    for(int i = N; i < N+10; i++)
    {
        float current_occurrenceProb = static_cast<float>(distinctWords[i].count) / totalNumWords;
        if(previous_occurrenceProb == current_occurrenceProb && ((distinctWords[i].word)[0] < (distinctWords[i+1].word)[0]))
        {
            // Since we want to alphabetize the word where they have the same probability we want to know when the words with the same probablilty starts and ends
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
        std::cout << std::setprecision(5) << std::fixed << occurrenceProb << " - " << distinctWords[i].word << std::endl;
    }
}

int main(int argc, char* argv[])
{
    int N = std::stoi(argv[1]);
    const char* readTextFile = argv[2];
    const char* stopwordsFile = argv[3];

    std::string ignoreWords[50];
    getIgnoreWords(stopwordsFile, ignoreWords);

    std::ifstream instream;
    instream.open(readTextFile);

    std::string word;

    int numArrayDoubled = 0;
    int arrSize = 100;
    int numElements = 0;
    
    wordRecord *distinctWords = new wordRecord[arrSize];
    while(instream >> word)
    {
        if(!isIgnoreWord(word, ignoreWords))
        {
            bool isUnique = true;
            for(int i = 0; i < numElements; i++)
            {
                if((&distinctWords[i])->word == word)
                {
                    isUnique = false;
                    (&distinctWords[i])->count += 1;
                }
            }
            if(isUnique)
            {
                (&distinctWords[numElements])->word = word;
                (&distinctWords[numElements])->count += 1;
                numElements++;
            }
            if(!(numElements < arrSize))
            {
                numArrayDoubled += 1;
                arrSize *= 2;
                wordRecord *temp_arr = new wordRecord[arrSize*2];
                for(int i = 0; i < numElements; i++)
                {
                    temp_arr[i] = distinctWords[i];
                }
                delete[] distinctWords;
                distinctWords = temp_arr;
            }
        }
    }
    instream.close();

    sortArray(distinctWords, numElements);

    int totalNumWords = getTotalNumberNonIgnoreWords(distinctWords, numElements);
    std::cout << "Array doubled: " << numArrayDoubled << std::endl;
    std::cout << "Distinct non-common words: " << numElements << std::endl;
    std::cout << "Total non-common words: " << totalNumWords << std::endl;
    std::cout << "Probability of next 10 words from rank " << N << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    printTenFromN(distinctWords, N, totalNumWords);
    return 0;
}