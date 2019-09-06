#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int markerChecker(string marker[3][3]) {
    int ret = 0;
    //1,2,3 - done
    if(marker[0][0] == "m1" && marker[0][1] == "m1" && marker[0][2] == "m1") {
        ret = 1;
    }
    //1,4,7 - done
    if(marker[0][0] == "m1" && marker[1][0] == "m1" && marker[2][0] == "m1") {
        ret = 1;
    }
    //1,5,9 - done
    if(marker[0][0] == "m1" && marker[1][1] == "m1" && marker[2][2] == "m1") {
        ret = 1;
    }
    //2,5,8 - done
    if(marker[0][1] == "m1" && marker[1][1] == "m1" && marker[2][1] == "m1") {
        ret = 1;
    }
    //3,6,9 - done
    if(marker[0][2] == "m1" && marker[1][2] == "m1" && marker[2][2] == "m1") {
        ret = 1;
    }
    //3,5,7 - done
    if(marker[0][2] == "m1" && marker[1][1] == "m1" && marker[2][0] == "m1") {
        ret = 1;
    }
    //4,5,6 - done
    if(marker[1][0] == "m1" && marker[1][1] == "m1" && marker[1][2] == "m1") {
        ret = 1;
    }
    //7,8,9 - done
    if(marker[2][0] == "m1" && marker[2][1] == "m1" && marker[2][2] == "m1") {
        ret = 1;
    }

    //1,2,3 - done
    if(marker[0][0] == "m2" && marker[0][1] == "m2" && marker[0][2] == "m2") {
        ret = 1;
    }
    //1,4,7 - done
    if(marker[0][0] == "m2" && marker[1][0] == "m2" && marker[2][0] == "m2") {
        ret = 1;
    }
    //1,5,9 - done
    if(marker[0][0] == "m2" && marker[1][1] == "m2" && marker[2][2] == "m2") {
        ret = 1;
    }
    //2,5,8 - done
    if(marker[0][1] == "m2" && marker[1][1] == "m2" && marker[2][1] == "m2") {
        ret = 1;
    }
    //3,6,9 - done
    if(marker[0][2] == "m2" && marker[1][2] == "m2" && marker[2][2] == "m2") {
        ret = 1;
    }
    //3,5,7 - done
    if(marker[0][2] == "m2" && marker[1][1] == "m2" && marker[2][0] == "m2") {
        ret = 1;
    }
    //4,5,6 - done
    if(marker[1][0] == "m2" && marker[1][1] == "m2" && marker[1][2] == "m2") {
        ret = 1;
    }
    //7,8,9 - done
    if(marker[2][0] == "m2" && marker[2][1] == "m2" && marker[2][2] == "m2") {
        ret = 1;
    }
    return ret;
}

int inputMarker(int input, int player, string marker[3][3]) {
    int ret = 0;
    if(input == 1 && player == 1) {
        marker[0][0] = "m1";
        ret = markerChecker(marker);
    } 
    if(input == 2 && player == 1) {
        marker[0][1] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 3 && player == 1) {
        marker[0][2] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 4 && player == 1) {
        marker[1][0] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 5 && player == 1) {
        marker[1][1] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 6 && player == 1) {
        marker[1][2] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 7 && player == 1) {
        marker[2][0] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 8 && player == 1) {
        marker[2][1] = "m1";
        ret = markerChecker(marker);
    }
    if(input == 9 && player == 1) {
        marker[2][2] = "m1";
        ret = markerChecker(marker);
    }

    if(input == 1 && player == 2) {
        marker[0][0] = "m2";
        ret = markerChecker(marker);
    } 
    if(input == 2 && player == 2) {
        marker[0][1] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 3 && player == 2) {
        marker[0][2] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 4 && player == 2) {
        marker[1][0] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 5 && player == 2) {
        marker[1][1] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 6 && player == 2) {
        marker[1][2] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 7 && player == 2) {
        marker[2][0] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 8 && player == 2) {
        marker[2][1] = "m2";
        ret = markerChecker(marker);
    }
    if(input == 9 && player == 2) {
        marker[2][2] = "m2";
        ret = markerChecker(marker);
    }
    return ret;
}

int userInput(int val, int player) {
    fprintf(stdout, "Player %d, enter a number:", player);
    cin >> val;
    if(val < 1 || val > 9) {
        fprintf(stdout, "Invalid answer\n");
        userInput(val, player);
    }
    return val;
}

int main(int argc, char const *argv[]) {
    int value = 0;
    int player = 1;
    bool endgame = false;
    int ret;
    string marker[3][3];
    
    while(!endgame) {
        value = userInput(value, player);
        cout << value << endl;
        ret = inputMarker(value, player, marker);

        if(ret == 1 && player == 1) {
            cout << "Player 1 wins" << endl;
            endgame = true;
        }
        if(ret == 1 && player == 2) {
            cout << "Player 2 wins" << endl;
            endgame = true;
        }
        if(player == 1) {
            player = 2;
        } else {
            player = 1;
        } 
    }
    return 0;
}