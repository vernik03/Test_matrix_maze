#include <iostream>
#include <vector>

using namespace std;

bool move(vector<vector<bool>> matrix, int m_i, int m_j) {   
    matrix[m_i][m_j] = 0;
    if (m_i + 1 < matrix.size() && matrix[m_i + 1][m_j]==1)
    {
        if (!move(matrix, m_i + 1, m_j))
        {
            matrix[m_i + 1][m_j] = 0;
        }
        else
        {
            return true;
        }
    }
    if (m_j + 1 < matrix[m_i].size() && matrix[m_i][m_j + 1] == 1)
    {
        
        if (!move(matrix, m_i, m_j + 1))
        {
            matrix[m_i][m_j + 1] = 0;
        }
        else
        {
            return true;
        }
    }
    if (m_i - 1 >= 0 && matrix[m_i - 1][m_j] == 1)
    {
        if (!move(matrix, m_i - 1, m_j))
        {
            matrix[m_i - 1][m_j] = 0;
        }
        else
        {
            return true;
        }
    }
    if (m_j - 1 >= 0 && matrix[m_i][m_j - 1] == 1)
    {
        if (!move(matrix, m_i, m_j - 1))
        {
            matrix[m_i][m_j - 1] = 0;
        }
        else
        {
            return true;
        }
    }
    if ((m_i == matrix.size() - 1) && (m_j == matrix[matrix.size() - 1].size() - 1))
    {
        return true;
    }
    else
    {
       return false;
    }
   

}

bool way_check(vector<vector<bool>> matrix) {

    int m_i = 0;
    int m_j = 0;
    if (matrix.size()<2 || matrix[matrix.size()-1].size()<2)
    {
        cout << "Error. Matrix is too small" << endl;
        return false;
    }
    if (matrix.size() > 50 || matrix[matrix.size() - 1].size() > 50)
    {
        cout << "Error. Matrix is too big" << endl;
        return false;
    }
    return move(matrix, m_i, m_j);
    
};


int main()
{
    vector<vector<bool>> matrix{
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 1, 1, 1},
         {1, 1, 0, 1} };
    vector<vector<bool>> matrix2{
         {1, 1, 0, 0, 1, 0, 1, 0},
         {0, 1, 0, 0, 1, 1, 1, 1},
         {0, 1, 1, 1, 1, 0, 0, 1},
         {1, 1, 0, 1, 1, 1, 1, 0},
         {1, 1, 0, 1, 0, 0, 1, 0},
         {1, 1, 0, 1, 0, 0, 1, 1},
         {0, 1, 1, 1, 1, 0, 0, 1}, };
    vector<vector<bool>> matrix3{
         {1, 1, 0, 0, 1, 0, 1, 0},
         {0, 1, 0, 0, 1, 1, 1, 1},
         {0, 1, 1, 1, 0, 0, 0, 1},
         {1, 1, 0, 1, 0, 1, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {1, 1, 0, 1, 0, 0, 1, 1},
         {0, 1, 1, 1, 1, 0, 0, 1}, };
    vector<vector<bool>> matrix4;
    for (int i = 0; i < 50; i++)
    {
        vector<bool> str;
        for (int j = 0; j < 50; j++)
        {
            str.push_back(rand() % 2);
        }
        matrix4.push_back(str);
    }
    vector<vector<bool>> matrix5{
         {1, 1},
         {0, 1} };
    vector<vector<bool>> matrix6{
         {1}, };
    vector<vector<bool>> matrix7;
    for (int i = 0; i < 70; i++)
    {
        vector<bool> str;
        for (int j = 0; j < 70; j++)
        {
            str.push_back(rand() % 2);
        }
        matrix7.push_back(str);
    }
    cout << way_check(matrix) << endl; //1
    cout << way_check(matrix2) << endl;//1
    cout << way_check(matrix3) << endl;//0
    cout << way_check(matrix4) << endl;//0
    cout << way_check(matrix5) << endl;//1
    cout << way_check(matrix6) << endl;//Error. small
    cout << way_check(matrix7) << endl;//Error. big
}
