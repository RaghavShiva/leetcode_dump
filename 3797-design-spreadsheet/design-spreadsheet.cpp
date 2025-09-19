class Spreadsheet {
public:
    vector<vector<int>> s;
    Spreadsheet(int rows) {
        s.resize(rows);
        for (int i = 0; i < rows; i++) {
            s[i].resize(26, 0);
        }
    }

    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1));
        r--;
        s[r][c] = value;
    }

    void resetCell(string cell) {
        int c = cell[0] - 'A';
        cell = cell.substr(1);
        int r = stoi(cell);
        r--;
        s[r][c] = 0;
    }

    int getValue(string formula) {
        int i = formula.find('+');
        int x=0,y=0;
        if (formula[1] <= 'Z' && formula[1] >= 'A') {
            int c = formula[1] - 'A';
            int r = stoi(formula.substr(2,i-2));
            r--;
            x = s[r][c];
        }
        else{
            x = stoi(formula.substr(1,i-1));
        }
        if (formula[i+1] <= 'Z' && formula[i+1] >= 'A') {
            int c = formula[i+1] - 'A';
            int r = stoi(formula.substr(i+2));
            r--;
            y = s[r][c];
        }
        else{
            y = stoi(formula.substr(i+1));
        }
        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */