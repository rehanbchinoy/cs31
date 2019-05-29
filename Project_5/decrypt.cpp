#include <iostream>
#include <cstring>

using namespace std;

bool decrypt(const char ciphertext[], const char crib[]);
bool build_match(int n, int i, char (&match)[81], const char encrypt[][81], const char key[]); //pointer to match array so I can return a bool.

void runtest(const char ciphertext[], const char crib[])
{
    cerr << "====== " << crib << endl;
    bool result = decrypt(ciphertext, crib);
    cerr << "Return value: " << result << endl;
}

int main()
{
    cerr.setf(ios::boolalpha); // output bools as "true"/"false"
    
    runtest("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "my secret");
    runtest("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "shadow");
    runtest("The abcde\nbrown fox", "quick");
    runtest("Zysqjs zbguncyqzo jdsbyo eybmnu bg Wqzsvbbf.\nUnysqx eybmgxrsuu ymtbyu kcq Jicjjsy.\nNbuj sajysts rcvsyqr qgx sajysts zbgusykqjcks nbucjcbgu bg xcuzmuucbg wbymtu.\nZU 31 cu zdqrrsgecge!", "conspiracy theory");
    runtest("Kpio't dmpbl-boe-ebhhfs opwfm", "s cloak and");
    runtest("DiebjiggK, zyxZYXzyx--Abca abCa    bdefg## $$hidbijk6437 wvuWVUwvu\n\n8 9\n", "hush-hush until January 20, 2021");
    runtest("bwra wmwt\nqeirtk spst\n", "alan turing");
    runtest("fox    quiz", "8888");
}

bool decrypt(const char ciphertext[], const char crib[])
{
    if (strlen(crib) == 0 || strlen(crib) > 80) //if key is of length zero, then decryption is impossible. key cannot be over 80 characters.
        return false;
    
    //copy key into a new C-string. delete repeating non-alpha characters.
    char key[81];
    strcpy(key, "");
    int t= 0; //position number for key
    for (int i = 0; i < strlen(crib); i++) //traverse length of crib. copy characters into key if they are alpha or non-repeating non-alpha chars.
    {
        if (!(!isalpha(crib[i]) && !isalpha(crib[i+1])))
        {
            key[t] = crib[i];
            t++;
        }
    }
    key[t] = '\0';
    
    char encrypt[62][81]; //2-d character array for lines of ciphertext. 62 possible lines. 80 possible characters, 1 for null byte.
    for (int i = 0; i < 62; i++) //assign array of C-strings as null
        strcpy(encrypt[i], "");
    
    char hold[81]; //holds individual lines of ciphertext, one at a time
    strcpy(hold, "");
    
    int x = 0, r = 0; //to increment position value in encrypt and hold, respectively
    
    for (int i = 0; i < strlen(ciphertext); i++) //assign each line of ciphertext to encrypt. don't include the newline character.
    {
        if (ciphertext[i] != '\n') //assign characters of ciphertext if they are not newlines.
        {
            hold[r] = ciphertext[i];
            r++;
        }
        if ((ciphertext[i] == '\n') || (i== strlen(ciphertext)-1)) //if character is a newline or at the end of ciphertext, encrypt gets hold.
        {
            hold[r++] = '\0'; //terminate the C-string
            strncpy(encrypt[x], hold, r);
            x++;
            r = 0;
            strcpy(hold, "");
        }
    }

    int n = 0, i = 0; //variable to navigate through a line of ciphertext, and variable to navigate through the encrypt array, respectively.
    bool found_match = false;
    char match[81]; //contains the text in encrypt that potentially matches key.
    strcpy(match, ""); //initialize to null.
    
    while (!found_match && i < x) //traverse the entirety of the encrypted message while we have not found a match.
    {
        n = 0; //reset to zero after inner while loop breaks.
        while (!found_match && n < strlen(encrypt[i])) //will exit if potential match is proven incorrect or if end of a C-string in encrypt.
        {
            found_match = build_match(n, i, match, encrypt, key);
            if(!found_match) //continue searching C-string.
                n++;
        }
        i++;
    }
    if (!found_match)//traversed ciphertext and no matches to be found.
        return false;
    
    char unlocked [4941]; //a C-string for the full decrypted message.
    strcpy(unlocked, "");
    
    int m = 0, count = 0; //incrementors
    
    for (int c = 0; c < strlen(ciphertext); c++) //traversing original ciphertext message.
    {
        for (int i = 0; i < strlen(key); i++) //traversing key.
        {
            if (!isalpha(ciphertext[c]))
            {
                unlocked[m] = ciphertext[c];
                m++;
                count = 0;
                i = 1000; //break statement to avoid printing duplicates.
                break;
            }
            else if (toupper(ciphertext[c]) == toupper(match[i])) //if a ciphertext letter is the same as a letter in the matched string of characters...
            {
                unlocked[m] = toupper(key[i]); //then unlocked gets the uppercase version of the corresponding element in key.
                m++;
                count = 0;
                i = 1000; //break statement to avoid printing duplicates.
                break;
            }
            else
                count++;
        }
        if (count == strlen(key)) //if there were no matches between the ciphertext letter to the letters of match, then copy original ciphertext letter.
        {
            unlocked[m] = tolower(ciphertext[c]);
            m++;
            count = 0;
        }
    }
    unlocked[m] = '\0';
    
    cout << unlocked << endl;
    return true;
}

// ===============================================================================================================
bool build_match(int n, int i, char (&match)[81], const char encrypt[][81], const char key[])
{
    int z = 0; //first position in match
    
    strcpy(match, ""); //assign to null.
    
    if (n == 0) //first character in C-string
    {
        match[z] = encrypt[i][n];
        match[z+1] = '\0';
        z++;
        n++;
    }
    for (int j = 0; j < strlen(encrypt[i]); j++) //traverse each line, including null byte, adding chars to match until length equals length of key.
    {
        if ((strlen(match) < strlen(key)) && (!(!isalpha(encrypt[i][n]) && !isalpha(encrypt[i][n-1]))) && j != strlen(encrypt[i]) - 1) //alpha char or non-repeating non-alpha
        {
            match[z] = encrypt[i][n];
            match[z+1] = '\0';
            n++;
            z++;
        }
        if (!isalpha(encrypt[i][n]) && !isalpha(encrypt[i][n-1])) //if repeating non-alpha character, then do not copy into match and move to the next character in encrypt[i]
            n++;
        if (strlen(match) < strlen(key) && j == strlen(encrypt[i]) - 1)
            return false;
        if (strlen(match) == strlen(key)) //to avoid needlessly iterating through for loop
            break;
    }
    
    if (strlen(match) != strlen(key))
        return false;
    else
    {
        int track = 0;
        
        for (int s = 0; s < strlen(key); s++)
        {
            if (isalpha(match[s]))
                track++;
            if (!isalpha(match[s]) && ((!isalpha(key[s]) && isalpha(match[s])) || (!isalpha(match[s]) && isalpha(key[s])))) //if key at pos s is non-alpha, corresponding char in match must be non-alpha, and vice versa.
                return false;
            else if (isalpha(match[s]))
            {
                for (int e = 0; e < strlen(key); e++)
                {
                    if ((toupper(key[s]) == toupper(key[e]) && toupper(match[s]) != toupper(match[e])) || (toupper(match[s]) == toupper(match[e]) && toupper(key[s]) != toupper(key[e]))) //if two characters in key match, their corresponding characters must be the same and vice versa.
                    {
                        return false;
                    }
                }
            }
        }
        if ((track!= 0) && !isalpha(encrypt[i][n])) //if there's at least one alpha char in match and the next character in encrypt[i] after the last character in match is non-alpha, then return true.
            return true;
        else
            return false;
    }
}
