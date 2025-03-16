#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/design-spreadsheet/

class Spreadsheet {
    public:
        vector<vector<int>> sheet;
        int n;
        Spreadsheet(int rows) {
            n=rows;
            sheet.resize(26, vector<int>(1001, 0));
        }
        
        void setCell(string cell, int value) {
            int x=cell[0]-'A';
            int y=0;
            for(int i=1;i<cell.length();i++){
                y=y*10 + cell[i]-'0';
            }
            sheet[x][y]=value;
        }
        
        void resetCell(string cell) {
            int x=cell[0]-'A';
            int y=0;
            for(int i=1;i<cell.length();i++){
                y=y*10 + cell[i]-'0';
            }
            sheet[x][y]=0;
        }
        
        int getValue(string formula) {
            int index=1;
            int val1=0;
            if(formula[1]>='A' && formula[1]<='Z'){
                int x=formula[1]-'A';
                int y=0;
                index++;
                while(index<formula.length() && formula[index]!='+'){
                    y=y*10+formula[index]-'0';
                    index++;
                }
                val1=sheet[x][y];
            }
            else{
                int y=0;
                while(index<formula.length() && formula[index]!='+'){
                    y=y*10+formula[index]-'0';
                    index++;
                }
                val1=y;
            }
            if(index==formula.length()){
                return val1;
            }
            index++;
            int val2=0;
            if(formula[index]>='A' && formula[index]<='Z'){
                int x=formula[index]-'A';
                int y=0;
                index++;
                while(index<formula.length() && formula[index]!='+'){
                    y=y*10+formula[index]-'0';
                    index++;
                }
                val2=sheet[x][y];
            }
            else{
                int y=0;
                while(index<formula.length() && formula[index]!='+'){
                    y=y*10+formula[index]-'0';
                    index++;
                }
                val2=y;
            }
            return val1+val2;
        }
    };
    
    /**
     * Your Spreadsheet object will be instantiated and called as such:
     * Spreadsheet* obj = new Spreadsheet(rows);
     * obj->setCell(cell,value);
     * obj->resetCell(cell);
     * int param_3 = obj->getValue(formula);
     */