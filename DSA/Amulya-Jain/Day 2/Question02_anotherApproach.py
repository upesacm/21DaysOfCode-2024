def currentRank(leaderboard_scores, player_scores):
    unique_leaderboard = sorted(set(leaderboard_scores), reverse=True)
    ranks = []
    n = len(unique_leaderboard)

    for score in player_scores:
        while n > 0 and score >= unique_leaderboard[n - 1]:
            n -= 1
        ranks.append(n + 1)
    return ranks

if __name__ == "__main__":
    leaderboardsize = int(input("Enter the size of leaderboard scores: -\n"))
    print("Enter the leaderboard scores: -")
    leaderboard_scores = [int(input()) for i in range(leaderboardsize)]

    player_scores_size = int(input("Enter the size of player scores: -\n"))
    print("Enter the player scores: -")
    player_scores = [int(input()) for i in range(player_scores_size)]

    playerrank = currentRank(leaderboard_scores, player_scores)

    print("Player rank in leaderboard after each score is: ", end="")
    print(" ".join(map(str, playerrank)))
