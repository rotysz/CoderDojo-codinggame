#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int ParseLabels (int width, string input_line,char out_label[100])
{
    int label_number=0;
    for(int i=0;i<input_line.length();i++)
    {
        if(input_line[i]!=' ')
        {
            out_label[label_number++]=input_line[i];
        }
    }
    return label_number;
}
int GhostGo (int column,int height,char GhostLegs[100][100])
{
    int EndColumn=column;
    for(int i=0;i<height;i++)
    {
        if(GhostLegs[i][EndColumn]=='>')
        {
            EndColumn++;
        }
        else if(GhostLegs[i][EndColumn]=='<')
        {
            EndColumn--;
        }
    }
    return EndColumn;
}
int main()
{
    char TopLabel[100];
    char BottomLabel[100];
    char GhostLegs[100][100];
    int ColumnNumber=0;
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    for (int i = 0; i < H; i++) {
        string line;
        getline(cin, line);
        if(i==0)
        {
            ColumnNumber=ParseLabels(W,line, TopLabel);

        }
        else if(i==H-1)
        {
            ParseLabels(W, line, BottomLabel);
        }
        else
        {
            int poziomy_index=0;
            poziomy_index=0;
            for(int j=0;j<line.length();j++)
            {
                
                if(line[j]=='|')
                {
                    if(poziomy_index>0 && GhostLegs[i-1][poziomy_index-1]=='>')
                    {
                        GhostLegs[i-1][poziomy_index++]='<';
                    }
                    else
                    GhostLegs[i-1][poziomy_index++]='|';
                }
                else if(line[j]=='-')
                {
                    GhostLegs[i-1][poziomy_index-1]='>';
                }
                
            }
        }
        cerr<<line<<endl;
    }

    for(int i=0;i<H;i++)
    {
        cerr<<TopLabel[i]<<" "<<BottomLabel[i]<<endl;
    }
    for(int a=0;a<H;a++)
    {
        for(int b=0;b<W;b++)
        {
            cerr<<GhostLegs[a][b]<<" ";
        }
        cerr<<endl;
    }
    int i=0;
    while(i<ColumnNumber)
    {
        cout<<TopLabel[i]<<BottomLabel[GhostGo(i,H-2,GhostLegs)]<<endl;
        i++;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "answer" << endl;
}
