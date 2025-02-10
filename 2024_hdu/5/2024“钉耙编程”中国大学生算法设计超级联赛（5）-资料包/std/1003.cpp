#include <bits/stdc++.h>

using namespace std;

#define ULL unsigned long long
const ULL MOD = 1e18 + 3;
typedef pair<int, int> PII;

#define GREEN 0
#define ORANGE 1
#define BLUE 2
#define RED 3
#define WHITE 4
#define YELLOW 5


bool locked[100][100];
vector<PII> rot_check_pair[6];
vector<int> rot_array[6];
unordered_map<ULL, int> dist, lrot;
unordered_map<ULL, ULL> lst;
unordered_map<int, int> scan_find_id[6];

inline int col(int x) {return x / 9;}
inline int pos(int x) {return x % 9;}
inline int id(int color, int pos){return color * 9 + pos;}
struct Cube
{
    int a[6][8];
    ULL h;
    bool hash_st;
    Cube()
    {
        for (int i = 0; i < 6; i ++ )
            for (int j = 0; j < 8; j ++ )
                a[i][j] = i * 9 + j;
        hash_st = 0;
    }
    ULL Hash()
    {
        if (hash_st) return h;
        h = 0;
        for (int i = 0; i < 6; i ++ )
        {
            unsigned int res = 0;
            for (int j = 0; j < 8; j ++ )
            {
                res = res * 6 + col(a[i][j]);
            }
            h = (h * (1 << 21) + res) % MOD;
        }
        hash_st = 1;
        return h;
    }
    bool check(int color)
    {
        if (color == 3 || color == 4) return false;
        for (PII p : rot_check_pair[color])
        {
            int x = p.first, y = p.second;
            if (locked[a[col(x)][pos(x)]][pos(y) < 8 ? a[col(y)][pos(y)] : id(col(y), 8)]) return false;
        }
        return true;
    }
    Cube Rot(int color, int dir) //dir:1为顺时针，-1为逆时针
    {
        Cube res;
        for (int i = 0; i < 6; i ++ )
            for (int j = 0; j < 8; j ++ )
                res.a[i][j] = a[i][j]; 
        
        for (int i = 0; i < 8; i ++ )
            res.a[color][i] = a[color][(i - 2 * dir + 8) % 8];
        for (int i = 0; i < 12; i ++ )
        {
            int x = rot_array[color][i];
            int y = rot_array[color][(i - 3 * dir + 12) % 12];
            res.a[col(x)][pos(x)] = a[col(y)][pos(y)];
        }
        return res;
    }

    void scan()
    {
        hash_st = 0;

        int xx;
        for (int i = 5; i <= 5; i ++ )
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            cin >> a[i][7] >> xx >> a[i][3];
            cin >> a[i][6] >> a[i][5] >> a[i][4];
        }
        int i = 3;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        i = 0;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        i = 1;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        i = 2;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        i = 3;  
        cin >> a[i][7] >> xx >> a[i][3];
        i = 0;  
        cin >> a[i][7] >> xx >> a[i][3];
        i = 1;  
        cin >> a[i][7] >> xx >> a[i][3];
        i = 2;  
        cin >> a[i][7] >> xx >> a[i][3];
        i = 3;
        cin >> a[i][6] >> a[i][5] >> a[i][4];
        i = 0;
        cin >> a[i][6] >> a[i][5] >> a[i][4];
        i = 1;
        cin >> a[i][6] >> a[i][5] >> a[i][4];
        i = 2;
        cin >> a[i][6] >> a[i][5] >> a[i][4];

        for (int i = 4; i <= 4; i ++ )
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            cin >> a[i][7] >> xx >> a[i][3];
            cin >> a[i][6] >> a[i][5] >> a[i][4];
        }

        for (int i = 0; i < 6; i ++ )
            for (int j = 0; j < 8; j ++ ) a[i][j] *= 9;

        a[0][0] += scan_find_id[col(a[0][0])][col(a[3][2]) * 10 + col(a[5][6])];
        a[0][1] += scan_find_id[col(a[0][1])][100 + col(a[5][5])];
        a[0][2] += scan_find_id[col(a[0][2])][col(a[5][4]) * 10 + col(a[1][0])];
        a[0][3] += scan_find_id[col(a[0][3])][100 + col(a[1][7])];
        a[0][4] += scan_find_id[col(a[0][4])][col(a[1][6]) * 10 + col(a[4][2])];
        a[0][5] += scan_find_id[col(a[0][5])][100 + col(a[4][1])];
        a[0][6] += scan_find_id[col(a[0][6])][col(a[4][0]) * 10 + col(a[3][4])];
        a[0][7] += scan_find_id[col(a[0][7])][100 + col(a[3][3])];

        a[1][0] += scan_find_id[col(a[1][0])][col(a[0][2]) * 10 + col(a[5][4])];
        a[1][1] += scan_find_id[col(a[1][1])][100 + col(a[5][3])];
        a[1][2] += scan_find_id[col(a[1][2])][col(a[5][2]) * 10 + col(a[2][0])];
        a[1][3] += scan_find_id[col(a[1][3])][100 + col(a[2][7])];
        a[1][4] += scan_find_id[col(a[1][4])][col(a[2][6]) * 10 + col(a[4][4])];
        a[1][5] += scan_find_id[col(a[1][5])][100 + col(a[4][3])];
        a[1][6] += scan_find_id[col(a[1][6])][col(a[4][2]) * 10 + col(a[0][4])];
        a[1][7] += scan_find_id[col(a[1][7])][100 + col(a[0][3])];

        a[2][0] += scan_find_id[col(a[2][0])][col(a[1][2]) * 10 + col(a[5][2])];
        a[2][1] += scan_find_id[col(a[2][1])][100 + col(a[5][1])];
        a[2][2] += scan_find_id[col(a[2][2])][col(a[5][0]) * 10 + col(a[3][0])];
        a[2][3] += scan_find_id[col(a[2][3])][100 + col(a[3][7])];
        a[2][4] += scan_find_id[col(a[2][4])][col(a[3][6]) * 10 + col(a[4][6])];
        a[2][5] += scan_find_id[col(a[2][5])][100 + col(a[4][5])];
        a[2][6] += scan_find_id[col(a[2][6])][col(a[4][4]) * 10 + col(a[1][4])];
        a[2][7] += scan_find_id[col(a[2][7])][100 + col(a[1][3])];

        a[3][0] += scan_find_id[col(a[3][0])][col(a[2][2]) * 10 + col(a[5][0])];
        a[3][1] += scan_find_id[col(a[3][1])][100 + col(a[5][7])];
        a[3][2] += scan_find_id[col(a[3][2])][col(a[5][6]) * 10 + col(a[0][0])];
        a[3][3] += scan_find_id[col(a[3][3])][100 + col(a[0][7])];
        a[3][4] += scan_find_id[col(a[3][4])][col(a[0][6]) * 10 + col(a[4][0])];
        a[3][5] += scan_find_id[col(a[3][5])][100 + col(a[4][7])];
        a[3][6] += scan_find_id[col(a[3][6])][col(a[4][6]) * 10 + col(a[2][4])];
        a[3][7] += scan_find_id[col(a[3][7])][100 + col(a[2][3])];

        a[4][0] += scan_find_id[col(a[4][0])][col(a[3][4]) * 10 + col(a[0][6])];
        a[4][1] += scan_find_id[col(a[4][1])][100 + col(a[0][5])];
        a[4][2] += scan_find_id[col(a[4][2])][col(a[0][4]) * 10 + col(a[1][6])];
        a[4][3] += scan_find_id[col(a[4][3])][100 + col(a[1][5])];
        a[4][4] += scan_find_id[col(a[4][4])][col(a[1][4]) * 10 + col(a[2][6])];
        a[4][5] += scan_find_id[col(a[4][5])][100 + col(a[2][5])];
        a[4][6] += scan_find_id[col(a[4][6])][col(a[2][4]) * 10 + col(a[3][6])];
        a[4][7] += scan_find_id[col(a[4][7])][100 + col(a[3][5])];

        a[5][0] += scan_find_id[col(a[5][0])][col(a[3][0]) * 10 + col(a[2][2])];
        a[5][1] += scan_find_id[col(a[5][1])][100 + col(a[2][1])];
        a[5][2] += scan_find_id[col(a[5][2])][col(a[2][0]) * 10 + col(a[1][2])];
        a[5][3] += scan_find_id[col(a[5][3])][100 + col(a[1][1])];
        a[5][4] += scan_find_id[col(a[5][4])][col(a[1][0]) * 10 + col(a[0][2])];
        a[5][5] += scan_find_id[col(a[5][5])][100 + col(a[0][1])];
        a[5][6] += scan_find_id[col(a[5][6])][col(a[0][0]) * 10 + col(a[3][2])];
        a[5][7] += scan_find_id[col(a[5][7])][100 + col(a[3][1])];
    }
    
    void show()
    {
        for (int i = 5; i <= 5; i ++ )
        {
            cout << "      " << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << '\n';
            cout << "      " << col(a[i][7]) << " " << i << " " << col(a[i][3]) << '\n';
            cout << "      " << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << '\n';
        }
        int i = 3;
        cout << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << " ";
        i = 0;
        cout << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << " ";
        i = 1;
        cout << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << " ";
        i = 2;
        cout << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << '\n';
        i = 3;  
        cout << col(a[i][7]) << " " << i << " " << col(a[i][3]) << " ";
        i = 0;  
        cout << col(a[i][7]) << " " << i << " " << col(a[i][3]) << " ";
        i = 1;  
        cout << col(a[i][7]) << " " << i << " " << col(a[i][3]) << " ";
        i = 2;  
        cout << col(a[i][7]) << " " << i << " " << col(a[i][3]) << '\n';
        i = 3;
        cout << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << " ";
        i = 0;
        cout << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << " ";
        i = 1;
        cout << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << " ";
        i = 2;
        cout << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << '\n';

        for (int i = 4; i <= 4; i ++ )
        {
            cout << "      " << col(a[i][0]) << " " << col(a[i][1]) << " " << col(a[i][2]) << '\n';
            cout << "      " << col(a[i][7]) << " " << i << " " << col(a[i][3]) << '\n';
            cout << "      " << col(a[i][6]) << " " << col(a[i][5]) << " " << col(a[i][4]) << '\n';
        }
        cout << endl;
    }


};

void add_lock(int color, int x, int y)
{
    locked[id(color, x)][id(color, y)] = 1;
    locked[id(color, y)][id(color, x)] = 1;
}

void locked_init()
{
    memset(locked, 0, sizeof locked);
    int color = GREEN;
    add_lock(color, 0, 1);
    add_lock(color, 3, 4);
    add_lock(color, 5, 8);
    add_lock(color, 6, 7);

    color = ORANGE;
    add_lock(color, 1, 2);
    add_lock(color, 3, 8);
    add_lock(color, 4, 5);
    add_lock(color, 6, 7);

    color = BLUE;
    add_lock(color, 1, 2);
    add_lock(color, 3, 8);
    add_lock(color, 4, 5);
    
    color = RED;
    add_lock(color, 3, 4);
    add_lock(color, 5, 8);

    color = WHITE;
    add_lock(color, 3, 4);
    add_lock(color, 5, 6);
    add_lock(color, 7, 8);

    color = YELLOW;
    add_lock(color, 0, 1);
    add_lock(color, 2, 3);
    add_lock(color, 5, 6);
    add_lock(color, 7, 8);
}

void add_rot_check(int center, int color, int x, int y)
{
    rot_check_pair[center].emplace_back(id(color, x), id(color, y));
}

void rot_check_init()
{
    int center, color;
    
    center = GREEN;
    
        color = WHITE;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);

        color = YELLOW;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);

        color = RED;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = ORANGE;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);

    center = ORANGE;
    
        color = WHITE;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = YELLOW;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = GREEN;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = BLUE;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);

    center = BLUE;

        color = WHITE;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);

        color = YELLOW;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);

        color = ORANGE;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = RED;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);

    center = RED;

        color = WHITE;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);

        color = YELLOW;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);

        color = BLUE;
        //right
        add_rot_check(center, color, 2, 1);
        add_rot_check(center, color, 3, 8);
        add_rot_check(center, color, 4, 5);

        color = GREEN;
        //left
        add_rot_check(center, color, 0, 1);
        add_rot_check(center, color, 7, 8);
        add_rot_check(center, color, 6, 5);
    center = WHITE;
        
        color = BLUE;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);

        color = GREEN;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);
        
        color = ORANGE;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);
        
        color = RED;
        //down
        add_rot_check(center, color, 4, 3);
        add_rot_check(center, color, 5, 8);
        add_rot_check(center, color, 6, 7);

    center = YELLOW;

        color = BLUE;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);

        color = GREEN;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);
        
        color = ORANGE;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);
        
        color = RED;
        // up
        add_rot_check(center, color, 0, 7);
        add_rot_check(center, color, 1, 8);
        add_rot_check(center, color, 2, 3);
}

void rot_array_init()
{
    rot_array[GREEN] = {
        id(YELLOW, 6), id(YELLOW, 5), id(YELLOW, 4),
        id(ORANGE, 0), id(ORANGE, 7), id(ORANGE, 6),
        id(WHITE, 2), id(WHITE, 1), id(WHITE, 0),
        id(RED, 4), id(RED, 3), id(RED, 2)};

    rot_array[ORANGE] = {
        id(YELLOW, 4), id(YELLOW, 3), id(YELLOW, 2),
        id(BLUE, 0), id(BLUE, 7), id(BLUE, 6),
        id(WHITE, 4), id(WHITE, 3), id(WHITE, 2),
        id(GREEN, 4), id(GREEN, 3), id(GREEN, 2)};

    rot_array[BLUE] = {
        id(YELLOW, 2), id(YELLOW, 1), id(YELLOW, 0),
        id(RED, 0), id(RED, 7), id(RED, 6),
        id(WHITE, 6), id(WHITE, 5), id(WHITE, 4),
        id(ORANGE, 4), id(ORANGE, 3), id(ORANGE, 2)};

    rot_array[RED] = {
        id(YELLOW, 0), id(YELLOW, 7), id(YELLOW, 6),
        id(GREEN, 0), id(GREEN, 7), id(GREEN, 6),
        id(WHITE, 0), id(WHITE, 7), id(WHITE, 6),
        id(BLUE, 4), id(BLUE, 3), id(BLUE, 2)};

    rot_array[WHITE] = {
        id(GREEN, 6), id(GREEN, 5), id(GREEN, 4),
        id(ORANGE, 6), id(ORANGE, 5), id(ORANGE, 4),
        id(BLUE, 6), id(BLUE, 5), id(BLUE, 4),
        id(RED, 6), id(RED, 5), id(RED, 4)};

    rot_array[YELLOW] = {
        id(BLUE, 2), id(BLUE, 1), id(BLUE, 0),
        id(ORANGE, 2), id(ORANGE, 1), id(ORANGE, 0),
        id(GREEN, 2), id(GREEN, 1), id(GREEN, 0),
        id(RED, 2), id(RED, 1), id(RED, 0)};
}

void bfs_init()
{
    Cube a;
    dist[a.Hash()] = 0;
    lst[a.Hash()] = 0;
    queue<Cube> q;
    q.push(a);
    int cnt = 0, maxdist = 0;
    while (q.size())
    {
        Cube x = q.front(); q.pop();

        cnt ++ ;
        maxdist = dist[x.Hash()];
        if (maxdist >= 30) break;

        for (int i = 0; i < 6; i ++ )
        {
            if (!x.check(i)) continue;
            Cube y = x.Rot(i, -1);
            if (dist.count(y.Hash()))
            {
                if (dist[y.Hash()] == dist[x.Hash()] + 1 && lrot[y.Hash()] > i)
                {
                    lst[y.Hash()] = x.Hash();
                    lrot[y.Hash()] = i;
                }
                continue;
            }
            dist[y.Hash()] = dist[x.Hash()] + 1;
            lst[y.Hash()] = x.Hash();
            lrot[y.Hash()] = i;
            q.push(y);
        }   
    }
}

void scan_init()
{
    int color;
    {
        color = GREEN;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[RED * 10 + YELLOW] = 0;
        mp[100 + YELLOW] = 1;
        mp[YELLOW * 10 + ORANGE] = 2;
        mp[100 + ORANGE] = 3;
        mp[ORANGE * 10 + WHITE] = 4;
        mp[100 + WHITE] = 5;
        mp[WHITE * 10 + RED] = 6;
        mp[100 + RED] = 7;
    }
    {
        color = ORANGE;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[GREEN * 10 + YELLOW] = 0;
        mp[100 + YELLOW] = 1;
        mp[YELLOW * 10 + BLUE] = 2;
        mp[100 + BLUE] = 3;
        mp[BLUE * 10 + WHITE] = 4;
        mp[100 + WHITE] = 5;
        mp[WHITE * 10 + GREEN] = 6;
        mp[100 + GREEN] = 7;
    }
    {
        color = BLUE;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[ORANGE * 10 + YELLOW] = 0;
        mp[100 + YELLOW] = 1;
        mp[YELLOW * 10 + RED] = 2;
        mp[100 + RED] = 3;
        mp[RED * 10 + WHITE] = 4;
        mp[100 + WHITE] = 5;
        mp[WHITE * 10 + ORANGE] = 6;
        mp[100 + ORANGE] = 7;
    }
    {
        color = RED;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[BLUE * 10 + YELLOW] = 0;
        mp[100 + YELLOW] = 1;
        mp[YELLOW * 10 + GREEN] = 2;
        mp[100 + GREEN] = 3;
        mp[GREEN * 10 + WHITE] = 4;
        mp[100 + WHITE] = 5;
        mp[WHITE * 10 + BLUE] = 6;
        mp[100 + BLUE] = 7;
    }
    {
        color = WHITE;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[RED * 10 + GREEN] = 0;
        mp[100 + GREEN] = 1;
        mp[GREEN * 10 + ORANGE] = 2;
        mp[100 + ORANGE] = 3;
        mp[ORANGE * 10 + BLUE] = 4;
        mp[100 + BLUE] = 5;
        mp[BLUE * 10 + RED] = 6;
        mp[100 + RED] = 7;
    }
    {
        color = YELLOW;
        unordered_map<int, int> &mp = scan_find_id[color];
        mp[RED * 10 + BLUE] = 0;
        mp[100 + BLUE] = 1;
        mp[BLUE * 10 + ORANGE] = 2;
        mp[100 + ORANGE] = 3;
        mp[ORANGE * 10 + GREEN] = 4;
        mp[100 + GREEN] = 5;
        mp[GREEN * 10 + RED] = 6;
        mp[100 + RED] = 7;
    }
}

void init()
{
    locked_init();
    rot_check_init();
    rot_array_init();
    scan_init();
    bfs_init();
}

void find_rot(ULL x)
{
    while (lst[x] != 0)
    {
        cout << lrot[x] << " ";
        x = lst[x];
    }
    cout << '\n';
}

void solve()
{
    Cube a;
    a.scan();
    if (lst.count(a.Hash()))
    {
        cout << dist[a.Hash()] << '\n';
        find_rot(a.Hash());
        return;
    }
    queue<Cube> q;

    unordered_map<ULL, int> _dist, lrot;
    unordered_map<ULL, ULL> lst;

    q.push(a);
    _dist[a.Hash()] = -1;
    lst[a.Hash()] = 0;
    while (q.size())
    {
        Cube x = q.front(); q.pop();
        for (int i = 0; i < 6; i ++ )
        {
            if (!x.check(i)) continue;
            Cube y = x.Rot(i, 1);
            if (lst.count(y.Hash())) continue;
            lst[y.Hash()] = x.Hash();
            lrot[y.Hash()] = i;
            if (dist.count(y.Hash()) && dist[y.Hash()] >= 0)
            {
                cout << dist[y.Hash()] - _dist[x.Hash()] << endl;

                ULL xx = x.Hash();
                vector<int> v;
                while (lst[xx] != 0)
                {
                    v.push_back(lrot[xx]);
                    xx = lst[xx];
                }
                reverse(v.begin(), v.end());
                for (int x : v) cout << x << " ";

                cout << i << " ";
                find_rot(y.Hash());
                return;
            }
            _dist[y.Hash()] = _dist[x.Hash()] - 1;
            q.push(y);
        }
    }
}

signed main()
{
    init();
    int T = 1;
    cin >> T;
    while (T -- ) solve();
    return 0;
} 
