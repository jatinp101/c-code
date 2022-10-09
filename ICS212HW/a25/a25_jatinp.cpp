/*
Takes in document and outputs it with format.
Pandya, Jatin
ICS 212 Assignment #26  
4/28/2019
certain pieces of code found from slide show and example code
*/ 

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>     //to get the vector class (a vector is a type of array)
#include <algorithm>  //to use the sort() function
#include <iomanip>    //to use the setw() function

#define SIZE  130
using namespace std;

//Used to store three strings: the English, the Japanese, and the sort field 
class Entry{
public:
//default constructor
  Entry() {
  }
//three set functions
  void setEng(string newEng) {
    eng = newEng;
  }
  void setJap(string newJap) {
    jap = newJap;
  }
  void setSort(string newSort) {
    sortfield = newSort;
  }
//three get functions 
  const string getEng() const{
    return eng;
  }
  const string getJap() const{
    return jap;
  }
  const string getSort() const{
    return sortfield;
  }
//overload the operator< (less than operator)
  bool operator< (const Entry &entry) const{
    if (this->sortfield < entry.sortfield)
      return true;
    return false;
  }
  friend ostream & operator<<(ostream & output, const Entry & e){
    output << e.getEng()<< "\t\t";
     output<< e.getJap() << endl;
    return output;
  }
private:
//data field for English
  string eng = " ";
//data field for Japanese
  string jap = " ";
//data field for the sort field
  string sortfield = " ";
};

int main(int argc, char *argv[]){
  string line = "";
  ifstream myInStream(argv[1]);
  if(!myInStream.is_open()){ //newer way
    cout<<"Cannot open file"<<endl;
    return 1;
  }
//Make a vector of Entry objects.
  vector<Entry> entries;
//Read the data from the file one line at a time
  while(!myInStream.eof()) {
    /*
      If s is a string and w is an input stream, 
      then getline(w, s) reads a line from stream w into s
    */
    Entry temp;
    cout << "Works after creating temp"<< endl;
    getline(myInStream, line);
    cout << "Line: " << line << endl;
    cout << "Got line" << endl;
    int j = 0;
    if (line[j] == 91) {
	j = line.find("]");
	j++;
    } if (line[j] == 32) {
      j++;
    } if (line[j] == 40) {
	j = line.find(")");
	j++;
    } if (line[j] == 32) {
	j++;
    }
    cout << "figured out where the actual place is: " << j << endl;
    int i = line.find("\t");
    int l = j;
    while (line[l] != 32){
      //cout << "works l: " <<l << endl; 
      l++;
    }
    l++;
    cout << "l: " << l << endl;
    cout <<"Substring" << line.substr(j,l) << endl;
    temp.setSort(line.substr(j,l));
    string s = temp.getSort();
    transform (s.begin(), s.end(), s.begin(), ::tolower);
    temp.setSort(s);
    temp.setEng(line.substr(0,line.find("\t")));
    temp.setJap(line.substr(line.find("\t")+1));
    entries.push_back(temp);
  }
  sort(entries.begin(), entries.end());
  for(int i = 0; i<entries.size(); i++){
    cout << entries[i];
  }
//Break the line into three parts as described on the assignment webpage. 
//Store the data for each line in an Entry object. 
//Store each Entry object in the vector.
//Sort the vector of Entry objects.
//Display the English and Japanese parts of the sorted Entry objects.	
   return 0;
}
