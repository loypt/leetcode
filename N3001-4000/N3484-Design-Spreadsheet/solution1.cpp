class Spreadsheet {
public:
    Spreadsheet(int rows) {
        this->grid = vector<vector<int>>(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value) {
        auto [x, y] = getPos(cell);
        grid[x][y] = value;
    }
    
    void resetCell(string cell) {
        auto [x, y] = getPos(cell);
        grid[x][y] = 0;
    }
    
    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return getCellVal(cell1) + getCellVal(cell2);
    }

private:
    vector<vector<int>> grid;

    pair<int, int> getPos(const string &cell) {
        int x = stoi(cell.substr(1));
        int y = cell[0] - 'A';
        return {x, y};
    }

    int getCellVal(string &cell) {
        if (isalpha(cell[0])) {
            auto [x, y] = getPos(cell);
            return grid[x][y];
        } else {
            return stoi(cell);
        }
    }
};
