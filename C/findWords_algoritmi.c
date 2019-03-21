#include <stdio.h>
#include <time.h>
#define SIZE (40000)

struct Storage
{
    char fraasi[100];
    char selitys[100];
    int fmaara, hc, unique, testimaara;
}rutto[SIZE];

struct Storage* hashArray[SIZE];
struct Storage* item2;
struct Storage* item;
struct Storage* swap2;
struct Storage* swap3;

//Inserting phrases into array and counting how many times each phrase is found. Also how many unique words
void insert(char *fraasi, char *selitys, int h)
{
    struct Storage *item = (struct Storage*)malloc(sizeof(struct Storage));
    struct Storage *item2 = (struct Storage*)malloc(sizeof(struct Storage));

    strcpy(item -> fraasi, fraasi); //Copy phrase to item

    int n = 0;
    for (n = 0; n < SIZE; n++)
    {
        if (hashArray[h] == NULL)
        {
            hashArray[h] = item;
            rutto[0].unique++;
            break;
        }else
        {
            if ((strcmp(item->fraasi, hashArray[h]->fraasi) == 0))
            {
                rutto[h].fmaara++;
                break;
            }else
            {
                rutto[0].hc++;
                h = h % SIZE;
                break;
            }
        }
    }
}
//djb for hashkey
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)

        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash % SIZE;
}

//changes all letters to uppercase
char toUpperCase (char *sana)
{
    while (*sana != '\0')
    {
        *sana = toupper(*sana);
        sana++;
    }
return *sana;
}

//nulls the array
void nullForEveryone ()
{
    int nol;

    for (nol = 0; nol < SIZE; nol++)
    {
        hashArray[nol] = NULL;
    }
}
//prints wordcount, unique words, hash collisions amount and the top 100 most common words
char printFindings(wordCounter)
{
int cc = 0;

printf("\nTotal number of Phrases in file %d\n", wordCounter);
printf("Total number of unique phrases %d\n", rutto[0].unique);
printf("Total number of Hash Collisions %d\n\n", rutto[0].hc);
printf("Phrase and how many times it has occured in the given file\n");

for ( cc = 0 ; cc < 100 ; cc++ )
{
    printf("%s %d\n", hashArray[cc], rutto[cc].fmaara+1);
}
printf("\nDo you want to search a word for their explanations? 1 for yes, 2 for exit\n");
return 0;
}
//rutto[dd].fmaara

void shellsort(int num) //credit to http://www.sanfoundry.com/c-program-implement-shell-sort/
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (rutto[k+i].fmaara <= rutto[k].fmaara)
                    break;
                else
                {
                    tmp = rutto[k].fmaara;
                    rutto[k].fmaara = rutto[k+i].fmaara;
                    rutto[k+i].fmaara = tmp;
                    //here we swap in sync in both arrays to keep them matching.
                    swap2 = hashArray[k];
                    hashArray[k] = hashArray[k+i];
                    hashArray[k+i] = swap2;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char str[250], filePath[250], tempword[250], tempexplanation[250], filePath2[250]; //fgets saves line from text file here
  char *seperatedLine; //temporary place for seperated words
  const char seperator = ':'; //Text file seperates frase:explanation with :
  int wordCounter = 0, yn; //counts how many phrases appear in file

  printf("Please insert the path to the file without the file extension\n");
  scanf ("%s", filePath );
  strcat(filePath, ".txt"); //adds the file extension
  //clock_t begin = clock(); If you want to test times, remove comment
  nullForEveryone(); //Used to NULL the array
  fp = fopen (filePath, "r");//Open file for reading and test if it actually opened
  if (fp == NULL)
  {
    printf("Can't open file\n");
    system("pause");
  }

  if (fp)
  {
    while(fgets(str, 250, fp))
        {
        seperatedLine = strchr (str, seperator);//search until you find the : in phrase:expanation
        *seperatedLine = 0;//becomes phrase0explanation

        strcpy(tempword, str);//copy word from str to tempword
        toUpperCase (tempword); //Makes the words UPPERCASE
        strcpy(tempexplanation, seperatedLine+1);//move pointer 1 and get the explanation for the word
        toUpperCase (tempexplanation);//Makes the words UPPERCASE

        int number = hash(tempword); //getting hash number
        insert(tempword, tempexplanation, number);//inserting the word to hasharray
        wordCounter++; //Calculatin how many phrases in  file
        }
  }
shellsort(40000);//sorting the array to find most frequent words 40000 is for the gap
//clock_t end = clock(); If you want to test times, remove comment
//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; If you want to test times, remove comment
//printf("time spent is %f", time_spent); If you want to test times, remove comment
printFindings(wordCounter);//To print result for user
scanf ("%d", &yn);//Asks if the users wants to search for explanations

 if (yn == 1)//User wants to test so it goes here
 {
    printf("\nWhat word would you like to see explanations for?\n\n");
    scanf("%s", filePath2); //ask for the word to be searched
    toUpperCase (filePath2);

    fp = fopen (filePath, "r"); //Open file for reading and test if it actually opened

     if (fp == NULL)
     {
       printf("Can't open file\n");
       system("pause");
     }

    if (fp)
    {
    while(fgets(str, 250, fp))//search the whole file and print the explanation part if a match is found
        {
            seperatedLine = strchr (str, seperator); //search until you find the : in phrase:expanation
            *seperatedLine = 0; //becomes phrase0explanation

            strcpy(tempword, str); //
            toUpperCase (tempword);
            if ((strcmp(tempword, filePath2) == 0))
            {
            strcpy(tempexplanation, seperatedLine+1);
            toUpperCase (tempexplanation);
            printf("%s", tempexplanation); //print the explanation if matching word is found
            }
         }
    }
 }else
 {
  return;
 }
system("pause");
return 0;
}
