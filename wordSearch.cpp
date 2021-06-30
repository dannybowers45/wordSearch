
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iterator>
using namespace std;

int main(){
  unordered_set<string> wordSet;
  ifstream wordList("words.txt");
  string temp;

  while(getline(wordList,temp)){ //Feed words.txt into unordered_set wordSet
    wordSet.insert(temp);
  }
  wordList.close();


  ifstream puzzleInput("puzzle.txt");
  string temp2;
  char cTemp;
  vector<string> vec;
  while(getline(puzzleInput,temp2)){  //Feed puzzle.txt into vector to find dimensions
    for(int a = 0; a < temp2.length(); a++){
      temp2.erase(remove_if(temp2.begin(), temp2.end(), ::isspace), temp2.end());
    }
    vec.push_back(temp2);
    temp2="";
  }
  puzzleInput.close();
  int rowSize=vec.size();         //size of array row
  int colSize=vec.at(0).length(); //size of array column
  string twoArr[rowSize][colSize];//initialize 2D array

  ifstream puzzleInput2("puzzle.txt");
  for(int row = 0; row<rowSize; row++){
    for(int col=0; col<colSize; col++){
    puzzleInput2>>twoArr[row][col]; //input values into 2D array
  }
}

  puzzleInput2.close();


    string tempStr, revTempStr;

  //Loop through 2D arrays side to size with triple for loop
    for(int row = 0; row<rowSize; row++){
      for(int col=0; col<colSize-5; col++){ //colSize-5 because words must be at least 6 letters
        tempStr=twoArr[row][col]+twoArr[row][col+1]+twoArr[row][col+2]+twoArr[row][col+3]+twoArr[row][col+4]; //Add first five letters
        for(int col2=col+5; col2<colSize; col2++){
            tempStr+=twoArr[row][col2]; //continue to add elements to string until column ends
            revTempStr=tempStr;
            reverse(revTempStr.begin(),revTempStr.end());
            // cout<<tempStr<<endl;
            // cout<<revTempStr<<endl;
            if (wordSet.find(tempStr) != wordSet.end()) {
              cout << tempStr << " from (" << row << ", " << col <<") to ("<<row<< ", " <<col2<<")" << endl;
            }
            else if (wordSet.find(revTempStr) != wordSet.end()){
              cout << revTempStr  << " from (" << row << ", " << col2 <<") to ("<<row<< ", " <<col<<")" << endl;
            }
        }
      }
    }
      //Loop through 2D arrays up and down with triple for loop
    for(int col = 0; col<colSize; col++){
      for(int row=0; row<rowSize-5; row++){ //colSize-5 because words must be at least 6 letters
        tempStr=twoArr[row][col]+twoArr[row+1][col]+twoArr[row+2][col]+twoArr[row+3][col]+twoArr[row+4][col]; //Add first five letters
        for(int row2=row+5; row2<rowSize; row2++){
            tempStr+=twoArr[row2][col]; //continue to add elements to string until column ends
            revTempStr=tempStr;
            reverse(revTempStr.begin(),revTempStr.end());
            //cout<<tempStr<<endl;
            //cout<<revTempStr<<endl;
            if (wordSet.find(tempStr) != wordSet.end()) {
              cout << tempStr << " from (" << row << ", " << col <<") to ("<<row2<< ", " <<col<<")" << endl;
            }
            else if (wordSet.find(revTempStr) != wordSet.end()){
              cout << revTempStr  << " from (" << row2 << ", " << col <<") to ("<<row<< ", " <<col<<")" << endl;
            }
        }
      }
    }

int rowStart, colStart;

//first half of traversal down to right and up to the left
for(int row = rowSize; row>=0; row--){
  tempStr="";
  revTempStr="";
    for(int row2 = row, col2=0; (row2<rowSize && col2<colSize); row2++, col2++){
      if(tempStr.length()==0){
        rowStart = row2;
        colStart = col2;
      }
      tempStr+=twoArr[row2][col2];
      if(tempStr.length()>5){
      string revTempStr=tempStr;
      reverse(revTempStr.begin(),revTempStr.end());
        //cout<<tempStr<<endl;
        //cout<<revTempStr<<endl;
          if (wordSet.find(tempStr) != wordSet.end()){
                       cout << tempStr << " from (" << rowStart << ", " << colStart <<") to ("<<row2<< ", " <<col2<<")" << "\n"<<endl;
                     }
                     else if (wordSet.find(revTempStr) != wordSet.end()){
                       cout << revTempStr  << " from (" << row2 << ", " << col2 <<") to ("<<rowStart<< ", " <<colStart<<")" <<"\n"<< endl;
                     }
        }

  }

  }

//second half of traversal down to right and up to the left
for(int col=colSize; col>0; col--){
  tempStr="";
  revTempStr="";
    for(int row2 = 0, col2=col; (row2<rowSize && col2<colSize); row2++, col2++){
      if(tempStr.length()==0){
        rowStart = row2;
        colStart = col2;
      }
        tempStr+=twoArr[row2][col2];
        if(tempStr.length()>5){
        string revTempStr=tempStr;
        reverse(revTempStr.begin(),revTempStr.end());
          //  cout<<tempStr<<endl;
            //cout<<revTempStr<<endl;
            if (wordSet.find(tempStr) != wordSet.end()){
                         cout << tempStr << " from (" << rowStart << ", " << colStart <<") to ("<<row2<< ", " <<col2<<")" << "\n"<<endl;
                       }
                       else if (wordSet.find(revTempStr) != wordSet.end()){
                         cout << revTempStr  << " from (" << row2 << ", " << col2 <<") to ("<<rowStart<< ", " <<colStart<<")" <<"\n"<< endl;
                       }
          }

  }
 }

//first half of traversal down to the left and up to the right
for( int k = 0 ; k <= colSize + rowSize - 2; k++ ) {
  tempStr="";
  for(int col = 0 ; col <= k ; col++ ) {
    int row = k - col;
    //for (int row2 = row+5, int col2 = col+5; (y <10 || x <10); x++, y++)
    if( row < rowSize && col < colSize ) {
       if(tempStr.length()==0){
       rowStart=row;
       colStart=col; //for printing purposes
     }
       tempStr+=twoArr[row][col];
       int len = tempStr.length();
       if(len>=6){
       string revTempStr=tempStr;
       reverse(revTempStr.begin(),revTempStr.end());
       //cout<<"k: "<<k<<". row: "<< row<< ". col: "<<col<<endl;
       //cout<<tempStr<<endl;
       // cout<<revTempStr<<endl;
       if (wordSet.find(tempStr) != wordSet.end()){  //chicken from [5][0] to [0][5]
         cout << tempStr << " from (" << rowStart << ", " << colStart <<") to ("<<row<< ", " <<col<<")" << "\n"<<endl;
       }
       else if (wordSet.find(revTempStr) != wordSet.end()){
         cout << revTempStr  << " from (" << row << ", " << col <<") to ("<<rowStart<< ", " <<colStart<<")" <<"\n"<< endl;
       }
     }
  }
}
}
    //second half of traversal down to the left and up to the right
for( int k = 0 ; k <= colSize + rowSize - 2; k++ ) {
  tempStr="";
  for(int col = 0 ; col <= k ; col++ ) {
      int row = k - col;
      //for (int row2 = row+5, int col2 = col+5; (y <10 || x <10); x++, y++)
      if( row < rowSize && col < colSize ) {
         if(tempStr.length()==0){
           rowStart=row;
           colStart=col; //for printing purposes
         }
         tempStr+=twoArr[row][col];
         int len = tempStr.length();
         if(len>=6){
           string revTempStr=tempStr;
           reverse(revTempStr.begin(),revTempStr.end());
           if (wordSet.find(tempStr) != wordSet.end()){  //chicken from [5][0] to [0][5]
             cout << tempStr << " from (" << rowStart << ", " << colStart <<") to ("<<row<< ", " <<col<<")" << "\n"<<endl;
           }
           else if (wordSet.find(revTempStr) != wordSet.end()){
             cout << revTempStr  << " from (" << row << ", " << col <<") to ("<<rowStart<< ", " <<colStart<<")" <<"\n"<< endl;
           }
         }
      }
  }
}

  return 0;
}
