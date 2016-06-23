/// #sh

#include <bits/stdc++.h>

using namespace std;

bool matrix[20][20];

int x, y;
bool func(int check){

    bool done = false;
    for(int i=1; i<=10; ++i){

        for(int j=1; j<=10; ++j){
            /// #
            if(check == 1){
                if(matrix[i][j] == false){
                    matrix[i][j] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// #
            if(check == 2){
                if(matrix[i][j] == false and matrix[i+1][j] == false and i+1 <= 10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    //printf("%d %d",i+1, j);
                    x = i+1, y = j;
                    done = true;
                }
            }
            /// ##
            if(check == 3){
                if(matrix[i][j] == false and matrix[i][j+1] == false and j+1 <= 10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// #
            /// #
            if(check == 4){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and i+2 <=10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    //printf("%d %d", i+2, j);
                    x = i+2, y = j;
                    done = true;
                }
            }
            /// ###
            if(check == 5){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and j+2 <= 10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// #
            /// #
            /// #
            if(check == 6){
                 if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and matrix[i+3][j] == false and i+3 <= 10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    matrix[i+3][j] = true;
                    //printf("%d %d", i+3, j);
                    x = i+3, y = j;
                    done = true;
                }
            }
            /// ####
            if(check == 7){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and matrix[i][j+3] == false and j+3 <= 10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    matrix[i][j+3] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// #
            /// #
            /// #
            /// #
            if(check == 8){
                 if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and matrix[i+3][j] == false and matrix[i+4][j] == false and i+4 <= 10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    matrix[i+3][j] = true;
                    matrix[i+4][j] = true;
                    //printf("%d %d", i+4, j);
                    x = i+4, y = j;
                    done = true;
                }
            }
            /// #####
            if(check == 9){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and matrix[i][j+3] == false and matrix[i][j+4] == false and j+4 <= 10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    matrix[i][j+3] = true;
                    matrix[i][j+4] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// ##
            /// ##
            if(check == 10){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i+1][j] == false and matrix[i+1][j+1] == false and i+1 <= 10 and j+1 <= 10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i+1][j] = true;
                    matrix[i+1][j+1] = true;
                    //printf("%d %d", i+1, j);
                    x = i+1, y = j;
                    done = true;
                }
            }
            /// ###
            /// ###
            /// ###
            if(check == 11){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and matrix[i][j+1] == false and matrix[i+1][j+1] == false and matrix[i+2][j+1] == false and matrix[i][j+2] == false and matrix[i+1][j+2] == false and matrix[i+2][j+2] == false and i+2 <= 10 and j+2 <= 10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i+1][j+1] = true;
                    matrix[i+2][j+1] = true;
                    matrix[i][j+2] = true;
                    matrix[i+1][j+2] = true;
                    matrix[i+2][j+2] = true;
                    //printf("%d %d", i+2, j);
                    x = i+2, y = j;
                    done = true;
                }
            }
            /// ###
            ///   #
            ///   #
            if(check == 12){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and matrix[i+1][j+2] == false and matrix[i+2][j+2] == false and i+2<=10 and j+2<=10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    matrix[i+1][j+2] = true;
                    matrix[i+2][j+2] = true;
                    //printf("%d %d", i+2, j+2);
                    x = i+2, y = j;
                    done = true;
                }
            }
            ///   #
            ///   #
            /// ###
            if(check == 13){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and matrix[i-1][j+2] == false and matrix[i-2][j+2] == false and i-2>=1 and j+2<=10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    matrix[i-1][j+2] = true;
                    matrix[i-2][j+2] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// #
            /// ###
            if(check == 14){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and matrix[i+2][j+1] == false and matrix[i+2][j+2] == false and i+2<=10 and j+2<=10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    matrix[i+2][j+1] = true;
                    matrix[i+2][j+2] = true;
                    //printf("%d %d", i+2, j);
                    x = i+2, y = j;
                    done = true;
                }
            }
            /// ###
            /// #
            /// #
            if(check == 15){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+2][j] == false and matrix[i][j+1] == false and matrix[i][j+2] == false and i+2<=10 and j+2 <=10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+2][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i][j+2] = true;
                    //printf("%d %d", i+2, j);
                    x = i+2, y = j;
                    done = true;
                }
            }
            /// ##
            /// #
            if(check == 16){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i][j+1] == false and i+1<=10 and j+1<=10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i][j+1] = true;
                    //printf("%d %d", i+1, j);
                    x = i+1, y = j;
                    done = true;
                }

            }
            /// ##
            ///  #
            if(check == 17){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i+1][j+1] == false and i+1<=10 and j+1<=10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i+1][j+1] = true;
                    //printf("%d %d", i+1, j+1);
                    x = i+1, y = j;
                    done = true;
                }
            }
            ///  #
            /// ##
            if(check == 18){
                if(matrix[i][j] == false and matrix[i][j+1] == false and matrix[i-1][j+1] == false and i-1>=1 and j+1<=10){
                    matrix[i][j] = true;
                    matrix[i][j+1] = true;
                    matrix[i-1][j+1] = true;
                    //printf("%d %d", i, j);
                    x = i, y = j;
                    done = true;
                }
            }
            /// #
            /// ##
            if(check == 19){
                if(matrix[i][j] == false and matrix[i+1][j] == false and matrix[i+1][j+1] == false and i+1<=10 and j+1<=10){
                    matrix[i][j] = true;
                    matrix[i+1][j] = true;
                    matrix[i+1][j+1] = true;
                    //printf("%d %d", i+1, j);
                    x = i+1, y = j;
                    done = true;
                }
            }
            if(done)
                return done;
        }

    }
    return done;

}
vector<int> row, col;
void horizontal(){
    for(int i=1; i<=10; ++i){
            int cnt = 0;
            for(int j=1; j<=10; ++j)
                if(matrix[i][j] == true)
                    cnt++;
            if(cnt == 10)
                row.push_back(i);
        }
}

void vertical(){
    for(int i=1; i<=10; ++i){
        int cnt = 0;
        for(int j=1; j<=10; ++j)
            if(matrix[j][i] == true)
                cnt++;
        if(cnt == 10)
            col.push_back(i);
    }
}
void row_del(){
    for(int j=0; j<row.size(); ++j){
        //cout << "cleared row" << row[j] << endl;
        for(int i=1; i<=10; ++i)
            matrix[row[j]][i] = false;
    }

}

void col_del(){
    for(int j=0; j<col.size(); ++j){
        //cout << "cleared column " << col[j] << endl;
        for(int i=1; i<=10; ++i)
            matrix[i][col[j]] = false;
    }

}
int main(){


    int a, b, c;



    for(int i=0; i<20; ++i)
        for(int j=0; j<20; ++j)
            matrix[i][j] = true;

    for(int i=1; i<=10; ++i)
        for(int j=1; j<=10; ++j)
            matrix[i][j] = false;


    bool m = false;
    bool n = false;
    bool o = false;


    while(true){
        row.clear();
        col.clear();
        scanf("%d %d %d", &a, &b, &c);


        if(a == -1 and b == -1 and c == -1){
            break;
            //return 0;
        }

        x = -1, y = -1;
        m = func(a);
        int x1 = x, y1 = y;
        horizontal();
        vertical();

        row_del();
        col_del();

        row.clear();
        col.clear();

        x = -1, y = -1;
        n = func(b);
        int x2 = x, y2 = y;
        horizontal();
        vertical();

        row_del();
        col_del();

        row.clear();
        col.clear();

        x = -1, y = -1;
        o = func(c);
        int x3 = x, y3 = y;
        horizontal();
        vertical();

        row_del();
        col_del();

        /// all are true
        if(m == true and n == true and o == true)
            printf("1 %d %d 2 %d %d 3 %d %d", x1, y1, x2, y2, x3, y3);
            //cout << "1 " << x1 << " " << y1 << " " << "2 " << x2 << " " << y2 << " "<< "3 " << x3 << " " << y3;

        /// 1 = true 2 = true and 3 = false

        else if(m == true and n == true and o == false){
            printf("1 %d %d 2 %d %d -1 -1 -1", x1, y1, x2, y2);
            //cout << "1 " << x1 << " " << y1 << " " << "2 " << x2 << " " << y2 << " "<< "-1 -1 -1";
            //break;
            //return 0;
            //continue;
        }


        /// 1 = true 2 = false 3 = true
        else if(m == true and n == false and o == true){
            printf("1 %d %d 3 %d %d -1 -1 -1", x1, y1, x3, y3);
            //cout << "1 " << x1 << " " << y1 << " " << "3 " << x3 << " " << y3 << " "<< "-1 -1 -1";
            //break;
            //return 0;
            //continue;
        }


        /// 1 =false 2 = true 3 = true
        else if(m == false and n == true and o == true){
            printf("2 %d %d 3 %d %d -1 -1 -1", x2, y2, x3, y3);
            //cout << "2 " << x2 << " " << y2 << " " << "3 " << x3 << " " << y3 << " "<< "-1 -1 -1";
            //break;
            //return 0;
           // continue;
        }


        /// 1 true 2 = false 3 = false
        else if(m == true and n == false and o == false){
            printf("1 %d %d -1 -1 -1 -1 -1 -1", x1, y1);
            //cout << "1 " << x1 << " " << y1 << " " << "-1 -1 -1 -1 -1 -1";
            //break;
            //return 0;
            //continue;
        }

        /// 1 = false 2 = true 3 = false
        else if(m == false and n == true and o == false){
            printf("2 %d %d -1 -1 -1 -1 -1 -1", x2, y2);
            //cout << "2 " << x2 << " " << y2 << " " << "-1 -1 -1 -1 -1 -1";
            //break;
            //return 0;
            //continue;
        }

        /// 1 = false 2 = false 3 = true
        else if(m == false and n == false and o == true){
            printf("3 %d %d -1 -1 -1 -1 -1 -1", x3, y3);
            //cout << "3 " << x3 << " " << y3 << " " << "-1 -1 -1 -1 -1 -1";
            //break;
            //return 0;
            //continue;
        }

        else{
            printf("-1 -1 -1 -1 -1 -1 -1 -1 -1");
            //cout << "-1 -1 -1 -1 -1 -1 -1 -1 -1";
            //break;b
            //return 0;
            //continue;
        }


        cout << endl;
        fflush(stdout);

        //printf("\n");
        /*
        for(int i=1; i<=10; ++i){
            for(int j=1; j<=10; ++j)
                cout << matrix[i][j] << "  ";
            cout << endl << endl;
        }
        */

    }
}
