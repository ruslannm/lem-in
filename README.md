# lem-in
Алгоритм Диница
https://wiki2.red/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%94%D0%B8%D0%BD%D0%B8%D1%86%D0%B0

step 1. Construct a level graph by doing a BFS
step 2. If th sink was never reached while building the level graph, then stop and return the max flow/
step 3. Using only valid edges in the level graph, do multiple DFS, until a blocking flow is reached.
