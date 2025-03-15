class Spreadsheet
{
public:
    map<string, int> valMap;

    int getter(string cell)
    {
        if (isdigit(cell[0]))
            return stoi(cell);
        return valMap[cell];
    }

    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        valMap[cell] = value;
    }

    void resetCell(string cell)
    {
        valMap[cell] = 0;
    }

    int getValue(string formula)
    {
        if (formula[0] != '=')
            return stoi(formula);

        string s1 = "";
        string s2 = "";
        int i = 1;
        int n = formula.size();
        while (i < n && formula[i] != '+')
            s1 += formula[i++];
        i++;
        while (i < n)
            s2 += formula[i++];

        return getter(s1) + getter(s2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */