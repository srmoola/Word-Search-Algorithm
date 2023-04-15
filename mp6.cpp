#include <bits/stdc++.h>

using namespace std;

const int ROWS = 8;
const int COLS = 8;
vector<vector<string>> table(ROWS, vector<string>(COLS)); //declares a 2d vector, which has 8 rows and columns (to limit the number of lines read)
ifstream infile("mp6input.txt");
ofstream outFile("mp6output.txt");
string temp;
int row;
int col;


bool horizontal_check(string target) {

    //int len = target.size();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 2; j++) { //kept getting bad alloc errors so -2 so it doesnt go out of bounds
            string check = table[i][j] + table[i][j+1] + table[i][j+2];
            if (check == target) {
                outFile << "The word " << target << " was found horizontally in row " << i << " and columns " << j<< " to "<< j+(target.length()-1)<<endl;
                return true;

            }
        }
    }
return false;

}

bool vertical_check(string target) {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS - target.length() + 1; j++) {
            string check = "";
            for (int k = 0; k < target.length(); k++) {
                check += table[j+k][i];

                if (check == target) {
                    outFile << "The word " << target << " was found vertically in column " << i << " and rows " << j << " to " << j+target.length()-1 << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

bool diagonal_search(string target){
    for (int i = 0; i < COLS - target.length(); i++) {
        for (int j = 0; j < ROWS - target.length() + 1; j++) {
            string check = "";
            for (int k = 0; k < target.length(); k++) {
                check += table[j+k][i+k];

                if (check == target) {
                    outFile << "The word " << target << " was found diagonally in column " << i << " and rows " << j << " to " << j+target.length()-1 << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

bool all_checks(string target){

    while(true){
    if(horizontal_check(target) == 1){
        break;
    }
    else if(vertical_check(target) == 1){
        break;
    }
    else if(diagonal_search(target) == 1){
        break;
    }
    else{
        outFile<<"The word "<<target <<" was not found"<<endl;
        break;
    }
    }
}

void printArray(){
    // Print the table for verification
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            outFile << table[i][j] << " ";

        }
        outFile << endl;
    }
}

string readWords(){

    while(getline(infile, temp)){

    if(temp.length() == 0){
        continue;
    }

    all_checks(temp);

    }
}

int main() {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            infile >> table[i][j];
        }
    }

    printArray();
    outFile<<"\n\n"<<endl;
    readWords();

cout<<"File written successfully, check for a file named mp6output.txt"<<endl;

    // Close the input file
    infile.close();

    return 0;
}



