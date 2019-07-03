// tolower example (C++)
#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include <fstream> 
using namespace std;
const int alphabetSize = 26;
/* this function grabs a string and converts all the characters to lowercase characters*/
void convertToLowercase(string  & fileString){
    locale loc;
    string newLowercaseString = "";
    for (string::size_type i=0; i<fileString.length(); ++i){
        newLowercaseString += tolower(fileString[i],loc);
    }
    fileString = newLowercaseString;    
}
/*this function finds how many times a character appears in a string*/
int countCharacters(char onechar,string fileLine){
    int count = 0;
    for(string::size_type i = 0;i<fileLine.length();i++){
        if(fileLine[i] == onechar){
            count++;
        } 
    }
    return count;
}
/*this function counts how many words are in a string*/
int countWords(string fileline){
    int count = 0;
    for(string::size_type i = 0;i<fileline.length();i++){
        if(fileline[i] == ' ' && fileline[i-1] != '.'){
            count++;
        }
        else if(fileline[i] == '.'){
            count++;
        } 
    }
    return count;
}
/*this function assign the the number of instnaces a character appears in string, to an integer array*/
void assignCharactersInstances(string fileString,int  numberPerLetter[]){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < alphabetSize; i++){
        numberPerLetter[i] = countCharacters(alphabet[i],fileString);
    }
}
//this function outputs a formated version of the final results
void outputFormat(int numberEachLetter[],string fileLine){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cout<<countWords(fileLine)<<" words"<<endl;
    for(string::size_type i = 0; i<alphabet.length();i++){
        if(numberEachLetter[i] != 0){
            
            cout<<numberEachLetter[i] << " "<< alphabet[i]<<endl;
        }
    }
}
int main(){
    int numberEachLetter[alphabetSize];
    ifstream input( "mytext.dat" );
    for(string line; getline( input, line ); )
    {
        cout<<line<<endl;
        convertToLowercase(line);
        assignCharactersInstances(line,numberEachLetter);
        outputFormat(numberEachLetter,line);
        
    }  
    return 0;
}