
#include <iostream>
#include <string>

using std::cout;

int main()
{
    int count = 1;
    std::string str1;

    cout << "Type in any sentence: ";
    std::getline(std::cin, str1);

    cout << "\n\n";

    //count number of items in string
    for (int i = 0; str1.length() > i; i++ ) {
        if (str1[i] == ' ') {
            count++;
        }
    }

    //set size of array according to count
    std::string *stringItemz = new std::string[count];

    //put items in array
    int strItemIndex = 0;
    int prevIndex = 0;
    for (int i = 0; str1.length() > i; i++) {
        if (str1[i] == ' ') {
            stringItemz[strItemIndex] = str1.substr(prevIndex, i-prevIndex);
            strItemIndex++;
            prevIndex = i+1;
        }
        //get last item
        if (i == str1.length() - 1) {
            stringItemz[strItemIndex] = str1.substr(prevIndex, str1.length());
        }
    }

    //go through array to find out count of numbers and words
    int numbers = 0;
    int words = 0;
    bool wordFound = false;
    for (int i = 0; count > i ; i++) {
        for (int x = 0; stringItemz[i].length() > x; x++) {
            if (std::isdigit(stringItemz[i][x])) {
                
            }
            else {
                wordFound = true;
            }
        }
        if (wordFound) {
            words++;
            wordFound = false;
        }
        else {
            numbers++;
        }
    }

    //results
    cout << "Words total: " << words+numbers << "\nNumeric values: " << numbers << "\nNon-numeric Words: " << words << std::endl;

    cout << std::endl;
    delete [] stringItemz;
    return 0;
}