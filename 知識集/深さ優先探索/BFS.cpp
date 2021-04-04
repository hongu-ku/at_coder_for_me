#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> field_t;

typedef pair<int, int> point_t;

point_t operator+(const point_t &lhs, const point_t &rhs)
{
    point_t p = { lhs.first + rhs.first, lhs.second + rhs.second };
    return p;
}

bool operator==(const point_t &lhs, const point_t &rhs)
{
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

bool is_in_field(int col, int row, const point_t &point)
{
    const int c = point.second;
    const int r = point.first;
    return (0 <= c && c < col) && (0 <= r && r < row);
}

int solve(int col, int row, field_t &field, const point_t &start, const point_t &goal)
{
    // 2. 各マスの訪問履歴(memo)を作成する
    //    memoにはスタートからそのマスまでの歩数を格納する(初期値は0)
    vector<vector<int>> memo;
    for(int i = 0; i < row; ++i) {
        vector<int> v(col, 0);
        memo.push_back(v);
    }

    // 移動方向(上下左右)
    const point_t points[] = {
        { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 },
    };

    // 3. スタートのマスをキューに格納する
    queue<point_t> q;
    q.push(start);

    // 11. 4から10をキューが空になるまで繰り返す
    while( !q.empty() ) {
        // 4. キューの先頭から一マス取得する
        point_t cur = q.front(); q.pop();

        // 5. 取り出したマスがゴールなら終了
        if(cur == goal) {
            return memo[cur.first][cur.second];
        }

        for(const auto &point : points) {
            // 6. 手順4で取り出したマス(cur)から上下左右の何れかに移動する
            point_t next = cur + point;
            // 7. 移動先のマス(next)が迷路外でないことを確認する(迷路外の場合は手順6に戻る)
            if( is_in_field(col, row, next) ) {
                const char s = field[next.first][next.second];
                // 8. 移動先のマス(next)が道またはゴールであることを確認する(道でもゴールでもない場合は手順6に戻る)
                if(s == '0' || s == 'g') {
                    // 9. 移動先のマス(next)が未訪問であることを確認する(訪問済みの場合は手順6に戻る)
                    if(memo[next.first][next.second] == 0) {
                        // 10. 移動先のマス(next)をキューに格納し、訪問履歴を更新する
                        q.push(next);
                        memo[next.first][next.second] = memo[cur.first][cur.second] + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int col, row;
    cin >> col >> row;

    point_t start, goal;
    field_t field;

    // 1. 迷路(field)を作成する
    for(int i = 0; i < row; ++i) {
        vector<char> v;
        for(int j = 0; j < col; ++j) {
            char c;
            cin >> c;
            v.push_back(c);
            // スタート地点とゴール地点は別途覚えておく
            if( c == 's' ) {
                start.first = i;
                start.second = j;
            } else if( c == 'g' ) {
                goal.first = i;
                goal.second = j;
            }
        }
        field.push_back(v);
    }

    // 最短歩数はsolveで計算する
    cout << solve(col, row, field, start, goal) << endl;
    return 0;
}
