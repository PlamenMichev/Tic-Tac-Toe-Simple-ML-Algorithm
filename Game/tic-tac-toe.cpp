#include  <iostream>
#include  <cstdlib>
#include  <cstring>
#include <bits/stdc++.h>
using  namespace  std;

void CreateField(char field[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            field[i][j] = '.';
        }
    }
}

void PrintSign(char field[3][3], int row, int col, int position) {
    if(field[row][col] == '.') {
        cout<<position;
        }
        else {
            cout<<field[row][col];
        }
}

void PrintField(char field[3][3], char playerSign, char computerSign)
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player ("<<playerSign<<")  -  Computer ("<<computerSign<<")" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  "; PrintSign(field, 0, 0, 1); cout << "  |  "; PrintSign(field, 0, 1, 2); cout << "  |  "; PrintSign(field, 0, 2, 3); cout << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  "; PrintSign(field, 1, 0, 4); cout << "  |  "; PrintSign(field, 1, 1, 5); cout << "  |  "; PrintSign(field, 1, 2, 6); cout << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  "; PrintSign(field, 2, 0, 7); cout << "  |  "; PrintSign(field, 2, 1, 8); cout << "  |  "; PrintSign(field, 2, 2, 9); cout << endl;

    cout << "     |     |     " << endl << endl;
}

bool IsDraw(char field[3][3])
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(field[i][j] == '.')
            {
                counter++;
            }
        }
    }

    if (counter != 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool CheckCoordinates(int x, int y)
{
    if ((x < 0 || x >= 3) || (y < 0 || y >= 3))
    {
        return false;
    }

    return true;
}

bool CheckFieldNum(char field[3][3], int x, int y)
{
    if (field[x][y] != '.')
    {
        return false;
    }

    return true;
}

bool IsWin(char field[3][3], char playerSign)
{
    for (int i = 0; i < 3; i++)
    {
        int rowCounter = 0;
        for (int j = 0; j < 3; j++)
        {
            if(field[i][j] == playerSign)
            {
                rowCounter++;
            }
        }

        if(rowCounter == 3)
        {
            return true;
        }
    }

    int mainDiagonalCounter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(field[i][j] == playerSign && i == j)
            {
                mainDiagonalCounter++;
            }
        }
    }

    if(mainDiagonalCounter == 3)
    {
        return true;
    }

    int secondaryDiagonalCounter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(field[i][j] == playerSign && j == 3 - i - 1)
            {
                secondaryDiagonalCounter++;
            }
        }
    }

    if(secondaryDiagonalCounter == 3)
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        int columnCounter = 0;
        for (int j = 0; j < 3; j++)
        {
            if(field[j][i] == playerSign)
            {
                columnCounter++;
            }
        }

        if(columnCounter == 3)
        {
            return true;
        }
    }

    return false;
}

pair <int, int> GetCoordinates(int num) {
int currentX = -1;
    int currentY = -1;

    switch(num) {
        case 1: {
            currentX = 0;
            currentY = 0;
            break;
        }
        case 2: {
            currentX = 0;
            currentY = 1;
            break;
        }
        case 3: {
            currentX = 0;
            currentY = 2;
            break;
        }
        case 4: {
            currentX = 1;
            currentY = 0;
            break;
        }
        case 5: {
            currentX = 1;
            currentY = 1;
            break;
        }
        case 6: {
            currentX = 1;
            currentY = 2;
            break;
        }
        case 7: {
            currentX = 2;
            currentY = 0;
            break;
        }
        case 8: {
            currentX = 2;
            currentY = 1;
            break;
        }
        case 9: {
            currentX = 2;
            currentY = 2;
            break;
        }
    }

    pair<int, int> coordinates;
    coordinates.first = currentX;
    coordinates.second = currentY;

    return coordinates;
}

bool PutSign(int num, char field[3][3], char playerSign) {
    pair<int, int> currentCoordinates = GetCoordinates(num);
    int currentX = currentCoordinates.first;
    int currentY = currentCoordinates.second;
    bool coordinates = CheckCoordinates(currentX, currentY);
    bool checkIsOccupied = CheckFieldNum(field, currentX, currentY);
    if(coordinates == false)
        {
            cout<<"This position is out of the field!\n\n";
            system("pause");
            return false;
        }
        else if(checkIsOccupied == false)
        {
            cout<<"This position is occupied\n\n";
            system("pause");
            return false;
        }
        else {
            field[currentX][currentY] = playerSign;
            return true;
        }
}

void AddPositionToFile(string position) {
    ofstream file("Positions.txt", std::ofstream::app);
    file << position << endl;
    file.close();
}

string CreateLoosingPosition(char field[3][3], char computerSign, char playerSign) {
    string position = "";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(field[i][j] == playerSign) {
                position += 'P';
            } else if(field[i][j] == computerSign) {
                position += 'C';
            } else {
                position += field[i][j];
            }
        }
    }

    return position;
}

bool IsLoosingMove(char field[3][3], int x, int y, char computerSign, char playerSign) {
    char copyOfField[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            copyOfField[i][j] = field[i][j];
        }
    }

    copyOfField[x][y] = computerSign;
    string position = CreateLoosingPosition(copyOfField, computerSign, playerSign);
    ifstream fileToRead("Positions.txt");
    string line;
    while(!fileToRead.eof()) {
        fileToRead >> line;
        if(position == line) {
            return false;
        }
    }
    fileToRead.close();
    return true;
}

int main()
{
	//This is needed for randomasing numbers
    srand (time(NULL));
	
    //Creating field
    char field[3][3];
    CreateField(field);

    //Choosing player's sign && computer's sign
    char playerSign;
    char computerSign;
    cout<<"Choose your sign:\n1 - X\n2 - O\n";
    int numOfSign;
    do
    {
        cin>>numOfSign;
        if(numOfSign == 1)
        {
            playerSign = 'X';
            computerSign = 'O';
        }
        else if(numOfSign == 2)
        {
            playerSign = 'O';
            computerSign = 'X';
        }
        else
        {
            cout<<"You should choose between 1 and 2\n";
        }
    }
    while(numOfSign != 1 && numOfSign != 2);
    PrintField(field, playerSign, computerSign);
	
    //Game loop
    while(true)
    {
        //Enter coordinates
        int currentPossition;
        cout<<"Enter current position: ";
        cin>>currentPossition;

        //Player's move
        bool isValid = PutSign(currentPossition, field, playerSign);
        if (isValid == true)
        {
            //Check result
            bool isPlayerWin = IsWin(field, playerSign);
            if (isPlayerWin == true)
            {
                PrintField(field, playerSign, computerSign);
                int currentX = -1;
                int currentY = -1;
                pair<int, int> currentCoordinates = GetCoordinates(currentPossition);
                currentX = currentCoordinates.first;
                currentY = currentCoordinates.second;
                field[currentX][currentY] = '.';
                string currentLoosingPosition = CreateLoosingPosition(field, computerSign, playerSign);
                AddPositionToFile(currentLoosingPosition);
                cout<<"You win!\n";
                return 0;
            }


            bool currentIsDraw = IsDraw(field);
            if (currentIsDraw == true)
            {
                PrintField(field, playerSign, computerSign);
                cout<<"Raven rezulat slabaci!\n";
                return 0;
            }

            //Move bot
            //Picking coordinates
            int botX = -1;
            int botY = -1;
            bool isOccupied = false;
            bool isLoosingMove = false;
            while(isOccupied == false || isLoosingMove == false)
            {
                botX = rand() % 3;
                botY = rand() % 3;
                isLoosingMove = IsLoosingMove(field, botX, botY, computerSign, playerSign);
                isOccupied = CheckFieldNum(field, botX, botY);
            }

            field[botX][botY] = computerSign;

            //Check Bot Wins
            bool isBotWin = IsWin(field, computerSign);
            currentIsDraw = IsDraw(field);
            if (isBotWin == true)
            {
                PrintField(field, playerSign, computerSign);
                cout<<"You Lost!\n";
                return 0;
            }

            if (currentIsDraw == true)
            {
                PrintField(field, playerSign, computerSign);
                cout<<"Draw!\n";
                return 0;
            }
        }

        PrintField(field, playerSign, computerSign);
    }

    return 0;
}
