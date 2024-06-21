def count(candy, day, month):
  n = len(candy)
  dp = [[0] * (day + 1) for _ in range(n + 1)]
  for i in range(n + 1):
    dp[i][0] = 1
  for j in range(1, day + 1):
    dp[0][j] = 0

  for i in range(1, n + 1):
    for j in range(1, day + 1):
      if candy[i - 1] > j:
        dp[i][j] = dp[i - 1][j]
      else:
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - candy[i - 1]]

  return dp[n][day]

candy = [2, 2, 1, 3, 2]
day = 4
month = 2

result = count(candy, day, month)
print("Number of valid segments:", result)
