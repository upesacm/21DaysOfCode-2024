def rank_after_each_round(leaderboard, player_score):
    if leaderboard is None or player_score is None:
        return None
    rank = [0] * len(player_score)

    for i in range(len(player_score)):
        count = 0
        j = 0
        while j < len(leaderboard) and player_score[i] < leaderboard[j]:
            if j < len(leaderboard) - 1 and leaderboard[j] == leaderboard[j + 1]:
                j += 1
                continue
            count += 1
            j += 1
        rank[i] = count + 1
    return rank

def main():
    leaderboard = [160, 120, 100, 95, 85, 80, 80, 75]  # test case_1
    player_score = [60, 80, 90, 100, 120]
    rank = rank_after_each_round(leaderboard, player_score)
    print("Output from test case 1")
    for r in rank:
        print(r)

    leaderboard1 = [100, 95, 85, 70]  # test case_2
    player_scores1 = [70, 80, 120]
    rank1 = rank_after_each_round(leaderboard1, player_scores1)
    print("Output from test case 2")
    for r in rank1:
        print(r)

main()

