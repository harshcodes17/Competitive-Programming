#include <bits/stdc++.h>
using namespace std;

/*
  Pattern-checker for "straight ray" solutions on the triangular board.

  Reads:
    n
    rows: 1..n lines, i-th line has 2*i-1 numbers (labels 1..4), a1,1 == 4 guaranteed
    x y  (target row x, pos y)  (1-based)

  If a straight sequence of repeated identical rolls from start reaches target
  and the bottom labels along the path match the repeating cycle produced by
  that roll, prints the minimum number of rolls. Otherwise prints -1.

  NOTE: This only checks straight-line repeated-direction solutions.
*/

using Perm = array<int, 4>; // permutation of labels at positions [B, L, F, R]

Perm apply_perm(const Perm &p, const Perm &perm)
{
    Perm out;
    for (int i = 0; i < 4; i++)
        out[i] = p[perm[i]];
    return out;
}

// compute cycle (preperiod and cycle) of bottom labels when repeatedly applying roll_perm
pair<vector<int>, vector<int>> compute_bottom_cycle(const Perm &start, const Perm &roll_perm)
{
    map<Perm, int> seen;
    vector<int> seq;
    Perm cur = start;
    int step = 0;
    while (!seen.count(cur))
    {
        seen[cur] = step++;
        seq.push_back(cur[0]); // bottom label
        cur = apply_perm(cur, roll_perm);
    }
    int first = seen[cur];
    vector<int> pre(seq.begin(), seq.begin() + first);
    vector<int> cyc(seq.begin() + first, seq.end());
    return {pre, cyc};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    // compute total cells and row starts
    int m = 0;
    for (int r = 1; r <= n; r++)
        m += 2 * r - 1;
    vector<int> row_start(n + 1, 0);
    int acc = 0;
    for (int r = 1; r <= n; r++)
    {
        row_start[r] = acc;
        acc += 2 * r - 1;
    }

    vector<int> labels(m);
    int idx = 0;
    for (int r = 1; r <= n; r++)
    {
        int len = 2 * r - 1;
        for (int j = 0; j < len; j++)
        {
            cin >> labels[idx++];
        }
    }
    int tx, ty;
    cin >> tx >> ty;
    if (tx < 1 || tx > n || ty < 1 || ty > 2 * tx - 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    int target = row_start[tx] + (ty - 1);
    int start = 0; // a1,1

    // Build coordinate map: id -> (r,c)
    vector<pair<int, int>> coord(m);
    for (int r = 1; r <= n; r++)
    {
        int len = 2 * r - 1;
        for (int c = 1; c <= len; c++)
        {
            int id = row_start[r] + (c - 1);
            coord[id] = {r, c};
        }
    }

    // adjacency (same scheme as earlier messages)
    vector<vector<int>> adj(m);
    auto idf = [&](int r, int c) -> int
    { return row_start[r] + (c - 1); };
    for (int r = 1; r <= n; r++)
    {
        int len = 2 * r - 1;
        for (int c = 1; c <= len; c++)
        {
            int u = idf(r, c);
            if (c - 1 >= 1)
                adj[u].push_back(idf(r, c - 1));
            if (c + 1 <= len)
                adj[u].push_back(idf(r, c + 1));
            if (r - 1 >= 1)
            {
                int up_len = 2 * (r - 1) - 1;
                if (c - 1 >= 1 && c - 1 <= up_len)
                    adj[u].push_back(idf(r - 1, c - 1));
                if (c >= 1 && c <= up_len)
                    adj[u].push_back(idf(r - 1, c));
            }
            if (r + 1 <= n)
            {
                int down_len = 2 * (r + 1) - 1;
                if (c >= 1 && c <= down_len)
                    adj[u].push_back(idf(r + 1, c));
                if (c + 1 >= 1 && c + 1 <= down_len)
                    adj[u].push_back(idf(r + 1, c + 1));
            }
            sort(adj[u].begin(), adj[u].end());
            adj[u].erase(unique(adj[u].begin(), adj[u].end()), adj[u].end());
        }
    }

    // Initial orientation by problem statement: bottom=4, left=1, front=2, right=3
    Perm start_perm = {4, 1, 2, 3};

    // Example roll permutations (you can replace with physically-derived ones)
    // positions: index 0 = B, 1 = L, 2 = F, 3 = R
    Perm rollL = {1, 0, 2, 3}; // new positions are old indices mapped by perm: out[i] = p[perm[i]]
    Perm rollR = {3, 1, 2, 0};
    Perm rollF = {2, 1, 0, 3};

    // Precompute cycles for each roll type
    auto cycL = compute_bottom_cycle(start_perm, rollL);
    auto cycR = compute_bottom_cycle(start_perm, rollR);
    auto cycF = compute_bottom_cycle(start_perm, rollF);

    // For debugging you can print cycles:
    // cerr << "L pre size " << cycL.first.size() << " cyc size " << cycL.second.size() << "\n";

    // Now try each neighbor of start as a straight-ray direction.
    // For a neighbor v of start, compute (dr,dc) and follow that vector repeatedly to produce the ray.
    // Map (dr,dc) to one of rollL, rollR, rollF by heuristic:
    //   (0,-1) -> L, (0,1) -> R, else -> F
    auto choose_roll = [&](int dr, int dc) -> int
    {
        if (dr == 0 && dc == -1)
            return 0; // L
        if (dr == 0 && dc == 1)
            return 1; // R
        return 2;     // F (next-row / diagonal)
    };

    auto &preL = cycL.first;
    auto &cycleL = cycL.second;
    auto &preR = cycR.first;
    auto &cycleR = cycR.second;
    auto &preF = cycF.first;
    auto &cycleF = cycF.second;

    auto check_ray = [&](int dirType, vector<int> const &cycle_pre, vector<int> const &cycle) -> int
    {
        // simulate bottom labels along a ray and verify they match repeated application of the roll
        // returns number of rolls to reach target if match, else -1
        // We will build the ray from start in the chosen direction (passed externally)
        return -1; // placeholder, actual ray building below uses neighbor-specific data
    };

    int answer = -1;
    for (int v : adj[start])
    {
        // compute direction vector from start to v
        auto [r0, c0] = coord[start];
        auto [rv, cv] = coord[v];
        int dr = rv - r0;
        int dc = cv - c0;
        int dirType = choose_roll(dr, dc); // 0->L,1->R,2->F

        // Build the ray: repeatedly step by (dr,dc) as long as inside board
        vector<int> ray_cells;
        int cr = r0, cc = c0;
        while (true)
        {
            int nr = cr + dr, nc = cc + dc;
            if (nr < 1 || nr > n)
                break;
            int len = 2 * nr - 1;
            if (nc < 1 || nc > len)
                break;
            int nid = idf(nr, nc);
            ray_cells.push_back(nid);
            cr = nr;
            cc = nc;
        }
        if (ray_cells.empty())
            continue;

        // prepare cycle (pre + cyclic part) for this dirType
        vector<int> pre, cyc;
        if (dirType == 0)
        {
            pre = preL;
            cyc = cycleL;
        }
        else if (dirType == 1)
        {
            pre = preR;
            cyc = cycleR;
        }
        else
        {
            pre = preF;
            cyc = cycleF;
        }

        // simulate along ray: bottom must match labels of cells in sequence (including start cell at step0)
        // The sequence of bottoms from start is: pre (maybe) then repeated cyc.
        // We need to produce the infinite sequence of bottoms starting from initial orientation.
        vector<int> bottom_seq;
        for (int x : pre)
            bottom_seq.push_back(x);
        for (int i = 0; i < (int)cyc.size(); ++i)
            bottom_seq.push_back(cyc[i]); // one cycle appended
        // If ray length > bottom_seq length, it repeats cyc part
        // We'll check element by element using modular indexing.
        // Step 0 corresponds to start bottom (start_perm bottom). That must match label at start (it does per problem: a1,1 == 4)
        int cur_index = 0; // index into infinite bottom sequence
        auto bottom_at = [&](int step) -> int
        {
            if (step < (int)pre.size())
                return pre[step];
            int idx2 = step - (int)pre.size();
            return cyc[idx2 % (int)cyc.size()];
        };

        bool ok = true;
        // verify start cell label
        if (labels[start] != bottom_at(0))
            ok = false; // expected to match since a1,1 == 4
        if (!ok)
            continue;

        // walk through ray cells; i-th ray cell corresponds to step = i+1 (one roll to move into that cell)
        for (int i = 0; i < (int)ray_cells.size() && ok; i++)
        {
            int step = i + 1;
            int expected = bottom_at(step);
            int cellid = ray_cells[i];
            if (labels[cellid] != expected)
                ok = false;
            if (cellid == target && ok)
            {
                answer = step; // number of rolls to reach target
                break;
            }
        }
        if (answer != -1)
            break;
    }

    cout << answer << "\n";
    return 0;
}
